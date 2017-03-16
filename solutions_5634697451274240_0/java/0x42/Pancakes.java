import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;

public class Pancakes {

	public static void main(String[] args) throws Exception {
		Pancakes object = new Pancakes();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase() + ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		st.resetSyntax();
		st.wordChars(0, 256);
		st.whitespaceChars(0, 32);

		for (int tc = 1; tc <= testCases; tc++) {

			System.out.println("At test " + tc + "/" + testCases);

			st.nextToken();
			String s = st.sval;

			int result = object.solve(s);
			wr.write("Case #" + tc + ": " + result + "\r\n");
		}

		wr.close();
	}

	public int solve(String S) {

		char[] c = S.toCharArray();

		int flips = 0;

		for (int z = S.length() - 1; z >= 0; z--)
			if (c[z] == '-') {

				// aah, we need to flip
				for (int i = 0; i <= z; i++) {
					if (c[i] == '+') {
						c[i] = '-';
					} else {
						c[i] = '+';
					}
				}

				flips++;
			}

		return flips;

	}
}
