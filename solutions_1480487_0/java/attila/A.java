package at.jaki.codejam.y2012.r1B.A;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class A {

	private static final String NAME = "A";
	private static final String IN = ".in";
	private static final String OUT = ".out";
	private static final String TYPE = "-small-attempt3";
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
		List<Integer> j = new ArrayList<Integer>(n);
		List<Double> j2 = new ArrayList<Double>(n);
		List<Double> j3 = new ArrayList<Double>(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int nextInt = sc.nextInt();
			j.add(nextInt);
			sum += nextInt;
		}
		for (int i = 0; i < n; i++) {
			double d = (j.get(i).doubleValue() / (double) sum);
			j2.add(d);
		}

		double missing = (double) 2 / (double) n;

		double negSum = 0;
		int pos = 0;

		for (int i = 0; i < n; i++) {
			double x = missing - j2.get(i);
			j3.add(x);
			if (x < 0) {
				negSum += x;
			} else {
				pos++;
			}
		}

		System.out.println(j3);
		double unit = negSum / (double) pos;

		for (int i = 0; i < n; i++) {
			Double d = j3.get(i);
			if (d < 0) {
				j3.set(i, 0d);
			} else {
				j3.set(i, (d+unit));
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			double x = j3.get(i);
			x *= 100;
			sb.append(String.format("%1$.6f", x));
			sb.append(" ");
		}
		
		String st = sb.toString().replaceAll(",", ".");
		pw.println(String.format(TEMPLATE, test, st));

	}
}
