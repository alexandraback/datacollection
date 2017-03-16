package qualifying_round_2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class MineSweeper {

	public static void main(String[] args) throws IOException {
		BufferedReader f = new BufferedReader(new FileReader("Mine.in"));
		PrintWriter out = new PrintWriter(new FileWriter("C:/Users/David/Desktop/Mine.txt"));
		StringTokenizer t = new StringTokenizer(f.readLine());
		int testCases = Integer.parseInt(t.nextToken());
		for (int i = 0; i < testCases; i++)
		{
			t = new StringTokenizer(f.readLine());
			int R = Integer.parseInt(t.nextToken());
			int C = Integer.parseInt(t.nextToken());
			int M = Integer.parseInt(t.nextToken());
			
			System.out.println("Case #" + (i+1) + ": ");
			out.println("Case #" + (i+1) + ": ");
			if (M == 0) // no bombs
			{
				for (int r = 0; r < R; r++)
				{
					for (int c = 0; c < C; c++)
					{		
						if (r == R-1 && c == C-1)
						{
							System.out.print("c");
							out.print("c");
						}
						else
						{
							System.out.print(".");
							out.print(".");
						}
					}
					System.out.println();
					out.println();
				}
			}
			else if (R == 1) //single row
			{
				for (int c = 0; c < M; c++)
				{
					out.print("*");
					System.out.print("*");
				}
				for (int c = 0; c < C-M-1; c++)
				{
					out.print(".");
					System.out.print(".");
				}
				out.println("c");
				System.out.println("c");
			}
			else if (C == 1) //single column
			{
				for (int r = 0; r < M; r++)
				{
					out.println("*");
					System.out.println("*");
				}
				for (int r = 0; r < R-M-1; r++)
				{
					out.println(".");
					System.out.println(".");
				}
				out.println("c");
				System.out.println("c");
			}
			else
			{
				if (R*C - M == 1) //single click
				{
					out.print("c");
					System.out.print("c");
					for (int c = 1; c < C; c++)
					{
						out.print("*");
						System.out.print("*");
					}
					System.out.println();
					out.println();
					for (int r = 1; r < R; r++)
					{
						for (int c = 0; c < C; c++)
						{
							out.print("*");
							System.out.print("*");
						}
						out.println();
						System.out.println();
					}
				}
				else if (R*C - M <= 3 || R*C - M == 5 || R*C - M == 7
						|| ((R==2||C==2)&& M%2==1))
				{
					out.println("Impossible");
					System.out.println("Impossible");
				}
				else //fill normally
				{
					char[][] fill = new char[R][C];
					if (C == 2)
					{
						int temp = M/2;
						for (int r = 0; r < temp; r++)
						{
							fill[r][0] = '*';
							fill[r][1] = '*';
						}
						fill[R-1][C-1] = 'c';
					}
					else if (R == 2)
					{
						int temp = M/2;
						for (int c = 0; c < temp; c++)
						{
							fill[0][c] = '*';
							fill[1][c] = '*';
						}
						fill[R-1][C-1] = 'c';
					}
					else if (C == 3)
					{
						int temp = M/3;
						for (int r = 0; r < temp; r++)
						{
							fill[r][0] = '*';
							fill[r][1] = '*';
							fill[r][2] = '*';
						}
						M -= temp*3;
						for (int r = 0; r < M; r++)
						{
							fill[temp+r][0] = '*';
						}
						
						fill[R-1][C-1] = 'c';
					}
					else if (R == 3)
					{
						int temp = M/3;
						for (int c = 0; c < temp; c++)
						{
							fill[0][c] = '*';
							fill[1][c] = '*';
							fill[2][c] = '*';
						}
						M -= temp*3;
						for (int c = 0; c < M; c++)
						{
							fill[0][c+temp] = '*';
						}
						
						fill[R-1][C-1] = 'c';
					}
					else if (C >= R)
					{
						int rowsOfBombs = M/C;
						if (rowsOfBombs > R - 3) rowsOfBombs = R - 3;
						for (int r = 0; r < rowsOfBombs; r++)
							for (int c = 0; c < C; c++) fill[r][c] = '*';
						if (rowsOfBombs > 0)
							M -= rowsOfBombs*C;
						else
						{
							rowsOfBombs = 0;
							for (int c = 0; c < C-2; c++)
							{
								fill[0][c] = '*';
								M--;
								if (M == 0)break;
							}
							if (M == 1)
								fill[1][0] = '*';
							M = 0;
						}
						int colsOfBombs = M / (R - rowsOfBombs);
						for (int r = rowsOfBombs; r < R; r++)
							for (int c = 0; c < colsOfBombs; c++)
								fill[r][c] = '*';
						if (colsOfBombs > 0)
							M -= colsOfBombs*(R-rowsOfBombs);
						else
							colsOfBombs = 0;
						//System.out.println("Bombs left" + M);
						for (int j = 0; j < M; j++)
						{
							fill[rowsOfBombs][colsOfBombs++] = '*';
						}
						fill[R-1][C-1] = 'c';
					}
					else
					{
						int colsOfBombs = M/R;
						if (colsOfBombs > C - 3) colsOfBombs = C - 3;
						for (int c = 0; c < colsOfBombs; c++)
							for (int r = 0; r < R; r++) fill[r][c] = '*';
						if (colsOfBombs > 0)
							M -= colsOfBombs*R;
						else
						{
							colsOfBombs = 0;
							for (int r = 0; r < R-2; r++)
							{
								fill[r][0] = '*';
								M--;
								if (M == 0)break;
							}
							if (M == 1)
								fill[0][1] = '*';
							M = 0;
						}
						int rowsOfBombs = M / (C - colsOfBombs);
						for (int c = colsOfBombs; c < C; c++)
							for (int r = 0; r < rowsOfBombs; r++)
								fill[r][c] = '*';
						if (rowsOfBombs > 0)
							M -= rowsOfBombs*(C-colsOfBombs);
						else
							rowsOfBombs = 0;
						//System.out.println("Bombs left" + M);
						for (int j = 0; j < M; j++)
						{
							fill[rowsOfBombs++][colsOfBombs] = '*';
						}
						fill[R-1][C-1] = 'c';
					}
					for (int r = 0; r < R; r++)
					{
						for (int c = 0; c < C; c++)
						{
							if (fill[r][c] != '*' && fill[r][c] != 'c')
							{
								System.out.print(".");
								out.print(".");
							}
							else
							{
								System.out.print(fill[r][c]);
								out.print(fill[r][c]);
							}
						}
						System.out.println();
						out.println();
					}
				}
			}
			
			
		}

		out.close(); f.close(); System.exit(0);

	}

}
