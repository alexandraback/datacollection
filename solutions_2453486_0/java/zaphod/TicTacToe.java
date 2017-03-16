import java.io.*;
import java.util.Scanner;

public class TicTacToe
{

	public static void display(char[][] board)
	{
		for (int row = 0; row < 4; row++)
		{
			for (int col = 0; col < 4; col++)
				System.out.print(board[row][col]);
			System.out.println();
		}
	}

	public static String checkWinner(char[][] board)
	{
		// Check rows and count spaces
		int spaceCount = 0;
		for (int row = 0; row < 4; row++)
		{
			int xCount = 0;
			int oCount = 0;
			for (int col = 0; col < 4; col++)
				if (board[row][col] == 'X')
					xCount++;
				else if (board[row][col] == 'O')
					oCount++;
				else if (board[row][col] == 'T')
				{
					xCount++;
					oCount++;
				}
				else
					spaceCount++;
			if (xCount == 4)
				return "X won";
			else if (oCount == 4)
				return "O won";
		}
		// Check columns
		for (int col = 0; col < 4; col++)
		{
			int xCount = 0;
			int oCount = 0;
			for (int row = 0; row < 4; row++)
				if (board[row][col] == 'X')
					xCount++;
				else if (board[row][col] == 'O')
					oCount++;
				else if (board[row][col] == 'T')
				{
					xCount++;
					oCount++;
				}
			if (xCount == 4)
				return "X won";
			else if (oCount == 4)
				return "O won";
		}

		// Check diagonal \
		int xCount = 0;
		int oCount = 0;
		for (int row = 0, col = 0; row < 4; row++, col++)
		{
			if (board[row][col] == 'X')
				xCount++;
			else if (board[row][col] == 'O')
				oCount++;
			else if (board[row][col] == 'T')
			{
				xCount++;
				oCount++;
			}
		}
		if (xCount == 4)
			return "X won";
		else if (oCount == 4)
			return "O won";

		// Check diagonal /
		xCount = 0;
		oCount = 0;
		for (int row = 0, col = 3; row < 4; row++, col--)
		{
			if (board[row][col] == 'X')
				xCount++;
			else if (board[row][col] == 'O')
				oCount++;
			else if (board[row][col] == 'T')
			{
				xCount++;
				oCount++;
			}

		}
		if (xCount == 4)
			return "X won";
		else if (oCount == 4)
			return "O won";

		// No winner yet
		if (spaceCount == 0)
			return "Draw";
		else
			return "Game has not completed";

	}

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException
	{
		String fileName = "A-small0";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		in.nextLine(); // Clean up line
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			char[][] board = new char[4][4];
			for (int line = 0; line < 4; line++)
				board[line] = in.nextLine().toCharArray();

			// display(board);

			// Check for winner - Brute force
			String message = checkWinner(board);

			System.out.println("Case #" + caseNo + ": " + message);
			out.println("Case #" + caseNo + ": " + message);

			// Read in blank line between cases
			if (in.hasNext())
				in.nextLine();
		}
		in.close();
		out.close();

	}

}
