import java.io.*;
import java.util.ArrayList;
import java.util.InputMismatchException;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Artem Gilmudinov
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream;
        try {
            inputStream = new FileInputStream("B-large.in");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("output.txt");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        static final int MAX = 61;
        boolean[][] adj;
        boolean[][] cache;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.readInt();
            for (int t = 1; t <= T; t++) {
                int b = in.readInt();
                adj = new boolean[b][b];
                cache = new boolean[b][b];
                long m = in.readLong();
                int[][] dp = new int[b][MAX];
                dp[0][0] = 1;
                PairInt[][][] edges = new PairInt[b][MAX][];
                for (int i = 1; i < b - 1; i++) {
                    for (int j = 0; j < MAX; j++) {
                        PairInt[] e = find(dp, i, (1l << j));
                        if (e != null) {
                            dp[i][j] = 1;
                            edges[i][j] = e;
                        }
                    }
                }
                PairInt[] ans = find(dp, b - 1, m);

                if (ans == null) {
                    out.println(String.format("Case #%d: %s ", t, "IMPOSSIBLE"));
                } else {
                    rec(ans, b - 1, edges);
                    out.println(String.format("Case #%d: %s ", t, "POSSIBLE"));
                    for (boolean[] a : adj) {
                        for (boolean v : a) {
                            out.print(v ? 1 : 0);
                        }
                        out.println();
                    }
                }

            }
        }

        public void rec(PairInt[] u, int curV, PairInt[][][] edges) {
            if (u == null) {
                return;
            }
            for (PairInt e : u) {
                adj[e.x][curV] = true;
                if (!cache[e.x][e.y]) {
                    cache[e.x][e.y] = true;
                    rec(edges[e.x][e.y], e.x, edges);
                }
            }
        }

        public PairInt[] find(int[][] dp, int u, long val) {
            ArrayList<PairInt> ans = new ArrayList<>();
            for (int v = u - 1; v >= 0; v--) {
                for (int j = MAX - 1; j >= 0; j--) {
                    if (dp[v][j] != 0 && (val >= (1l << j))) {
                        val -= (1l << j);
                        ans.add(new PairInt(v, j));
                        if (val == 0) {
                            return ans.toArray(new PairInt[ans.size()]);
                        }
                        break;
                    }
                }
            }
            return null;
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private SpaceCharFilter filter;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1)
                throw new InputMismatchException();
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0)
                    return -1;
            }
            return buf[curChar++];
        }

        public int readInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public long readLong() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            long res = 0;
            do {
                if (c < '0' || c > '9')
                    throw new InputMismatchException();
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public boolean isSpaceChar(int c) {
            if (filter != null)
                return filter.isSpaceChar(c);
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class PairInt {
        public int x;
        public int y;

        public PairInt(int x, int y) {
            this.x = x;
            this.y = y;
        }


        public boolean equals(Object obj) {
            PairInt pairInt = (PairInt) obj;
            return pairInt.x == x && pairInt.y == y;
        }

        public String toString() {
            return x + " " + y;
        }

        public PairInt clone() {
            return new PairInt(x, y);
        }

    }
}

