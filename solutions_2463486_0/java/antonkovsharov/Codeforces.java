import java.util.*;
import java.io.*;

public class Codeforces {
	FastScanner in;
	PrintWriter out;

	final long maxNumber = 1_000_000_000_000_00L;
	
	ArrayList<Long> goodNumbers = new ArrayList<Long>();
	
	boolean isPalindrome(long x) {
		String s = Long.toString(x);
		int i = 0, j = s.length() - 1;
		while (i < j) {
			if (s.charAt(i) != s.charAt(j)) {
				return false;
			}
			i++;
			j--;
		}
		return true;
	}
	
	public void precalc() {
		for (long x = 1; x * x <= maxNumber; x++) {
			if (isPalindrome(x) && isPalindrome(x * x)) {
				goodNumbers.add(x * x);
			}
		}
	}
	
	public void solve() throws IOException {
		long a = in.nextLong(), b = in.nextLong();
		int ans = 0;
		for (long x : goodNumbers) {
			if (x >= a && x <= b) {
				ans++;
			}
		}
		out.println(ans);
	}

	public void run() {
		try {
			precalc();
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));
			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.print("Case #" + (i + 1) + ": ");
				solve();
			}

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		boolean hasNext() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) {
						return false;
					}
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return true;
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] arg) {
		new Codeforces().run();
	}
}