using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

class Minesweeper
{
	public int n;

	public Minesweeper()
	{
		this.n = int.Parse(Console.ReadLine());
	}

	public void Run()
	{
		File.WriteAllText("out.txt", String.Empty);

		for (int i = 0; i < this.n; i++)
		{
			int[] nums = Console.ReadLine().Split(' ').Select(s => int.Parse(s)).ToArray();
			int R = nums[0], C = nums[1], M = nums[2];
			int L = R * C - M;

			string drawing = "";
			bool possible = true;

			if (R != 1 && C != 1 && (L == 2 || L == 3 || L == 5 || L == 7))
				possible = false;
			else if (L != 1 && (R == 2 || C == 2) && (M % 2) != 0)
				possible = false;
			else
			{
				for (; R > 0; R--)
				{
					if (M == 0 && R > 1)
					{
						for (int k = 0; k < C; k++)
							drawing += ".";
					}
					else if (M >= C && R > 3)
					{
						for (int k = 0; k < C; k++)
							drawing += "*";
						M -= C;
					}
					else if (R > 3)
					{
						for (int k = 0; k < C-2; k++)
						{
							if (M > 0)
							{
								drawing += "*";
								M--;
							}
							else
								drawing += ".";
						}
						drawing += "..";
					}
					else if (R == 3)
					{
						if (M >= C)
						{
							if ((M - C) % 2 != 0 && R*C != M+1)
							{
								for (int k = 0; k < C-3; k++)
									drawing += "*";
								M -= (C-3);
								drawing += "...";
							}
							else
							{
								for (int k = 0; k < C; k++)
									drawing += "*";
								M -= C;
							}
						}
						else
						{
							for (int k = 0; k < C-2; k++)
							{
								if (M > 0 && !((k == C-3) && M == 2))
								{
									drawing += "*";
									M--;
								}
								else
									drawing += ".";
							}
							drawing += "..";
						}
					}
					else if (R == 2)
					{
						if (M % 2 == 0)
						{
							for (int k = 0; k < M/2; k++)
								drawing += "*";
							for (int k = M/2; k < C; k++)
								drawing += ".";
							M = M - M/2;
						}
						else
						{
							for (int k = 0; k < C; k++)
								drawing += "*";
							M -= C;
						}
					}
					else if (R == 1)
					{
						for (int k = 0; k < C-1; k++)
						{
							if (M > 0)
							{
								drawing += "*";
								M--;
							}
							else
								drawing += ".";
						}
						drawing += "c";
					}
					drawing += "\n";
				}
			}

			using (StreamWriter w = File.AppendText("out.txt"))
			{
				w.WriteLine("Case #{0}:", i + 1);
				if (possible)
					w.Write(drawing);
				else
					w.WriteLine("Impossible");
			}
		}
	}
	
	static void Main(string[] args)
	{
		Minesweeper m = new Minesweeper();
		m.Run();
	}
}
