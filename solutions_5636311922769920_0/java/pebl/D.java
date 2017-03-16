package codejam.f2016;

import java.math.BigInteger;
import java.util.Scanner;

public class D {

	private static long calc(int startK, int k, int c) {
		long before = 0;
		
		BigInteger kB = BigInteger.valueOf(k);
		
		for(int d=0; d<c; d++) {
			// long res1 = ((long)Math.pow(k, c - d - 1)) * startK; 
			long res2 = kB.pow(c-d-1).multiply(BigInteger.valueOf(startK)).longValue();
			before += res2;
			startK = Math.min(startK+1, k-1);
		}
		
		return before+1;
	}

	private static void handleCase(int nr, Scanner scanner) {
		int k = scanner.nextInt();
		int c = scanner.nextInt();
		int s = scanner.nextInt();

		if ((k+c-1) / c > s ) {
			System.out.println("Case #"+nr+": "+"IMPOSSIBLE");
			return;
		}

		StringBuilder sb = new StringBuilder();
		sb.append("Case #").append(nr).append(":");
		
		int startK = 0;
		while(startK < k) {
			long ret = calc(startK,k,c);
			sb.append(" ").append(ret);
			startK += c;
		}
		
		System.out.println(sb);
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		
		for(int i=0;i<cases; i++)
			handleCase(i+1,scanner);
	}

}
