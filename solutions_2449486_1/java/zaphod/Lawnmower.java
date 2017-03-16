import java.io.*;
import java.util.Scanner;

public class Lawnmower
{

	public static int[][] grass;
	public static boolean check(int chRow, int chCol)
	{
		int value = grass[chRow][chCol];
		if (value == 100)
			return true;
		boolean check = true;
		for (int row = 0; row < grass.length; row++)
		{
			if (grass[row][chCol] > value)
				check = false;
		}
		if (check)
			return true;
		for (int col = 0; col < grass[0].length; col++)
		{
			if (grass[chRow][col] > value)
				return false;
		}	
		
		return true;
	}
	
	public static boolean check()
	{
// Check inner grass
		for (int row = 0; row < grass.length; row++)
			for (int col = 0; col < grass[0].length; col++)
				if (!check(row, col))
				{
					 return false;
				    
				}
		return true;
	}
	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "B-large";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			int N = in.nextInt();
			int M = in.nextInt();
			grass = new int[N][M];
			for (int row = 0; row < N; row++)
				for (int col = 0; col < M; col++)
					grass[row][col] = in.nextInt();
			boolean possible = check();

			if (possible)
			{
				System.out.println("Case #" + caseNo + ": YES");
				out.println("Case #" + caseNo + ": YES");
			}
			else
			{
				System.out.println("Case #" + caseNo + ": NO");
				out.println("Case #" + caseNo + ": NO");
			}

		}
		in.close();
		out.close();

	}

}
