import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

//Google Code Jam
public class GoogleCode1 {
	private static MyScanner in;
	private static PrintStream out;

	private static void solve() throws IOException
	{
		int C = in.nextInt();
		in.nextLine();
		for (int i = 0; i < C; i++) {
			out.print("Case #" + (i + 1) + ": ");
			solveCase();
		}
	}

	private static void solveCase() throws IOException {
		char[][] b = new char[4][4];
		int dot = 0;
		for (int i = 0; i < 4; i++) {
			String s = in.nextLine();
			for (int j = 0; j < 4; j++) {
				b[i][j] = s.charAt(j);
				if (b[i][j] == '.')
					dot++;
			}
		}
		in.nextLine();
		for (int i = 0; i < 4; i++) {
			int tx = 0;
			int to = 0;
			for (int j = 0; j < 4; j++) {
				char c = b[i][j];
				if (c == 'X')
					tx++;
				else if (c == 'O')
					to++;
				else if (c == 'T') {
					to++;
					tx++;
				}
			}
			if (tx == 4) {
				out.println("X won");
				return;
			}
			if (to == 4) {
				out.println("O won");
				return;
			}
		}
		for (int i = 0; i < 4; i++) {
			int tx = 0;
			int to = 0;
			for (int j = 0; j < 4; j++) {
				char c = b[j][i];
				if (c == 'X')
					tx++;
				else if (c == 'O')
					to++;
				else if (c == 'T') {
					to++;
					tx++;
				}
			}
			if (tx == 4) {
				out.println("X won");
				return;
			}
			if (to == 4) {
				out.println("O won");
				return;
			}
		}
		int tx = 0;
		int to = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i != j)
					continue;
				char c = b[i][j];
				if (c == 'X')
					tx++;
				else if (c == 'O')
					to++;
				else if (c == 'T') {
					to++;
					tx++;
				}
			}
			if (tx == 4) {
				out.println("X won");
				return;
			}
			if (to == 4) {
				out.println("O won");
				return;
			}
		}
		tx = 0;
		to = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i + j != 3)
					continue;
				char c = b[i][j];
				if (c == 'X')
					tx++;
				else if (c == 'O')
					to++;
				else if (c == 'T') {
					to++;
					tx++;
				}
			}
			if (tx == 4) {
				out.println("X won");
				return;
			}
			if (to == 4) {
				out.println("O won");
				return;
			}
		}

		if (dot == 0)
			out.println("Draw");
		else
			out.println("Game has not completed");
	}

	public static void main(String[] args) throws IOException {
		// helpers for input/output
		boolean usingFileForIO = true;
		if (usingFileForIO) {
			// using input.txt and output.txt as I/O
			in = new MyScanner("E:\\zin.txt");
			out = new PrintStream("E:\\zout.txt");
		}
		else {
			in = new MyScanner();
			out = System.out;
		}

		solve();
	}

	// =====================================
	static class MyScanner {
		Scanner inp = null;

		public MyScanner() throws IOException
		{
			inp = new Scanner(System.in);
		}

		public MyScanner(String inputFile) throws IOException {
			inp = new Scanner(new FileInputStream(inputFile));
		}

		public int nextInt() throws IOException {
			return inp.nextInt();
		}

		public long nextLong() throws IOException {
			return inp.nextLong();
		}

		public double nextDouble() throws IOException {
			return inp.nextDouble();
		}

		public String nextString() throws IOException {
			return inp.next();
		}

		public String nextLine() throws IOException {
			return inp.nextLine();
		}
	}

}