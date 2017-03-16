import java.io.*;
import java.util.Locale;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.concurrent.Callable;
import java.util.concurrent.Future;
import java.util.concurrent.ScheduledThreadPoolExecutor;

public class GCJ2015Q_C implements Runnable {

    final static int[][] T = {
        {0, 1, 2, 3, 4, 5, 6, 7}, // +1
        {1, 0, 3, 2, 5, 4, 7, 6}, // -1
        {2, 3, 1, 0, 6, 7, 5, 4}, // +i
        {3, 2, 0, 1, 7, 6, 4, 5}, // -i
        {4, 5, 7, 6, 1, 0, 2, 3}, // +j
        {5, 4, 6, 7, 0, 1, 3, 2}, // -j
        {6, 7, 4, 5, 3, 2, 1, 0}, // +k
        {7, 6, 5, 4, 2, 3, 0, 1}, // -k
    };

    static {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                for (int k = 0; k < 8; ++k) {
                    if (T[i][T[j][k]] != T[T[i][j]][k]) {
                        throw new AssertionError();
                    }
                }
            }
        }
    }

    static int pow(int x, long pow) {
        int r = 0;
        while (pow > 0) {
            if (pow % 2 == 1) {
                r = T[r][x];
            }
            pow /= 2;
            x = T[x][x];
        }
        return r;
    }

	private PrintWriter out;
	
	final String file = "C-small-attempt0";
	Random rnd = new Random(42);

	static class InputData {
        int n;
        long k;
        int[] s;
		
		InputData(FastReader in) throws IOException {
            n = in.nextInt();
            s = new int[n];
            k = in.nextLong();
            String str = in.next();
            for (int i = 0; i < n; ++i) {
                s[i] = "1ijk".indexOf(str.charAt(i)) * 2;
            }
		}
		
		void solve(PrintWriter out) {
            int total = 0;
            for (int i = 0; i < n; ++i) {
                total = T[total][s[i]];
            }
            total = pow(total, k);
            int cur = 0;
            long i = 0;
            while (i < n * Math.min(k, 16) + 1 && cur != 2) {
                cur = T[cur][s[((int) ((i++) % n))]];
            }
            while (i < n * Math.min(k, 16) + 1 && cur != 6) {
                cur = T[cur][s[((int) ((i++) % n))]];
            }
            out.println(i <= n * Math.min(k, 16) && total == 1 ? "YES" : "NO");
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
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new GCJ2015Q_C().run();
	}
	
}
