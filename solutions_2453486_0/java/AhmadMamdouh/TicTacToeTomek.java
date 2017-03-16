import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class TicTacToeTomek {

	public static void main(String[] args) throws Exception {
		InputReader r = new InputReader(new FileReader("A.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			char[][] arr = new char[4][4];
			boolean complete = true;
			for (int i = 0; i < arr.length; i++) {
				arr[i] = r.next().toCharArray();
				for (int j = 0; j < arr.length; j++) {
					if (arr[i][j] == '.')
						complete = false;
				}
			}
			boolean xWin = false, oWin = false;
			boolean xDiagLeft = true, oDiagLeft = true;
			boolean xDiagRight = true, oDiagRight = true;
			for (int i = 0; i < 4; i++) {
				boolean canXRow = true, canXCol = true;
				for (int j = 0; j < 4; j++) {
					if (arr[i][j] == 'O' || arr[i][j] == '.')
						canXRow = false;
					if (arr[j][i] == 'O' || arr[j][i] == '.')
						canXCol = false;
				}
				xWin |= canXRow;
				xWin |= canXCol;
				boolean canORow = true, canOCol = true;
				for (int j = 0; j < 4; j++) {
					if (arr[i][j] == 'X' || arr[i][j] == '.')
						canORow = false;
					if (arr[j][i] == 'X' || arr[j][i] == '.')
						canOCol = false;
				}
				oWin |= canORow;
				oWin |= canOCol;
				if (arr[i][i] == 'O' || arr[i][i] == '.')
					xDiagLeft = false;
				if (arr[i][i] == 'X' || arr[i][i] == '.')
					oDiagLeft = false;
				if (arr[i][3 - i] == 'O' || arr[i][3 - i] == '.')
					xDiagRight = false;
				if (arr[i][3 - i] == 'X' || arr[i][3 - i] == '.')
					oDiagRight = false;
			}
			xWin |= xDiagLeft;
			oWin |= oDiagLeft;
			xWin |= xDiagRight;
			oWin |= oDiagRight;
			if (xWin)
				out.printf("Case #%d: X won\n", test);
			else if (oWin)
				out.printf("Case #%d: O won\n", test);
			else {
				if (complete)
					out.printf("Case #%d: Draw\n", test);
				else
					out.printf("Case #%d: Game has not completed\n", test);
			}
			test++;
		}
		out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
