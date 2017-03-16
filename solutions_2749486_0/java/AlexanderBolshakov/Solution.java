import java.util.*;
import java.io.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	int destx, desty;
	
	int progSolve(int s, int dist) {
		int l = -1, r = 3000;
		while (r - l > 1) {
			int m = (l + r) / 2;
			int val = (s + s + m - 1) * m / 2;
			if (val < dist) {
				l = m;
			} else {
				r = m;
			}
		}
		return r;
	}
	
	class State implements Comparable<State> {
		
		int x, y, moves;
		State from;
		char lastmove;
		int evaluation = -1;
		
		public State(int x, int y, int moves, State from, char lastmove) {
			this.x = x;
			this.y = y;
			this.moves = moves;
			this.from = from;
			this.lastmove = lastmove;
		}
		
		int eval() {
			if (evaluation == -1) {
				evaluation = moves + progSolve(moves + 1, abs(x - destx) + abs(y - desty));
			}
			return evaluation;
		}
		
		@Override
		public int compareTo(State o) {
			return this.eval() - o.eval();
		}
		
	}
	
	class ByXY implements Comparator<State> {
		
		@Override
		public int compare(State o1, State o2) {
			if (o1.x != o2.x) {
				return o1.x - o2.x;
			} else {
				return o1.y - o2.y;
			}
		}
		
	}
	
	void relax(TreeMap<State, Integer> dist, PriorityQueue<State> heap, State st) {
		if (!dist.containsKey(st) || st.moves < dist.get(st)) {
			dist.put(st, st.moves);
			heap.offer(st);
		}
	}

	public void solve() throws Exception {
		int t = sc.nextInt();
	outer:
		for (int Case = 1; Case <= t; Case++) {
			out.print("Case #" + Case + ": ");
			destx = sc.nextInt();
			desty = sc.nextInt();
			PriorityQueue<State> heap = new PriorityQueue<State>();
			TreeMap<State, Integer> dist = new TreeMap<State, Integer>(new ByXY());
			State start = new State(0, 0, 0, null, '\0');
			heap.offer(start);
			dist.put(start, 0);
			while (!heap.isEmpty()) {
				State min = heap.poll();
				//System.out.println(min.x + " " + min.y + " " + min.eval());
				if (min.x == destx && min.y == desty) {
					//out.println("GOOD " + min.moves);
					StringBuilder sb = new StringBuilder();
					State cur = min;
					while (cur.from != null) {
						sb.append(cur.lastmove);
						cur = cur.from;
					}
					sb.reverse();
					int x = 0, y = 0;
					for (int i = 0; i < sb.length(); i++) {
						if (sb.charAt(i) == 'N') {
							y += i + 1;
						} else if (sb.charAt(i) == 'S') {
							y -= i + 1;
						} else if (sb.charAt(i) == 'E') {
							x += i + 1;
						} else {
							x -= i + 1;
						}
					}
					out.println(sb.toString());
					break;
				}
				State n = new State(min.x, min.y + (min.moves + 1), min.moves + 1, min, 'N');
				State s = new State(min.x, min.y - (min.moves + 1), min.moves + 1, min, 'S');
				State e = new State(min.x + (min.moves + 1), min.y, min.moves + 1, min, 'E');
				State w = new State(min.x - (min.moves + 1), min.y, min.moves + 1, min, 'W');
				relax(dist, heap, n);
				relax(dist, heap, s);
				relax(dist, heap, e);
				relax(dist, heap, w);
			}
		}
	}

	static Throwable uncaught;

	BufferedReader in;
	FastScanner sc;
	PrintWriter out;

	@Override
	public void run() {
		try {
			in = new BufferedReader(new FileReader("B-small-attempt1.in"));
			out = new PrintWriter(new FileWriter("B-small-attempt1.out"));
			sc = new FastScanner(in);
			solve();
		} catch (Throwable uncaught) {
			Solution.uncaught = uncaught;
		} finally {
			out.close();
		}
	}

	public static void main(String[] args) throws Throwable {
		Thread thread = new Thread(null, new Solution(), "", (1 << 26));
		thread.start();
		thread.join();
		if (Solution.uncaught != null) {
			throw Solution.uncaught;
		}
	}

}

class FastScanner {

	BufferedReader in;
	StringTokenizer st;

	public FastScanner(BufferedReader in) {
		this.in = in;
	}

	public String nextToken() throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}

	public int nextInt() throws Exception {
		return Integer.parseInt(nextToken());
	}

	public long nextLong() throws Exception {
		return Long.parseLong(nextToken());
	}

	public double nextDouble() throws Exception {
		return Double.parseDouble(nextToken());
	}

}