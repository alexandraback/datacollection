/*
 * 
 * To compile: javac <filename>.java
 * To run: java <filename> <input_file> > <output_file>
 * 
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class TicTacToeTomek
{
	public static final int SIZE = 4;

	public static final String X_WON = "X won";

	public static final String O_WON = "O won";

	public static final String DRAW = "Draw";

	public static final String NOT_COMPLETE = "Game has not completed";

	private static class Game
	{
		public char[][] board;

		public Game(char[][] board)
		{
			this.board = board;
		}

		private void print()
		{
			for (int j = 0; j < SIZE; j++)
				System.out.println(board[j]);
		}

		private boolean isFull()
		{
			for (int j = 0; j < SIZE; j++)
			{
				for (int k = 0; k < SIZE; k++)
				{
					if (board[j][k] == '.')
						return false;
				}
			}
			return true;
		}

		private boolean hasWon(char player)
		{
			int dia1Count = 0, dia2Count = 0;

			for (int j = 0; j < SIZE; j++)
			{
				int rowCount = 0, colCount = 0; // Since rows and cols are equal in number
				for (int k = 0; k < SIZE; k++)
				{
					if (board[j][k] == player || board[j][k] == 'T')
						rowCount++;

					if (board[k][j] == player || board[k][j] == 'T')
						colCount++;
				}

				if (rowCount == SIZE || colCount == SIZE)
					return true;

				if (board[j][j] == player || board[j][j] == 'T')
					dia1Count++;

				if (board[j][SIZE - 1 - j] == player || board[j][SIZE - 1 - j] == 'T')
					dia2Count++;

			}
			if (dia1Count == SIZE || dia2Count == SIZE)
				return true;
			return false;
		}

		public String getStatus()
		{
			if (hasWon('X'))
				return X_WON;
			if (hasWon('O'))
				return O_WON;
			return isFull() ? DRAW : NOT_COMPLETE;
		}

	}

	public static void main(String[] args)
	{
		if (args.length != 1)
		{
			System.err.println("Run it with 1 command line argument i.e. filename of input file");
		}
		File file = new File(args[0]);
		Scanner scan = null;
		try
		{
			scan = new Scanner(file);
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File not found");
			e.printStackTrace();
		}

		int T = scan.nextInt();

		for (int i = 0; i < T; i++)
		{
			char[][] board = new char[SIZE][SIZE];
			for (int j = 0; j < SIZE; j++)
			{
				board[j] = scan.next().toCharArray();
			}

			Game game = new Game(board);
			System.out.println("Case #" + (i + 1) + ": " + game.getStatus());
			// game.print();
		}
	}
}
