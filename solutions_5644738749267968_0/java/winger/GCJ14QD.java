import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ14QD implements Runnable {

	private PrintWriter out;

	final String file = "D-small-attempt0";
	Random rnd = new Random(42);

	static class InputData {
        int n;
        double[] a, b;

		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            a = new double[n];
            for (int i = 0; i < n; ++i) {
                a[i] = in.nextDouble();
            }
            b = new double[n];
            for (int i = 0; i < n; ++i) {
                b[i] = in.nextDouble();
            }
		}

		void solve(PrintWriter out) {
            Arrays.sort(a);
            Arrays.sort(b);
            out.println(f(b, a) + " " + (n - f(a, b)));
		}

        private int f(double[] a, double[] b) {
            int ret = 0;
            for (int i = 0, j = 0; i < n; ++i) {
                while (j < n && a[i] > b[j]) {
                    ++j;
                }
                if (j < n) {
                    ++j;
                    ++ret;
                }
            }
            return ret;
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
		new GCJ14QD().run();
	}

}