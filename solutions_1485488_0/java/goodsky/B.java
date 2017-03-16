import java.util.*;
public class B {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t = 1; t <= T; ++t)
		{
			int H = in.nextInt();
			int N = in.nextInt();
			int M = in.nextInt();
			
			int[][] gridc = new int[M][N];
			int[][] gridf = new int[M][N];
			
			for (int n = 0; n < N; ++n)
				for (int m = 0; m < M; ++m)
					gridc[m][n] = in.nextInt();
			for (int n = 0; n < N; ++n)
				for (int m = 0; m < M; ++m)
					gridf[m][n] = in.nextInt();
			
			PriorityQueue<State> next = new PriorityQueue<State>();
			ArrayDeque<State> bfs = new ArrayDeque<State>();
			boolean[][] visit = new boolean[M][N];
			
			// first bfs and find all the positions that can be visited at second 0
			bfs.add(new State(0.0, 0, 0));
			visit[0][0] = true;
			
			int[] dx = {-1, 0, 1, 0};
			int[] dy = {0, -1, 0, 1};
			while (!bfs.isEmpty())
			{
				State cur = bfs.remove();
				next.add(cur);
				for (int i = 0; i < 4; ++i)
				{
					int newx = cur.x + dx[i];
					int newy = cur.y + dy[i];
					// check out of bounds
					if (cur.x + dx[i] >= 0 && cur.x + dx[i] < M && cur.y + dy[i] >= 0 && cur.y + dy[i] < N)
					{
						// make sure it is movable
						if (gridc[newx][newy] - H >= 50 && gridc[newx][newy] - gridf[newx][newy] >= 50 && !visit[newx][newy] && gridc[newx][newy] - gridf[cur.x][cur.y] >= 50 && gridc[cur.x][cur.y] - gridf[newx][newy] >= 50)
						{
							visit[newx][newy] = true;
							bfs.add(new State(0.0, newx, newy));
						}
					}
				}
			}
			
			// Now do a modified Dijkstras to check each of the fastest paths through the cave
			visit = new boolean[M][N];
			double ans = 0.0;
			while (!next.isEmpty())
			{
				State cur = next.remove();
				if (visit[cur.x][cur.y]) continue;
				
				visit[cur.x][cur.y] = true;
				
				// end case
				if (cur.x == M-1 && cur.y == N-1)
				{
					ans = cur.time;
					break;
				}
				
				// check surroundings
				for (int i = 0; i < 4; ++i)
				{
					int newx = cur.x + dx[i];
					int newy = cur.y + dy[i];
					// check out of bounds
					if (cur.x + dx[i] >= 0 && cur.x + dx[i] < M && cur.y + dy[i] >= 0 && cur.y + dy[i] < N)
					{
						// make sure it is movable
						if (!visit[newx][newy] && gridc[newx][newy] - gridf[newx][newy] >= 50 && gridc[newx][newy] - gridf[cur.x][cur.y] >= 50 && gridc[cur.x][cur.y] - gridf[newx][newy] >= 50)
						{
							// calculate time to move to it
							double newtime = cur.time;
							double waittime = (H-cur.time*10 - gridc[newx][newy] + 50)/10.0;
							if (waittime < 0.0) waittime = 0.0;
							
							if ((H-(cur.time+waittime)*10) - gridf[cur.x][cur.y] >= 20) newtime += 1.0;
							else newtime += 10.0;
							
							newtime += waittime;

							next.add(new State(newtime, newx, newy));
						}
					}
				}
			}
			
			System.out.printf("Case #%d: %.1f\n", t, ans);
		}
	}

	static class State implements Comparable<State> {
		double time;
		int x,y;
		
		public State(double t, int xx, int yy)
		{
			time = t;
			x = xx;
			y = yy;
		}

		public int compareTo(State o) {
			return o.time - time < 0 ? 1 : -1;
		}
	}
}

/*
5
200 1 2
250 233
180 100
100 3 3
500 500 500
500 500 600
500 140 1000
10 10 10
10 10 490
10 10 10
100 3 3
500 100 500
100 100 500
500 500 500
10 10 10
10 10 10
10 10 10
100 2 2
1000 1000
1000 1000
100 900
900 100
1000 1 5
1050 100 1000 1000 1000
0 0 0 0 0
*/
