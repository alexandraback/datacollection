import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Jens Staahl
 */

public class Pancake {

	// some local config
	// static boolean test = false ;
	private boolean test = System.getProperty("ONLINE_JUDGE") == null;
	static String testDataFile = "B-small-attempt2.in";
//	 static String testDataFile = "testdata.txt";
	private static String ENDL = "\n";
	// Just solves the acutal kattis-problem
	ZKattio io;
		
	int cnt = 0, max = 0;
	private void solve() throws Throwable {
		io = new ZKattio(stream);

		int n = io.getInt();
		for (int i = 0; i < n; i++) {
			solveIt(i+1);
			
		}
		out.flush();
	}


	private void solveIt(int casenr) {
		int n = io.getInt();
		int[] val = new int[n];
		for (int i = 0; i < n; i++) {
			val[i] = io.getInt();
		}

		int ans = Integer.MAX_VALUE;
		for (int i = 1; i <= 1000; i++) {
			int splitcost = 0;
			for (int j = 0; j < val.length; j++) {
				int num = val[j]/i - 1;
				if(val[j] % i != 0) {
					num ++;
				}
				splitcost += num;
			}
			ans =Math.min(ans, splitcost + i);
		}
//		PriorityQueue<Integer> queue = new PriorityQueue<>(1000, Collections.reverseOrder());
//		for (int i = 0; i < n; i++) {
//			queue.offer(io.getInt());
//		}
//
//		int ans = queue.peek();
//		int cnt = 0;
//		while(true) {
//			Integer poll = queue.poll();
//			queue.offer(poll/2);
//			if(poll%2 == 1) {
//				queue.offer((poll/2) + 1);
//			} else {
//				queue.offer(poll/2);
//			}
//			cnt ++;
//			ans = Math.min(ans, queue.peek() + cnt);
//			if(cnt > 2000 || poll == 1) {
//				break;
//			}
//		}

		print("Case #" + casenr + ": " + ans + "");
	}


	private void print(String string) {
		out.println(string);
		System.out.println(string);
	}


	public static void main(String[] args) throws Throwable {
		new Pancake().solve();
	}

	public Pancake() throws Throwable {
		if (test) {
			stream = new FileInputStream(testDataFile);
		}
	}

	InputStream stream = System.in;
//	PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));// outStream
	PrintWriter out = new PrintWriter(new File(this.getClass().getCanonicalName() + ".out")); //new OutputStreamWriter(System.out));// outStream

	public class ZKattio extends PrintWriter {
		public ZKattio(InputStream i) {
			super(new BufferedOutputStream(System.out));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public ZKattio(InputStream i, OutputStream o) {
			super(new BufferedOutputStream(o));
			r = new BufferedReader(new InputStreamReader(i));
		}

		public boolean hasMoreTokens() {
			return peekToken() != null;
		}

		public int getInt() {
			return Integer.parseInt(nextToken());
		}

		public double getDouble() {
			return Double.parseDouble(nextToken());
		}

		public long getLong() {
			return Long.parseLong(nextToken());
		}

		public String getWord() {
			return nextToken();
		}

		private BufferedReader r;
		private String line;
		private StringTokenizer st;
		private String token;

		private String peekToken() {
			if (token == null)
				try {
					while (st == null || !st.hasMoreTokens()) {
						line = r.readLine();
						if (line == null)
							return null;
						st = new StringTokenizer(line);
					}
					token = st.nextToken();
				} catch (IOException e) {
				}
			return token;
		}

		private String nextToken() {
			String ans = peekToken();
			token = null;
			return ans;
		}
	}
	// System.out;

}