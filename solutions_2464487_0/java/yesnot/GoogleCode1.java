import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

//Google Code Jam
public class GoogleCode1 {
	private static MyScanner in;
	private static PrintStream out;
	private static PrintStream sysout = System.out;
	static int caseNum;

	private static void solve() throws IOException
	{
		PreCompute();
		int C = in.nextInt();
		for (int i = 0; i < C; i++) {
			caseNum = i + 1;
			out.print("Case #" + caseNum + ": ");
			solveCase();
		}
	}

	private static void PreCompute() {
	}

	private static void solveCase() throws IOException {
		long R = in.nextLong();
		long T = in.nextLong();
		long reqdPaint;
		long nRing = 1;
		while (true) {
			reqdPaint = 0;
			for (int n = 1; n <= nRing; n++) {
				reqdPaint += 2 * (R + (n - 1) * 2) + 1;
			}
			if (reqdPaint > T)
				break;
			nRing++;
		}
		long ans = nRing - 1;
		out.println(ans);
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