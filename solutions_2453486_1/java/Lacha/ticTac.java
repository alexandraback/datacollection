import java.util.*;
	
public class ticTac {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int numCase = in.nextInt();
		for (int testCase = 0; testCase < numCase; testCase++)
		{
			int[][] board = new int[4][4];	// i is row, j is column, 2 is 'X', -2 is 'O', 100 is 'T', 0 is '.'
			for (int i = 0; i < 4; i++)
			{
				String readLine = in.next();
				for (int j = 0; j < 4; j++)
				{
					if (readLine.charAt(j) == 'X')
						board[i][j] = 2;
					else if (readLine.charAt(j) == 'O')
						board[i][j] = -2;
					else if (readLine.charAt(j) == 'T')
						board[i][j] = 100;
					else board[i][j] = 0;
				}
			}
			int[] row = new int[4];
			int[] column = new int[4];
			int[] diagonal = new int[2];
			boolean filled = true; 
			//add Row, column and diagonal
			boolean gameOver = false;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (board[i][j] == 0)
						filled = false;
					row[i] += board[i][j];
					column[j] += board[i][j];
					if (i == j)
					{
						diagonal[0] += board[i][j];
					}
					if (i+j == 3)
					{
						diagonal[1] += board[i][j];
					}
				}
			}
			//test Row, column
			for (int i = 0; i < 4; i++)
			{
				if ((row[i] == 8 || column[i] == 8 || row[i] == 106 || column[i] == 106) && !gameOver)
				{
					System.out.println("Case #" + (testCase+1)+": X won");
					gameOver = true;
				}
				else if ((row[i] == -8 || column[i] == -8 || row[i] == 94 || column[i] == 94) && !gameOver)
				{
					System.out.println("Case #" + (testCase+1)+": O won");
					gameOver = true;
				}
			}
			for (int i = 0; i < 2; i++)
			{
				if ((diagonal[i] == 8 || diagonal[i] == 106) && !gameOver)
				{
					System.out.println("Case #" + (testCase+1)+": X won");
					gameOver = true;
				}
				else if ((diagonal[i] == -8 || diagonal[i] == 94) && !gameOver)
				{
					System.out.println("Case #" + (testCase+1)+": O won");
					gameOver = true;
				}
			}
			if (filled && !gameOver)
			{
				System.out.println("Case #" + (testCase+1)+": Draw");
			}
			else if (!filled && !gameOver){
				System.out.println("Case #" + (testCase+1)+": Game has not completed");
			}
		}
	}
}
