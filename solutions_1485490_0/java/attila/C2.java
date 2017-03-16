package at.jaki.codejam.y2012.r1C.C;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class C2 {

	private static final String NAME = "C";
	private static final String IN = ".in";
	private static final String OUT = ".out";
	// private static final String TYPE = "-small-attempt0";
	// private static final String TYPE = "-large";
	private static final String TYPE = "";
	private static final String TEMPLATE = "Case #%d: %s";

	private static Scanner sc;
	private static PrintWriter pw;
	private static int totalTests;

	private static void init() {
		try {
			sc = new Scanner(new File(NAME.concat(TYPE.concat(IN))));
			pw = new PrintWriter(new File(NAME.concat(TYPE.concat(OUT))));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static void start() {
		totalTests = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= totalTests; i++) {
			doStuff(i);
		}
	}

	private static void close() {
		pw.flush();
		pw.close();
	}

	public static void main(String[] args) {
		init();
		start();
		close();
	}

	private static int[][] t1;
	private static int[][] t2;

	private static void doStuff(int test) {
		int n = sc.nextInt();
		int m = sc.nextInt();

		t1 = new int[2][n];
		t2 = new int[2][m];

		for (int i = 0; i < n; i++) {
			t1[0][i] = sc.nextInt();
			t1[1][i] = sc.nextInt();
		}

		for (int i = 0; i < m; i++) {
			t2[0][i] = sc.nextInt();
			t2[1][i] = sc.nextInt();
		}

		// print(t1, 2, n);
		// print(t2, 2, m);

		Integer calc = calc(0, 0, 0, 0);
		pw.println(String.format(TEMPLATE, test, calc.toString()));
	}

	private static int calc(int i, int j, int usedI, int usedJ) {
		if (i == t1[0].length || j == t2[0].length) {
			return 0;
		}
		int r = 0;
		boolean skipI = false;
		boolean skipJ = false;
		if (t1[1][i] == t2[1][j]) {
			int f = t1[0][i] - usedI;
			int s = t2[0][j] - usedJ;
			if (f < 00) {
				skipI = true;
			}
			if (s <= 0) {
				skipJ = true;
			}
			r = Math.min(f, s);
		}
		int tr1 = 0;
		int tr2 = 0;
		if (!skipJ) {
			tr1 = calc(i + 1, j, 0, usedJ + r);
		}
		if (!skipI) {
			tr2 = calc(i, j + 1, usedI + r, 0);
		}
		return Math.max(tr1, tr2) + r;
	}

	private static void print(int[][] t, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print(t[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}

	private static void print(long[][] t, int n, int m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print(t[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println();
	}
}
