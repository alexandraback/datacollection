import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("diamonds.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("diamonds.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		Diamonds solver = new Diamonds();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class Diamonds {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int x = in.nextInt();
        int y = in.nextInt();
        out.println("Case #" + testNumber + ": " + solve(n, x, y));
    }

    static double solve(int n, int x, int y) {
        int i;
        for (i = 0; 2 * i + 1 <= n; i += 2) {
            n -= 2 * i + 1;
        }
        if (x + y < i && y - x < i) {
            return 1.;
        }
        if (x + y != i && y - x != i) {
            return 0.;
        }
        int z = Math.abs(Math.abs(x) - i) + 1;
        if (z == i + 1 || n < z) {
            return 0.;
        }
        double ans = 0;
        double[][] dp = getDP(i);
        for (int l = 0; l <= i; l++) {
            for (int r = 0; r <= i; r++) {
                if (l >= z && l + r == n) ans += dp[l][r];
            }
        }
        return ans;
    }


    static double[][] getDP(int n) {
        double[][] ret = new double[n + 1][n + 1];
        ret[0][0] = 1.;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                double cur = ret[i][j];
                if (cur == 0) continue;
                if (i + 1 <= n && j + 1 <= n) {
                    ret[i + 1][j] += cur * .5;
                    ret[i][j + 1] += cur * .5;
                } else if (i + 1 <= n) {
                    ret[i + 1][j] += cur;
                } else if (j + 1 <= n) {
                    ret[i][j + 1] += cur;
                }
            }
        }
        return ret;
    }

}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}

