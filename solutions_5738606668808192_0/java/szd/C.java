import java.io.*;
import java.util.*;

public class C {

	private static long getDivisor(long n) {
		int max = (int)Math.sqrt(n);
		for(int d = 2; d <= max; d++)
			if(n % d == 0)
				return d;
		return 0;
	}
	
	public static void main(String args[]) throws Exception {
		String fn = args.length > 0 ?  args[0] :
		//	"c1.in";
			"C-small-attempt0.in";
		//	"C-large.in";
		LineNumberReader in = new LineNumberReader(new FileReader(fn));
		PrintWriter out = new PrintWriter(new FileWriter(fn.replace(".in", ".out")));
		int T = Integer.parseInt(in.readLine());
		long div[] = new long[11];
		for(int i = 0; i < T; i++) {
			out.print("Case #" + (i+1) + ":");
			out.println();
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int J = Integer.parseInt(st.nextToken());
			final int pad = (1 << (N - 1)) + 1;
		_n:
			for(int n = 1 << (N - 2); --n >= 0; ) {
				String jamcoin = Integer.toBinaryString((n << 1) + pad);
				for(int base = 2; base <= 10; base++) {
					long nb = Long.parseLong(jamcoin, base);
					if((div[base] = getDivisor(nb)) == 0)
						continue _n;
				}
				out.print(jamcoin);
				for(int base = 2; base <= 10; base++) {
					out.print(' ');
					out.print(div[base]);
				}
				out.println();
				out.flush();
				if(--J <= 0)
					break;
			}
			out.flush();
		}
		out.close();
	}
}
