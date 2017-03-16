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

        int n;
        String[][] s;

        InputData(FastReader in) throws IOException {
            n = in.nextInt();
            s = new String[n][2];
            for (int i = 0; i < n; ++i) {
                s[i][0] = in.next();
                s[i][1] = in.next();
            }
        }

        void solve(PrintWriter out) {
            int res = n;
            for (int mask = 0; mask < (1 << n); ++mask) {
                if (canBeReal(mask)) {
                    res = Math.min(res, Integer.bitCount(mask));
                }
            }
            out.println(n - res);
        }

        private boolean canBeReal(int mask) {
            while (mask != (1 << n) - 1) {
                int idx = -1;
                for (int i = 0; i < n; ++i) {
                    if ((mask & (1 << i)) == 0) {
                        if (canGet(mask, i)) {
                            mask |= (1 << i);
                            idx = i;
                            break;
                        }
                    }
                }
                if (idx == -1) return false;
            }
            return true;
        }

        private boolean canGet(int mask, int id) {
            int first = 0;
            int second = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask & (1 << i)) != 0) {
                    if (s[i][0].compareTo(s[id][0]) == 0) {
                        first |= (1 << i);
                    }
                    if (s[i][1].compareTo(s[id][1]) == 0) {
                        second |= (1 << i);
                    }
                }
            }
            if (first != 0 && second != 0) {
                return true;
            }
            return false;
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
