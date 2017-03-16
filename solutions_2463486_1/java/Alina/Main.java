import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) throws Exception {
		FileScanner in = new FileScanner("input.txt");
		PrintWriter out = new PrintWriter("output.txt");
		ArrayList<Long> sAndf = new ArrayList<Long>();
		for (long i = 1; i <= 11000000; i++) {
			if (isPalindrom(i) && isPalindrom(i * i)) {
				sAndf.add(i);
			}
		}
		int n = in.nextInt();
		for (int k = 1; k <= n; k++) {
			out.print("Case #" + k + ": ");
			long a = in.nextLong();
			long b = in.nextLong();
			long x = sAndf.get(0);
			int i = 0;
			while (x * x < a){
				i++;
				x = sAndf.get(i);
			}
			int res = 0;
			while (x * x <= b) {
				res++;
				i++;
				x = sAndf.get(i);
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
