import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FilenameFilter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Vaibhav Mittal
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "B-(small|large).*[.]in";
			File directory = new File(".");
			File[] candidates = directory.listFiles(new FilenameFilter() {
				public boolean accept(File dir, String name) {
					return name.matches(regex);
				}
			});
			File toRun = null;
			for (File candidate : candidates) {
				if (toRun == null || candidate.lastModified() > toRun.lastModified())
					toRun = candidate;
			}
			inputStream = new FileInputStream(toRun);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("b.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    int[] A;
    int[] B;
    int[] K;
    long[][][][] dp;

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int a = in.readInt();
        int b = in.readInt();
        int k = in.readInt();

        out.println("Case #" + testNumber + ": " + solveDP(a, b, k));
    }

    private long solveDP(int a, int b, int k) {
        A = new int[32];
        B = new int[32];
        K = new int[32];
        dp = new long[32][4][4][4];
        for (int i = 0; a > 0; ++i, a /= 2) A[i] = a % 2;
        for (int i = 0; b > 0; ++i, b /= 2) B[i] = b % 2;
        for (int i = 0; k > 0; ++i, k /= 2) K[i] = k % 2;

        for (long[][][] x: dp) for (long[][] y: x) for (long[] z: y) Arrays.fill(z, -1);

        return rec(31, 2, 2, 2);
    }

    private long rec(int i, int sa, int sb, int sk) {
        if (i == 0) return sa <= 1 && sb <= 1 && sk <= 1 ? 1 : 0;
        if (dp[i][sa][sb][sk] != -1) return dp[i][sa][sb][sk];
        long res = 0;
        for (int ba = 0; ba <= 1; ++ba) {
            if (sa <= 1 || ba <= A[i - 1]) {
                int nsa = 2 * (sa > 1 && ba == A[i - 1] ? 1 : 0) + ba;
                for (int bb = 0; bb <= 1; ++bb) {
                    if (sb <= 1 || bb <= B[i - 1]) {
                        int nsb = 2 * (sb > 1 && bb == B[i - 1] ? 1 : 0) + bb;
                        int bk = (ba & bb);
                        if (sk <= 1 || bk <= K[i - 1]) {
                            int nsk = 2 * (sk > 1 && bk == K[i - 1] ? 1 : 0) + bk;
                            res += rec(i - 1, nsa, nsb, nsk);
                        }
                    }
                }
            }
        }
        return dp[i][sa][sb][sk] = res;
    }

}

class InputReader {
    private InputStream stream;
    private byte[] buffer = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    private int read() {
        if (numChars == -1)
            throw new InputMismatchException();
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buffer);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0)
                return -1;
        }
        return buffer[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isWhiteSpace(c))
            c = read();
        int sign = 1;
        if (c == '-') {
            sign = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isWhiteSpace(c));
        return res * sign;
    }

    public String readString() {
        int c = read();
        while (isWhiteSpace(c))
            c = read();
        StringBuilder res = new StringBuilder();
        do {
            res.appendCodePoint(c);
            c = read();
        } while (!isWhiteSpace(c));
        return res.toString();
    }

    public String next() {
        return readString();
    }

    private boolean isWhiteSpace(int c) {
        return c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == -1;
    }
}

