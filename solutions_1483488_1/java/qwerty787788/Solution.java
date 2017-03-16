import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int doFromStr(String s, int k) {
		int ans = 0;
		for (int i = k; i < s.length(); i++) {
			ans = ans * 10 + s.charAt(i) - '0';
		}
		for (int i = 0; i < k; i++) {
			ans = ans * 10 + s.charAt(i) - '0';
		}
		return ans;
	}
	
	public void solve() throws IOException {
		int cases = in.nextInt();
		for (int nowCase = 1; nowCase <= cases; nowCase++) {
			int a = in.nextInt();
			int b = in.nextInt();
			long ans = 0;
			for (int x = a; x < b; x++) {
				ArrayList <Integer> add = new ArrayList<Integer>();
				String s = (new Integer(x)).toString();
				for (int k = 1; k < s.length(); k++) {
					int newVal = doFromStr(s, k);
					boolean newV = true;
					if (newVal > x && newVal <= b) {
						for (int i = 0; i < add.size(); i++) {
							if (add.get(i) == newVal) newV = false;
						}
						if (newV) add.add(newVal);
					}
				}
				ans += add.size();
			}
			//
			out.print("Case #");
			out.print(nowCase);
			out.print(": ");
			//
			out.print(ans);
			//
			out.println();
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("c.in"));
			out = new PrintWriter(new File("c.out"));

			//in = new FastScanner(System.in);
			//out = new PrintWriter(System.out);

			solve();

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
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
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
		
		String readLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return " ";
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}