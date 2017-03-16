import java.util.PriorityQueue;
import java.util.Scanner;


public class B_1C {

	private static int[] x = {-1, 1, 0, 0},
						 y = {0, 0, -1, 1};
	
	private static int n,m,k;
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tc = in.nextInt();
		
		for (int caseno = 1; caseno <= tc; caseno++)
		{
			n = in.nextInt();
			m = in.nextInt();
			k = in.nextInt();
			
			//ensure n >= m
			if (n < m)
			{
				int temp = m;
				m = n;
				n = temp;
			}
			
			boolean[][] board = new boolean[n][m];
			int count = 1;
			board[n/2][m/2] = true;
			PriorityQueue<Tuple> q = new PriorityQueue<Tuple>();
			q.add(new Tuple(n/2,m/2));
			
			queueloop: while (!q.isEmpty())
			{
				Tuple t = q.poll();
				for (int i = 0; i < 4; i++)
				{
					int r = t.r + x[i],
						c = t.c + y[i];
					if (r >= 0 && r < n && c >= 0 && c < m)
					{
						if (!board[r][c])
						{
							board[r][c] = true;
							count++;
							
							if (count == k)
							{
								break queueloop;
							}
							else
							{
								q.add(new Tuple(r,c));
							}
						}
					}
				}
			}
			
			int outers = 0;
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (board[i][j])
					{
						adjloop: for (int p = 0; p < 4; p++)
						{
							int r = i + x[p],
								c = j + y[p];
							if (r < 0 || r >= n || c < 0 || c >= m || !board[r][c])
							{
								outers++;
								break adjloop;
							}
						}
					}
				}
			}
			
			System.out.println("Case #" + caseno + ": " + outers);
		}
	}
	
	private static class Tuple implements Comparable<Tuple>
	{
		int r, c;
		public Tuple(int r, int c)
		{
			this.r = r;
			this.c = c;
		}
		
		public boolean equals (Object o)
		{
			if (o instanceof Tuple)
			{
				Tuple t = (Tuple) o;
				return r == t.r && c == t.c;
			}
			return false;
		}
		
		public int hashCode()
		{
			return r + (c >> 10);
		}

		@Override
		public int compareTo(Tuple o) {
			int d = Math.abs(r - n/2) + Math.abs(c - m/2);
			int od = Math.abs(o.r - n/2) + Math.abs(o.c - m/2);
			
			return d - od;
		}
	}

}
