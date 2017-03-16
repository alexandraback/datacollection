import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class ProblemC {

	static final String YES = "YES";
	static final String NO = "NO";
	
	static long[] f = new long[10000010];
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		prec();
		
		int T = in.nextInt();
		for (int cn = 1 ; cn <= T ; cn++) {
			long A = in.nextLong();
			long B = in.nextLong();
			out.println(String.format("Case #%d: %d", cn, solve(A, B)));
			debug(B-A);
		}
		out.flush();
	}
	
	private static void prec() {
		for (int a = 1 ; a <= 10000005 ; a++) {
			String x = String.valueOf(a);
			boolean okay = false;
			if (x.equals(new StringBuffer(x).reverse().toString())) {
				long a2 = 1L * a * a;
				String x2 = String.valueOf(a2);
				if (x2.equals(new StringBuffer(x2).reverse().toString())) {
					okay = true;
				}
			}
			f[a] += f[a-1] + (okay ? 1 : 0);
		}
	}

	private static long solve(long A, long B) {
		int aq = (int)Math.sqrt(A);
		int bq = (int)Math.sqrt(B);
		if (1L * aq * aq < A) {
			aq++;
		}
		return f[bq] - f[aq-1];
	}


	public static void debug(Object... o) {
		System.err.println(Arrays.deepToString(o));
	}
}
