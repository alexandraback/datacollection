import java.io.*;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Solution implements Runnable {
	
	int dr [] = {0, 0, 1, -1};
	int dc [] = {1, -1, 0, 0};
	
	class State implements Comparable<State> {
		int r, c;
		int time;
		
		public State(int r, int c, int time) {
			this.r = r;
			this.c = c;
			this.time = time;
		}
		
		@Override
		public int compareTo(State arg0) {
			if (this.time < arg0.time) return -1;
			if (this.time > arg0.time) return 1;
			if (this.r < arg0.r) return -1;
			if (this.r > arg0.r) return 1;
			return this.c - arg0.c;
		}
		
	}
	
	int intersect (int l1, int r1, int l2, int r2) {
		return min (r1, r2) - max (l1, l2);
	}
	
	public void solve () throws Exception {
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			
			int h = nextInt();
			int n = nextInt();
			int m = nextInt();
			
			int c [][] = new int [n][m];
			int f [][] = new int [n][m];
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					c [i][j] = nextInt();
				}
			}
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					f [i][j] = nextInt();
				}
			}
			
			int time [][][] = new int [n][m][4];
			boolean can [][][] = new boolean [n][m][4];
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					for (int k = 0; k < 4; k++) {
						can[i][j][k] = true;
						
						int ti = dr [k] + i;
						int tj = dc [k] + j;
						if (ti >= 0 && tj >= 0 && ti < n && tj < m) {
							
							int c1 = c[i][j];
							int f1 = f[i][j];
							
							int c2 = c[ti][tj];
							int f2 = f[ti][tj];
							
							int g1 = max (f[i][j], h);
							int g2 = max (f[ti][tj], h);
							
							if (intersect (f1, c1, f2, c2) < 50) {
								can [i][j][k] = false;
							} else if (intersect (g1, c1, g2, c2) >= 50) {
								time [i][j][k] = 0;
							} else {
								int level = min (c1, c2) - 50;
								time [i][j][k] = h - level;
							}
							
						} else {
							can[i][j][k] = false;
						}
					}
				}
			}
			
			// use bfs
			
			boolean d1 [][] = new boolean [n][m];
			
			LinkedList<State> q = new LinkedList<Solution.State>();
			d1 [0][0] = true;
			q.add(new State (0, 0, 0));
			
			while (!q.isEmpty()) {
				State cur = q.pollFirst();
				int row = cur.r;
				int column = cur.c;
				
				for (int k = 0; k < 4; k++) {
					int trow = dr[k] + row;
					int tcolumn = dc[k] + column;
					if (can[row][column][k] && time[row][column][k] == 0 && !d1[trow][tcolumn]) {
						d1[trow][tcolumn] = true;
						q.addLast(new State (trow, tcolumn, 0));
					}
				}
				
			}

			int result = 0;
			
			if (!d1[n - 1][m - 1]) {
				int dist [][] = new int [n][m];
				PriorityQueue<State> qu = new PriorityQueue<Solution.State>();
				
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						dist[i][j] = Integer.MAX_VALUE / 2;
						if (d1 [i][j]) {
							dist [i][j] = 0;
							qu.add(new State (i, j, 0));
						}
					}
				}
				
				while (!qu.isEmpty()) {
					State cur = qu.poll();
					int rr = cur.r;
					int cc = cur.c;
					for (int k = 0; k < 4; k++) {
						if (can[rr][cc][k]) {
							int tr = rr + dr [k];
							int tc = cc + dc [k];
							
							
							int add = 10;
							
							int tt = max (time[rr][cc][k], dist[rr][cc]);
							
							int hh = h - tt;
							if (hh - f[rr][cc] < 20) {
								add = 100;
							}
							
							if (dist[tr][tc] > tt + add) {
								qu.remove(new State (tr, tc, dist[tr][tc]));
								dist[tr][tc] = tt + add;
								qu.add(new State (tr, tc, dist[tr][tc]));
							}
						}
					}
				}
				
				result = dist [n - 1][m - 1];
				
			}
			
			
			double res = (double) result / 10.0;
			
			out.printf("Case #%d: %.7f\n", test, res);

		}
	}
	
	static final String fname = "";
	static long stime = 0;
	
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	
	private String nextToken () throws Exception {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(in.readLine());
		}
		return st.nextToken();
	}
	
	private int nextInt () throws Exception {
		return Integer.parseInt(nextToken());
	}
	
	private long nextLong () throws Exception {
		return Long.parseLong(nextToken());
	}
	
	private double nextDouble () throws Exception {
		return Double.parseDouble(nextToken());
	}
	
	@Override
	public void run() {
		try {
			Locale.setDefault(Locale.US);
			in = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			solve ();
		} catch (Exception e) {
			throw new RuntimeException(e);
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Thread(null, new Solution(), "", 1<<25).start();
	}

}