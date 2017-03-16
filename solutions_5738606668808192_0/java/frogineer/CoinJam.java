import java.io.*;
import java.util.*;

public class CoinJam {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		PrintStream writer = System.out;
		int t = scan.nextInt();
		for(int caseNum = 1; caseNum <= t; caseNum++) {
			int n = scan.nextInt(), j = scan.nextInt();
			writer.println("Case #" + caseNum + ":");
			int num = 0;
			int count = 0;
			while(count < j) {
				String coin = createJamcoin(num, n);
				String isCoin = isJamcoin(coin);
				if(isCoin != null) {
					writer.println(isCoin);
					count++;
				}
				num++;
			}
		}
		System.out.println("done");
		scan.close();
		writer.close();
	}
	
	private static String createJamcoin(int num, int n) {
		String s = Integer.toBinaryString(num);
		while(s.length() < n-2) {
			s = "0" + s;
		}
		return "1" + s + "1";
	}
	
	private static String isJamcoin(String num) {
		String string = String.valueOf(num);
		for(int base = 2; base <= 10; base++) {
			long result = Long.parseLong(num, base);
			long factor = findFactor(result);
			if(factor == -1) return null;
			string += " " + factor;
		}
		return string;
	}
	
	private static long findFactor(long n) {
		if(n % 2 == 0) return 2;
		if(n % 3 == 0) return 3;
		for(long i = 5; i * i < n; i += 6) {
			if(n % i == 0) return i;
			if(n % (i+2) == 0) return i+2;
		}
		return -1;
	}
}
