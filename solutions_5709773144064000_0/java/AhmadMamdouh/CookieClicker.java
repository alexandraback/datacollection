import java.io.*;
import java.util.*;

public class CookieClicker {
	static String problem = "B";
	static double c, f, x;

	public static void main(String[] args) throws Exception {
//		InputReader r = new InputReader(System.in);
//		PrintWriter out = new PrintWriter(System.out);
		InputReader r = new InputReader(new FileReader(problem + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(problem + "Solution.out"));
		int T = r.nextInt();
		int test = 1;
		while (T-- > 0) {
			c = r.nextDouble();
			f = r.nextDouble();
			x = r.nextDouble();
			double res = Double.MAX_VALUE;
			double gain = 2;
			double cookies = 0;
			double time = 0;
			for (int farms = 0; farms < 500007; farms++) {
				double timeToGoal = (x - cookies) / gain;
				timeToGoal = Math.max(0, timeToGoal);
				res = Math.min(res, time + timeToGoal);
				double timeToFarm = (c - cookies) / gain;
				timeToFarm = Math.max(0, timeToFarm);
				time += timeToFarm;
				cookies += timeToFarm * gain - c;
				gain += f;
			}
			out.printf("Case #%d: %.9f\n", test++, res);
		}
		out.close();
	}

	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;

		public InputReader(InputStream stream) {
			reader = new BufferedReader(new InputStreamReader(stream));
			tokenizer = null;
		}

		public InputReader(FileReader stream) {
			reader = new BufferedReader(stream);
			tokenizer = null;
		}

		public String nextLine() {
			try {
				return reader.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
		}

		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}
