package net.anzix.learn.codejam.r1b12;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class TiedGoesIn {

	int floor[][];
	int ceiling[][];
	int startLevel;
	Map<Pair, Double> times = new HashMap<Pair, Double>();
	Set<Pair> nodes = new HashSet<Pair>();

	public static void main(String args[]) throws Exception {
		run(args[0], args[1]);
	}

	public static void run(String from, String to) throws Exception {
		Scanner scanner = new Scanner(new FileInputStream(new File(from)));
		PrintWriter writer = new PrintWriter(new FileWriter(new File(to)));
		int tests = scanner.nextInt();
		for (int i = 0; i < tests; i++) {
			int startLevel = scanner.nextInt();
			int h = scanner.nextInt();
			int w = scanner.nextInt();
			int[][] ceils = new int[w][h];
			int[][] floors = new int[w][h];
			for (int y = 0; y < h; y++) {
				for (int x = 0; x < w; x++) {
					ceils[x][y] = scanner.nextInt();
				}
			}
			for (int y = 0; y < h; y++) {
				for (int x = 0; x < w; x++) {
					floors[x][y] = scanner.nextInt();
				}
			}
			TiedGoesIn ti = new TiedGoesIn(floors, ceils, startLevel);
			
			writer.printf("Case #%1$d: %2$.6f" +
					"\n", i + 1, ti.calculate());
			writer.flush();

		}
		writer.close();
	}

	public TiedGoesIn(int[][] floor, int[][] ceiling, int startLevel) {
		super();
		this.floor = floor;
		this.ceiling = ceiling;
		this.startLevel = startLevel;
	}

	public double calculate() {
		for (int x = 0; x < floor.length; x++) {
			for (int y = 0; y < floor[0].length; y++) {
				Pair p = new Pair(x, y);
				times.put(p, Double.MAX_VALUE);
				nodes.add(p);
			}
		}
		times.put(new Pair(0, 0), 0d);
		while (nodes.size() > 0) {
			Pair min = findMin();
			nodes.remove(min);
			check(min, new Pair(min.x, min.y - 1));
			check(min, new Pair(min.x, min.y + 1));
			check(min, new Pair(min.x + 1, min.y));
			check(min, new Pair(min.x - 1, min.y));
		}
		return times.get(new Pair(floor.length - 1, floor[0].length - 1));

	}

	private Pair findMin() {
		double min = Double.MAX_VALUE;
		Pair c = null;
		for (Pair p : nodes) {
			if (times.get(p) < min) {
				c = p;
				min = times.get(p);
			}
		}
		if (c==null){
			return nodes.iterator().next();
		}
		return c;
	}

	private void check(Pair from, Pair to) {
		if (to.x < 0 || to.y < 0)
			return;
		if (to.x > floor.length - 1 || to.y > floor[0].length - 1) {
			return;
		}

		if (nodes.contains(to)) {
			double time = calculateBestTime(from, to);
			if (time < times.get(to)) {
				times.put(to, time);
			}

		}

	}

	private double calculateBestTime(Pair from, Pair to) {
		if (floor[from.x][from.y] + 50 > ceiling[to.x][to.y]) {
			return Double.MAX_VALUE;
		}
		if (floor[to.x][to.y] + 50 > ceiling[to.x][to.y]) {
			return Double.MAX_VALUE;
		}

		if (floor[to.x][to.y] + 50 > ceiling[from.x][from.y]) {
			return Double.MAX_VALUE;
		}

		double now = times.get(from);
		double level = startLevel - 10 * now;
		double wait = 0;
		if (level <= ceiling[to.x][to.y] - 50) {
			wait = 0;
		} else {
			wait = (level - (ceiling[to.x][to.y] - 50)) / 10;
		}
		level -= wait * 10;
		if (level - floor[from.x][from.y] >= 20) {
			if (wait == 0 && now == 0) {
				return 0;
			}
			return now + wait + 1;

		} else {
			if (wait == 0 && now == 0) {
				return 0;
			}
			return now + wait + 10;
		}

	}

	private class Pair {
		public int x;
		public int y;

		public Pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		private TiedGoesIn getOuterType() {
			return TiedGoesIn.this;
		}

	}
}
