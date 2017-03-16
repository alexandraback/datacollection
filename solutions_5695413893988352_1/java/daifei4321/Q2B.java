package r1B;

import java.util.Scanner;

public class Q2B {
	public static void main(String... args) throws Throwable {
		try (Scanner in = new Scanner(System.in)) {
			int T = in.nextInt();
			for (int caseI = 0; caseI < T; caseI++) {
				String a = in.next();
				String b = in.next();
				assert(a.length() == b.length());
				int length = a.length();
				// l-1, l-2, ..., 1, 0
				long minA = 0;
				long maxA = 0;
				long minB = 0;
				long maxB = 0;
				long nearA = 0;
				long nearB = 0;
				long mul = 1;
				for (int forDigit = 0; forDigit <= length - 1; forDigit++, mul *= 10) {
					char charA = a.charAt(length - 1 - forDigit);
					int digitA = charA - '0';
					char charB = b.charAt(length - 1 - forDigit);
					int digitB = charB - '0';
					if (charA == '?') {
						if (charB == '?') {
							long nearA1 = nearA;
							long nearB1 = nearB;
							long diff1 = Math.abs(nearA1 - nearB1);
							long nearA2 = mul + minA;
							long nearB2 = maxB;
							long diff2 = Math.abs(nearA2 - nearB2);
							long nearA3 = maxA;
							long nearB3 = mul + minB;
							long diff3 = Math.abs(nearA3 - nearB3);
							if (diff1 <= diff2 && diff1 <= diff3) {
								nearA = nearA1;
								nearB = nearB1;
							} else if (diff3 <= diff1 && diff3 <= diff2) {
								nearA = nearA3;
								nearB = nearB3;
							} else {
								nearA = nearA2;
								nearB = nearB2;
							}
							maxA += mul * 9;
							maxB += mul * 9;
						} else { // A is ?, B is digit
							long nearA1 = mul * digitB + nearA;
							long nearB1 = mul * digitB + nearB;
							long diff1 = Math.abs(nearA1 - nearB1);
							long nearA2 = mul * Math.min(9, digitB + 1) + minA;
							long nearB2 = mul * digitB + maxB;
							long diff2 = Math.abs(nearA2 - nearB2);
							long nearA3 = mul * Math.max(0, digitB - 1) + maxA;
							long nearB3 = mul * digitB + minB;
							long diff3 = Math.abs(nearA3 - nearB3);
							if (diff3 <= diff1 && diff3 <= diff2) {
								nearA = nearA3;
								nearB = nearB3;
							} else if (diff1 <= diff2 && diff1 <= diff3) {
								nearA = nearA1;
								nearB = nearB1;
							} else {
								nearA = nearA2;
								nearB = nearB2;
							}
							maxA += mul * 9;
							minB += mul * digitB;
							maxB += mul * digitB;
						}
					} else {
						if (charB == '?') { // B is ?, A is digit
							long nearA1 = mul * digitA + nearA;
							long nearB1 = mul * digitA + nearB;
							long diff1 = Math.abs(nearB1 - nearA1);
							long nearA2 = mul * digitA + minA;
							long nearB2 = mul * Math.max(0, digitA - 1) + maxB;
							long diff2 = Math.abs(nearB2 - nearA2);
							long nearA3 = mul * digitA + maxA;
							long nearB3 = mul * Math.min(9, digitA + 1) + minB;
							long diff3 = Math.abs(nearB3 - nearA3);
							if (diff2 <= diff1 && diff2 <= diff3) {
								nearA = nearA2;
								nearB = nearB2;
							} else if (diff1 <= diff2 && diff1 <= diff3) {
								nearA = nearA1;
								nearB = nearB1;
							} else {
								nearA = nearA3;
								nearB = nearB3;
							}
							minA += mul * digitA;
							maxA += mul * digitA;
							maxB += mul * 9;
						} else {
							minA += mul * digitA;
							maxA += mul * digitA;
							minB += mul * digitB;
							maxB += mul * digitB;
							if (digitA == digitB) {
								nearA += mul * digitA;
								nearB += mul * digitB;
							} else if (digitA > digitB) {
								nearA = minA;
								nearB = maxB;
							} else {
								nearA = maxA;
								nearB = minB;
							}
						}
					}
				}
				System.out.println("Case #" + (caseI + 1) + ": "
						+ preFill(nearA, a.length()) + " "
						+ preFill(nearB, a.length()));
			}
		}
	}

	private static String preFill(long n, int length) {
		String s = Long.toString(n);
		while (s.length() < length) {
			s = '0' + s;
		}
		return s;
	}
}
