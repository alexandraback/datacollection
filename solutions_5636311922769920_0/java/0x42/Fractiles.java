import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;

public class Fractiles {

	public static void main(String[] args) throws Exception {
		Fractiles object = new Fractiles();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		for (int tc = 1; tc <= testCases; tc++) {

			System.out.println("At test " + tc + "/" + testCases);

			st.nextToken();
			int K = (int) st.nval;

			st.nextToken();
			int C = (int) st.nval;

			st.nextToken();
			int S = (int) st.nval;

			long[] result = object.solve(K, C, S);
			String str = Arrays.toString(result).replaceAll("[\\[\\],]+", "");
			wr.write("Case #" + tc + ": " + str + "\r\n");
		}

		wr.close();
	}

	public long[] solve(long K, long C, long S) {

		long[] output = new long[(int) S];

		for (int i = 1; i <= S; i++) {

			long value = i;
			output[i - 1] = value;
		}

		return output;
	}
}
