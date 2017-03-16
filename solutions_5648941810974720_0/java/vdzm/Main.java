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
            final String regex = "A-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("a.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        private static final int THREADS_QTY = 4;

        public void solve(int useless, InputReader in, PrintWriter out) {
            final long startTime = System.nanoTime();
            ExecutorService pool = Executors.newFixedThreadPool(THREADS_QTY);
            int tests = in.nextInt();
            List<Future<TaskA.CaseSolver>> futures = new ArrayList<>(tests);
            for (int testCase = 1; testCase <= tests; ++testCase) {
                TaskA.CaseSolver solver = new TaskA.CaseSolver(testCase);
                solver.readInput(in);
                futures.add(pool.submit(solver));
            }
            pool.shutdown();
            for (Future<TaskA.CaseSolver> future : futures) {
                TaskA.CaseSolver solver;
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

        private static class CaseSolver implements Callable<TaskA.CaseSolver> {
            String[] digits = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
            String input;
            private final int testNumber;
            private String output;

            void solve() {
                int[] cnt = new int[256];
                for (char ch : input.toCharArray()) {
                    cnt[ch]++;
                }
                int[] times = new int[10];
                times[0] += update(cnt, 0, 'Z');
                times[2] += update(cnt, 2, 'W');
                times[4] += update(cnt, 4, 'U');
                times[5] += update(cnt, 5, 'F');
                times[6] += update(cnt, 6, 'X');
                times[8] += update(cnt, 8, 'G');
                times[7] += update(cnt, 7, 'V');
                times[9] += update(cnt, 9, 'I');
                times[1] += update(cnt, 1, 'O');
                times[3] += update(cnt, 3, 'T');
                for (int i : cnt) if (i != 0) throw new AssertionError(i);
                StringBuilder result = new StringBuilder("");
                for (int i = 0; i < 10; ++i) {
                    for (int j = 0; j < times[i]; ++j) {
                        result.append(i);
                    }
                }
                output = result.toString();
            }

            private int update(int[] cnt, int n, char ch) {
                int count = cnt[ch];
                for (int cha : digits[n].toCharArray()) {
                    cnt[cha] -= count;
                    if (cnt[cha] < 0) throw new AssertionError(cnt[cha]);
                }
                return count;
            }

            void readInput(InputReader in) {
                input = in.next();
            }

            void printOutput(PrintWriter out) {
                out.println("Case #" + testNumber + ": " + output);
            }


            public TaskA.CaseSolver call() {
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

