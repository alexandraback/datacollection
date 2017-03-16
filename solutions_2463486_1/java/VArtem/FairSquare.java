import java.io.*;
import java.util.*;

public class FairSquare {

	FastScanner in;
	PrintWriter out;
	
	List<Long> ans;
	
	void init() {
		ans=  new ArrayList<Long>();
		for (int i = 0; i <= 10_000_000; i++) {
			String s = Integer.toString(i);
			if (!isPali(s)) {
				continue;
			}
			
			long a = (long) i * (long) i;
			if (isPali(Long.toString(a))) {
				ans.add(a);
			}
		}
	}

	void solve() {
		long l = in.nextLong();
		long r = in.nextLong();
		int res = 0;
		for (long s : ans) {
			if (l <= s && s <= r) {
				res++;
			}
		}
		out.println(res);
	}

	private boolean isPali(String s) {
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) != s.charAt(s.length() - i - 1)) {
				return false;
			}
		}
		return true;
	}

	void run() throws FileNotFoundException {
		in = new FastScanner("input.txt");
		out = new PrintWriter("output.txt");
		
		init();
		int tests = in.nextInt();
		for (int i = 0; i < tests; i++) {
			out.printf("Case #%d: ", i + 1);
			solve();
		}
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String name) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(new File(name)));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		new FairSquare().run();
	}
}
