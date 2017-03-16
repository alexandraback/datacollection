import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

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
}

class TaskC {
    private static final int EXPECTED_TEST_NUMBER = 100;

    private static class TestSolver implements Callable<TestSolver> {
        private final int testNumber;
        private String output;

        private int length;
        private long repeat;
        private char[] sequence;

        private static final String YES = "YES";
        private static final String NO = "NO";

        private void solve() {
            int product = 1;
            for (int i = 0; i < length; ++i) {
                sequence[i] -= 'i' - 2;
                assert 1 <= sequence[i] && sequence[i] <= 4 : sequence[i];
                product = multiply(product, sequence[i]);
            }
            if (repeat % 2 == 0) {
                char[] tmp = new char[length * 2];
                for (int i = 0; i < tmp.length; ++i) {
                    tmp[i] = sequence[i % length];
                }
                product = multiply(product, product);
                length *= 2;
                repeat /= 2;
                sequence = tmp;
            }
            if (product != -1 || repeat % 2 == 0) {
                output = NO;
                return;
            }
            long firstI = -1;
            long lastK = -1;
            for (int it = 0, offset = 0, prefixProduct = 1; it < Math.min(2, repeat); ++it, offset += length) {
                for (int i = 0; i < length; ++i) {
                    prefixProduct = multiply(prefixProduct, sequence[i]);
                    if (prefixProduct == 2 && firstI == -1) {
                        firstI = i + offset;
                    }
                }
            }
            for (int it = 0, offset = 0, prefixProduct = 1; it < Math.min(2, repeat); ++it, offset += length) {
                for (int i = length - 1; i >= 0; --i) {
                    prefixProduct = multiply(prefixProduct, sequence[i]);
                    if (prefixProduct == 4 && lastK == -1) {
                        lastK = length * repeat - i - offset;
                    }
                }
            }
            if (firstI == -1 || lastK == -1) {
                output = NO;
                return;
            }
            if (firstI > lastK) {
                output = NO;
                return;
            }
            output = YES;
        }

        private static final int[][] MULTIPLICATION_TABLE = new int[][]{
                {0, 0,  0,  0,  0},
                {0, 1,  2,  3,  4},
                {0, 2, -1,  4, -3},
                {0, 3, -4, -1,  2},
                {0, 4,  3, -2, -1}
        };

        private int multiply(int left, int right) {
            int result = signum(left) * signum(right);
            result *= MULTIPLICATION_TABLE[Math.abs(left)][Math.abs(right)];
            assert 1 <= Math.abs(result) && Math.abs(result) <= 4 : result;
            return result;
        }

        private int signum(int number) {
            return number < 0 ? -1 : number > 0 ? 1 : 0;
        }

        public void readInput(final InputReader in) {
            length = in.nextInt();
            repeat = in.nextLong();
            sequence = in.next().toCharArray();
            assert length == sequence.length;
        }

        public void printOutput(final PrintWriter out) {
            out.println("Case #" + testNumber + ": " + output);
        }

        public TestSolver call() {
            System.err.println("In process testcase #" + testNumber);
            solve();
            System.err.println("Done testcase #" + testNumber + ": " + output);
            return this;
        }

        public TestSolver(final int testNumber) {
            this.testNumber = testNumber;
        }
    }

    public void solve(final int foo, final InputReader in, final PrintWriter out) {
        int tests = in.nextInt();
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

    public long nextLong() {
        return Long.parseLong(next());
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

