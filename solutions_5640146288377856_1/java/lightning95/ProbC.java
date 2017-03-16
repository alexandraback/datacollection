import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/18/15.
 */

public class ProbC {
    RW rw;

    class RW {
        private boolean eof;
        StringTokenizer st;
        PrintWriter out;
        BufferedReader br;

        RW(String inputFile, String outputFile) {
            br = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(new OutputStreamWriter(System.out));

            File f = new File(inputFile);
            if (f.exists() && f.canRead()) {
                try {
                    br = new BufferedReader(new FileReader(inputFile));
                    out = new PrintWriter(new FileWriter(outputFile));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    eof = true;
                    return "-1";
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        void println() {
            out.println();
        }

        void println(Object o) {
            out.println(o);
        }

        void print(Object o) {
            out.print(o);
        }

        void close() {
            try {
                br.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            out.close();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new ProbC().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    private void solve() {
        int t_num = rw.nextInt();

        for (int t_id = 0; t_id < t_num; ++t_id) {
            int r = rw.nextInt();
            int c = rw.nextInt();
            int v = rw.nextInt();

            long ans = (r - 1) * (c / v);

            d = new long[c + 1];
            Arrays.fill(d, -1);
            if (c == v) {
                ans += v;
            } else {
                ans += rec(c, v);
            }

            rw.println("Case #" + (t_id + 1) + ": " + ans);
        }
    }

    long[] d;

    private long rec(int c, int v) {

        if (d[c] > -1) {
            return d[c];
        }
        if (c < v) {
            return d[c] = 0;
        }
        if (c == v) {
            return d[c] = v;
        }

        long ans = Long.MAX_VALUE;
        for (int i = 0; i < c; ++i) {
            long cur = rec(i, v) + rec(c - i - 1, v) + 1;
            if (c - i - 1 >= v) {
                ans = Math.min(ans, cur);
            } else {
                ans = Math.min(ans, i - 1 + v + 1);
            }
        }
        return d[c] = ans;
    }


}

