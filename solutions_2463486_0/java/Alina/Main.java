import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) throws Exception {
		FileScanner in = new FileScanner("input.txt");
		PrintWriter out = new PrintWriter("output.txt");
		int n = in.nextInt();
		for (int k = 1; k <= n; k++) {
			out.print("Case #" + k + ": ");
			int a = in.nextInt();
			int b = in.nextInt();
			long x = Math.round(Math.sqrt(a));
			if (x * x < a) {
				x++;
			}
			int res = 0;
			while (x * x <= b) {
				if (isPalindrom(x) && isPalindrom(x * x)) {
					res++;
				}
				x++;
			}
			out.println(res);
		}
		out.close();
	}
	
	public static boolean isPalindrom(long x) {
		String s = "" + x;
		for (int i = 0; i < s.length() / 2; i++) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
	public static class FileScanner {
		BufferedReader br;
		StringTokenizer st;

		public FileScanner(String File) throws Exception {
			br = new BufferedReader(new FileReader(File));
		}

		public String getLine() throws IOException {
			return br.readLine();
		}

		String next() throws Exception {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		}

		public int nextInt() throws Exception {
			return Integer.parseInt(next());
		}

		public long nextLong() throws Exception {
			return Long.parseLong(next());
		}

		public double nextDouble() throws Exception {
			return Double.parseDouble(next());
		}
	}
}
