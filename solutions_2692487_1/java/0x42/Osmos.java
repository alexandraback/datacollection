import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.ArrayList;
import java.util.Arrays;

public class Osmos {

	public static void main(String[] args) throws Exception {
		Osmos object = new Osmos();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			long a = (int) st.nval;

			st.nextToken();
			int n = (int) st.nval;

			int[] arr = new int[n];
			for (int i = 0; i < n; i++) {
				st.nextToken();
				arr[i] = (int) st.nval;
			}

			Arrays.sort(arr);

			int output = object.solve(a, arr);
			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	private int solve(long a, int[] arr) {

		int best = 1000000000;

		for (int keep = 0; keep <= arr.length; keep++) {

			ArrayList<Integer> inside = new ArrayList<Integer>();

			for (int z = 0; z < keep; z++)
				inside.add(arr[z]);

			int removed = arr.length - keep;

			int toAdd = solve2(a, inside);

			if (toAdd != -1)
				if (toAdd + removed < best)
					best = toAdd + removed;
		}

		return best;
	}

	private int solve2(long a, ArrayList<Integer> inside) {

		long currentSize = a;
		int plus = 0;

		for (int next = 0; next < inside.size(); next++) {
			long sizeOfNext = inside.get(next);

			while (currentSize <= sizeOfNext) {
				// we need to add motes
				
				if (currentSize == 1) //cannot eat anything
					return -1;
				
				plus++;
				currentSize += (currentSize - 1);
			}
			
			currentSize += sizeOfNext;
		}

		return plus;
	}
}
