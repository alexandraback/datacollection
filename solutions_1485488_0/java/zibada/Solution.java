import java.io.*;
import java.util.*;

public class Solution implements Runnable
{
	BufferedReader in;
	StringTokenizer tokenizer;
	PrintWriter out;
	
	private void solve() throws Exception
	{
		int tests = Integer.parseInt(in.readLine());
		for (int test = 0; test < tests; test++)
		{
			out.printf("Case #%d: %.1f\n", test + 1, solveTest());
		}
	}
	
	int n, m, H;
	int[][] floor;
	int[][] ceil;
	int[][][] mem;
	int[][] dist;
	
	boolean[][] reachable;
	int[] dr = new int[]{-1, 0, 1, 0};
	int[] dc = new int[]{0, -1, 0, 1};

	double solveTest() throws Exception
	{
		H = nextInt();
		n = nextInt();
		m = nextInt();
		floor = new int[n][m];
		ceil = new int[n][m];
		reachable = new boolean[n][m];
		dist = new int[n][m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				ceil[i][j] = nextInt();
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				floor[i][j] = nextInt();
			}
		}
		mem = new int[n][m][H + 1];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				dist[i][j] = -1;
				Arrays.fill(mem[i][j], -1);
			}
		}
		findReachablePoints(0, 0);
		findDists();
		int res = 1 << 30;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!reachable[i][j]) continue;
				res = Math.min(res, doit(i, j, H));
			}
		}
		return res / 10.0;
	}
	
	int doit(int r, int c, int h)
	{
		if (r == n - 1 && c == m - 1) return 0;
		if (h <= 0) return dist[r][c] * 100;
		if (mem[r][c][h] != -1) return mem[r][c][h];
		int res = 1 << 30;
		for (int i = 0; i < 4; i++)
		{
			int r2 = r + dr[i];
			int c2 = c + dc[i];
			if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) continue;
			int time = (h - floor[r][c]) >= 20 ? 10 : 100;
			if (canMove(r, c, r2, c2, h))
			{
				res = Math.min(res, time + doit(r2, c2, h - time));
			}
			else
			{
				int delay = h - (ceil[r2][c2] - 50);
				if (delay > 0 && canMove(r, c, r2, c2, h - delay))
				{
					time = (h - delay - floor[r][c]) >= 20 ? 10 : 100;
					res = Math.min(res, delay + time + doit(r2, c2, h - delay - time));
				}
			}
		}
		mem[r][c][h] = res;
		return res;
	}
	
	boolean canMove(int r, int c, int r2, int c2, int h)
	{
		if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) return false;
		int d = floor[r2][c2];
		int u = ceil[r2][c2];
		if (ceil[r][c] - d < 50) return false;
		if (u - d < 50) return false;
		if (u - h < 50) return false;
		if (u - floor[r][c] < 50) return false;
		return true;
	}

	void findReachablePoints(int r, int c)
	{
		reachable[r][c] = true;
		for (int i = 0; i < 4; i++)
		{
			int r2 = r + dr[i];
			int c2 = c + dc[i];
			if (!canMove(r, c, r + dr[i], c + dc[i], H)) continue;
			if (reachable[r2][c2]) continue;
			findReachablePoints(r2, c2);
		}
	}
	
	void findDists()
	{
		int[] qr = new int[n * m];
		int[] qc = new int[n * m];
		int qh = 0;
		int qt = 1;
		qr[0] = n - 1;
		qc[0] = m - 1;
		dist[n - 1][m - 1] = 0;
		for (; qh < qt; qh++)
		{
			int r = qr[qh];
			int c = qc[qh];
			for (int i = 0; i < 4; i++)
			{
				int r2 = r + dr[i];
				int c2 = c + dc[i];
				if (!canMove(r, c, r2, c2, 0)) continue;
				if (dist[r2][c2] != -1) continue;
				dist[r2][c2] = dist[r][c] + 1;
				qr[qt] = r2;
				qc[qt] = c2;
				qt++;
			}
		}
	}

	private int nextInt() throws Exception
	{
		return Integer.parseInt(next());
	}

	private String next() throws Exception
	{
		if (tokenizer == null || !tokenizer.hasMoreTokens())
		{
			String s = "";
			while (s.equals(""))
			{
				s = in.readLine();
			}
			tokenizer = new StringTokenizer(s);
		}
		return tokenizer.nextToken();
	}

	public void run()
	{
		try
		{
			solve();
		}
		catch (Exception ex)
		{
			throw new RuntimeException(ex);
		}
		finally
		{
			out.close();
		}
	}
	
	public Solution() throws IOException
	{
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
	}

	public static void main(String[] args) throws IOException
	{
		Locale.setDefault(Locale.US);
		new Thread(new Solution()).start();
	}
}
