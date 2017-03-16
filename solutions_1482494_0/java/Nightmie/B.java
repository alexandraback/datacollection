import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B implements Runnable {

	private void solve() throws IOException {
		int T = nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			int numLevel = nextInt();

			Challenge[] c = new Challenge[numLevel * 2];
			for (int i = 0; i < numLevel; i++) {
				int A = nextInt();
				int B = nextInt();
				c[i * 2] = new Challenge(1, A, i, B);
				c[i * 2 + 1] = new Challenge(2, B, i);
			}

			int[] numStar = new int[numLevel];
			Arrays.fill(numStar, 0);

			Arrays.sort(c);

			int totalStar = 0, numTry = 0;
			boolean pleaseCont = true;
			while (pleaseCont) {
				pleaseCont = false;
				for (int i = 0; i < c.length; i++) {
					if (numStar[c[i].whatLevel] < c[i].numStar
							&& totalStar >= c[i].requiredStar) {
						totalStar += (c[i].numStar - numStar[c[i].whatLevel]);
						numStar[c[i].whatLevel] = c[i].numStar;
						numTry++;
						pleaseCont = true;
						break;
					}
				}
			}

			writer.print("Case #" + testCase + ": ");
			if (totalStar < 2 * numLevel) {
				writer.println("Too Bad");
			} else {
				writer.println(numTry);
			}
		}
	}

	private class Challenge implements Comparable<Challenge> {

		public int numStar;
		public int requiredStar;
		public int level2;
		public int whatLevel;

		public Challenge(int numStar, int requiredStar, int whatLevel) {
			this.numStar = numStar;
			this.requiredStar = requiredStar;
			this.whatLevel = whatLevel;
			this.level2 = -requiredStar;
		}

		public Challenge(int numStar, int requiredStar, int whatLevel,
				int level2) {
			this.numStar = numStar;
			this.requiredStar = requiredStar;
			this.whatLevel = whatLevel;
			this.level2 = level2;
		}

		@Override
		public int compareTo(Challenge o) {
			if (numStar != o.numStar) {
				return (numStar > o.numStar ? -1 : 1);
			}
			if (level2 != o.level2) {
				return (level2 > o.level2 ? -1 : 1);
			}
			return 0;
		}
	}

	public static void main(String[] args) {
		new B().run();
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	public void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			tokenizer = null;
			writer = new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}