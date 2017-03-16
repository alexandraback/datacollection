import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author shu_mj @ http://shu-mj.com
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        Scanner in;
        PrintWriter out;
        private int ans;
        private int[] f;
        private boolean[] vis;
        private List<Integer>[] s;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
            run();
        }

        void run() {
            int t = in.nextInt();
            for (int i = 1; i <= t; i++) {
                out.printf("Case #%d: ", i);
                Algo.debug(i);
                solve();
            }
        }

        private void solve() {
            int n = in.nextInt();
            f = new int[n];
            for (int i = 0; i < n; i++) f[i] = in.nextInt() - 1;
            s = new List[n];
            for (int i = 0; i < n; i++) {
                s[i] = new ArrayList<>();
            }
            for (int i = 0; i < n; i++) {
                s[f[i]].add(i);
            }
            ans = 0;
            vis = new boolean[n];
            solve2(n, f, s);
            for (int i = 0; i < n; i++) {
                Arrays.fill(vis, false);
                if (!vis[i]) {
                    int x = i;
                    int c = 0;
                    while (!vis[x]) {
                        vis[x] = true;
                        c++;
                        x = f[x];
                    }
                    if (x == i) {
                        ans = Math.max(ans, c);
                    }
                }
            }
            out.println(ans);
        }

        private void solve2(int n, int[] f, List<Integer>[] s) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (f[i] > i && f[f[i]] == i) {
                    int t0 = 0, t1 = 0;
                    for (int son : s[i]) {
                        if (son != f[i]) t0 = Math.max(t0, dfsCnt(son));
                    }
                    for (int son : s[f[i]]) {
                        if (son != i) t1 = Math.max(t1, dfsCnt(son));
                    }
                    sum += t0 + t1 + 2;
                }
            }
            ans = Math.max(ans, sum);
        }

        private int dfsCnt(int v) {
            int r = 0;
            for (int son : s[v]) {
                r = Math.max(r, dfsCnt(son));
            }
            return r + 1;
        }

    }

    static class Scanner {
        BufferedReader br;
        StringTokenizer st;

        public Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
            eat("");
        }

        private void eat(String s) {
            st = new StringTokenizer(s);
        }

        public String nextLine() {
            try {
                return br.readLine();
            } catch (IOException e) {
                return null;
            }
        }

        public boolean hasNext() {
            while (!st.hasMoreTokens()) {
                String s = nextLine();
                if (s == null)
                    return false;
                eat(s);
            }
            return true;
        }

        public String next() {
            hasNext();
            return st.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }

    static class Algo {
        public static void debug(Object... os) {
            System.err.println(Arrays.deepToString(os));
        }

    }
}

