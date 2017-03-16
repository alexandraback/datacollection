import java.io.*;
import java.util.Locale;
import java.util.StringTokenizer;

import static java.lang.Math.abs;

public class Main {
    private final InputReader in;
    private final PrintWriter out;

    public Main(final InputReader in, final PrintWriter out) {
        this.in = in;
        this.out = out;
    }

    private static PrintWriter getOutput(final String filename) throws IOException {
        if (filename == null || filename.isEmpty()) {
            return new PrintWriter(new OutputStreamWriter(System.out));
        } else {
            return new PrintWriter(new FileWriter(filename + ".out"));
        }
    }

    public static void main(final String[] args) throws NumberFormatException, IOException {
        final String filename = "B-large";
        final long time = System.currentTimeMillis();
        try (final InputReader in = new InputReader(filename); final PrintWriter out = getOutput(filename)) {
            new Main(in, out).solve();
        }
//        System.err.println("Running time: " + (System.currentTimeMillis() - time));
    }

    public void solve() throws NumberFormatException, IOException {
        final int t = in.nextInt();
        for (int i = 1; i <= t; i++) {
            final char[] a = in.nextToken().toCharArray();
            final char[] b = in.nextToken().toCharArray();
            final int n = a.length;

            final long[] result = dfs(0, 0, a, b, 0);

            out.println(String.format(Locale.ROOT, "Case #%d: %0" + n + "d %0" + n + "d", i, result[0], result[1]));
        }
    }

    private long[] dfs(final long aResult, final long bResult, final char[] a, final char[] b, final int j) {
        final int comp = Long.compare(aResult, bResult);
        if (j == a.length) {
            return new long[]{aResult, bResult};
        }
        if (comp < 0) {
            final long newAResult = aResult * 10 + (a[j] == '?' ? 9 : a[j] - '0');
            final long newBResult = bResult * 10 + (b[j] == '?' ? 0 : b[j] - '0');
            return dfs(newAResult, newBResult, a, b, j + 1);
        } else if (comp > 0) {
            final long newAResult = aResult * 10 + (a[j] == '?' ? 0 : a[j] - '0');
            final long newBResult = bResult * 10 + (b[j] == '?' ? 9 : b[j] - '0');
            return dfs(newAResult, newBResult, a, b, j + 1);
        } else { // comp == 0;
            final int[][] t;
            if (a[j] == '?' && b[j] == '?') {
                t = new int[][]{{0, 0}, {0, 1}, {1, 0}};
            } else if (a[j] == '?') {
                t = new int[][]{{b[j] - '0' - 1, b[j] - '0'}, {b[j] - '0', b[j] - '0'}, {b[j] - '0' + 1, b[j] - '0'}};
            } else if (b[j] == '?') {
                t = new int[][]{{a[j] - '0', a[j] - '0' - 1}, {a[j] - '0', a[j] - '0'}, {a[j] - '0', a[j] - '0' + 1}};
            } else {
                t = new int[][]{{a[j] - '0', b[j] - '0'}};
            }

            long[] best = null;
            for (final int[] d : t) {
                if (d[0] < 0 || d[0] > 9 || d[1] < 0 || d[1] > 9) continue;
                final long newAResult = aResult * 10 + d[0];
                final long newBResult = bResult * 10 + d[1];
                final long[] result = dfs(newAResult, newBResult, a, b, j + 1);
                if (best == null || abs(result[0] - result[1]) < abs(best[0] - best[1])) {
                    best = result;
                }
            }

            if (best == null) throw new IllegalStateException();
            return best;
        }
    }

    private void assertTrue(final boolean t) {
        if (!t) throw new RuntimeException();
    }
}

class InputReader implements Closeable {
    private StringTokenizer st;
    private final BufferedReader in;

    public InputReader(final String filename) throws IOException {
        if (filename == null || filename.isEmpty())
            in = new BufferedReader(new InputStreamReader(System.in));
        else
            in = new BufferedReader(new FileReader(filename + ".in"));
    }

    public boolean hasNextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null)
                return false;
            st = new StringTokenizer(line);
        }
        return true;
    }

    public String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = in.readLine();
            if (line == null)
                return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public String readLine() throws IOException {
        return in.readLine();
    }

    public int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(nextToken());
    }

    public long nextLong() throws NumberFormatException, IOException {
        return Long.parseLong(nextToken());
    }

    public double nextDouble() throws NumberFormatException, IOException {
        return Double.parseDouble(nextToken());
    }

    @Override
    public void close() throws IOException {
        in.close();
    }
}