import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
import static java.lang.Integer.*;
import static java.lang.Double.*;
import static java.lang.Character.*;


public class A {
	
	static String[] WW = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	static int[][] W;
	static int[][] WC;
	static char[] DC = {};
	
	static {
		W = new int[10][];
		for (int i = 0; i < WW.length; i++) {
			W[i] = new int[WW[i].length()];
			for (int j = 0; j < WW[i].length(); j++)
				W[i][j] = WW[i].charAt(j) - 'A';
		}
		
		WC = new int[10][26];
		for (int i = 0; i < W.length; i++) {
			for (int j = 0; j < W[i].length; j++)
				WC[i][W[i][j]]++;
		}
	}
	
	
	Object solve() {
		String s = sc.next();
		int[] cnt = new int[26];
		int sum = s.length();
		for (char c : s.toCharArray()) {
			cnt[c-'A']++;
		}
		
		return go(cnt, sum, 0);
	}

	private String go(int[] cnt, int sum, int i) {
		if (i == 10)
			return sum == 0 ? "" : null;
		
		int m = Integer.MAX_VALUE;
		for (int c : W[i]) {
			m = Math.min(m, cnt[c]/WC[i][c]);
		}
		
		for (int c : W[i]) {
			cnt[c] -= m;
		}

		for (int take = m; take > 0; take--) {
			String res = go(cnt, sum - W[i].length*take, i+1);
			if (res != null)
				return mult(i, take) + res;
			for (int c : W[i]) {
				cnt[c]++;
			}
		}
		return go(cnt, sum, i+1);
	}

	private String mult(int i, int n) {
		char[] c = new char[n];
		Arrays.fill(c, (char)(i + '0'));
		return new String(c);
	}

	private static Scanner sc; private static PrintWriter fw;

	public static void main(String[] args) throws Exception {
		String inFile = "input.txt", outFile = "output.txt";
		if (args.length == 0) {
//			sc = new Scanner(System.in);
			sc = new Scanner(new FileInputStream(inFile));
		} else {
			inFile = args[0];
			sc = new Scanner(new FileInputStream(inFile));
			if (args.length > 1)
				outFile = args[1];
			else if (inFile.endsWith(".in"))
				outFile = inFile.substring(0, inFile.length() - 2) + "out";
			System.out.println(inFile + " -> " + outFile);
		}
		
		fw = new PrintWriter(new FileWriter(outFile, false)) {
			public PrintWriter printf(String format, Object... args) {
				System.out.printf(format, args);
				return super.printf(format, args);
			}
		};
		
		int N = sc.nextInt();
		sc.nextLine();
		System.out.println(N + " cases.");
		
		int progress = 0, progress1;
		for (int cas = 1; cas <= N; cas++) {
			fw.printf("Case #" + cas + ": ");
//			fw.println("Case #" + cas + ": ");
			Object res = new A().solve();
			if (res instanceof Double) 
				fw.printf("%.10f\n", res);
			else
				fw.printf("%s\n", res);
			fw.flush();
			if ((progress1 = cas*10/N) > progress) { System.out.println("*" + progress1*10 + "% "); progress = progress1; };
		}
		fw.close();
		sc.close();
	}
}
