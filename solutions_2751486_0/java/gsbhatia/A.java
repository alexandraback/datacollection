package a;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	public final String fileName = "A-small-attempt0";
	//public final String fileName = "A.0";

	public Scanner scanner;
	public PrintWriter pw;
	public int nCases;

	public A() {
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

	boolean isVow(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;
		return false;
	}

	void doCase(int kase) {
		doCaseLarge(kase);
		return;
	}

	void doCaseSmall(int kase) {
		return;
	}

	void doCaseLarge(int kase) {
		String s = scanner.next();
		int N = scanner.nextInt();
		int M = s.length();
		int A[] = new int[M];
		long B[] = new long[M];
		long ret = 0;
		for (int i = M - 1; i > -1; --i) {
			if (!isVow(s.charAt(i))) {
				A[i] = 1 + (i == M - 1 ? 0 : A[1 + i]);
			} else
				A[i] = 0;
			if (A[i] >= N)
				B[i] = M - i - N + 1;
			else
				B[i] = i == M - 1 ? 0 : B[1 + i];
			ret += B[i];
		}

		pw.printf("%s\n", new Long(ret).toString());
	}

	public static void main(String[] args) {
		A t = new A();
		t.nCases = t.scanner.nextInt();
		for (int kase = 1; kase <= t.nCases; ++kase) {
			t.pw.printf("Case #%d: ", kase);
			t.doCase(kase);
		}
		t.pw.close();
	}
}