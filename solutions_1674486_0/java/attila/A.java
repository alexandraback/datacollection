package at.jaki.codejam.y2012.r1C.A;

import java.io.File;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class A {

	private static final String NAME = "A";
	private static final String IN = ".in";
	private static final String OUT = ".out";
	private static final String TYPE = "-small-attempt1";
	// private static final String TYPE = "-large";
	// private static final String TYPE = "";
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

	private static void doStuff(int test) {
		int n = sc.nextInt();

		boolean[][] t = new boolean[n][n];
		String res = "No";
		boolean stop = false;
		try {
			for (int i = 0; i < n; i++) {
				// print(t, n);
				int m = sc.nextInt();
				for (int j = 0; j < m; j++) {
					int x = sc.nextInt();
					if (!stop) {
						x = x - 1;
						
						if (t[i][x]) {
							res = "Yes";
							stop = true;
						}
						t[i][x] = true; // i inherits from x

						List<Integer> news = new LinkedList<Integer>();
						news.add(x);

						for (int k = 0; k < n; k++) {
							if (t[x][k]) {
								if (t[i][k]) {
									res = "Yes";
									stop = true;
								}
								t[i][k] = true;
								news.add(k);
							}
						}

						for (int k = 0; k < n; k++) {
							if (t[k][i]) {
								for (Integer xx : news){
									if (t[k][xx]) {
										res = "Yes";
										stop = true;
									}
									t[k][xx] = true;
								}
							}
						}
					}
				}
			}
		} catch (RuntimeException e) {
			res = "Yes";
		} finally {
			pw.println(String.format(TEMPLATE, test, res));
		}

	}

	private static void print(boolean[][] t, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print((t[i][j] ? 1 : 0) + " ");
			}
			System.out.println();
		}
		System.out.println();
	}
}
