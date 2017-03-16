/**
 * Written By Kylin
 * Last modified: 2012-5-6
 * State: Pending
 */
package me.kylin.gcj.c2012R1B;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class SafetyInNumbers {

	String file;

	Scanner sc;

	PrintWriter pr;

	int caseNO;

	boolean showDebug;

	void out(Object str) {
		str = "Case #" + caseNO + ": " + str;
		System.out.println(str);
		if (pr != null)
			pr.println(str);
	}

	void outNoPre(Object str) {
		System.out.println(str);
		if (pr != null)
			pr.println(str);
	}

	void debug(Object str) {
		if (showDebug)
			System.out.printf("DEBUG - Case #%d: %s\n", caseNO, str);
	}

	void work() {
		if (file != null) {
			try {
				sc = new Scanner(new FileInputStream(new File(file + ".in")));
				pr = new PrintWriter(new File(file + ".out"));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
				System.exit(1);
			}
		} else {
			sc = new Scanner(System.in);
		}
		int tc = sc.nextInt();
		sc.nextLine();
		for (caseNO = 1; caseNO <= tc; caseNO++) {
			solveACase();
			if (pr != null)
				pr.flush();
		}
		if (pr != null)
			pr.close();
	}

	static String generateFilename(String x, int scale, int t) {
		String fn = x.toUpperCase();
		if (scale == 0)
			return "sample";
		if (scale == 1)
			fn += "-small";
		if (scale == 2)
			fn += "-large";
		if (t < 0)
			return fn + "-practice";
		if (t > 0) {
			if (scale == 1)
				fn += "-attempt" + (t - 1);
			return fn;
		}
		return fn;
	}

	public static void main(String[] args) {
		SafetyInNumbers cls = new SafetyInNumbers();
		String base = "data/2012R1B/";
		cls.file = base + generateFilename("A", 1, 4);
		cls.showDebug = true;
		cls.work();
	}

	void solveACase() {
		int n = sc.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		int s = 0;
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
			b[i] = a[i];
			s += a[i];
		}
		Arrays.sort(b);
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < n; i++) {
			int ds = s;
			double m = 0;
			int t = a[i];
			for (int j = 0; j < n && ds > 0; j++) {
				if (b[j] < t) {
					ds -= t - b[j];
				} else {
					if (ds > (b[j] - t) * j) {
						m += (double)(b[j] - t) / s;
					} else {
						m += (double) ds / j / s;
					}
					ds -= (b[j] - t) * j;
					t = b[j];
				}
			}
			if (ds > 0) m += (double) ds / n / s;
			sb.append(String.format("%.7f ", m * 100));
		}
		out(sb);
	}
}