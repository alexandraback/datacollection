using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2
{
	struct inputCase
	{
		public int Googlers { get; set; }
		public int Surprising { get; set; }
		public int BestResult { get; set; }
		public int BestGooglers { get; set; }
		public int[] Scores { get; set; }
	}

	class Program
	{
		static void Main(string[] args)
		{
			try
			{
				using (StreamReader sr = new StreamReader(File.OpenRead("B-small-attempt1.in")))
				{
					using (StreamWriter sw = new StreamWriter(File.OpenWrite("B-small-attempt1.out")))
					{
						int caseNumber = int.Parse(sr.ReadLine());
						for (int i = 1; i <= caseNumber; i++)
						{
							string[] line = sr.ReadLine().Split(' ');
							if (line.Length < 4) { throw new Exception(string.Format("Case #{0} is malformed.", i)); }

							inputCase input = new inputCase()
							{
								Googlers = int.Parse(line[0]),
								Surprising = int.Parse(line[1]),
								BestResult = int.Parse(line[2]),
								BestGooglers = 0,
								Scores = Array.ConvertAll(line.Skip(3).ToArray(), item => int.Parse(item))
							};
							foreach (int total in input.Scores)
							{
								if (total >= input.BestResult)
								{
									if (total >= input.BestResult * 3 ||
										total >= (input.BestResult + ((input.BestResult - 1) * 2)))
									{
										input.BestGooglers++;
									}
									else
									{
										if (total >= (input.BestResult + ((input.BestResult - 2) * 2)) &&
											input.Surprising > 0)
										{
											input.BestGooglers++;
											input.Surprising--;
										}
									}
								}
							}
							sw.WriteLine("Case #{0}: {1}", i, input.BestGooglers);
						}
					}
				}
			}
			catch (Exception e)
			{
				Console.WriteLine(e.Message);
			}
		}
	}
}
