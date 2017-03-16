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
import java.util.List;
import java.util.Scanner;

public class BoxFactory {

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
		BoxFactory cls = new BoxFactory();
		String base = "data/2012R1C/";
		cls.file = base + generateFilename("C", 1, 2);
		cls.showDebug = true;
		cls.work();
	}

	class Seg {
		long length;
		int type;
	}
	
	class State {
		long remainBox;
		long remainToy;
		long value;
		
		State() {
		}
		
		State(State s) {
			remainBox = s.remainBox;
			remainToy = s.remainToy;
			value = s.value;
		}
	}
	
	class StateMap {
		List<List<List<State>>> states;
		
		StateMap(int n, int m) {
			states = new ArrayList<List<List<State>>>(n);
			for (int i = 0; i <= n; i++) {
				states.add(new ArrayList<List<State>>(m));
				for (int j = 0; j <= m; j++) {
					states.get(i).add(new ArrayList<State>());
				}
			}
		}
		
		List<State> get(int i, int j) {
			return states.get(i).get(j);
		}
		
		void add(int i, int j, State s) {
			for (State ss : states.get(i).get(j)) {
				if (s.value <= ss.value && s.remainBox <= ss.remainBox && s.remainToy <= ss.remainToy) {
					return;
				}
			}
			states.get(i).get(j).add(s);
		}
	}
	
	Seg[] boxes;
	Seg[] toys;
	StateMap map;

	void solveACase() {
		int n = sc.nextInt();
		int m = sc.nextInt();
		boxes = new Seg[n + 1];
		toys = new Seg[m + 1];
		for (int i = 1; i <= n; i++) {
			boxes[i] = new Seg();
			boxes[i].length = sc.nextLong();
			boxes[i].type = sc.nextInt();
		}
		for (int i = 1; i <= m; i++) {
			toys[i] = new Seg();
			toys[i].length = sc.nextLong();
			toys[i].type = sc.nextInt();
		}
		map = new StateMap(n, m);
		State s = new State();
		s.remainBox = 0;
		s.remainToy = toys[1].length;
		s.value = 0;
		map.add(0, 1, s);
		s = new State();
		s.remainBox = boxes[1].length;
		s.remainToy = 0;
		s.value = 0;
		map.add(1, 0, s);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (State os : map.get(i - 1, j)) {
					Seg b = boxes[i];
					s = new State(os);
					if (b.type != toys[j].type) {
						s.remainBox = b.length;
					} else {
						if (b.length >= os.remainToy) {
							s.remainBox = b.length - os.remainToy;
							s.remainToy = 0;
							s.value += os.remainToy; 
						} else {
							s.remainBox = 0;
							s.remainToy -= b.length;
							s.value += b.length;
						}
					}
					map.add(i, j, s);
				}
				for (State os : map.get(i, j - 1)) {
					Seg t = toys[j];
					s = new State(os);
					if (t.type != boxes[i].type) {
						s.remainToy = t.length;
					} else {
						if (t.length >= os.remainBox) {
							s.remainToy = t.length - os.remainBox;
							s.remainBox = 0;
							s.value += os.remainBox; 
						} else {
							s.remainToy = 0;
							s.remainBox -= t.length;
							s.value += t.length;
						}
					}
					map.add(i, j, s);
				}
			}
		}
		long max = 0;
		for (State ss : map.get(n, m)) {
			if (ss.value > max) max = ss.value;
		}
		debug(map.get(n, m).size());
		out(max);
	}
}