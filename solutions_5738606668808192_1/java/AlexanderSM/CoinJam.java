package by.bsu.fpm.semenkev;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;

public class CoinJam {
	
	public static void main(String[] args) throws Exception {
		solve(args.length > 0 ? args[0] : "C-large.in");
	}
	
	private static String getFileName(String filePath) {
		return filePath.replaceAll("\\.([^\\.]*)$", "");
	}
	
	private static void solve(String testFile) throws Exception {
		File inputFile = new File(testFile);
		File outputFile = new File(getFileName(inputFile.getAbsolutePath())+".out");
		BufferedReader input = new BufferedReader(new FileReader(inputFile));
		PrintWriter output = new PrintWriter(outputFile);
		solve(input, output);
		input.close();
		output.close();
	}
	
	private static void solve(BufferedReader input, PrintWriter output) throws Exception {
		int testNum = Integer.parseInt(input.readLine());
		for (int i=0; i<testNum; i++) {
			String[] rcw = input.readLine().split(" ");
			int n = Integer.parseInt(rcw[0]);
			int j = Integer.parseInt(rcw[1]);
			String answer = toString(solve(n, j));
			output.format("Case #%d:\n", i+1);
			output.write(answer);
		}
	}
	
	public static String[] divisors(String jamcoin) {
		String[] res = new String[9];
		for(int i=2; i<=10; i++) {
			res[i-2] = divisor(jamcoin, i);
		}
		return res;
	}
	
	public static String divisor(String jamcoin, int radix) {
		BigInteger bi = new BigInteger(jamcoin, radix);
		BigInteger bd = new BigInteger("100000");
		for(BigInteger d = new BigInteger("2"); d.compareTo(bd) < 0; d = d.add(BigInteger.ONE)) {
			if (bi.remainder(d).equals(BigInteger.ZERO)) {
				return d.toString();
			}
		}
		return "*";
	}

	public static String toString(String[][] arr) {
		StringBuilder b = new StringBuilder();
		for(String[] sub : arr) {
			b.append(String.join(" ", sub)).append('\n');
		}
		return b.toString();
	}
	
	public static String[][] solve(int n, int j) {
		String jamcoin = startJamcoin(n);
		String[][] res = new String[j][10];
		int num = 0;
		while(num < j) {
			if (!isPrimary(jamcoin)) {
				String[] div = divisors(jamcoin);
				if (!contains(div, "*")) {
				     res[num][0] = jamcoin;
				     for(int i = 0; i<div.length; i++) {
				    	 res[num][i+1] = div[i];
				     }
				     num++;
				}
			}
			jamcoin = incJamcoin(jamcoin);
		}
		return res;
	}
	
	private static boolean contains(String[] arr, String str) {
		for(String a : arr) {
			if (a.equals(str)) {
				return true;
			}
		}
		return false;
	}
	
	private static String startJamcoin(int n) {
		StringBuilder builder = new StringBuilder(n);
		builder.append("1");
		for(int i=1; i<n-1; i++) {
			builder.append("0");
		}
		builder.append("1");
		return builder.toString();
	}
	
	private static boolean isPrimary(String jamcoin) {
		for(int i=2; i<=10; i++) {
			if (new BigInteger(jamcoin, i).isProbablePrime(10000000)) {
				return true;
			}
		}
		return false;
	}
	
	private static String incJamcoin(String jamcoin) {
		return new BigInteger(jamcoin, 2).add(BigInteger.ONE).add(BigInteger.ONE).toString(2);
	}
		
}
