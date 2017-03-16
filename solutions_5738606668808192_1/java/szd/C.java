import java.io.*;
import java.util.*;

public class C {

	private static final int primes[] = {
		2,3,5,7,11,13,17,19
	};
	
	private static long getDivisor0(long n) {
		int max = (int)Math.sqrt(n);
		for(int d = 2; d <= max; d++)
			if(n % d == 0)
				return d;
		return 0;
	}
	
	private static long getDivisor(long n) {
		int max = (int)Math.sqrt(n);
		for(int d = 0; d < primes.length; d++)
			if(n % primes[d] == 0)
				return primes[d];
		return 0;
	}
	
	public static void main(String args[]) throws Exception {
		String fn = args.length > 0 ?  args[0] :
		//	"c1.in";
		//	"C-small-attempt0.in";
			"C-large.in";
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
			int p1 = 1;
			int p2 = 2;
			int p3 = 3;
			int p4 = 4;
			char ch[] = new char[N];
			Arrays.fill(ch, '0');
			ch[0] = ch[N - 1] = '1';
			for(int j = 0; j < J; j++) {
				ch[p1] = '1';
				ch[p2] = '1';
				ch[p3] = '1';
				ch[p4] = '1';
				String jamcoin = new String(ch);
				ch[p1] = '0';
				ch[p2] = '0';
				ch[p3] = '0';
				ch[p4] = '0';
				/*for(int base = 2; base <= 10; base++) {
					long nb = Long.parseLong(jamcoin, base);
					if((div[base] = getDivisor(nb)) == 0)
						System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!");
				}
				out.print(jamcoin);
				for(int base = 2; base <= 10; base++) {
					out.print(' ');
					out.print(div[base]);
				}
				out.println();*/
				out.print(jamcoin);
				out.print(" 3 2 3 2 7 2 3 2 3");
				out.println();
				out.flush();
				if((p1 += 2) == p3) {
					p1 = 1;
					if((p3 += 2) >= N - 1) {
						p3 = 3;
						if((p2 += 2) == p4) {
							p2 = 2;
							if((p4 += 2) >= N)
								System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!");
						}
					}
				}
			}
			out.flush();
		}
		out.close();
	}
}
