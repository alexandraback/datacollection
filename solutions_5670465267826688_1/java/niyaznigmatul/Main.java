import java.util.InputMismatchException;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;
import java.io.Reader;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.File;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		InputStream inputStream;
		try {
			final String regex = "C-(small|large).*[.]in";
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
			outputStream = new FileOutputStream("c.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskC {

    static final int[][] T = {
            {0, 1, 2, 3},
            {1, 4, 3, 6},
            {2, 7, 4, 1},
            {3, 2, 5, 4},
    };

    static int multiply(int a, int b) {
        int sign = (a ^ b) >> 2;
        a &= ~4;
        b &= ~4;
        int ret = T[a][b];
        if (sign == 1) {
            ret ^= 4;
        }
        return ret;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        System.err.println(testNumber);
        int[][][] ms = new int[3][][];
        for (int i = 0; i < 3; i++) {
            int[][] a = new int[32][32];
            for (int have = 0; have < 4; have++) {
                for (int val = 0; val < 8; val++) {
                    int newVal = multiply(val, i + 1);
                    if (have < 3 && newVal == have + 1) {
                        a[have * 8 + val][(have + 1) * 8] = 1;
                    }
                    a[have * 8 + val][have * 8 + newVal] = 1;
                }
            }
            ms[i] = a;
        }
        in.nextInt();
        long repeat = in.nextLong();
        char[] c = in.next().toCharArray();
        int[][] m = new int[32][32];
        for (int i = 0; i < 32; i++) m[i][i] = 1;
        for (char e : c) {
            m = multiply(m, ms[e - 'i']);
        }
        m = pow(m, repeat);
        boolean answer = m[0][3 * 8] == 1;
        out.println("Case #" + testNumber + ": " + (answer ? "YES" : "NO"));
    }

    static int[][] pow(int[][] a, long b) {
        int[][] ret = new int[32][32];
        for (int i = 0; i < 32; i++) {
            ret[i][i] = 1;
        }
        while (b > 0) {
            if ((b & 1) == 1) {
                ret = multiply(ret, a);
            }
            a = multiply(a, a);
            b >>= 1;
        }
        return ret;
    }

    static int[][] multiply(int[][] a, int[][] b) {
        int[][] c = new int[32][32];
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                for (int k = 0; k < 32; k++) {
                    c[i][j] |= a[i][k] & b[k][j];
                }
            }
        }
        return c;
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

    public long nextLong() {
        return Long.parseLong(next());
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


}

