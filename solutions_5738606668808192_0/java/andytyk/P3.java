import java.io.*;
import java.util.*;
import java.math.*;

public class P3 {
	
	static boolean [] sieve;
	static int [] primes;
	static int [] store;
	
	public static String compute(String s) throws Exception {
		StringBuffer sb = new StringBuffer();
		int [] divs = new int[10];
		for(int cr = 2; cr <= 10; cr++) {
			BigInteger b = new BigInteger(s,cr);
			for(int cp = 0; cp < primes.length; cp++) {
				BigInteger cpv = BigInteger.valueOf(primes[cp]);
				BigInteger mv = b.mod(cpv);
				if(b.compareTo(cpv) <= 0)
					break;
//				System.out.println(b.toString() + " " + primes[cp] + " " + mv.toString());
				if(mv.equals(BigInteger.ZERO)) {
					divs[cr-2] = primes[cp];
					break;
				}
			}
			if(divs[cr-2] == 0)
				return "BAD";
		}
		sb.append(s);
		for(int i = 0; i < 9; i++)
			sb.append(" "+divs[i]);
		return sb.toString();
	}
	
	public static void precomp() throws Exception {
		int cprimes = 0;
		sieve = new boolean[10000000];
		Arrays.fill(sieve,true);
		sieve[0] = sieve[1] = false;
		for(int i = 2; i < sieve.length; i++) {
			if(!sieve[i])
				continue;
			for(int j = 2*i; j < sieve.length; j+= i)
				sieve[j] = false;
			cprimes++;
		}
		primes = new int[cprimes];
		cprimes = 0;
		for(int i = 2; i < sieve.length; i++)
			if(sieve[i]) {
				primes[cprimes++] = i;
			}
		for(int clen = 2; clen <= 32; clen++) {
			if(store[clen] == 0)
				continue;
			int mv = 1 << (clen-2);
			for(int cv = 0; cv < mv; cv++) {
				String bs = Integer.toString(cv, 2);
				while(bs.length() < (clen - 2))
					bs = "0"+bs;
				String res = compute("1"+bs+"1");
				if(!res.equals("BAD")) {
					System.out.println(res);
					store[clen]--;
				}
				if(store[clen] == 0)
					break;
			}
		}
	}
	
	public static void main(String [] args) throws Exception {
		store = new int[33];
		store[6] = 3;
		store[16] = 50;
		store[32] = 500;
		precomp();
		BufferedReader in = new BufferedReader(new FileReader("/Users/andykong/Downloads/gcj2016/p3/p3.sample.in"));
		PrintWriter out = new PrintWriter(new FileWriter("/Users/andykong/Downloads/gcj2016/p3/p3.sample.out"));
		int T = Integer.parseInt(in.readLine());
		for(int cc = 1; cc <= T; cc++) {
			String [] sp = in.readLine().split(" ");
			int N = Integer.parseInt(sp[0]);
			int J = Integer.parseInt(sp[1]);
			out.printf("Case #%d:\n",cc);
		}
		in.close();
		out.close();
	}
}
