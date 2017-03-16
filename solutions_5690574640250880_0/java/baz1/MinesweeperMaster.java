import java.util.*;

public class MinesweeperMaster {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(), i = 0, R, C, M, free, j, k;
		while (i++ < T)
		{
			System.out.println("Case #" + i + ":");
			R = in.nextInt();
			C = in.nextInt();
			M = in.nextInt();
			free = R * C - M;
			if (free == 1)
			{
				String line = repeat('*', C - 1);
				System.out.println("c" + line);
				line += "*";
				for (j = 1; j < R; ++j)
					System.out.println(line);
				continue;
			}
			if ((R >= 3) && (C >= 3))
			{
				if ((free == 4) || (free == 6) || (free >= 8))
				{
					byte[][] board = new byte[C][R];
					board[0][0] = 2;
					board[0][1] = 1;
					board[1][0] = 1;
					board[1][1] = 1;
					free -= 4;
					if (free == 0)
					{
						dispBoard(board);
						continue;
					}
					board[0][2] = 1;
					board[1][2] = 1;
					free -= 2;
					if (free == 0)
					{
						dispBoard(board);
						continue;
					}
					board[2][0] = 1;
					board[2][1] = 1;
					free -= 2;
					for (j = 3; (free >= 2) && (j < R); ++j)
					{
						board[0][j] = 1;
						board[1][j] = 1;
						free -= 2;
					}
					for (j = 3; (free >= 2) && (j < C); ++j)
					{
						board[j][0] = 1;
						board[j][1] = 1;
						free -= 2;
					}
					for (j = 2; free > 0; ++j)
					{
						for (k = 2; (free > 0) && (k < R); ++k)
						{
							board[j][k] = 1;
							--free;
						}
					}
					dispBoard(board);
				} else {
					System.out.println("Impossible");
				}
				continue;
			}
			if ((R >= 2) && (C >= 2))
			{
				if ((free >= 4) && ((free & 1) == 0))
				{
					j = (free >> 1) - 2;
					if (R == 2)
					{
						String remaining = repeat('.', j) + repeat('*', C - j - 2);
						System.out.println("c." + remaining);
						System.out.println(".." + remaining);
					} else {
						System.out.println("c.");
						System.out.println("..");
						for (k = 0; k < j; ++k)
							System.out.println("..");
						for (k = R - j - 2; k > 0; --k)
							System.out.println("**");
					}
				} else {
					System.out.println("Impossible");
				}
				continue;
			}
			if ((R == 1) && (C == 1))
			{
				if (free == 1)
					System.out.println("c");
				else System.out.println("Impossible");
				continue;
			}
			if (free >= 2)
			{
				j = free - 2;
				if (R == 1)
				{
					System.out.println("c." + repeat('.', j) + repeat('*', C - j - 2));
				} else {
					System.out.println("c");
					System.out.println(".");
					for (k = 0; k < j; ++k)
						System.out.println(".");
					for (k = R - j - 2; k > 0; --k)
						System.out.println("*");
				}
			} else {
				System.out.println("Impossible");
			}
		}
		in.close();
	}
	public static void dispBoard(byte[][] board)
	{
		for (int y = 0; y < board[0].length; ++y)
		{
			for (int x = 0; x < board.length; ++x)
			{
				switch (board[x][y])
				{
				case 0:
					System.out.print("*");
					break;
				case 1:
					System.out.print(".");
					break;
				case 2:
					System.out.print("c");
					break;
				}
			}
			System.out.println();
		}
	}
	public static String repeat(char c, int repet)
	{
		StringBuilder result = new StringBuilder(repet);
		for (int i = 0; i < repet; ++i)
			result.append(c);
		return result.toString();
	}
}
