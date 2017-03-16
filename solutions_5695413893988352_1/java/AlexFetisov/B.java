import java.io.*;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class B implements Runnable {

    private static boolean stressMode = false;
    private static PrintWriter out;

    final String file = "B";

    static class InputData {

        char[] c1;
        char[] c2;
        int len;

        InputData(FastReader in) throws IOException {
            c1 = in.next().toCharArray();
            c2 = in.next().toCharArray();
            len = c1.length;
            best1 = -1;
        }

        boolean match(String s, char[] c) {
            while (s.length() < len) s = "0" + s;
            for (int i = 0; i < len; ++i) {
                char cc = s.charAt(i);
                if (c[i] == '?' || c[i] == cc) continue;
                return false;
            }
            return true;
        }

        void solve(PrintWriter out) {
            rec(0);

            String s = String.valueOf(best1);
            while (s.length() < len) s = "0" + s;
            out.print(s);
            out.print(" ");
            s = String.valueOf(best2);
            while (s.length() < len) s = "0" + s;
            out.println(s);
        }

        long best1, best2, bestDiff;

        long get(char[] c) {
            String s = new String(c);
            return Long.parseLong(s);
        }

        void check() {
            long x = get(c1);
            long y = get(c2);
            long d = Math.abs(x - y);
            if (best1 == -1) {
                best1 = x;
                best2 = y;
                bestDiff = d;
                return;
            }
            if (bestDiff > d) {
                best1 = x;
                best2 = y;
                bestDiff = d;
                return;
            }
            if (bestDiff < d) return;
            if (best1 > x) {
                best1 = x;
                best2 = y;
                return;
            }
            if (best1 < x) return;
            if (best2 > y) {
                best1 = x;
                best2 = y;
            }
        }

        void fill(int o1) {
            for (int i = 0; i < len; ++i) {
                if (o1 == 0) {
                    if (c1[i] == '?') c1[i] = '0';
                    if (c2[i] == '?') c2[i] = '9';
                } else {
                    if (c1[i] == '?') c1[i] = '9';
                    if (c2[i] == '?') c2[i] = '0';
                }
            }
        }

        void rec(int pos) {
            if (pos == len) {
                check();
                return;
            }
            if (c1[pos] != '?' && c2[pos] != '?') {
                if (c1[pos] == c2[pos]) {
                    rec(pos + 1);
                    return;
                }
                char[] cc1 = c1.clone();
                char[] cc2 = c2.clone();
                if (c1[pos] < c2[pos]) {
                    fill(1);
                } else {
                    fill(0);
                }
                check();
                c1 = cc1;
                c2 = cc2;
                return;
            }

            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    if (c1[pos] == '?' || (c1[pos] - '0' == i)) {
                        if (c2[pos] == '?' || c2[pos] - '0' == j) {
                            if (i == j) {
                                if (c1[pos] == '?' && c2[pos] == '?') {
                                    if (i != 0) continue;
                                }
                                c1[pos] = (char) (i + '0');
                                c2[pos] = (char) (j + '0');
                                rec(pos + 1);
                                c1[pos] = '?';
                                c2[pos] = '?';
                            } else {
                                char[] cc1 = c1.clone();
                                char[] cc2 = c2.clone();
                                c1[pos] = (char) (i + '0');
                                c2[pos] = (char) (j + '0');
                                if (i < j) {
                                    fill(1);
                                } else {
                                    fill(0);
                                }
                                check();
                                c1 = cc1;
                                c2 = cc2;
                            }
                        }
                    }
                }
            }
        }
    }

    static class Solver implements Callable<String> {

        InputData data;

        Solver(InputData data) {
            this.data = data;
        }

        @Override
        public String call() throws Exception {
            StringWriter out = new StringWriter();
            data.solve(new PrintWriter(out));
            return out.toString();
        }

    }

    public void run() {
        try {
            FastReader in = new FastReader(new BufferedReader(new FileReader(file + ".in")));
            out = new PrintWriter(file + ".out");
            // Stress
            if (stressMode) {
                while (true) {
                    new Solver(new InputData(in)).call();
                }
            } else {
                ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(16);

                int tests = in.nextInt();
                Future<String>[] ts = new Future[tests];
                for (int test = 0; test < tests; ++test) {
                    ts[test] = service.submit(new Solver(new InputData(in)));
                }
                for (int test = 0; test < tests; ++test) {
                    while (!ts[test].isDone()) {
                        Thread.sleep(500);
                    }
                    System.err.println("Test " + test);
                    out.print("Case #" + (test + 1) + ": ");
                    out.print(ts[test].get());
                }
                service.shutdown();
            }
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static class FastReader {
        public FastReader(BufferedReader in) {
            this.in = in;
            eat("");
        }

        private StringTokenizer st;
        private BufferedReader in;

        void eat(String s) {
            st = new StringTokenizer(s);
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) {
                String line = in.readLine();
                if (line == null) {
                    return null;
                }
                eat(line);
            }
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public String nextString() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                st = new StringTokenizer(next());
            }
            return st.nextToken();
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        new B().run();
    }

}
