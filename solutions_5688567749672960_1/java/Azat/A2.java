import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class A2 {

	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;
	static long INF = (long) 1e18;
	
	public static void main(String[] args) throws IOException{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int tests = nextInt();
		for (int test = 1; test <= tests; test++) {
			pw.print("Case #"+test+": ");
			long n = nextLong();
			long ans = 0;
			while (n >= 10) {
				long rev = rev(n);
				if (rev==INF) {
					ans++;
					n--;
				}
				else {
					String s = n+"";
					long min = INF;
					for (int i = 1; i < s.length(); i++) {
						String q1 = s.substring(i);
						String q2 = new StringBuffer(s.substring(0, i)).reverse().toString();
						long cur = Long.parseLong(q1)+Long.parseLong(q2);
						if (cur < min) {
							min = cur;
						}
					}
					String res = "1";
					for (int i = 1; i < s.length(); i++) {
						res += "0";
					}
					ans += Math.min(min, n-Long.parseLong(res));
					n = Long.parseLong(res);
				}
			}
			ans += n;
			pw.println(ans);
		}
		pw.close();
	}

	private static long rev(long n) {
		long res = 0;
		if (n % 10==0)
			return INF;
		while (n > 0) {
			res = res * 10 + n % 10;
			n /= 10;
		}
		return res;
	}

	private static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	private static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
	private static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	private static String next() throws IOException{
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

}
