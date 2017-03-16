import java.util.*;
import java.io.*;

class Mines
{
	public static void main(String[] args) throws Exception
	{
		String file = "C-small-attempt3.in";
		Scanner in = new Scanner(new File(file));
		//BufferedReader in = new BufferedReader(new FileReader(file));
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		int testcase = in.nextInt();
		for (int test = 1; test <= testcase; ++test)
		{
			int M = in.nextInt();
			int N = in.nextInt();
			int mines = in.nextInt();
			char[][] grid = new char[M][N];
			for (int i = 0; i < M; ++i)
			{
				for (int j = 0; j < N; ++j)
				{
					grid[i][j] = '.';
				}
			}
			grid[0][0] = 'c';
			boolean check = arrange(grid,M,N,mines);
			if (check == false) out.format("Case #%d:\nImpossible\n", test);
			if (check == true) 
			{
				out.format("Case #%d:\n", test);
				for (int i = 0; i < M; ++i)
				{
					for (int j = 0; j < N; ++j)
					{
						out.print(grid[i][j]);
					}
					out.println();
				}
			}
		}
		out.close();
		in.close();
		
	}

	public static boolean arrange(char[][] grid, int M, int N, int mines)
	{
		if (M == 3 && N >= 3)
		{
			if (mines >= 3)
			{
				grid[0][N-1] = '*';
				grid[1][N-1] = '*';
				grid[2][N-1] = '*';
				return arrange(grid,M,N-1,mines-3);
			}
		}
		if (N == 3 && M >=3)
		{
			if (mines >= 3)
			{
				grid[M-1][0] ='*';
				grid[M-1][1] = '*';
				grid[M-1][2] = '*';
				return arrange(grid,M-1,N,mines-3);
			}
		}
		if (mines == 0 || M == 0 || N == 0) return true;
		if (M == 1 && N == 1)
		{
			if (mines == 0) return true;
			return false;
		}
		if (M == 1 && N > 1)
		{
			if (mines < N)
			{
				int m = mines;
				int i = N-1;
				while (m > 0)
				{
					grid[0][i] = '*';
					--i;
					--m;
				}
				return true;
			}
			return false;
		}
		if (M > 1 && N == 1)
		{
			if (mines < M)
			{
				int m = mines;
				int i = M-1;
				while (m > 0)
				{
					grid[i][0] = '*';
					--i;
					--m;
				}
				return true;
			}
			return false;
		}
		if (M == 2 && N == 2)
		{
			if (mines == 3) 
			{
				grid[0][1] = '*';
				grid[1][0] = '*';
				grid[1][1] = '*';
				return true;
			}
			return false;
		}
		if (M == 2 && N > 2)
		{
			if (mines == 1) return false;
			grid[0][N-1] = '*';
			grid[1][N-1] = '*';
			return arrange(grid,M,N-1,mines-2);
		}
		if (M > 2 && N == 2)
		{
			if (mines == 1) return false;
			grid[M-1][0] = '*';
			grid[M-1][1] = '*';
			return arrange(grid,M-1,N,mines-2);
		}
		int sider = M + N - 1;
		int sidehold = M + N - 5;
		int threshold = (M-2)*(N-2) - sidehold;
		if (mines >= sider)
		{
			for (int i = 0; i < N; ++i)
			{
				grid[M-1][i] = '*';
			}
			for (int i = 0; i < M; ++i)
			{
				grid[i][N-1] = '*';
			}
			return arrange(grid,M-1,N-1,mines-sider);
		}
		int remainder = mines;
		grid[M-1][N-1] = '*';
		--remainder;
		int i = N-2;
		while (i > 1 && remainder > 0)
		{
			grid[M-1][i] = '*';
			--remainder;
			--i;
		}
		int j = M-2;
		while(j > 1 && remainder > 0)
		{
			grid[j][N-1] = '*';
			--remainder;
			--j;
		}
		boolean one_side_filled = false;
		if (remainder >= 2)
		{
			grid[M-1][0] = '*';
			grid[M-1][1] = '*';
			remainder -= 2;
			one_side_filled = true;
		}
		if (remainder == 1 && threshold != 0)
		{
			grid[M-2][N-2] = '*';
			return true;
		} else if (remainder == 1 && threshold == 0)
		{ 
			if (one_side_filled == true) return false;
			boolean did_replaced = false;
			if (M == 3 && N != 3)
			{
				did_replaced = true;
			int toreplace = 0;
			while (grid[2][toreplace] == '.')
			{
				++toreplace;
			}
			grid[2][toreplace] = '.';
			grid[0][N-1] = '*';
			grid[1][N-1] = '*';
			}
			else if (N == 3 && M != 3)
			{
				did_replaced = true;
			int toreplace = 0;
			while (grid[toreplace][2] == '.')
			{
				++toreplace;
			}
			grid[toreplace][2] = '.';
			grid[M-1][0] = '*';
			grid[M-1][1] = '*';
			}
			return did_replaced;
		}
		return true;
	}
}