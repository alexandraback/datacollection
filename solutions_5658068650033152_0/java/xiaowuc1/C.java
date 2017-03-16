import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;
	static Semaphore processorSemaphore = new Semaphore(Runtime.getRuntime().availableProcessors());
	static Semaphore inputSemaphore = new Semaphore(1);
	static Semaphore outputSemaphore = new Semaphore(0);
	static String[] output;
	static int[] dx = new int[]{-1,1,0,0};
	static int[] dy = new int[]{0,0,-1,1};

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new FileReader("c.in"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("c.out")));
		final int MAX_CASES = readInt();
		output = new String[MAX_CASES];
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			processorSemaphore.acquire();
			inputSemaphore.acquire();
			new WorkThread(casenum).start();
		}
		for(int casenum = 1; casenum <= MAX_CASES; casenum++) {
			outputSemaphore.acquire();
		}
		for(String out: output) {
			pw.println(out);
		}
		pw.close();
	}

	static class WorkThread extends Thread {
		public int casenum;

		public WorkThread(int casenum) {
			super();
			this.casenum = casenum;
		}
		public void run() {


			int n = readInt();
			int m = readInt();
			int k = readInt();

			inputSemaphore.release();

			int ret = k;

			for(int mask = 0; mask < (1 << (m*n)); mask++) {
				if(Integer.bitCount(mask) >= ret) {
					continue;
				}
				boolean[][] grid = new boolean[n][m];
				int index = 0;
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < m; j++) {
						if((mask & (1<<index)) != 0) {
							grid[i][j] = true;
						}
						index++;
					}
				}
				boolean[][] reachable = new boolean[n][m];
				LinkedList<State> q = new LinkedList<State>();
				for(int i = 0; i < n; i++) {
					for(int j = 0; j < m; j++) {
						if(grid[i][j]) continue;
						if(i == 0 || j == 0 || i == n-1 || j == m-1) {
							reachable[i][j] = true;
							q.add(new State(i, j));
						}
					}
				}
				int numBlocked = n*m;
				while(!q.isEmpty()) {
					State curr = q.removeFirst();
					numBlocked--;
					for(int qqq = 0; qqq < dx.length; qqq++) {
						int nx = curr.x + dx[qqq];
						int ny = curr.y + dy[qqq];
						if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
							if(grid[nx][ny]) {
								continue;
							}
							if(!reachable[nx][ny]) {
								reachable[nx][ny] = true;
								q.add(new State(nx, ny));
							}
						}
					}
				}
				if(numBlocked >= k) {
					ret = Integer.bitCount(mask);
				}
			}

			output[casenum-1] =  String.format("Case #%d: %d", casenum, ret);

			outputSemaphore.release();
			processorSemaphore.release();
		}

		static class State {
			public int x,y;

			public State(int x, int y) {
				super();
				this.x = x;
				this.y = y;
			}

		}
	}



	public static int readInt() {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() {
		return Double.parseDouble(nextToken());
	}

	public static String nextToken() {
		while(st == null || !st.hasMoreTokens())	{
			try {
				if(!br.ready())	{
					pw.close();
					System.exit(0);
				}
				st = new StringTokenizer(br.readLine());
			}
			catch(IOException e) {
				System.err.println(e);
				System.exit(1);
			}
		}
		return st.nextToken();
	}

	public static String readLine()	{
		st = null;
		try {
			return br.readLine();
		}
		catch(IOException e) {
			System.err.println(e);
			System.exit(1);
			return null;
		}
	}

}
