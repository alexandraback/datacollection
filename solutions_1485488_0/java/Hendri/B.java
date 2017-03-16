import java.util.*;
import java.io.*;

class Main
{
	BufferedReader input;
	StringTokenizer token;
	BufferedWriter out;

	class Node implements Comparable<Node>
	{
		double time;
		int row,col;
		boolean started;
		public Node(double t,int r,int c,boolean s)
		{
			time = t;
			row = r;
			col = c;
			started = s;
		}

		public int compareTo(Node that)
		{
			return (this.time - that.time) > 0.0 ? 1 : -1;
		}
	}

	void solve() throws IOException
	{
		input = new BufferedReader(new InputStreamReader(System.in));
		out = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = nextInt();
		for(int t = 1; t <= T; t++)
		{
			int H = nextInt();
			int N = nextInt();
			int M = nextInt();
			//System.out.println(H + " " + N + " " + M);
			int[][] C = new int[N][M];
			int[][] F = new int[N][M];
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)C[i][j] = nextInt();
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)F[i][j] = nextInt();
			PriorityQueue<Node> pq = new PriorityQueue<Node>();
			pq.add(new Node(0,0,0,false));
			double[][] opt = new double[N][M];
			for(double[] x: opt)Arrays.fill(x,999999);
			opt[0][0] = 0;
			int[] dr = {1,-1,0,0};
			int[] dc = {0,0,1,-1};
			while(!pq.isEmpty())
			{
				Node current = pq.poll();
				//System.out.println("?"+current.row + " " + current.col + " " + current.time);
				if(opt[current.row][current.col] > current.time)continue;
				if(current.row == N-1 && current.col == M-1)
				{
					System.out.printf("Case #%d: %.5f\n",t,current.time);
					break;
				}
				for(int i = 0; i < 4; i++)
				{
					int x = current.row + dr[i];
					int y = current.col + dc[i];
					if(x < 0 || x >= N || y < 0 || y >= M)continue;
					if(F[x][y] > C[current.row][current.col]-50)continue;
					double waterlevel = H - current.time*10;
					double hcur = F[current.row][current.col];
					double hgo = F[x][y];
					double cgo = C[x][y];
					double wait = 0;
					//System.out.println("!" + (1.0*(50 - (cgo-waterlevel)) / 10.0) + " " + 1.0*(50 - (cgo-hcur)) / 10.0 + " " + 1.0*(50 - (cgo-hgo)) / 10.0);
					wait = Math.max(wait, 1.0*(50 - (cgo-waterlevel)) / 10.0);
					wait = Math.max(wait, 1.0*(50 - (cgo-hcur)) / 10.0);
					wait = Math.max(wait, 1.0*(50 - (cgo-hgo)) / 10.0);
					int timeneed = (waterlevel - 10 * wait) - hcur >= 20 ? 1 : 10;
					if(!current.started && wait == 0)timeneed = 0;
					double nextcost = wait != 0.0 || current.started ? current.time + timeneed + wait : current.time;
					//System.out.println("from " + current.row + " " + current.col + " to " + x + " " + y + " " + nextcost);
					//System.out.println("opt " + opt[x][y]);
					if(opt[x][y] > nextcost)
					{
						opt[x][y] = nextcost;
						pq.add(new Node(nextcost,x,y,wait + timeneed > 0 ? true : current.started));
					}
				}
			}
		}
		out.flush();
	}

	int nextInt() throws IOException
	{
		if(token == null || !token.hasMoreTokens())
			token = new StringTokenizer(input.readLine());
		return Integer.parseInt(token.nextToken());
	}

	Long nextLong() throws IOException
	{
		if(token == null || !token.hasMoreTokens())
			token = new StringTokenizer(input.readLine());
		return Long.parseLong(token.nextToken());
	}

	String next() throws IOException
	{
		if(token == null || !token.hasMoreTokens())
			token = new StringTokenizer(input.readLine());
		return token.nextToken();
	}

	public static void main(String[] args) throws Exception
	{
		new Main().solve();
	}
}