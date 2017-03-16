import java.util.*;

public class lawnmower {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int numCase = in.nextInt();
		for (int testCase = 0; testCase < numCase; testCase++)
		{
			int N = in.nextInt();	// row
			int M = in.nextInt();	// column
			int[][] lawn = new int[N][M];
			int[][] lawnRowCopy = new int[N][M];
			int[][] lawnColumnCopy = new int[M][N];
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					int input = in.nextInt();
					lawn[i][j] = input;
					lawnRowCopy[i][j] = input;
					lawnColumnCopy[j][i] = input;
				}
			}
			for (int i = 0; i < N; i++)
				Arrays.sort(lawnRowCopy[i]);
			for (int j = 0; j < M; j++)
				Arrays.sort(lawnColumnCopy[j]);
			boolean can = true;
			for (int i = 0; i < N && can; i++)
			{
				for (int j = 0; j < M && can; j++)
				{
					if (lawn[i][j] < lawnRowCopy[i][M-1] && lawn[i][j] < lawnColumnCopy[j][N-1])
						can = false;
				}
			}
			if (can)
				System.out.println("Case #" + (testCase+1)+": YES");
			else System.out.println("Case #" + (testCase+1)+": NO");
		}
	}
	
	
}
