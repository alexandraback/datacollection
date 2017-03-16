import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class P3MinesweeperMaster
{
	private final int id;
	private final int rows;
	private final int cols;
	private final int mines;
	private State state;

	private enum State
	{
		FILL_ROWS,
		FILL_COLS
	}

	public P3MinesweeperMaster(int id, int rows, int cols, int mines)
	{
		this.id = id;
		this.rows = rows;
		this.cols = cols;
		this.mines = mines;
	}

	public void solve()
	{
		boolean possible = true;
		char[][] board = new char[rows][cols];

		// fill board with mines
		for(int y = 0; y < rows; y++)
		{
			for(int x = 0; x < cols; x++)
			{
				board[y][x] = '*';
			}
		}

		// number of fields without mines
		int a = (rows * cols) - mines;

		if(a == 1)
		{
			board[0][0] = '.';
		}
		else if(rows == 1)
		{
			// 1 row -> trivial
			for(int x = 0; x < cols - mines; x++)
			{
				board[0][x] = '.';
			}
		}
		else if(cols == 1)
		{
			// 1 col -> trivial
			for(int y = 0; y < rows - mines; y++)
			{
				board[y][0] = '.';
			}
		}
		else if(rows == 2)
		{
			// 2 rows -> trivial
			if(a % 2 != 0 || a <= 3)
			{
				possible = false;
			}
			else
			{
				for(int x = 0; x < cols - (mines / 2); x++)
				{
					board[0][x] = '.';
					board[1][x] = '.';
				}
			}
		}
		else if(cols == 2)
		{
			// 2 cols -> trivial
			if(a % 2 != 0 || a <= 3)
			{
				possible = false;
			}
			else
			{
				for(int y = 0; y < rows - (mines / 2); y++)
				{
					board[y][0] = '.';
					board[y][1] = '.';
				}
			}
		}
		else
		{
			// rows >= 3 and cols >= 3

			// trivial cases <= 3 x 3
			if(a <= 3 || a == 5 || a == 7)
			{
				possible = false;
			}
			else if(a == 4)
			{
				for(int y = 0; y < 2; y++)
				{
					for(int x = 0; x < 2; x++)
					{
						board[y][x] = '.';
					}
				}
			}
			else if(a == 6)
			{
				for(int y = 0; y < 3; y++)
				{
					for(int x = 0; x < 2; x++)
					{
						board[y][x] = '.';
					}
				}
			}
			else if(a == 8)
			{
				for(int y = 0; y < 3; y++)
				{
					for(int x = 0; x < 3; x++)
					{
						board[y][x] = '.';
					}
				}
				board[2][2] = '*';
			}
			else if(a == 9)
			{
				for(int y = 0; y < 3; y++)
				{
					for(int x = 0; x < 3; x++)
					{
						board[y][x] = '.';
					}
				}
			}
			else
			{
				state = State.FILL_ROWS;
				int n = 0;
				int y = 0;
				int x = 0;
				while(n < a)
				{
					if(state == State.FILL_ROWS)
					{
						board[y][x] = '.';
						x++;
						if(x >= 3)
						{
							x = 0;
							y++;
						}
						if(y >= rows)
						{
							y = 0;
							x = 3;
							state = State.FILL_COLS;
						}
						n++;
					}
					else
					{
						board[y][x] = '.';
						y++;
						if(y >= rows)
						{
							y = 0;
							x++;
						}
						n++;
					}
				}
				// fix single fields
				if(x == 1)
				{
					// steal one from previous row
					board[y][x] = '.';
					board[y - 1][2] = '*';
				}
				if(y == 1)
				{
					// steal one from previous column
					board[y][x] = '.';
					board[rows - 1][x - 1] = '*';
				}
			}
		}

		// always start on field (0,0)
		board[0][0] = 'c';

		System.out.println("Case #" + (id + 1) + ":");
		if(possible)
		{
			for(int y = 0; y < rows; y++)
			{
				for(int x = 0; x < cols; x++)
				{
					System.out.print(board[y][x]);
				}
				System.out.println("");
			}
		}
		else
		{
			System.out.println("Impossible");
		}
	}

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);

		int numberOfTestCases = in.nextInt();
		List<P3MinesweeperMaster> problemList = new ArrayList<P3MinesweeperMaster>();

		for(int i = 0; i < numberOfTestCases; i++)
		{
			int rows = in.nextInt();
			int cols = in.nextInt();
			int mines = in.nextInt();
			problemList.add(new P3MinesweeperMaster(i, rows, cols, mines));
		}

		for(P3MinesweeperMaster problem : problemList)
		{
			problem.solve();
		}
	}
}
