import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

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
            inputStream = new FileInputStream("B-small-attempt0.in");
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
        int[] dp;
        boolean[][] adj;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int T = in.readInt();
            A:
            for (int t = 1; t <= T; t++) {
                int b = in.readInt();
                int m = in.readInt();
                int left = b - 2;
                int[] a = new int[left];
                dp = new int[b];
                adj = new boolean[b][b];
                for (int i = 0; i < left; i++) {
                    a[i] = i;
                }
                List<PairInt> subEdges = new ArrayList<>();
                List<PairInt> edges = new ArrayList<>();
                ArrayList<Integer> vertex = new ArrayList<>();
                do {
                    vertex.clear();
                    edges.clear();
                    vertex.add(0);
                    for (int i = 0; i < b - 2; i++) {
                        vertex.add(1 + a[i]);
                    }
                    vertex.add(b - 1);
                    for (int i = 0; i < b; i++) {
                        for (int j = i + 1; j < b; j++) {
                            edges.add(new PairInt(vertex.get(i), vertex.get(j)));
                        }
                    }

                    int max = (1 << edges.size());
                    for (int i = 0; i < max; i++) {
                        subEdges.clear();
                        for (int j = 0; j < edges.size(); j++) {
                            if (isBit(i, j)) {
                                subEdges.add(edges.get(j));
                            }
                        }
                        if (check(subEdges, m, vertex)) {
                            out.println(String.format("Case #%d: %s ", t, "POSSIBLE"));
                            for (boolean[] arr : adj) {
                                Arrays.fill(arr, false);
                            }
                            for (PairInt edge : subEdges) {
                                adj[edge.x][edge.y] = true;
                            }
                            for (boolean[] arr : adj) {
                                for (boolean v : arr) {
                                    out.print(v ? 1 : 0);
                                }
                                out.println();
                            }
                            continue A;
                        }
                    }
                } while (Utils.nextPermutation(a));
                out.println(String.format("Case #%d: %s ", t, "IMPOSSIBLE"));
            }
        }

        public boolean isBit(int x, int pos) {
            return (x & (1 << pos)) != 0;
        }

        public boolean check(List<PairInt> edges, int m, ArrayList<Integer> topological) {
            Arrays.fill(dp, 0);
            dp[0] = 1;
            for (int v : topological) {
                for (PairInt edge : edges) {
                    if (edge.y == v) {
                        dp[v] += dp[edge.x];
                    }
                }
            }
            return dp[dp.length - 1] == m;
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

    static class Utils {
        public static boolean nextPermutation(int[] a) {
            int temp, mid, n;
            n = a.length;
            for (int i = n - 1; i > 0; i--) {
                if (a[i] > a[i - 1]) {
                    for (int j = n - 1; j >= i; j--) {
                        if (a[j] > a[i - 1]) {
                            temp = a[i - 1];
                            a[i - 1] = a[j];
                            a[j] = temp;
                            break;
                        }
                    }
                    mid = i + (n - i) / 2;
                    for (int j = i, z = 0; j < mid; z++, j++) {
                        temp = a[j];
                        a[j] = a[n - z - 1];
                        a[n - z - 1] = temp;
                    }
                    return true;
                }
            }
            return false;
        }

    }
}

