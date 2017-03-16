import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ14QC implements Runnable {

	private PrintWriter out;

	final String file = "C-small-attempt0";
	Random rnd = new Random(42);

    static class InputData {

        int n, m, c;

		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            m = in.nextInt();
            c = in.nextInt();
		}

		void solve(PrintWriter out) {
            char[][] ans = new char[n][m];
            for (char[] ar : ans) {
                Arrays.fill(ar, '*');
            }
            if (c == n * m - 1) {
                ans[0][0] = 'c';
            } else {
                int[][][] d = new int[n][m + 1][n * m + 1];
                for (int[][] arr : d) {
                    for (int[] ar : arr) {
                        Arrays.fill(ar, -1);
                    }
                }
                for (int i = 1; i <= m; ++i) {
                    d[0][i][Math.min(m, i + 1)] = -2;
                }
                for (int i = 1; i < n; ++i) {
                    for (int j = 0; j <= m; ++j) {
                        for (int k = 0; k <= i * m; ++k) {
                            if (d[i - 1][j][k] != -1) {
                                for (int j1 = 0; j1 <= j; ++j1) {
                                    d[i][j1][k + Math.min(m, j == 0 ? 0 : j + 1)] = j;
                                }
                            }
                        }
                    }
                }
                int last = -1, lastc = n * m - c;
                for (int j = 0; j <= m; ++j) {
                    if (d[n - 1][j][lastc] != -1) {
                        last = j;
                    }
                }
                if (last == -1) {
                    out.println();
                    out.println("Impossible");
                    return;
                }
                for (int i = n - 1; i >= 0; --i) {
                    int p = d[i][last][lastc];
                    int h = Math.min(m, p == -2 ? last + 1 : p == 0 ? 0 : p + 1);
                    lastc -= h;
                    last = p;
                    for (int j = 0; j < h; ++j) {
                        ans[i][j] = '.';
                    }
                }
                if (lastc != 0) {
                    throw new AssertionError();
                }
                ans[0][0] = 'c';
            }
            out.println();
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    out.print(ans[i][j]);
                }
                out.println();
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

			ScheduledThreadPoolExecutor service = new ScheduledThreadPoolExecutor(7);

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

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

    static BigInteger bi(long value) {
        return BigInteger.valueOf(value);
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

		long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}

        BigInteger nextBigInteger() throws IOException {
            return new BigInteger(next());
        }
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new GCJ14QC().run();
	}

}