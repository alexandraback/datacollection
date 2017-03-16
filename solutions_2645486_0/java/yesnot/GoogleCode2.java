import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

//Google Code Jam
public class GoogleCode2 {
	private static MyScanner in;
	private static PrintStream out;
	static int caseNum;

	private static void solve() throws IOException
	{
		int C = in.nextInt();
		in.nextLine();
		for (int i = 0; i < C; i++) {
			caseNum = i + 1;
			out.print("Case #" + caseNum + ": ");
			solveCase();
		}
	}

	private static void solveCase() throws IOException {
		long E = in.nextInt();
		long R = in.nextInt();
		if (R > E)
			R = E;
		int N = in.nextInt();
		long[] v = new long[N];
		for (int i = 0; i < N; i++) {
			v[i] = in.nextLong();
		}

		long maxGain = 0;
		if (R == E) {
			long gain = 0;
			for (int i = 0; i < N; i++) {
				gain += v[i] * E;
			}
			maxGain = gain;
		}
		else {
			long gain = 0;
			long curE = E;
			for (int i = 0; i < N - 1; i++) {
				long maxAfter = 0;
				for (int j = i + 1; j < v.length; j++) {
					maxAfter = Math.max(maxAfter, v[j]);
				}
				long spent;
				if (v[i] <= maxAfter)
				{
					if (R <= curE)
						spent = R;
					else
						spent = curE;
				}
				else {
					spent = curE;
				}
				gain += spent * v[i];
				curE -= spent;
				curE += R;
				if (curE > E)
					curE = E;

			}
			gain += curE * v[N - 1];
			maxGain = gain;
		}

		out.println(maxGain);
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