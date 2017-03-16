package GCJ;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Qualification2016C {
	private static BigInteger change(long x, BigInteger b) {
		BigInteger ret = BigInteger.ZERO;
		BigInteger bas = BigInteger.ONE;
		
		while(x > 0) {
			if((x & 1) > 0) {
				ret = ret.add(bas);
			}
			bas = bas.multiply(b);
			x >>= 1;
		}
		
		return ret;
	}
	
	private static void output(PrintWriter out, long x) {
		ArrayList<Long> ret = new ArrayList<Long>();
		while(x > 0) {
			ret.add(x & 1);
			x >>= 1;
		}
		for(int i=ret.size()-1; i>=0; --i) {
			out.print(ret.get(i));
		}
	}
	
	private static BigInteger[] v = new BigInteger[10];
	
	private static void gao(Scanner in, PrintWriter out) {
		int n = in.nextInt();
		int m = in.nextInt();
		
		int tot = 0;
		for(long i = (long)1 << (n - 1); i < (long)1 << n; ++ i) {
			if((i & 1) > 0) {
				boolean yes = true;
				for(int j=2; j<=10; ++j) {
					BigInteger x = change(i, new BigInteger("" + j));
					BigInteger tmp = new BigInteger("300000");
					tmp = tmp.multiply(tmp);
					if(x.compareTo(tmp) < 0) {
						tmp = x;
					}
					if(x.isProbablePrime(3)) {
						yes = false;
						break;
					}
					BigInteger cur = null;
					for(BigInteger k = new BigInteger("2");
							k.multiply(k).compareTo(tmp) <= 0; 
								k = k.add(BigInteger.ONE)) {
						if(x.mod(k).compareTo(BigInteger.ZERO) == 0) {
							v[j-2] = cur = k;
							break;
						}
					}
					if(cur == null) {
						yes = false;
						break;
					}
				}
				if(yes) {
					output(out, i);
					for(int j=0; j<9; ++j) out.print(" " + v[j]);
					out.println();
					++ tot;
					if(tot == m) break;
				}
			}
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new FileInputStream("C-large.in"));
		PrintWriter out = new PrintWriter(new FileOutputStream("C-large.out"));
		
		int T = in.nextInt();
		int cas = 0;
		while(T-- > 0) {
			out.println("Case #" + (++cas) + ":");
			gao(in, out);
		}
		
		in.close();
		out.close();
	}

}
