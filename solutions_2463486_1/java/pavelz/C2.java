package qualify;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class C2 {

	private static int [] digits = new int[1000];
	
	private static int currentTotal;
	private static ArrayList<BigInteger> list;
	
	private static void checkNumber(int digitPosition, boolean middle) {
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<digitPosition;i++) sb.append(digits[i]);
		if (middle) sb.append(digits[digitPosition]);
		for(int i=digitPosition - 1;i>=0;i--) sb.append(digits[i]);

		BigInteger toCheck = new BigInteger(sb.toString());
		toCheck = toCheck.multiply(toCheck);
		list.add(toCheck);
	}
	
	private static void generateDigits(int level, int digitPosition, boolean middle) {
		if (level > 0) {
			int start = digitPosition > 0 ? 0 : 1;
			for(int i=start;i*i + currentTotal < 5;i++) {
				digits[digitPosition] = i;
				currentTotal += i*i;
				generateDigits(level - 1, digitPosition + 1, middle);
				currentTotal -= i*i;
			}
		} else {
			if (middle) {
				for(int i=0;i*i + 2 * currentTotal < 10;i++) {
					digits[digitPosition] = i;
					checkNumber(digitPosition, true);
				}
			} else {
				checkNumber(digitPosition, false);
			}
		}
	}

	private static int calculate(ArrayList<BigInteger> list, BigInteger a, BigInteger b) {
		int i = 0;
		int count = 0;
		while (list.get(i).compareTo(a) < 0) i++;
		while (list.get(i).compareTo(b) <= 0) { i++; count++; }
		return count;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		ArrayList<BigInteger> list1 = new ArrayList<BigInteger>();
		ArrayList<BigInteger> list2 = new ArrayList<BigInteger>();
		list = list1;
		for(int d=0;d<27;d++) generateDigits(d, 0, true);
		list = list2;
		for(int d=1;d<27;d++) generateDigits(d, 0, false);
		
		for (int i=0;i<t;i++) {
			BigInteger a = sc.nextBigInteger();
			BigInteger b = sc.nextBigInteger();
			
			int count = calculate(list1, a, b);
			count += calculate(list2, a, b);
			System.out.println("Case #" + (i + 1) + ": " + count);
		}
		
		sc.close();
	}

}
