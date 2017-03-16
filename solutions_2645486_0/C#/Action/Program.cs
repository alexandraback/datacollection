using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProblemB
{
	class Program
	{
		static void Main(string[] args)
		{
			using (var inFile = new FileStream("B.in", FileMode.Open, FileAccess.Read))
			{
				using (var reader = new StreamReader(inFile))
				{
					using (var outFile = new FileStream("B.out", FileMode.Create, FileAccess.Write))
					{
						using (var writer = new StreamWriter(outFile))
						{
							var line = reader.ReadLine();
							var testCount = int.Parse(line);
							for (int testIndex = 1; testIndex <= testCount; testIndex++)
							{
								line = reader.ReadLine();
								var parts = line.Split(' ');
								var E = long.Parse(parts[0]);
								var R = long.Parse(parts[1]);
								var N = long.Parse(parts[2]);
								line = reader.ReadLine();
								parts = line.Split(' ');
								var v = new long[N];
								for (long i = 0; i < N; i++)
								{
									v[i] = long.Parse(parts[i]);
								}
								var vals = new long[E + 1];
								for (int i = 0; i <= E; i++) vals[i] = 0;
								var newVals = new long[E + 1];
								for (int t = 0; t < N; t++)
								{
									var coeff = v[t];
									for (int i = 0; i <= E; i++) newVals[i] = -1;
									for (int e = 0; e <= E; e++)
									{
										for (int b = e; b <= E; b++)
										{
											var val = vals[b];
											if (vals[b] == -1) continue;
											var newVal = val + e * coeff;
											var newEnergy = b - e + R;
											if (newEnergy > E) newEnergy = E;
											if (newVals[newEnergy] < newVal)
											{
												newVals[newEnergy] = newVal;
											}
										}
									}
									var temp = vals;
									vals = newVals;
									newVals = temp;
								}
								long max = 0;
								for (int i = 0; i <= E; i++)
								{
									if (vals[i] > max)
									{
										max = vals[i];
									}
								}
								writer.WriteLine("Case #{0}: {1}", testIndex, max);
							}
						}
					}
				}
			}
		}
	}
}