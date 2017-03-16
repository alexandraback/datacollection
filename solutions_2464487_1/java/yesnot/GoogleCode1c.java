import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

//Google Code Jam
public class GoogleCode1c {
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
		long nL = 0;
		long nR = 1000000000;
		long nMid = 0;
		long ans = -1;
		while (true) {
			nMid = (nL + nR) / 2;
			reqdPaint = calcPaint(R, nMid, T);
			if (reqdPaint > T)
				nR = nMid - 1;
			else {
				ans = nMid;
				nL = nMid + 1;
			}
			if (nR < nL) {
				break;
			}
		}
		// ans = calcPaint(1, 2000000000L);
		out.println(ans);
	}

	static long calcPaint(long rad, long nring, long T)
	{
		long alpha;
		if (nring % 2 == 0)
			alpha = 2 * (nring - 1) * nring / 2;
		else
			alpha = 2 *
					(
					((nring - 1) * (nring - 1) / 2) + ((nring - 1) / 2)
					);

		BigInteger bn = new BigInteger(String.valueOf(nring));
		bn = bn.multiply(new BigInteger(String.valueOf(rad)));
		bn = bn.add(new BigInteger(String.valueOf(alpha)));
		bn = bn.multiply(new BigInteger("2"));
		bn = bn.add(new BigInteger(String.valueOf(nring)));
		BigInteger bT = new BigInteger(String.valueOf(T));
		if (bn.compareTo(bT) > 0)
			return T + 1;

		long ret = 2 * (nring * rad + alpha) + nring;
		return ret;
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