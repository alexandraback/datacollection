import java.util.Map;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.HashMap;
import java.io.PrintStream;
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
			inputStream = new FileInputStream("treasure.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("treasure.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		Treasure solver = new Treasure();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class Treasure {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        out.print("Case #" + testNumber + ":");
        System.err.println("[" + testNumber + "]");
        int k = in.nextInt();
        int n = in.nextInt();
        int[] haveStart = new int[k];
        for (int i = 0; i < k; i++) {
            haveStart[i] = in.nextInt();
        }
        int[] open = new int[n];
        int[][] takeStart = new int[n][];
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            open[i] = in.nextInt();
            if (!map.containsKey(open[i])) {
                map.put(open[i], map.size());
            }
            open[i] = map.get(open[i]);
            takeStart[i] = new int[in.nextInt()];
            for (int j = 0; j < takeStart[i].length; j++) {
                takeStart[i][j] = in.nextInt();
            }
        }
        int[][] have = new int[map.size()][1 << n];
        for (int i : haveStart) {
            if (map.containsKey(i)) {
                have[map.get(i)][0]++;
            }
        }
        int[][] take = new int[n][map.size()];
        for (int i = 0; i < n; i++) {
            for (int j : takeStart[i]) {
                if (map.containsKey(j)) {
                    take[i][map.get(j)]++;
                }
            }
        }
        for (int i = 1; i < 1 << n; i++) {
            int j = Integer.numberOfTrailingZeros(i);
            int mask = i & ~(1 << j);
            for (int d = 0; d < map.size(); d++) {
                have[d][i] = have[d][mask] + take[j][d];
            }
            have[open[j]][i]--;
        }
        boolean[] dp = new boolean[1 << n];
        dp[(1 << n) - 1] = true;
        for (int i = (1 << n) - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1 || !dp[i | (1 << j)] || have[open[j]][i] < 1) continue;
                dp[i] = true;
                break;
            }
        }
        if (!dp[0]) {
            out.println(" IMPOSSIBLE");
            return;
        }
        all: for (int i = 0; i < (1 << n) - 1; ) {
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    continue;
                }
                if (have[open[j]][i] > 0 && dp[i | (1 << j)]) {
                    out.print(" " + (j + 1));
                    i |= (1 << j);
                    continue all;
                }
            }
            throw new AssertionError();
        }
        out.println();
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
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

