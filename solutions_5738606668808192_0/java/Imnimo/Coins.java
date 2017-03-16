import java.math.BigInteger;
import java.util.Arrays;


public class Coins {
	public static void main(String[] args) {
		int[] proofs = new int[11];
		int count = 0;
		int n = 50;
		int length = 16;
		System.out.println("Case #1:");
		OUTER: for(int i = 0;i<(1<<(length-2)) && count<n;i++) {
			String bits = String.format("%0" + (length-2) + "d",Long.parseLong(Integer.toBinaryString(i)));
			String coin = "1" + bits + "1";
			
			for(int base = 2;base<=10;base++) {
				long val = Long.parseLong(coin,base);
				if(BigInteger.valueOf(val).isProbablePrime(10)) {
					continue OUTER;
				}
				int proof = trialDivide(val);
				if(proof == -1) continue OUTER;
				proofs[base] = proof;
			}
			System.out.print(coin);
			for(int base = 2;base<=10;base++) {
				System.out.print(" " + proofs[base]);
			}
			System.out.println();
			count++;
		}
	}
	public static int trialDivide(long n) {
		if(n%2==0) return 2;
		for(int divisor = 3;divisor<=Math.sqrt(n);divisor++) {
			if(n%divisor==0) return divisor;
		}
		return -1;
	}
}
