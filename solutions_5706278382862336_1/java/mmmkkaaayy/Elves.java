package codejams;

import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.HashMap;

public class Elves {
	
	HashMap<Long,Integer> powers;
	long[] exp;
	
	public Elves() {
		powers = new HashMap<Long,Integer>();
		exp = new long[42];
		long p = 1;
		for (int i = 0;i < 42;i++) {
			powers.put(p,i);
			exp[i] = p;
			p = p * 2;
		}
	}
	
	public void testCase(BufferedReader br, PrintWriter pw) {
		try {
			String[] fraction = br.readLine().split("/");
			long num = Long.parseLong(fraction[0]);
			long den = Long.parseLong(fraction[1]);
			
			long gcd = gcd(num,den);
			
			num = num/gcd;
			den = den/gcd;
			
			if (powers.containsKey(den)) {
				// den = 8, num = 5
				// p = 3
				
				// 5 = 4 + 1 = 1/2, 2 = 8/4
				// st = 4 = 2^(log_2(5))
				// lvls = 2 = den/st
				// bitch = 1/2 means 1 parent
				// bitch = 1/4 means 2 parents away
				// bitch = 1/8 means 3 parents away
				// ie log_2(den)
				
				// 5 = 3 + 2 = 2 + 2 + 1, therefore 2 is largest, and it takes 1 split to make 2
				
				// so 5/8 is 2 away
				
				long st = exp[(int) (Math.log(num)/Math.log(2))];
				long lvls = den/st;
				int out = (int) (Math.log(lvls)/Math.log(2));
				if (Main.debug) System.out.println(num+" "+den+" "+(int) (Math.log(num)/Math.log(2)));
											
			
				pw.print(out);
			}
			//if (powers.containsKey(den)) pw.print(powers.get(den));
			
			else pw.print("impossible");
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private long gcd(long a,long b) {
		while (b != 0) {
			long t = b;
			b = a % b;
			a = t;
		}
		return a;
	}	
}