package b;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

import org.omg.CORBA.INTERNAL;

public class B {
	public final String fileName = "B-small-attempt0";
	//public final String fileName = "B.0";
	public Scanner scanner;
	public PrintWriter pw;
	public int nCases;

	public B() {
		initClass();
	}

	void initClass() {
		try {
			// Load from stdin
			// scanner = new Scanner(System.in);

			// Load from file
			String loadFile = System.getProperty("user.dir") + File.separator
					+ "f" + File.separator + getClass().getSimpleName()
					+ File.separator + fileName;

			scanner = new Scanner(new FileInputStream(
					new File(loadFile + ".in")));

			pw = new PrintWriter(new File(loadFile + ".out"));
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}

	String f(ArrayList<Integer> a, boolean p, boolean x) {
		StringBuilder sb = new StringBuilder();
		for (int k : a) {
			assert (k != 0);
			if (x) {
				if (k > 0)
					sb.append(p ? 'E' : 'W');
				else
					sb.append(p ? 'W' : 'E');
			} else {
				if (k > 0)
					sb.append(p ? 'N' : 'S');
				else
					sb.append(p ? 'S' : 'N');
			}
		}
		return sb.toString();
	}

	void doCase(int kase) {
		doCaseSmall(kase);
		return;
	}

	public int start;

	ArrayList<Integer> g(int x) {
		//System.out.println("Doing: " + x +" start: " + start);
		ArrayList<Integer> list = new ArrayList<Integer>();
		int k = start, n = 0;
		while (n < x) {
			++k;
			n += k;
			list.add(k);
		}
		if (n > x) {
			for (int i = 0; i < n - x; ++i) {
				++k;
				list.add(k);
				++k;
				list.add(-k);
			}
		}
		start = k;
		return list;
	}

	void doCaseSmall(int kase) {
		int X = scanner.nextInt(), Y = scanner.nextInt();
		String s = "";
		start = 0;
		s += f(g(Math.abs(X)), X >= 0 ? true : false, true);
		s += f(g(Math.abs(Y)), Y >= 0 ? true : false, false);
		assert (s.length() <= 500);
		System.out.println(s);
		pw.println(s);
		return;
	}

	void doCaseLarge(int kase) {
		return;
	}

	public static void main(String[] args) {
		B t = new B();
		t.nCases = t.scanner.nextInt();
		for (int kase = 1; kase <= t.nCases; ++kase) {
			t.pw.printf("Case #%d: ", kase);
			t.doCase(kase);
		}
		t.pw.close();
	}
}