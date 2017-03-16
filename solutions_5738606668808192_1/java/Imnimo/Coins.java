import java.math.BigInteger;
import java.util.Arrays;


public class Coins {
	public static void main(String[] args) {
		int[] proofs = new int[11];
		int count = 0;
		int n = 500;
		int length = 32;
		System.out.println("Case #1:");
		OUTER: for(int i = 0;i<(1<<(length-2)) && count<n;i++) {
			
			String bits = Integer.toBinaryString(i);
			String paddedBits = String.format("%0" + (length-2-bits.length()) + "d",0)+bits;
			
			String coin = "1" + paddedBits + "1";
			if(coin.length()!=length) {
				System.out.println(coin + " " + coin.length());
				System.exit(1);
			}
			
			for(int base = 2;base<=10;base++) {
				BigInteger val = new BigInteger(coin,base);
				
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
	public static int trialDivide(BigInteger n) {
		if(n.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO)) {
			return 2;
		}
		for(long divisor = 3;divisor<=100000;divisor+=2) {
			if(n.mod(BigInteger.valueOf(divisor)).equals(BigInteger.ZERO)) {
				return (int)divisor;
			}
		}
		return -1;
	}
}
