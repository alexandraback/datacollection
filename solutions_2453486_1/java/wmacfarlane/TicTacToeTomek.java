import java.io.*;
import java.util.*;

class TicTacToeTomek
{
	public static void main ( String [] args ) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("TTTT.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("TTTT.out")));
		int numTests = Integer.parseInt(br.readLine());
		String throwAway;
		char[][] board = new char[5][5]; //doesn't matter that we're not declaring a new board each time
		TESTS:
		for(int test = 1; test <= numTests; test++)
		{
			for(int i = 1; i < 5; i++)
			{
				throwAway = br.readLine();
				for(int j = 1 ; j < 5; j++)
				{
					board[i][j] = (throwAway.substring(j - 1, j)).charAt(0);
				}
			}
			/* done scanning */
			/* algorithm */
			boolean isX; // true if this is an X line, false if it's an O line

			// check rows
			for(int i = 1; i < 5; i++)
			{
				if(board[i][1] == 'T')
				{
					if(board[i][2] == 'X')
						isX = true;
					else if (board[i][2] == 'O')
						isX = false;
					else // == '.'
						continue;
				}
				else if(board[i][1] == 'X')
					isX = true;
				else if(board[i][1] == 'O')
					isX = false;
				else // == '.'
					continue; //next row please
				for(int j = 2; j < 5; j++) //already checked first column
				{
					if      ( isX && (j != 4) )
					{
						if((board[i][j] != 'X') && (board[i][j] != 'T'))
							break;
					}
					else if ( !isX && (j != 4) )
					{
						if((board[i][j] != 'O') && (board[i][j] != 'T'))
							break;
					}
					else if (isX)
					{
						if((board[i][j] == 'X') || (board[i][j] == 'T'))
						{
							out.println("Case #" + test + ": X won");
							br.readLine();
							continue TESTS;
						}
					}
					else //if !isX
					{
						if((board[i][j] == 'O') || (board[i][j] == 'T'))
						{
							out.println("Case #" + test + ": O won");
							br.readLine();
							continue TESTS;
						}
					}
				}
			}
			// check cols
			for(int j = 1; j < 5; j++)
			{
				if(board[1][j] == 'T')
				{
					if(board[2][j] == 'X')
						isX = true;
					else if (board[2][j] == 'O')
						isX = false;
					else // == '.'
						continue;
				}
				else if(board[1][j] == 'X')
					isX = true;
				else if(board[1][j] == 'O')
					isX = false;
				else // == '.'
					continue;
				for(int i = 2; i < 5; i++)
				{
					if      ( isX && (i != 4) )
					{
						if((board[i][j] != 'X') && (board[i][j] != 'T'))
							break;
					}
					else if ( !isX && (i != 4) )
					{
						if((board[i][j] != 'O') && (board[i][j] != 'T'))
							break;
					}
					else if (isX)
					{
						if((board[i][j] == 'X') || (board[i][j] == 'T'))
						{
							out.println("Case #" + test + ": X won");
							br.readLine();
							continue TESTS;
						}
					}
					else //if !isX
					{
						if((board[i][j] == 'O') || (board[i][j] == 'T'))
						{
							out.println("Case #" + test + ": O won");
							br.readLine();
							continue TESTS;
						}
					}
				}
				
				
			}
			// check diags
			/* top left, bottom right diag */
			if(
				( (board[1][1] == 'X') || (board[1][1] == 'T') ) &&
				( (board[2][2] == 'X') || (board[2][2] == 'T') ) &&
				( (board[3][3] == 'X') || (board[3][3] == 'T') ) &&
				( (board[4][4] == 'X') || (board[4][4] == 'T') )     )
			{
				out.println("Case #" + test + ": X won");
				br.readLine();
				continue TESTS;
			}
			else if(
				( (board[1][1] == 'O') || (board[1][1] == 'T') ) &&
				( (board[2][2] == 'O') || (board[2][2] == 'T') ) &&
				( (board[3][3] == 'O') || (board[3][3] == 'T') ) &&
				( (board[4][4] == 'O') || (board[4][4] == 'T') )     )
			{
				out.println("Case #" + test + ": O won");
				br.readLine();
				continue TESTS;
			}
			/* top right, bottom left diag */
			if(
				( (board[1][4] == 'X') || (board[1][4] == 'T') ) &&
				( (board[2][3] == 'X') || (board[2][3] == 'T') ) &&
				( (board[3][2] == 'X') || (board[3][2] == 'T') ) &&
				( (board[4][1] == 'X') || (board[4][1] == 'T') )     )
			{
				out.println("Case #" + test + ": X won");
				br.readLine();
				continue TESTS;
			}
			if(
				( (board[1][4] == 'O') || (board[1][4] == 'T') ) &&
				( (board[2][3] == 'O') || (board[2][3] == 'T') ) &&
				( (board[3][2] == 'O') || (board[3][2] == 'T') ) &&
				( (board[4][1] == 'O') || (board[4][1] == 'T') )     )
			{
				out.println("Case #" + test + ": O won");
				br.readLine();
				continue TESTS;
			}
			/* check to see if game unfinished */
			for(int i = 1; i < 5; i++)
			{
				for(int j = 1; j < 5; j++)
				{
					if(board[i][j] == '.')
					{
						out.println("Case #" + test + ": Game has not completed");
						br.readLine();
						continue TESTS;
					}
				}	
			}
			/* game is a draw! */
			out.println("Case #" + test + ": Draw");
			br.readLine(); // should be a '\n'
			
			/* end algorithm */
		}
		
		
		br.close();
		out.close();
	}
}