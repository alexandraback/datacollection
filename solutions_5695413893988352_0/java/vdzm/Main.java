import java.io.OutputStream;
import java.io.FilenameFilter;
import java.util.Locale;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.FileInputStream;
import java.io.File;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.PrintStream;
import java.util.concurrent.Callable;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.concurrent.Executors;
import java.util.ArrayList;
import java.util.concurrent.ExecutionException;
import java.util.List;
import java.util.concurrent.Future;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.concurrent.ExecutorService;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Vadim Semenov
 */
public class Main {
    public static void main(String[] args) {
        Locale.setDefault(Locale.US);
        InputStream inputStream;
        try {
            final String regex = "B-(small|large).*[.]in";
            File directory = new File(".");
            File[] candidates = directory.listFiles(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.matches(regex);
                }
            });
            File toRun = null;
            for (File candidate : candidates) {
                if (toRun == null || candidate.lastModified() > toRun.lastModified())
                    toRun = candidate;
            }
            inputStream = new FileInputStream(toRun);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        OutputStream outputStream;
        try {
            outputStream = new FileOutputStream("b.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        private static final int THREADS_QTY = 4;

        public void solve(int useless, InputReader in, PrintWriter out) {
            final long startTime = System.nanoTime();
            ExecutorService pool = Executors.newFixedThreadPool(THREADS_QTY);
            int tests = in.nextInt();
            List<Future<TaskB.CaseSolver>> futures = new ArrayList<>(tests);
            for (int testCase = 1; testCase <= tests; ++testCase) {
                TaskB.CaseSolver solver = new TaskB.CaseSolver(testCase);
                solver.readInput(in);
                futures.add(pool.submit(solver));
            }
            pool.shutdown();
            for (Future<TaskB.CaseSolver> future : futures) {
                TaskB.CaseSolver solver;
                try {
                    solver = future.get();
                } catch (InterruptedException | ExecutionException e) {
                    e.printStackTrace();
                    continue;
                }
                solver.printOutput(out);
            }
            final long finishTime = System.nanoTime();
            System.err.println("Complete in " + (finishTime - startTime) / 1_000_000_000. + "s");
        }

        private static class CaseSolver implements Callable<TaskB.CaseSolver> {
            private String first;
            private String second;
            private final int testNumber;
            private String output;

            void solve() {
                if (first.length() != second.length()) throw new AssertionError(first + " " + second);
                int x = -1;
                int y = -1;
                int upTo = 1;
                for (int i = 0; i < first.length(); ++i) {
                    upTo *= 10;
                }
                for (int i = 0; i < upTo; ++i) {
                    for (int j = 0; j < upTo; j++) {
                        if (match(first, i) && match(second, j)) {
                            if (x == -1 || better(i, j, x, y)) {
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
                output = String.format("%" + first.length() + "d", x).replace(' ', '0') + " " +
                        String.format("%" + first.length() + "d", y).replace(' ', '0');
            }

            private boolean better(int i, int j, int x, int y) {
                if (Math.abs(i - j) < Math.abs(x - y)) return true;
                if (Math.abs(i - j) > Math.abs(x - y)) return false;
                if (i + j < x + y) return true;
                if (i + j > x + y) return false;
                if (j < y) return true;
                if (j > y) return false;
                throw new AssertionError(i + " " + j + " " + x + " " + y);
            }

            private static boolean match(String string, int number) {
                for (int i = 0; i < string.length(); ++i) {
                    char ch = string.charAt(string.length() - 1 - i);
                    int digit = number % 10;
                    number /= 10;
                    if (ch == '?') {
                        continue;
                    }
                    if (ch - '0' != digit) return false;
                }
                return true;
            }

            void readInput(InputReader in) {
                first = in.next();
                second = in.next();
            }

            void printOutput(PrintWriter out) {
                out.println("Case #" + testNumber + ": " + output);
            }


            public TaskB.CaseSolver call() {
                System.err.println("In process testcase #" + testNumber);
                solve();
                System.err.println("Done testcase #" + testNumber + " (" + output + ")");
                return this;
            }

            CaseSolver(final int testNumber) {
                this.testNumber = testNumber;
            }

        }

    }

    static class InputReader {
        private final BufferedReader reader;
        private StringTokenizer tokenizer;

        public InputReader(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                tokenizer = new StringTokenizer(readLine());
            }
            return tokenizer.nextToken();
        }

        public String readLine() {
            String line;
            try {
                line = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            return line;
        }

    }
}

