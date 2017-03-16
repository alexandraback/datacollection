import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class B {
	
	static int H;
	static int N;
	static int M;
	static int[][] ceiling;
	static int[][] floor;
	static boolean[][] reachable;
	static double ans;
	static double[][] dp;
	static Queue<Pair> queue;
	
	public static class Pair {
		public int r;
		public int c;
		
		public Pair(int r, int c) {
			this.r = r;
			this.c = c;
		}

		@Override
		public boolean equals(Object o) {
			if (o == null)
				return false;
			if (!(o instanceof Pair))
				return false;
			
			Pair p = (Pair) o;
			if (this.r == p.r && this.c == p.c)
				return true;
			else
				return false;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		
		int T = Integer.parseInt(in.readLine());
		for (int k = 0; k < T; ++ k) {
			String[] input = in.readLine().split(" ");
			
			H = Integer.parseInt(input[0]);
			N = Integer.parseInt(input[1]);
			M = Integer.parseInt(input[2]);
			
			ceiling = new int[N][M];
			for (int i = 0; i < N; ++ i) {
				input = in.readLine().split(" ");
				for (int j = 0; j < M; ++ j) {
					ceiling[i][j] = Integer.parseInt(input[j]);
				}
			}
			
			floor = new int[N][M];
			for (int i = 0; i < N; ++ i) {
				input = in.readLine().split(" ");
				for (int j = 0; j < M; ++ j) {
					floor[i][j] = Integer.parseInt(input[j]);
				}
			}
			
			reachable = new boolean[N][M];
			
			dfsReachable(0, 0);
			
			ans = 100000;
			for (int i = 0; i < N; ++ i) {
				for (int j = 0; j < M; ++ j) {
					System.out.println(i + " " + j);
					if (reachable[i][j]) {
						solveAt(i, j);
					}
				}
			}
			out.println("Case #" + (k + 1) + ": " + ans);
		}
		
		in.close();
		out.close();
	}
	
	private static void dfsReachable(int i, int j) {
		if (reachable[i][j])
			return;
		
		reachable[i][j] = true;
		
		if (i - 1 >= 0 && H + 50 <= ceiling[i - 1][j] && floor[i][j] + 50 <= ceiling[i - 1][j] && floor[i - 1][j] + 50 <= ceiling[i - 1][j] && floor[i - 1][j] + 50 <= ceiling[i][j]) {
			dfsReachable(i - 1, j);
		}
		
		if (i + 1 < N && H + 50 <= ceiling[i + 1][j] && floor[i][j] + 50 <= ceiling[i + 1][j] && floor[i + 1][j] + 50 <= ceiling[i + 1][j] && floor[i + 1][j] + 50 <= ceiling[i][j]) {
			dfsReachable(i + 1, j);
		}
		
		if (j - 1 >= 0 && H + 50 <= ceiling[i][j - 1] && floor[i][j] + 50 <= ceiling[i][j - 1] && floor[i][j - 1] + 50 <= ceiling[i][j - 1] && floor[i][j - 1] + 50 <= ceiling[i][j]) {
			dfsReachable(i, j - 1);
		}
		
		if (j + 1 < M && H + 50 <= ceiling[i][j + 1] && floor[i][j] + 50 <= ceiling[i][j + 1] && floor[i][j + 1] + 50 <= ceiling[i][j + 1] && floor[i][j + 1] + 50 <= ceiling[i][j]) {
			dfsReachable(i, j + 1);
		}
		
	}
	
	private static void solveAt(int x, int y) {
		dp = new double[N][M];
		
		for (int i = 0; i < N; ++ i) {
			for (int j = 0; j < M; ++ j) {
				dp[i][j] = 100000;
			}
		}
		
		dp[x][y] = 0;
		
		queue = new LinkedList<B.Pair>();
		
		queue.offer(new Pair(x, y));
		
		while (!queue.isEmpty()) {
			int i = queue.peek().r;
			int j = queue.poll().c;
			double time;
			
			if (i - 1 >= 0 && floor[i][j] + 50 <= ceiling[i - 1][j] && floor[i - 1][j] + 50 <= ceiling[i - 1][j] && floor[i - 1][j] + 50 <= ceiling[i][j]) {
				if (H + 50 - dp[i][j] * 10 <= ceiling[i - 1][j]) {
					if (H - dp[i][j] * 10 >= floor[i][j] + 20) {
						time = 1;
					}
					else {
						time = 10;
					}
					if (dp[i - 1][j] > dp[i][j] + time) {
						dp[i - 1][j] = dp[i][j] + time; 
						if (!queue.contains(new Pair(i - 1, j))) {
							queue.offer(new Pair(i - 1, j));
						}
					}
				}
				else {
					time = ((H + 50 - dp[i][j] * 10) - ceiling[i - 1][j]) / 10;
					if (H - (dp[i][j] + time) * 10 >= floor[i][j] + 20) {
						time += 1;
					}
					else {
						time += 10;
					}
					if (dp[i - 1][j] > dp[i][j] + time) {
						dp[i - 1][j] = dp[i][j] + time; 
						if (!queue.contains(new Pair(i - 1, j))) {
							queue.offer(new Pair(i - 1, j));
						}
					}
				}
			}
			
			if (i + 1 < N && floor[i][j] + 50 <= ceiling[i + 1][j] && floor[i + 1][j] + 50 <= ceiling[i + 1][j] && floor[i + 1][j] + 50 <= ceiling[i][j]) {
				if (H + 50 - dp[i][j] * 10 <= ceiling[i + 1][j]) {
					if (H - dp[i][j] * 10 >= floor[i][j] + 20) {
						time = 1;
					}
					else {
						time = 10;
					}
					if (dp[i + 1][j] > dp[i][j] + time) {
						dp[i + 1][j] = dp[i][j] + time; 
						if (!queue.contains(new Pair(i + 1, j))) {
							queue.offer(new Pair(i + 1, j));
						}
					}
				}
				else {
					time = ((H + 50 - dp[i][j] * 10) - ceiling[i + 1][j]) / 10;
					if (H - (dp[i][j] + time) * 10 >= floor[i][j] + 20) {
						time += 1;
					}
					else {
						time += 10;
					}
					if (dp[i + 1][j] > dp[i][j] + time) {
						dp[i + 1][j] = dp[i][j] + time; 
						if (!queue.contains(new Pair(i + 1, j))) {
							queue.offer(new Pair(i + 1, j));
						}
					}
				}
			}
			
			if (j - 1 >= 0 && floor[i][j] + 50 <= ceiling[i][j - 1] && floor[i][j - 1] + 50 <= ceiling[i][j - 1] && floor[i][j - 1] + 50 <= ceiling[i][j]) {
				if (H + 50 - dp[i][j] * 10 <= ceiling[i][j - 1]) {
					if (H - dp[i][j] * 10 >= floor[i][j] + 20) {
						time = 1;
					}
					else {
						time = 10;
					}
					if (dp[i][j - 1] > dp[i][j] + time) {
						dp[i][j - 1] = dp[i][j] + time;
						if (!queue.contains(new Pair(i, j - 1))) {
							queue.offer(new Pair(i, j - 1));
						}
					}
					
				}
				else {
					time = ((H + 50 - dp[i][j] * 10) - ceiling[i][j - 1]) / 10;
					if (H - (dp[i][j] + time) * 10 >= floor[i][j] + 20) {
						time += 1;
					}
					else {
						time += 10;
					}
					if (dp[i][j - 1] > dp[i][j] + time) {
						dp[i][j - 1] = dp[i][j] + time;
						if (!queue.contains(new Pair(i, j - 1))) {
							queue.offer(new Pair(i, j - 1));
						}
					}
				}
			}
			
			if (j + 1 < M && floor[i][j] + 50 <= ceiling[i][j + 1] && floor[i][j + 1] + 50 <= ceiling[i][j + 1] && floor[i][j + 1] + 50 <= ceiling[i][j]) {
				if (H + 50 - dp[i][j] * 10 <= ceiling[i][j + 1]) {
					if (H - dp[i][j] * 10 >= floor[i][j] + 20) {
						time = 1;
					}
					else {
						time = 10;
					}
					if (dp[i][j + 1] > dp[i][j] + time) {
						dp[i][j + 1] = dp[i][j] + time; 
						if (!queue.contains(new Pair(i, j + 1))) {
							queue.offer(new Pair(i, j + 1));
						}
					}
				}
				else {
					time = ((H + 50 - dp[i][j] * 10) - ceiling[i][j + 1]) / 10;
					if (H - (dp[i][j] + time) * 10 >= floor[i][j] + 20) {
						time += 1;
					}
					else {
						time += 10;
					}
					if (dp[i][j + 1] > dp[i][j] + time) {
						dp[i][j + 1] = dp[i][j] + time; 
						if (!queue.contains(new Pair(i, j + 1))) {
							queue.offer(new Pair(i, j + 1));
						}
					}
				}
			}
			
		}
		
		if (ans > dp[N - 1][M - 1]) {
			ans = dp[N - 1][M - 1];
		}
		
	}
	
}
