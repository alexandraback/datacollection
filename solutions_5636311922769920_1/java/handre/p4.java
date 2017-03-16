import java.math.BigInteger;
import java.util.Scanner;

public class p4 {
	private static BigInteger getTileIndex(int choices[], int K){
		BigInteger pow = BigInteger.ONE;
		BigInteger retval = BigInteger.ZERO;
		for(int i = 0; i < choices.length; i++){
			retval = retval.add(pow.multiply(BigInteger.valueOf(choices[i])));
			pow = pow.multiply(BigInteger.valueOf(K));
		}
		return retval.add(BigInteger.ONE);
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int testCases = sc.nextInt();
		for (int c = 1; c <= testCases; c++){
			int K = sc.nextInt();
			int C = sc.nextInt();
			int S = sc.nextInt();
			
			System.out.print("Case #" + Integer.valueOf(c).toString() + ":");
			
			if (S*C < K) System.out.println(" IMPOSSIBLE");
			else {
				int coords[] = new int[C];
				int curr = 0;
				while (curr < K){
					for (int i = 0; i < C && curr < K; i++, curr++) coords[i] = curr;
					System.out.print(" " + getTileIndex(coords, K).toString());
				}
				System.out.println("");
			}
			
		}
		sc.close();
	}
}
