package com.bd.codejam.y2012.r1c;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class A {
	
	private Map<Integer, List<Integer>> _map = new HashMap<Integer, List<Integer>>();
	
	public void solve() throws IOException {
		Scanner in = new Scanner(new File(getClass().getSimpleName() + ".in.txt"));
		PrintWriter out = new PrintWriter(new File(getClass().getSimpleName() + ".out.txt"));

		int T = Integer.parseInt(in.nextLine());
		for (int t = 0; t < T; t++) {
			_map = new HashMap<Integer, List<Integer>>();
			int N = in.nextInt();
			for (int n = 1; n <= N; n++) {
				int M = in.nextInt();
				for (int m = 0; m < M; m++) {
					add(in.nextInt(), n);
				}
			}
			
			String result = solveMap();
			
			out.println("Case #" + (t + 1) + ": " + result);
			System.out.println("Case #" + (t + 1) + ": " + result);
		}

		in.close();
		out.close();
	}
	
	private void add(int from, int to) {
		List<Integer> list = _map.get(from);
		if (list == null) {
			list = new ArrayList<Integer>();
			_map.put(from, list);
		}
		list.add(to);
	}
	
	private String solveMap() {
		
		for (Integer i : _map.keySet()) {
			if (canAccess(new ArrayList<Integer>(), i)) {
				return "Yes";
			}
		}
		
		return "No";
	}
	
	private boolean canAccess(List<Integer> a, Integer i) {
		if (_map.containsKey(i)) {
			for (Integer x : _map.get(i)) {
				if (a.contains(x)) {
					return true;
				}
				a.add(x);
				if (canAccess(a, x)) {
					return true;
				}
			}
		}
		return false;
	}
	
    public static void main(String[] args) throws IOException {
        new A().solve();
    }
}