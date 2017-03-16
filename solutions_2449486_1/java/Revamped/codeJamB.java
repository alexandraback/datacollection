import java.util.*;

public class codeJamB
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int testCase = sc.nextInt();
		for(int testNo = 1; testNo <=testCase; testNo++)
		{
			int row = sc.nextInt();
			int col = sc.nextInt();
			
			int[] rowMax = new int[row];
			int[] colMax = new int[col];
			int[][] lawn = new int[row][col];
			
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < col; j++)
				{
					int curr = sc.nextInt();
					if(curr > rowMax[i])
						rowMax[i] = curr;
					if(curr > colMax[j])
						colMax[j] = curr;
					lawn[i][j] = curr;
				}
			}
			
			boolean isPossible = true;
			
			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < col; j++)
				{
					if(lawn[i][j] < rowMax[i] && lawn[i][j] < colMax[j])
					{
						isPossible = false;
					}
				}
				if(!isPossible)
					break;
			}
			if(isPossible)
				System.out.println("Case #"+ testNo + ": YES");
			else
				System.out.println("Case #"+ testNo + ": NO");
		}
	}
}