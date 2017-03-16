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
import java.util.Arrays;
import java.util.concurrent.Callable;
import java.util.HashMap;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.concurrent.Executors;
import java.util.ArrayList;
import java.util.concurrent.ExecutionException;
import java.util.List;
import java.util.concurrent.Future;
import java.util.StringTokenizer;
import java.util.Map;
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
            final String regex = "C-(small|large).*[.]in";
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
            outputStream = new FileOutputStream("c.out");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        private static final int THREADS_QTY = 1;

        public void solve(int useless, InputReader in, PrintWriter out) {
            final long startTime = System.nanoTime();
            ExecutorService pool = Executors.newFixedThreadPool(THREADS_QTY);
            int tests = in.nextInt();
            List<Future<TaskC.CaseSolver>> futures = new ArrayList<>(tests);
            for (int testCase = 1; testCase <= tests; ++testCase) {
                TaskC.CaseSolver solver = new TaskC.CaseSolver(testCase);
                solver.readInput(in);
                futures.add(pool.submit(solver));
            }
            pool.shutdown();
            for (Future<TaskC.CaseSolver> future : futures) {
                TaskC.CaseSolver solver;
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

        private static class CaseSolver implements Callable<TaskC.CaseSolver> {
            List<Integer>[] graph;
            private int counter;
            private int lsize;
            private int rsize;
            int[] matching;
            boolean[] visited;
            private final int testNumber;
            private String output;

            void solve() {
                matching = new int[rsize];
                Arrays.fill(matching, -1);
                visited = new boolean[lsize];
                int matchingSize = 0;
                for (int i = 0; i < lsize; ++i) {
                    if (dfs(i)) {
                        ++matchingSize;
                        Arrays.fill(visited, false);
                    }
                }
                output = "" + (counter - (lsize + rsize - matchingSize));
            }

            private boolean dfs(int v) {
                if (visited[v]) return false;
                visited[v] = true;
                for (int to : graph[v]) {
                    if (matching[to] == -1) {
                        matching[to] = v;
                        return true;
                    }
                }
                for (int to : graph[v]) {
                    if (matching[to] == -1 || dfs(matching[to])) {
                        matching[to] = v;
                        return true;
                    }
                }
                return false;
            }

            void readInput(InputReader in) {
                counter = in.nextInt();
                graph = new List[counter];
                Map<String, Integer> left = new HashMap<>();
                lsize = 0;
                Map<String, Integer> right = new HashMap<>();
                rsize = 0;
                for (int i = 0; i < counter; ++i) {
                    String l = in.next();
                    String r = in.next();
                    Integer ll = left.get(l);
                    if (ll == null) left.put(l, (ll = lsize++));
                    Integer rr = right.get(r);
                    if (rr == null) right.put(r, (rr = rsize++));
                    if (graph[ll] == null) graph[ll] = new ArrayList<>();
                    graph[ll].add(rr);
                }

            }

            void printOutput(PrintWriter out) {
                out.println("Case #" + testNumber + ": " + output);
            }


            public TaskC.CaseSolver call() {
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

