import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p1 {

	private static long[]p2s = new long[41];
	
	public static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a%b);
	}
	
	public static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}

	public static void main(String... args) throws Exception {
		prep();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		solve(br, pw);
		pw.flush();
	}

	private static void prep() {
		p2s[0] = 1;
		for (int i=1;i<p2s.length;i++) {
			p2s[i]=p2s[i-1]*2;
		}
	}

	private static void solve(BufferedReader br, PrintWriter pw) throws Exception {
		int cases = Integer.parseInt(br.readLine());
		for (int c = 1; c <= cases; c++) {
			pw.printf("Case #%d: %s\n", c, solveCase(br, pw));
		}
	}

	private static Object solveCase(BufferedReader br, PrintWriter pw) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine(),"/");
		long p = Long.parseLong(st.nextToken());
		long q = Long.parseLong(st.nextToken());
		long g = gcd(p, q);
		p/=g;
		q/=g;
		//debug(p,q,g);
		int ok = -1;
		for (int i=1;i<=40;i++) {
			if (p2s[i]==q && p <= p2s[i]) {
				ok = i;
				break;
			}
		}
		if (ok == -1) {
			return "impossible";
		}
		for (int i=0;i<=ok;i++) {
			if (p >= q) {
				return i;
			}
			q/=2;
		}
		return ok;
	}
}