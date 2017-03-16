import java.util.*;

class CodeJamB
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int tt = in.nextInt();
		int trial = 0;
		while(trial < tt)
		{
			boolean ret = true;
			int m = in.nextInt();
			int n = in.nextInt();
			int[][] grid = new int[m][n];
			int[] maxM = new int[m];
			int[] maxN = new int[n];
			for(int i=0; i<m; ++i)
			{
				for(int j=0; j<n; ++j)
				{
					int q = in.nextInt();
					grid[i][j] = q;
					if(q > maxM[i]) maxM[i] = q;
					if(q > maxN[j]) maxN[j] = q;
				}
			}
			
			for(int i=0; i<m; ++i)
			{
				for(int j=0; j<n; ++j)
				{
					int q = grid[i][j];
					if(q < maxM[i] && q < maxN[j])
					{
						//System.err.println("~~BAD at " + i + " " + j + " with maxes: " + maxM[i] + " " + maxN[j]);
						ret = false;
					}
				}
			}
			
			System.out.println("Case #" + ++trial + ": " + (ret?"YES":"NO"));
		}
	}
}