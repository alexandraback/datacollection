using System;
using System.IO;
using System.Linq;

namespace MinesweeperMaster
{
	class Program
	{
		static void Main(string[] args)
		{
			var inFile = @"C:\Repository\GoogleCodeJam\Qualification2014\MinesweeperMaster\bin\Debug\C-large.in";
			var outFile = @"C:\Repository\GoogleCodeJam\Qualification2014\MinesweeperMaster\bin\Debug\output.out";

			var reader = new StreamReader(inFile);
			var writer = new StreamWriter(outFile);

			var T = int.Parse(reader.ReadLine());
			for (int i = 1; i <= T; i++)
			{
				int[] RCM = reader.ReadLine().Split(new[] { ' ' }).Select(n => int.Parse(n)).ToArray();
				int R = RCM[0];
				int C = RCM[1];
				int M = RCM[2];
				int S = R * C;
				int D = S - M;

				writer.WriteLine("Case #" + i + ":");

				if (R == 1 || C == 1)
				{
					for (int r = 0; r < R; r++)
					{
						for (int c = 0; c < C; c++)
							if (M-- > 0)
								writer.Write("*");
							else if (r == R - 1 && c == C - 1)
								writer.Write("c");
							else
								writer.Write(".");
						writer.WriteLine();
					}
					continue;
				}
				if (D == 2 || D == 3 || D == 5 || D == 7
					|| (D != 1 && D % 2 != 0 && (R < 3 || C < 3)))
				{
					writer.WriteLine("Impossible");
					continue;
				}
				var grid = new char[C, R];
				double root = Math.Sqrt(D);
				bool squareMethod = false;
				if ((int)root == root)
				{
					squareMethod = true;
					decimal n = 2;
					decimal p;
					while ((p = D / n) > n)
					{
						if (p % 2 == 0)
						{
							squareMethod = false;
							break;
						}
						n++;
					}
					
				}
				if (squareMethod)
				{
					for (int j = 0; j < C; j++)
						for (int k = 0; k < R; k++)
							if (j < C - root || k < R - root)
								grid[j, k] = '*';
							else
								grid[j, k] = '.';
					grid[C - 1, R - 1] = 'c';
				}
				else
				{
					for (int j = 0; j < C; j++)
						for (int k = 0; k < R; k++)
							grid[j, k] = '.';
					grid[C - 1, R - 1] = 'c';
					int x = 0, y = 0;
					while (M > 0)
					{
						if (x == C)
						{
							x = 0;
							y++;
						}
						if (x == C - 2 && M == 1)
							grid[0, y + 1] = '*';
						else if (y == R - 2)
						{
							grid[x, y] = '*';
							if (M > 1)
								grid[x, y + 1] = '*';
							M--;
						}
						else if (x == C - 3 && M == 2)
						{
							if (y == R - 3)
							{
								grid[x = 0, ++y] = '*';
								grid[x, y + 1] = '*';
							}
							else
							{
								grid[x, y] = '*';
								grid[x = 0, ++y] = '*';
							}
							M--;
						}
						else
							grid[x, y] = '*';
						M--;
						x++;
					}
				}
				for (int y = 0; y < R; y++)
				{
					for (int x = 0; x < C; x++)
					{
						writer.Write(grid[x, y]);
					}
					writer.WriteLine();
				}
			}

			reader.Close();
			writer.Close();
		}
	}
}
