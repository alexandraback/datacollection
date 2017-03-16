import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        Scanner in;
        PrintWriter out;

        public void solve(int testNumber, Scanner in, PrintWriter out) {
            this.in = in;
            this.out = out;
            run();
        }

        void run() {
            int t = in.nextInt();
            for (int i = 1; i <= t; i++) {
                out.printf("Case #%d: ", i);
                solve();
            }
        }

        private void solve() {
            int n = in.nextInt();
            int m = 2500;
            int[] cnt = new int[m + 1];
            for (int i = 0; i < 2 * n - 1; i++) {
                for (int j = 0; j < n; j++) {
                    cnt[in.nextInt()]++;
                }
            }
            boolean f = true;
            int c = 0;
            for (int i = 0; i <= m; i++) {
                if (cnt[i] % 2 == 1) {
                    if (f) f = false;
                    else out.print(" ");
                    out.print(i);
                    c++;
                }
            }
            if (c != n) Algo.debug("!!!!!!!!!!!!");
            out.println();
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

