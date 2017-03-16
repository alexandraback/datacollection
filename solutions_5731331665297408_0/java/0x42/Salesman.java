import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class Salesman {

	public static void main(String[] args) throws Exception {
		Salesman object = new Salesman();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			int n = (int) st.nval;

			st.nextToken();
			int m = (int) st.nval;

			List<String> codes = new ArrayList<>();

			for (int i = 0; i < n; i++) {
				st.nextToken();
				codes.add(String.valueOf((int) st.nval));
			}

			List<String> flights = new ArrayList<>();

			for (int i = 0; i < m; i++) {
				st.nextToken();
				int from = (int) st.nval;

				st.nextToken();
				int to = (int) st.nval;

				flights.add(from + "-" + to);
				flights.add(to + "-" + from);
			}

			String output = object.solve(codes, flights);
			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	private String solve(List<String> codes, List<String> flights) {
		int n = codes.size();

		int arr[] = new int[n];
		for (int z = 1; z <= n; z++)
			arr[z - 1] = z;

		BigInteger output = BigInteger.TEN;
		output = output.pow(100);

		do {

			BigInteger current = new BigInteger(codes.get(arr[0] - 1));

			for (int i = 1; i < arr.length; i++)
				current = current.multiply(BigInteger.TEN.pow(5)).add(
						new BigInteger(codes.get(arr[i] - 1)));

			if (current.compareTo(output) >= 0)
				continue;

			List<Integer> orderOfVisits = new ArrayList<>();
			orderOfVisits.add(arr[0]);

			List<Integer> done = new ArrayList<>();
			done.add(arr[0]);

			boolean ok = true;

			for (int visiti = 1; visiti < arr.length && ok; visiti++) {
				int visit = arr[visiti];

				for (int pos = orderOfVisits.size() - 1; pos >= -1; pos--) {

					if (pos == -1) {
						ok = false;
						break;
					}

					int currentCity = orderOfVisits.get(pos);

					// go from currentCity to visit
					if (flights.contains(currentCity + "-" + visit)) {
						orderOfVisits.add(visit);
						done.add(visit);

						// System.out.println("Taking flight: " + (currentCity +
						// "-" + visit));

						break;
					} else {
						orderOfVisits.remove(Integer.valueOf(currentCity));
						continue;
					}
				}

				if (!ok)
					continue;
			}

			if (ok)
				output = current;

		} while (gen(arr));

		return output.toString();
	}

	private static boolean reved(int[] a) {
		for (int i = 1; i < a.length; i++)
			if (a[i] > a[i - 1])
				return false;

		return true;
	}

	private static boolean gen(int[] arr) {
		if (arr.length == 0 || arr.length == 1 || reved(arr))
			return false;

		int i1 = -1;

		for (int i = arr.length - 1; i >= 1; i--)
			if (arr[i - 1] < arr[i]) {
				i1 = i - 1;
				break;
			}

		int i2 = -1;

		for (int i = arr.length - 1; i > i1; i--)
			if (arr[i] > arr[i1]) {
				i2 = i;
				break;
			}

		int tt = arr[i1];
		arr[i1] = arr[i2];
		arr[i2] = tt;

		for (int i = i1 + 1; i < i1 + 1 + (arr.length - 1 - i1) / 2; i++) {
			int sw = arr.length - 1 - (i - i1 - 1);
			tt = arr[i];
			arr[i] = arr[sw];
			arr[sw] = tt;

		}

		return true;
	}

}
