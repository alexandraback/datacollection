import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

//Google Code Jam
public class GoogleCode2 {
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
		int N = in.nextInt();
		int M = in.nextInt();
		int[][] a = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				a[i][j] = in.nextInt();
			}
		}
		int[][] b = new int[N][M];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				b[i][j] = 100;
			}
		}
		int maxh;
		for (int i = 0; i < N; i++) {
			maxh = 0;
			for (int j = 0; j < M; j++)
				maxh = Math.max(maxh, a[i][j]);
			for (int j = 0; j < M; j++) {
				if (b[i][j] > maxh)
					b[i][j] = maxh;
			}
		}
		for (int j = 0; j < M; j++) {
			maxh = 0;
			for (int i = 0; i < N; i++)
				maxh = Math.max(maxh, a[i][j]);
			for (int i = 0; i < N; i++) {
				if (b[i][j] > maxh)
					b[i][j] = maxh;
			}
		}

		boolean possible = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] != b[i][j])
					possible = false;
				if (!possible)
					break;
			}
			if (!possible)
				break;
		}
		if (possible)
			out.println("YES");
		else
			out.println("NO");
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