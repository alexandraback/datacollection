
import java.io.*;
import java.util.*;

public class C {
    // private static final String FIN = "C-small-attempt0.in";
    // private static final String FOUT = "C-small-attempt0.out";
    private static final String FIN = "C-large.in";
    private static final String FOUT = "C-large.out";

    @SuppressWarnings("unchecked")
    public static void solution(BufferedReader reader, PrintWriter out)
            throws IOException {
        In in = new In(reader);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            N = in.nextInt();
            adj = new ArrayList[N + 1];
            for (int i = 1; i <= N; i++)
                adj[i] = new ArrayList<Integer>();
            BFF = new int[N + 1];
            for (int i = 1; i <= N; i++) {
                BFF[i] = in.nextInt();
                adj[BFF[i]].add(i);
            }
            out.printf("Case #%d: %d\n", t, solve());
        }
    }

    private static int N;
    private static int[] BFF;
    private static ArrayList<Integer>[] adj;
    private static boolean[] used;

    private static int solve() {
        used = new boolean[N + 1];
        int p = pair(), c = circle();
        return Math.max(p, c);
    }

    private static int pair() {
        int sum = 0;
        for (int i = 1; i <= N; i++)
            if (!used[i] && BFF[BFF[i]] == i) {
                used[i] = true;
                used[BFF[i]] = true;
                int left = dfs(i, 1);
                int right = dfs(BFF[i], 1);
                sum += left + right;
            }
        return sum;
    }

    private static int dfs(int v, int d) {
        int max = d;
        for (Integer u : adj[v])
            if (!used[u]) {
                used[u] = true;
                max = Math.max(max, dfs(u, d + 1));
            }
        return max;
    }

    private static int circle() {
        int max = 0;
        for (int i = 1; i <= N; i++)
            if (!used[i]) {
                used[i] = true;
                int res = dfs2(i, BFF[i], 1);
                max = Math.max(max, res);
                used[i] = false;
            }
        return max;
    }

    private static int dfs2(int r, int u, int d) {
        if (u == r)
            return d;
        if (used[u])
            return 0;
        used[u] = true;
        d++;
        int res = dfs2(r, BFF[u], d);
        used[u] = false;
        return res;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(FIN));
        PrintWriter out = new PrintWriter(
                new BufferedWriter(new FileWriter(FOUT)));
        solution(reader, out);
        out.close();
    }

    protected static class In {
        private BufferedReader reader;
        private StringTokenizer tokenizer = new StringTokenizer("");

        public In(BufferedReader reader) {
            this.reader = reader;
        }

        public String next() throws IOException {
            while (!tokenizer.hasMoreTokens())
                tokenizer = new StringTokenizer(reader.readLine());
            return tokenizer.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
    }
}