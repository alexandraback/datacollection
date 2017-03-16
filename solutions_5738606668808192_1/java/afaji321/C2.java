import java.io.*;
import java.util.*;
import java.math.*;

public class C2 {
	public static long val[][] = new long[11][11];
	public static Set<String> res = new HashSet<String>();
	public static long D = 32;
	public static long limU = 1;
	public static long limB = 1;
	public static int sol[] = new int[99];
	
	public static long toBase(long count, int B) {
		String num = Long.toString(count, 2);
		return Long.parseLong(num, B);
	}
 	
	

	public static void main(String args[]) {
		System.out.println("Case #1:");
		Scanner in = new Scanner(System.in);
		D = in.nextInt();
		D = in.nextInt();
		D--;
		long Target = in.nextInt();
		int C = 0;

		for (int i=0;i<D;i++)
			limB = limB * 2;
			limU = limB * 2;

		for (long i=limB+1;i<=limU;i+=2){
			String st = Long.toString(i,2);
			boolean fail = false;

			for (int b=2;b<=10;b++){
				BigInteger test = new BigInteger(st,b);
				boolean found = false;

				for (int j=2;j<=1000;j++){
					BigInteger divisor = new BigInteger(j+"");
					
					BigInteger modulo = test.mod(divisor);
					if (modulo.compareTo(BigInteger.ZERO) == 0) {
						sol[b] = j;
						found = true;
						break;
					}
				}
				if (!found) {
				
					fail = true;
					break;
				}

			}
			if (fail)
				continue;

			System.out.print(st);
			for (int k=2;k<=10;k++)
				System.out.print(" "+sol[k]);
			System.out.println();
			
			C++;

			if (C == Target)
				return;
		}

	}

}
