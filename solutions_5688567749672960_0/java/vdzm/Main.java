import java.util.Locale;
import java.util.concurrent.ExecutionException;
import java.io.PrintStream;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.concurrent.Executors;
import java.io.PrintWriter;
import java.io.File;
import java.io.FilenameFilter;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.concurrent.Callable;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.util.concurrent.Future;
import java.util.concurrent.ExecutorService;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
}

class TaskA {
    private static final int EXPECTED_TEST_NUMBER = 100;

    private static class TestSolver implements Callable<TestSolver> {
        private final int testNumber;
        private String output;
        private int target;

        private static final int MAX = 2_000_000;
        private static final int[] dp = new int[MAX + 1];
        static {
            for (int i = 1; i < dp.length; ++i) {
                dp[i] = i + 1;
            }
            dp[1] = 1;
            List<Integer> queue = new ArrayList<>(dp.length);
            int head = 0;
            queue.add(1);
            while (head < queue.size()) {
                int current = queue.get(head++);
                for (int next = current + 1, it = 0; it < 2; ++it, next = reverse(current)) {
                    if (next <= MAX) {
                        int dist = dp[current] + 1;
                        if (dist < dp[next]) {
                            dp[next] = dist;
                            queue.add(next);
                        }
                    }
                }
            }
        }

        private static int reverse(int number) {
            int result = 0;
            while (number > 0) {
                result = result * 10 + (number % 10);
                number /= 10;
            }
            return result;
        }

        private void solve() {
            output = Integer.toString(dp[target]);
        }

        public void readInput(final InputReader in) {
            target = in.nextInt();
        }

        public void printOutput(final PrintWriter out) {
            out.println("Case #" + testNumber + ": " + output);
        }

        public TestSolver call() {
            System.err.println("In process testcase #" + testNumber);
            solve();
            System.err.println("Done testcase #" + testNumber);
            return this;
        }

        public TestSolver(final int testNumber) {
            this.testNumber = testNumber;
        }
    }

    public void solve(final int foo, final InputReader in, final PrintWriter out) {
        final int tests = in.nextInt();
        Executor executor = new Executor(in, out);
        for (int test = 1; test <= tests; ++test) {
            TestSolver solver = new TestSolver(test);
            executor.submit(solver);
        }
        executor.shutdown();
    }

    private static class Executor {
        public static final int THREADS_NUMBER = 4;

        private final long START_TIME = System.currentTimeMillis();

        private final InputReader in;
        private final PrintWriter out;

        private final ExecutorService pool = Executors.newFixedThreadPool(THREADS_NUMBER);
        private final List<Future<TestSolver>> tasks;

        public Executor(final InputReader in, final PrintWriter out) {
            this.in = in;
            this.out = out;
            this.tasks = new ArrayList<>(EXPECTED_TEST_NUMBER);
        }

        public void submit(final TestSolver solver) {
            solver.readInput(in);
            tasks.add(pool.submit(solver));
        }

        public void shutdown() {
            pool.shutdown();
            System.err.println("Began writing outputs");
            for (Future<TestSolver> solution : tasks) {
                try {
                    TestSolver solver = solution.get();
                    solver.printOutput(out);
                } catch (InterruptedException | ExecutionException e) {
                    throw new RuntimeException(e);
                }
            }
            System.err.println("Done in " + (System.currentTimeMillis() - START_TIME) + ".ms");
        }
    }
}

class InputReader {
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

