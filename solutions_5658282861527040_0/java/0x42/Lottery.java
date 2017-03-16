import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;

public class Lottery {

	public static void main(String[] args) throws Exception {
		Lottery object = new Lottery();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			int a = (int) st.nval;

			st.nextToken();
			int b = (int) st.nval;
			st.nextToken();

			int k = (int) st.nval;

			int output = object.solve(a, b, k);
			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	private int solve(int a, int b, int k) {

		int counter = 0;

		for (int i = 0; i < a; i++)
			for (int j = 0; j < b; j++) {
				int res = i & j;

				if (res < k)
					counter++;
			}

		return counter;

	}

}
