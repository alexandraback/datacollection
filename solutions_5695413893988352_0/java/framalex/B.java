package gcj.c2016.r1b;


import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;

public class B implements Runnable {

	public void run() {
		int tests = nextInt();
		for (int iter = 1; iter <= tests; ++iter) {
			String c = nextWord();
			String d = nextWord();

			String ans = solveEasy(c, d);

			out.println("Case #" + iter + ": " + ans);
		}
		out.flush();
	}

	private String solveEasy(String c, String d) {
		c = c.replace('?', '.');
		d = d.replace('?', '.');
		int len = c.length();
		int a = -1;
		int b = -1;

		for (int i = 0; i < 1000; ++i) {
			if (!toStr(i, len).matches(c)) {
				continue;
			}
			for (int j = 0; j < 1000; ++j) {
				if (!toStr(j, len).matches(d)) {
					continue;
				}

				if (a == -1) {
					a = i;
					b = j;
				} else if (Math.abs(i-j) < Math.abs(a-b)) {
					a = i;
					b = j;
				}
			}
		}

		return toStr(a, len) + " " + toStr(b, len);
	}

	String toStr(int num, int len) {
		String res = Integer.toString(num);
		while (res.length() < len) {
			res = '0' + res;
		}
		return res;
	}

	private static BufferedReader br = null;
	private static PrintWriter out = null;
	private static StringTokenizer stk = null;
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new FileReader(new File("B.txt")));
		out = new PrintWriter("BB.txt");
		(new B()).run();
	}

	private void loadLine() {
		try {
			stk = new StringTokenizer(br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
	}

	private String nextLine() {
		try {
			return (br.readLine());
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}

	private int nextInt() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Integer.parseInt(stk.nextToken());
	}

	private long nextLong() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Long.parseLong(stk.nextToken());
	}

	private double nextDouble() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return Double.parseDouble(stk.nextToken());
	}

	private String nextWord() {
		while (stk == null || !stk.hasMoreElements()) loadLine();
		return (stk.nextToken());
	}
}
