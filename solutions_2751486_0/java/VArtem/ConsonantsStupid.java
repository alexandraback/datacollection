import java.io.*;
import java.util.*;

public class ConsonantsStupid {

	FastScanner in;
	PrintWriter out;

	String vowels = "aeiou";
	
	boolean isCons(char c) {
		return vowels.indexOf(c) == -1;
	}
	
	void solve() {
		String s = in.next();
		int[] c = new int[s.length()];
		int n = in.nextInt();
		long ans = 0;
		
		int countN = 0;
		for (int i = 0; i < s.length(); i++) {
			for (int j = i; j < s.length(); j++) {
				int last = 0;
				for (int k = i; k <= j; k++) {
					if (isCons(s.charAt(k))) {
						last++;
					} else {
						last = 0;
					}
					if (last == n) {
						ans++;
						break;
					}
				}
			}
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter("output.txt");

			int tests = in.nextInt();
			for (int i = 0; i < tests; i++) {
				out.printf("Case #%d: ", (i + 1));
				solve();
			}

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String next() {
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
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new ConsonantsStupid().run();
	}
}
