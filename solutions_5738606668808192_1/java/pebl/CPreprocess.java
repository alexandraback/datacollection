package codejam.f2016;

import java.math.BigInteger;
import java.util.Scanner;

public class CPreprocess {

	static BigInteger two = BigInteger.valueOf(2);

	private static boolean calc(BigInteger cur) {
		String rep2 = cur.toString(2);

		StringBuilder sb = new StringBuilder();

		outer:
		for(int i=2; i<=10; i++) {
			BigInteger test = new BigInteger(rep2,i);
			BigInteger prime = two;
			
			if (test.mod(prime).equals(BigInteger.ZERO)) {
				sb.append(" ").append(prime);
				continue outer;
			}
			prime = prime.add(BigInteger.ONE);
			
			for(int j=0; j<2<<16 && prime.compareTo(test) < 0; j++) {
				if (test.mod(prime).equals(BigInteger.ZERO)) {
					sb.append(" ").append(prime);
					continue outer;
				}
				prime = prime.add(two);
			}
			return false;
		}

		System.out.println(rep2+sb);
		
		return true;
	}
	
	public static void doWork(int N, int J) {
		BigInteger min = two.pow(N-1);
		min = min.add(BigInteger.ONE);

		System.out.println("Case #1:");
		
		BigInteger cur = min;
		int found = 0;
		while(found < J) {
			boolean ok = calc(cur);
			if (ok)
				found++;
			cur = cur.add(two);
		}
	}
	
	
	public static void main(String[] args) {
		if (false) {
			//doWork(2,1);
			//doWork(16,50);
			doWork(32,500);
		} else {
			Scanner scanner = new Scanner(System.in);
			int cases = scanner.nextInt();
			int N = scanner.nextInt();
			int J = scanner.nextInt();
			
			doWork(N,J);
		}
	}
}
