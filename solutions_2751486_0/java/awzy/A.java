import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws IOException {
		String name = "A-small-attempt3";
		Scanner sc = new Scanner(new File(name + ".in"));
		//Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter(name + ".out"));
		int t = sc.nextInt();
		sc.nextLine();
		for (int c = 1; c <= t; c++) {
			BigInteger val = BigInteger.ZERO;
			long nvalue = 0;
			String[] strs = sc.nextLine().split(" ");
			String str = strs[0];
			long n = Long.parseLong(strs[1]);
			long answ = 0;
			for(int i = 0; i < str.length(); i++) {
				two: for(int j = i; j < str.length(); j++) {
					int cons = 0;
					for(int k = i; k <= j; k++) {
						if(!isVowel(str.charAt(k))) {
							cons++;
						} else {
							cons = 0;
						}
						if (cons >= n) {
							answ++;
							continue two;
						}
					}
				}
			}
			/*
			long m = 0;
			long f = 0;
			for (int j = 0; j < str.length(); j++) {
				if (m >= n) {
					nvalue = (j - n + 1 - f) * (str.length() - j + 1);
					BigInteger x1 = new BigInteger(String.valueOf(j - n + 1 - f));
					BigInteger x2 = new BigInteger(String.valueOf(str.length() - j + 1));
					x1 = x1.multiply(x2);
					if(x1.compareTo(BigInteger.ZERO) < 0) System.out.println(x1);
					val = val.add(x1);
					f++;
				}
				if (!isVowel(str.charAt(j))) {
					m++;
				} else {
					m = 0;
				}
			}
			if (m >= n) {
				nvalue = (str.length() - n + 1 - f);
				BigInteger x1 = new BigInteger(String.valueOf(str.length() - n + 1 - f));
				if(x1.compareTo(BigInteger.ZERO) < 0) System.out.println(x1);
				val = val.add(x1);
			}
			
			*/
			String ans = "Case #" + c + ": " + answ;
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		sc.close();
	}

	public static boolean isVowel(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;
		return false;
	}

}
