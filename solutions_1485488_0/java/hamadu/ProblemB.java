import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.concurrent.ArrayBlockingQueue;

public class ProblemB {
	
	static long INF = 1000000000000L;
	
	static class State implements Comparable<State> {
		int r;
		int c;
		int water;
		long time;
		@Override
		public int compareTo(State arg0) {
			return Long.signum(time - arg0.time);
		}
		
		State(int _r, int _c, int _w, long _t) {
			r = _r;
			c = _c;
			water = _w;
			time = _t;
		}
	}
	
	
	static class Stage {
		int s1;
		int s2;
		int id;
		Stage(int a, int b, int i) {
			s1 = a;
			s2 = b;
			id = i;
		}
	}
	
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	
	public static double solve(int h, int[][] ceil, int[][] floor) {
		int N = ceil.length;
		int M = ceil[0].length;
		
		Queue<State> q = new PriorityQueue<State>(1000000);
		q.add(new State(0, 0, h, 0));
		
		long[][][] dp = new long[N+1][M+1][1001];
		for (int i = 0 ; i <= N ; i++) {
			for (int j = 0 ; j <= M ; j++) {
				Arrays.fill(dp[i][j], INF);
			}
		}
		dp[0][0][h] = 0;
		
		
		Queue<Integer> qq = new ArrayBlockingQueue<Integer>(100000);
		qq.add(0);
		while (qq.size() >= 1) {
			int st = qq.poll();
			int nx = st % 100;
			int ny = st / 100;
			dp[0][0][h] = 0;
			int current_height = Math.max(floor[ny][nx], h);
			int current_floor = current_height;
			int current_ceil = ceil[ny][nx];
			for (int d = 0 ; d < 4 ; d++) {
				int tr = dy[d] + ny;
				int tc = dx[d] + nx;
				if (tr < 0 || tc < 0 || tr >= N || tc >= M) {
					continue;
				}
				int target_floor = Math.max(floor[tr][tc], h);
				int target_ceil = ceil[tr][tc];
				if (target_ceil - target_floor < 50) {
					continue;
				} else if (current_ceil - target_floor < 50) {
					continue;
				} else if (target_ceil - current_floor < 50) {
					continue;
				}
				if (dp[tr][tc][h] > 0) {
					dp[tr][tc][h] = 0;
					qq.add(tr * 100 + tc);
					q.add(new State(tr, tc, h, 0));
				}
			}
		}
		
		while (q.size() >= 1) {
			State s = q.poll();
			
			int current_height = Math.max(floor[s.r][s.c], s.water);
			int current_floor = floor[s.r][s.c];
			int current_ceil = ceil[s.r][s.c];
			
			
			for (int d = 0 ; d < 4 ; d++) {
				int tr = dy[d] + s.r;
				int tc = dx[d] + s.c;
				if (tr < 0 || tc < 0 || tr >= N || tc >= M) {
					continue;
				}
				
				int target_floor = floor[tr][tc];
				int target_ceil = ceil[tr][tc];
				if (target_ceil - target_floor < 50) {
					continue;
				} else if (current_ceil - target_floor < 50) {
					continue;
				} else if (target_ceil - current_floor < 50) {
					continue;
				}
				
				
				int move = 0;
				int diff = target_ceil - current_height;
				int water = s.water;
				if (diff < 50) {
					water -= 50 - diff;
					move += 50 - diff;
				}
				if (water <= 0) {
					water = 0;
				}
				int base_needtodec = 100;
				if (water - floor[s.r][s.c] >= 20) {
					base_needtodec = 10;
				}
				move += base_needtodec;
				
				int elptime = move;
				int willwater = s.water - move;
				if (willwater <= 0) {
					willwater = 0;
				}
				
				target_floor = Math.max(willwater, target_floor);
				if (target_ceil - target_floor < 50) {
					elptime += Math.abs((target_ceil - 50) - willwater);
					willwater = target_ceil - 50; 
				}
				
				long ttime = s.time + elptime;
				if (dp[tr][tc][willwater] > ttime) {
					dp[tr][tc][willwater] = ttime;
					q.add(new State(tr, tc, willwater, ttime));
				}
			}
		}
		
		long time = INF;
		for (int i = 0 ; i <= 1000 ; i++) {
			time = Math.min(time, dp[N-1][M-1][i]);
		}
		return time * 0.1d;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter w = new BufferedWriter(new FileWriter("./src/output.txt"));
		int T = Integer.valueOf(s.readLine());
		for (int t = 1 ; t <= T ; t++) {
			String[] data = s.readLine().split(" ");
			int h = Integer.valueOf(data[0]);
			int N = Integer.valueOf(data[1]);			
			int M = Integer.valueOf(data[2]);
			int[][] ceil = new int[N][M];
			int[][] floor = new int[N][M];

			for (int i = 0 ; i < N ; i++) {
				String[] line = s.readLine().split(" ");
				for (int j = 0 ; j < M ; j++) {
					ceil[i][j] = Integer.valueOf(line[j]);
				}
			}
			
			for (int i = 0 ; i < N ; i++) {
				String[] line = s.readLine().split(" ");
				for (int j = 0 ; j < M ; j++) {
					floor[i][j] = Integer.valueOf(line[j]);
				}
			}

			double d = solve(h, ceil, floor);
			w.write("Case #" + t + ": " + d);
			w.newLine();
		}
		w.flush();
		w.close();
	}
}