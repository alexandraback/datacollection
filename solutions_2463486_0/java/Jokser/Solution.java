import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	boolean isPalindrome (String s) {
		for (int i = 0; i < s.length() / 2; i++)
			if (s.charAt(i) != s.charAt(s.length() - i - 1))
				return false;
		return true;
	}

	boolean check(char charNum[]) {
		BigInteger num = new BigInteger(new String(charNum));
		num = num.multiply(num);
		return isPalindrome(num.toString());
	}
	
	boolean canPlaceTwoInMiddle;
	int len, needLen, answerCount;
	char charNum [];
	
	void brutforce (int index, boolean placeTwo) {
		if (index == needLen) {
			if (check(charNum)) {
				out.println(new String(charNum));
				answerCount++;
			}
			return;
		}
		if (index == 0) {
			charNum[index] = charNum[len - index - 1] = '1';
			brutforce (index + 1, false);
			charNum[index] = charNum[len - index - 1] = '2';
			brutforce (index + 1, true);
		} else if (index == needLen - 1) {
			charNum[index] = charNum[len - index - 1] = '0';
			brutforce (index + 1, placeTwo);
			charNum[index] = charNum[len - index - 1] = '1';
			brutforce (index + 1, placeTwo);
			if (canPlaceTwoInMiddle && !placeTwo) {
				charNum[index] = charNum[len - index - 1] = '2';
				brutforce (index + 1, true);
			}
		} else {
			charNum[index] = charNum[len - index - 1] = '0';
			brutforce (index + 1, placeTwo);
			charNum[index] = charNum[len - index - 1] = '1';
			brutforce (index + 1, placeTwo);
		}
	}
	
	
	public void solve() throws Throwable {
		/*
		out.println("1");
		out.println("2");
		out.println("3");
		for (len = 2; len <= 49; len++) {
			needLen = (len + 1) / 2;
			canPlaceTwoInMiddle = (len % 2 != 0);
			charNum = new char [len];
			answerCount = 0;
			brutforce(0, false);
			System.out.println("Length "+len+" is done. Find "+answerCount+" numbers.");
		}
		*/
		
		int n = 39225;
		BigInteger numbers [] = new BigInteger[n];
		for (int i = 0; i < n; i++) {
			BigInteger num = new BigInteger(precalcIn.readLine());
			numbers[i] = num.multiply(num);
		}
		int tests = sc.nextInt();
		for (int test = 1; test <= tests; test++) {
			BigInteger l = new BigInteger(sc.nextToken());
			BigInteger r = new BigInteger(sc.nextToken());
			int answer = 0;
			for (int i = 0; i < n; i++) {
				if (numbers[i].compareTo(l) >= 0 && numbers[i].compareTo(r) <= 0)
					answer++;
			}
			out.println("Case #"+test+": "+answer);
		}
	}

	BufferedReader precalcIn;
	BufferedReader in;
	PrintWriter out;
	FastScanner sc;

	static Throwable uncaught;

	@Override
	public void run() {
		try {
			precalcIn = new BufferedReader(new FileReader("palindromes.txt"));
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			sc = new FastScanner(in);
			solve();
		} catch (Throwable t) {
			Solution.uncaught = t;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread t = new Thread(null, new Solution(), "", (1 << 26));
		t.start();
		t.join();
		if (uncaught != null) {
			throw uncaught;
		}
	}

}

class FastScanner {

	BufferedReader reader;
	StringTokenizer strTok;

	public FastScanner(BufferedReader reader) {
		this.reader = reader;
	}

	public String nextToken() throws IOException {
		while (strTok == null || !strTok.hasMoreTokens()) {
			strTok = new StringTokenizer(reader.readLine().trim());
		}
		return strTok.nextToken();
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

}