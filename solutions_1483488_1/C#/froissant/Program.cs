using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam3
{
	class Program
	{
		static void Main(string[] args)
		{
			try
			{
				using (StreamReader sr = new StreamReader(File.OpenRead("C-large.in")))
				{
					using (StreamWriter sw = new StreamWriter(File.OpenWrite("C-large.out")))
					{
						int caseNumber = int.Parse(sr.ReadLine());
						for (int i = 1; i <= caseNumber; i++)
						{
							string[] line = sr.ReadLine().Split(' ');
							if (line.Length < 2) { throw new Exception(string.Format("Case #{0} is malformed.", i)); }

							int A = int.Parse(line[0]);
							int B = int.Parse(line[1]);
							int result = 0;
							for (int range = A; range <= B; range++)
							{
								string str = range.ToString();
								List<int> used = new List<int>();
								for (int j = 1; j < str.Length; j++)
									{
										int permutation = int.Parse(str.Substring(j) + str.Substring(0, j));
										if (
											range < permutation
											&&
											permutation >= A
											&&
											permutation <= B
											)
										{
											if (!used.Contains(permutation))
											{
												result++;
												used.Add(permutation);
											}
										}
									}
							}
							sw.WriteLine("Case #{0}: {1}", i, result);
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
