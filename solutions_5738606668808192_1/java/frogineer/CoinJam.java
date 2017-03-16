import java.io.*;
import java.util.*;
import java.math.*;

public class CoinJam {
//	private static BigInteger TWO = new BigInteger("2");
//	private static BigInteger THREE = new BigInteger("3");
//	private static BigInteger FIVE = new BigInteger("5");
//	private static BigInteger SIX = new BigInteger("6");
	
	private static String convertToNum(boolean[] arr) {
		String num = "";
		for(int i = 0; i < arr.length; i++) {
			if(arr[i]) num += "1";
			else num += "0";
		}
		return num;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		PrintStream writer = System.out;
		int t = scan.nextInt();
		for(int caseNum = 1; caseNum <= t; caseNum++) {
			int n = scan.nextInt(), j = scan.nextInt();
			writer.println("Case #" + caseNum + ":");
//			long num = 0;
//			int count = 0;
//			while(count < j) {
//				String coin = createJamcoin(num, n);
//				String isCoin = isJamcoin(coin);
//				if(isCoin != null) {
//					writer.println(isCoin);
//					count++;
//				}
//				num++;
//			}
			findNum(writer, n);
		}
		System.out.println("done");
		scan.close();
		writer.close();
	}
//	
//	private static String createJamcoin(long num, int n) {
//		String s = Long.toBinaryString(num);
//		while(s.length() < n-2) {
//			s = "0" + s;
//		}
//		return "1" + s + "1";
//	}
//	
//	private static String isJamcoin(String num) {
//		String string = String.valueOf(num);
//		for(int base = 2; base <= 10; base++) {
//			BigInteger result = new BigInteger(num, base);
//			BigInteger factor = findFactor(result);
//			if(factor == null) return null;
//			string += " " + factor;
//		}
//		return string;
//	}
//	
//	private static BigInteger findFactor(BigInteger n) {
//		if(n.remainder(TWO).equals(BigInteger.ZERO)) return TWO;
//		if(n.remainder(THREE).equals(BigInteger.ZERO)) return THREE;
//		for(BigInteger i = FIVE; i.multiply(i).compareTo(n) < 0; i = i.add(SIX)) {
//			if(n.remainder(i).equals(BigInteger.ZERO)) return i;
//			BigInteger iPlusTwo = i.add(TWO);
//			if(n.remainder(iPlusTwo).equals(BigInteger.ZERO)) return iPlusTwo;
//		}
//		return null;
//	}

	private static void findNum(PrintStream writer, int n) {
		boolean[] digits = new boolean[n];
		digits[0] = true;
		digits[n-1] = true;
		int count = 0;
		for(int i = 1; i < n-1; i += 2) {
			for(int z = 2; z < n-1; z += 2) {
				digits[i] = true;
				digits[z] = true;
				writer.print(convertToNum(digits));
				for(int b = 2; b <= 10; b++) {
					writer.print(" " + (b+1));
				}
				writer.println();
				digits[i] = false;
				digits[z] = false;
				count++;
			}
		}
		for(int i = 1; i < n-1; i += 2) {
			for(int x = 2; x < n-1; x += 2) {
				for(int y = i+2; y < n-1; y += 2) {
					for(int z = x+2; z < n-1; z += 2) {
						if(count == 500)
							return;
						digits[i] = true;
						digits[x] = true;
						digits[y] = true;
						digits[z] = true;
						writer.print(convertToNum(digits));
						for(int b = 2; b <= 10; b++) {
							writer.print(" " + (b+1));
						}
						writer.println();
						digits[i] = false;
						digits[x] = false;
						digits[y] = false;
						digits[z] = false;
						count++;
					}
				}
			}
		}
	}
}
