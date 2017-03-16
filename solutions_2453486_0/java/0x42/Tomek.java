import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.StreamTokenizer;

public class Tomek {

	public static void main(String[] args) throws Exception {
		Tomek object = new Tomek();
		String className = object.getClass().getSimpleName();

		FileReader fileReader = new FileReader(new File(className.toLowerCase()
				+ ".in"));
		StreamTokenizer st = new StreamTokenizer(new BufferedReader(fileReader));

		FileWriter wr = new FileWriter(className.toLowerCase() + ".out");

		st.nextToken();
		int testCases = (int) st.nval;

		st.resetSyntax();
		st.wordChars(0, 256);
		st.whitespaceChars(0, 32);

		for (int tc = 1; tc <= testCases; tc++) {
			st.nextToken();
			String line1 = st.sval;

			st.nextToken();
			String line2 = st.sval;

			st.nextToken();
			String line3 = st.sval;

			st.nextToken();
			String line4 = st.sval;

			String output = object.solve(new String[] { line1, line2, line3,
					line4 });
			wr.write("Case #" + tc + ": " + output + "\r\n");
		}

		wr.close();
	}

	private String solve(String[] state) {

		boolean allFilled = true;
		for (String line : state)
			if (line.contains("."))
				allFilled = false;

		for (int i = 0; i < 4; i++) {
			if (won(state[i], 'X'))
				return "X won";

			if (won(state[i], 'O'))
				return "O won";
		}

		for (int i = 0; i < 4; i++) {
			String col = "" + state[0].charAt(i) + state[1].charAt(i)
					+ state[2].charAt(i) + state[3].charAt(i);

			if (won(col, 'X'))
				return "X won";

			if (won(col, 'O'))
				return "O won";
		}

		String diag1 = "" + state[0].charAt(0) + state[1].charAt(1)
				+ state[2].charAt(2) + state[3].charAt(3);
		String diag2 = "" + state[0].charAt(3) + state[1].charAt(2)
				+ state[2].charAt(1) + state[3].charAt(0);

		if (won(diag1, 'X'))
			return "X won";

		if (won(diag1, 'O'))
			return "O won";

		if (won(diag2, 'X'))
			return "X won";

		if (won(diag2, 'O'))
			return "O won";

		if (allFilled)
			return "Draw";

		return "Game has not completed";
	}

	private boolean won(String string, char ch) {
		for (int i = 0; i < string.length(); i++)
			if (string.charAt(i) != 'T' && string.charAt(i) != ch)
				return false;

		return true;
	}
}
