/**
 * Written By Kylin
 * Last modified: 2012-5-6
 * State: Pending
 */
package me.kylin.gcj.c2012R1C;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class DiamondInheritance {

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
		DiamondInheritance cls = new DiamondInheritance();
		String base = "data/2012R1C/";
		cls.file = base + generateFilename("A", 2, 1);
		cls.showDebug = true;
		cls.work();
	}

	List<List<Integer>> children;
	boolean[] visit;
	boolean[] hasParents;
	
	void solveACase() {
		int n = sc.nextInt();
		children = new ArrayList<List<Integer>>();
		visit = new boolean[n + 1];
		hasParents = new boolean[n + 1];
		for (int i = 0; i <= n; i++) {
			children.add(new ArrayList<Integer>());
		}
		for (int i = 1; i <= n; i++) { 
			int m = sc.nextInt();
			hasParents[i] = m > 0;
			for (int j = 0; j < m; j++) {
				int c = sc.nextInt();
				children.get(c).add(i);
			}
		}
		// eliminate indirect children
//		for (int i = 1; i <= n; i++) {
//			List<Integer> c = children.get(i);
//			List<Integer> indirect = new ArrayList<Integer>();
//			for (Integer j : c) {
//				for (Integer k : c) {
//					if (children.get(j).contains(k)) indirect.add(k);
//				}
//			}
//			c.removeAll(indirect);
//		}
		boolean diamond = false;
		for (int i = 1; i <= n && !diamond; i++) {
			if (hasParents[i] == false) {
				Arrays.fill(visit, false);
				diamond = hasDiamond(i);
//				debug(i + " " + diamond);
			}
		}
		out(diamond ? "Yes" : "No");
	}
	
	boolean hasDiamond(int idx) {
		if (visit[idx]) return true;
		visit[idx] = true;
		for (Integer i : children.get(idx)) {
			if (hasDiamond(i)) return true;;
		}
		return false;
	}
}