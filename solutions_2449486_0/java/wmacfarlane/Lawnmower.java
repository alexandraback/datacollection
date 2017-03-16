import java.io.*;
import java.util.*;

class Lawnmower
{
	public static void main ( String [] args ) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("Lawnmower.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("Lawnmower.out")));
		int numTests = Integer.parseInt(br.readLine());
		String[] throwAway;
		int[][] field; // one-indexed
		int n, m;
		TESTS:
		for(int test = 1; test <= numTests; test++)
		{
			throwAway = br.readLine().split(" ");
			n = Integer.parseInt(throwAway[0]);
			m = Integer.parseInt(throwAway[1]);
			field = new int[n + 1][m + 1];
			for(int i = 1; i <= n; i++)
			{
				throwAway = br.readLine().split(" ");
				for(int j = 1; j <= m; j++)
				{
					field[i][j] = Integer.parseInt(throwAway[j - 1]);
				}
			} //scan complete
			/* begin algorithm */
			for(int row = 1; row <= n; row++)
			{
				for(int col = 1; col <= m; col++)
				{
					/* check this cell's row */
					int j;
					for(j = 1; j <= m; j++)
					{
						if(field[row][col] < field[row][j])
							break;
					}
					if( j != m + 1) /* row check was unsuccessful; check this cell's col */
					{
						for(int i = 1; i <= n; i++)
						{
							if(field[row][col] < field[i][col])
							{ // can't be done!
								out.println("Case #" + test + ": NO");
								continue TESTS;
							}
						}
					}
				}
			}
			out.println("Case #" + test + ": YES");
		}
		br.close();
		out.close();
	}
}