using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemA
{
	class Program
	{
		static void Main(string[] args)
		{
			using (var inFile = new FileStream("A.in", FileMode.Open, FileAccess.Read))
			{
				using (var reader = new StreamReader(inFile))
				{
					using (var outFile = new FileStream("A.out", FileMode.Create, FileAccess.Write))
					{
						using (var writer = new StreamWriter(outFile))
						{
							var line = reader.ReadLine();
							var testCount = int.Parse(line);
							for (int testIndex = 1; testIndex <= testCount; testIndex++)
							{
								line = reader.ReadLine();
								var parts = line.Split(' ');
								var A = int.Parse(parts[0]);
								var N = int.Parse(parts[1]);
								line = reader.ReadLine();
								parts = line.Split(' ');
								var motes = new List<int>(N);
								for (int i = 0; i < N; i++)
								{
									motes.Add(int.Parse(parts[i]));
								}
								motes.Sort();
								int answer;
								if (A == 1)
								{
									answer = N;
								}
								else
								{
									var required = new int[N];
									int index = 0;
									var temp = A;
									while (index < N)
									{
										if (temp > motes[index])
										{
											temp += motes[index];
											index++;
											continue;
										}
										temp += (temp - 1);
										required[index]++;
									}
									int sum = 0;
									index = 0;
									var min = N;
									while (index < N)
									{
										sum += required[index];
										required[index] = sum + N - index - 1;
										if (required[index] < min)
										{
											min = required[index];
										}
										index++;
									}
									answer = min;
								}
								writer.WriteLine("Case #{0}: {1}", testIndex, answer);
							}
						}
					}
				}
			}
		}
	}
}