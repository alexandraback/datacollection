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

        boolean[][] g;
        List<Integer> left;
        Map<String, Integer> wordToInt, wordToIntR;

        InputData(FastReader in) throws IOException {
            n = in.nextInt();

            g = new boolean[n][n];
            wordToInt = new HashMap<String, Integer>();
            wordToIntR = new HashMap<String, Integer>();
            for (int i = 0; i < n; ++i) {
                String s = in.next();
                int a, b;
                if (wordToInt.containsKey(s)) {
                    a = wordToInt.get(s);
                } else {
                    a = wordToInt.size();
                    wordToInt.put(s, a);
                }

                s = in.next();
                if (wordToIntR.containsKey(s)) {
                    b = wordToIntR.get(s);
                } else {
                    b = wordToIntR.size();
                    wordToIntR.put(s, b);
                }

                g[a][b] = true;
            }

        }

        int[] rr;
        boolean[] u;
        void solve(PrintWriter out) {
            rr = new int[n];
            u = new boolean[n];
            Arrays.fill(rr, -1);
            int count = 0;
            for (int i = 0; i < n; ++i) {
                Arrays.fill(u, false);
                if (dfs(i)) {
                    ++count;
                }
            }
            g2 = new int[n][n];
            for (int i = 0; i < n; ++i) {
                if (rr[i] != -1) {
                    g2[rr[i]][i] = 2;
                }

            }
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (g2[i][j] == 0 && g[i][j]) {
                        g2[i][j] = 1;
                    }
                }
            }

            int res = 0;
            while (true) {
                boolean found = false;

                loop: for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (g2[i][j] == 1) {
                            int d1 = 0, d2 = 0;
                            for (int k = 0; k < n; ++k) {
                                if (g2[i][k] != 0) {
                                    ++d1;
                                }
                                if (g2[k][j] != 0) {
                                    ++d2;
                                }
                            }
                            if (d1 > 1 && d2 > 1) {
                                g2[i][j] = 0;
                                found = true;
                                ++res;
                                break loop;
                            }

                        }
                    }
                }

                if (!found) break;
            }
            out.println(res);
        }

        int[][] g2;

        boolean dfs(int v) {
            if (u[v]) return false;
            u[v] = true;
            for (int i = 0; i < n; ++i) {
                if (g[v][i] && (rr[i] == -1 || dfs(rr[i]))) {
                    rr[i] = v;
                    return true;
                }
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
