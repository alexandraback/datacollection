import java.io.*;
import java.util.StringTokenizer;

/**
 * @author Aydar Gizatullin a.k.a. lightning95, aydar.gizatullin@gmail.com
 *         Created on 4/16/16.
 */

public class ProbB {
    private RW rw;

    public static void main(String[] args) {
        new ProbB().run();
    }

    private void run() {
        rw = new RW("input.txt", "output.txt");
        solve();
        rw.close();
    }

    private class RW {
        private StringTokenizer st;
        private PrintWriter out;
        private BufferedReader br;
        private boolean eof;

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

        private String nextLine() {
            String s = "";
            try {
                s = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return s;
        }

        private String next() {
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

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private void println() {
            out.println();
        }

        private void println(Object o) {
            out.println(o);
        }

        private void print(Object o) {
            out.print(o);
        }

        private void close() {
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

    private void solve() {
        int testNum = rw.nextInt();
        for (int testId = 1; testId <= testNum; ++testId) {
            rw.print("Case #" + testId + ": ");
            System.err.println(testId);
            int n = rw.nextInt();
            long num = rw.nextLong();
            int[][] a = new int[n][n];
            int[] bits = new int[51];
            long x = 1L << 62;
            int id = 62;
            if ((1L << (n - 2)) < num) {
                rw.println("IMPOSSIBLE");
                continue;
            }
            long p = num;
            while (p > 0) {
                if (p >= x) {
                    bits[id] = 1;
                    p -= x;
                }
                x >>= 1;
                --id;
            }
            long[] d = new long[n];
            d[0] = 1;

            for (int i = 0; i < n - 1; ++i) {
                for (int j = i + 1; j < n - 1; ++j) {
                    a[i][j] = 1;
                    d[j] += d[i];
                }
            }
            for (int i = n - 2; i >= 0; --i) {
                if (d[n - 1] + d[i] <= num) {
                    d[n - 1] += d[i];
                    a[i][n - 1] = 1;
                }
            }
            rw.println("POSSIBLE");
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    rw.print(a[i][j]);
                }
                rw.println();
            }
        }
    }
}

