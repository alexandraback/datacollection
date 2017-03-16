import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.StringTokenizer;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class B_CloseMatch {

	static InputStreamReader isr = new InputStreamReader(System.in, StandardCharsets.US_ASCII);
	static BufferedReader br = new BufferedReader(isr, 20 << 20);

	public static void main(String[] args) throws Exception {
		final ExecutorService es = Executors.newFixedThreadPool(5);

		Result[] res = parseInputAndCreateSolvers(es);

		printResults(es, res);
	}

	private static Result[] parseInputAndCreateSolvers(ExecutorService es) throws Exception {

		int T = Integer.parseInt(br.readLine());
		Result[] res = new Result[T];
		for (int i = 0; i < res.length; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String C = st.nextToken();
			String J = st.nextToken();
			res[i] = new Result();
			es.submit(new Solver(res[i], C, J));
		}

		return res;
	}

	private static void printResults(ExecutorService es, Result[] res) {
		es.shutdown();
		while (!es.isTerminated()) {
			try {
				Thread.sleep(1000);
			} catch (InterruptedException ie) {
				ie.printStackTrace();
			}
		}
		final StringBuilder sb = new StringBuilder();
		for (int ii = 0; ii < res.length; ii++) {
			sb.append("Case #").append(ii + 1).append(": ").append(res[ii]).append('\n');
		}
		System.out.print(sb);
	}

	static class Solver extends ResultHolder {

		String C, J;
		
		Solver(Result res, String C, String J) {
			super(res);
			this.C = C;
			this.J = J;
		}

		@Override
		public void run() {
			int min = -1;
			
			int len = C.length();
//			int from = findFrom(len);
			int to = findTo(len);
			for (int i = 0; i <= to; i++) {
				String mc = matches(len, C, i);
				if (mc != null) {
					for (int j = 0; j <= to; j++) {
						String mj = matches(len, J, j);
						if (mj != null) {
							int abs = Math.abs( i - j);
							if (min == -1) {
								min = abs;
								res.f = mc;
								res.t = mj;
							} else if (abs < min) {
								res.f = mc;
								res.t = mj;
								min = abs;
							}
						}
					}
				}
			}
		}

		private String matches(int len, String s, int v) {
			String is = Integer.toString(v);
			
			while (is.length() < len) {
				is = "0"+is;
			}
			
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == '?') {
					continue;
				}
				else if (s.charAt(i) != is.charAt(i)) {
					return null;
				}
			}
			return is;
		}

		private int findFrom(int len) {
			int res = 1;
			for (int i = 2; i <= len; i++) {
				res *= 10;
			}
			return res;
		}

		private int findTo(int len) {
			return findFrom(len + 1) - 1;
		}
	}

	static class ResultHolder extends Thread {
		Result res;

		public ResultHolder(Result res) {
			this.res = res;
		}

	}

	static class Result {

		String  f;
		String  t;
		
		@Override
		public String toString() {
			return f + " " + t;
		}
	}

}
