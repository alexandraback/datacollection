import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class C {
	
	private static class SimetricPart {
		private String firstHalf;
		private int sumOfSquaredDigits;
		
		public SimetricPart(String firstHalf, int sumOfSquaredDigits) {
			super();
			this.firstHalf = firstHalf;
			this.sumOfSquaredDigits = sumOfSquaredDigits;
		}
		
		private String getReverse() {
			int size = firstHalf.length();
			char[] ret = new char[size];
			for (int i=0;i<size;i++) ret[size - 1 - i] = firstHalf.charAt(i);
			return new String(ret);
		}
	}
	
	private static List<SimetricPart> parts = new ArrayList<SimetricPart>();
	private static int MAX_LENGTH = 25;
	
	private static void fillParts() {
		recFillParts(new SimetricPart("", 0));
	}
	
	private static void recFillParts(SimetricPart sp) {
		parts.add(sp);
		if (sp.sumOfSquaredDigits < 4 && sp.firstHalf.length() < MAX_LENGTH) {
			String old = sp.firstHalf;
			int upTo = sp.sumOfSquaredDigits == 0 ? 2 : 1;
			for (int i=old.length(); i < MAX_LENGTH; i++) {
				for (int ndig=1; ndig <= upTo; ndig++) {
					recFillParts(new SimetricPart(ndig + getZeroString(i-old.length()) + old, sp.sumOfSquaredDigits + ndig*ndig));
				}
			}
		}
	}
	
	private static List<BigInteger> allFairAndSquare = new ArrayList<BigInteger>();
	
	private static void fillFairAndSquare() {
		for (SimetricPart sp : parts) {
			String secondHalf = sp.getReverse();
			if (!secondHalf.isEmpty()) allFairAndSquare.add(new BigInteger(sp.firstHalf + secondHalf).pow(2));
			if (sp.firstHalf.length() < MAX_LENGTH) {
				int remaining = 9 - 2 * sp.sumOfSquaredDigits;
				for (int midDig = 0; midDig*midDig <= remaining; midDig++) {
					allFairAndSquare.add(new BigInteger(sp.firstHalf + midDig + secondHalf).pow(2));
				}
			}
		}
		Collections.sort(allFairAndSquare);
	}
	
	private static final String ZEROS="0000000000000000000000000";
	
	private static String getZeroString(int n) {
		return ZEROS.substring(0, n);
	}
	
	public static void main(String[] args) {
		fillParts();
		fillFairAndSquare();
		
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int i=1; i <= cases;i++) {
			BigInteger A = sc.nextBigInteger();
			BigInteger B = sc.nextBigInteger();
			
			int ret = Math.abs(Collections.binarySearch(allFairAndSquare, B) + 1);
			A = A.subtract(BigInteger.ONE);
			ret -= Math.abs(Collections.binarySearch(allFairAndSquare, A) + 1);
			
			System.out.println("Case #" + i + ": " + ret);
		}
		
	}
}


