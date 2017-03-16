import java.util.*;
import java.io.*;

class Event implements Comparable<Event>
{
	public int t;
	public int x, y;
	
	public Event(int t, int x, int y)
	{
		this.t = t;
		this.x = x;
		this.y = y;
	}
	
	@Override
	public int compareTo(Event arg0) {
		return t - arg0.t;
	}
	
}

public class ProblemB {

	static final int dirx[] = {0, 1, 0, -1};
	static final int diry[] = {1, 0, -1, 0};
	
	static int minPassableTime(int h, int f1, int c1, int f2, int c2)
	{
		if (!passable(0, f1, c1, f2, c2))
			return Integer.MAX_VALUE;
		if (passable(h, f1, c1, f2, c2))
			return 0;
		return h - (c2 - 50);
	}
	
	static boolean passable(int h, int f1, int c1, int f2, int c2)
	{
		if (c2 - f2 < 50)
			return false;
		if (c2 - h < 50)
			return false;
		if (c2 - f1 < 50)
			return false;
		if (c1 - f2 < 50)
			return false;
		return true;
	}
	
	static void reachInitial(int x, int y, int h, int[][] floor, int[][] ceil, boolean[][] initial)
	{
		initial[x][y] = true;
		for (int d=0; d<4; d++)
		{
			int x2 = x + dirx[d];
			int y2 = y + diry[d];
			if (passable(h, floor[x][y], ceil[x][y], floor[x2][y2], ceil[x2][y2]) && !initial[x2][y2])
				reachInitial(x2, y2, h, floor, ceil, initial);
		}
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner cin = new Scanner(new File("B.in"));
		PrintStream cout = new PrintStream("B.out");
		int caseN = cin.nextInt();
		for (int caseI=1; caseI <= caseN; caseI++)
		{
			int h = cin.nextInt();
			int n = cin.nextInt();
			int m = cin.nextInt();
			int[][] ceil = new int[n+2][m+2];
			int[][] floor = new int[n+2][m+2];
			for (int i=1; i<=n; i++)
				for (int j=1; j<=m; j++)
					ceil[i][j] = cin.nextInt();
			for (int i=1; i<=n; i++)
				for (int j=1; j<=m; j++)
					floor[i][j] = cin.nextInt();
			
			boolean[][] initial = new boolean[n+2][m+2];
			reachInitial(1, 1, h, floor, ceil, initial);
			
			boolean[][] flag = new boolean[n+2][m+2];
			int[][] reachtime = new int[n+2][m+2];
			for (int i=0; i<reachtime.length; i++)
				Arrays.fill(reachtime[i], Integer.MAX_VALUE);
			PriorityQueue<Event> queue = new PriorityQueue<Event>();
			for (int i=1; i<=n; i++)
				for (int j=1; j<=m; j++)
					if (initial[i][j])
						queue.add(new Event(0, i, j));
			while (queue.size() != 0)
			{
				Event cur = queue.poll();
				if (flag[cur.x][cur.y])
					continue;
				reachtime[cur.x][cur.y] = cur.t;
				flag[cur.x][cur.y] = true;
				for (int d=0; d<4; d++)
				{
					int x = cur.x + dirx[d];
					int y = cur.y + diry[d];
					if (flag[x][y])
						continue;
					int mint = minPassableTime(h, floor[cur.x][cur.y], ceil[cur.x][cur.y], floor[x][y], ceil[x][y]);
					if (mint != Integer.MAX_VALUE )
					{
						int t = Math.max(cur.t, mint);
						if (h - t - floor[cur.x][cur.y] >= 20)
							t += 10;
						else
							t += 100;
						queue.add(new Event(t, x, y));
					}				
				}
			}
			cout.println("Case #" + caseI + ": " + (0.1 * reachtime[n][m]));
		}
	}

}
