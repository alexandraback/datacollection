//package gcj;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class Main {

	/**
	 * @param args
	 */
	static Scanner cin = new Scanner(System.in);
	static PrintStream cout = System.out;
	static BigInteger maxB = BigInteger.TEN.pow(70);
	static String[] mid = { "", "0", "1", "2" };;
	Vector<BigInteger> tmp;

	String reverse(String s) {
		String res = "";
		for (int i = s.length() - 1; i >= 0; i--)
			res += s.substring(i, i + 1);
		return res;
	}

	void dfs(String s, int re) {
		if (s.length() > 0 && s.charAt(0) == '0')
			return;
		boolean flag = false;
		for (int i = 0; i < mid.length; i++)
			if (Math.max(i - 1, 0) * Math.max(i - 1, 0) <= re) {
				String t = s + mid[i] + reverse(s);
				if (t.length() == 0)
					continue;
				BigInteger r = new BigInteger(t);
				if (t.length() * 2 - 1 <= 100) {
					tmp.add(r);
					flag = true;
				}
			}
		if (!flag)
			return;
		for (char i = '0'; i <= '2'; i++)
			dfs(s + i, re - 2 * (i - '0') * (i - '0'));
	}

	void init() {
		tmp = new Vector<BigInteger>();
		dfs("", 9);
        tmp.add(new BigInteger("3"));
		Collections.sort(tmp);
		for (int i = 0; i < tmp.size(); i++)
			tmp.set(i, tmp.get(i).pow(2));
	}

	int getAns(BigInteger a, BigInteger b) {
		// (-(insertion point) - 1)
		int t1 = Collections.binarySearch(tmp, a);
		int t2 = Collections.binarySearch(tmp, b);
		//cout.println(t1 + " " + t2);
		if (t1 >= 0)
			t1--;
		else
			t1 = -(t1 + 1) - 1;
		if (t2 < 0)
			t2 = -(t2 + 1) - 1;
		//cout.println(tmp.get(t1) + " " + tmp.get(t2));
		return t2 - t1;
	}

	void solve() {
		int t = cin.nextInt();
		for (int i = 1; i <= t; i++) {
			cout.print("Case #" + i + ": ");
			BigInteger a = cin.nextBigInteger();
			BigInteger b = cin.nextBigInteger();
			cout.println(getAns(a, b));
		}
	}

	Main() {
		init();
		solve();
	}

	public static void main(String[] args) throws IOException {
		// cout = new PrintStream("data.txt");
		new Main();
	}

}
