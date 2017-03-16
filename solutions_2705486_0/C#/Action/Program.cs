using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ProjectC
{
	class Program
	{
		static void Main(string[] args)
		{
			var dictionary = new List<string>();
			using (var inFile = new FileStream("Dict.txt", FileMode.Open, FileAccess.Read))
			{
				using (var reader = new StreamReader(inFile))
				{
					while (inFile.CanRead)
					{
						var word = reader.ReadLine();
						if (string.IsNullOrWhiteSpace(word)) break;
						dictionary.Add(word.ToLower());
					}
				}
			}

			using (var inFile = new FileStream("C.in", FileMode.Open, FileAccess.Read))
			{
				using (var reader = new StreamReader(inFile))
				{
					using (var outFile = new FileStream("C.out", FileMode.Create, FileAccess.Write))
					{
						using (var writer = new StreamWriter(outFile))
						{
							var line = reader.ReadLine();
							var testCount = int.Parse(line);
							for (int testIndex = 1; testIndex <= testCount; testIndex++)
							{
								var S = reader.ReadLine().ToLower();
								var len = S.Length;
								var height = 5;
								var A = new int[height, len];
								for (int index = 0; index < len; index++)
								{
									for (int h = 0; h < height; h++) A[h, index] = int.MaxValue;
									foreach (var word in dictionary)
									{
										int wlen = word.Length;
										if (wlen > index + 1) continue;
										var lastDiffInd = int.MinValue;
										var firstDiffInd = int.MinValue;
										var numChanges = 0;
										bool impossible = false;
										for (int i = 0; i < wlen; i++)
										{
											if (word[i] == S[index - wlen + i + 1]) continue;
											if (firstDiffInd == int.MinValue) firstDiffInd = i;
											numChanges++;
											if (lastDiffInd != int.MinValue && i - lastDiffInd < 5)
											{
												impossible = true;
												break;
											}
											lastDiffInd = i;
										}
										if (impossible) continue;
										int minPrevChanges;
										if (index >= wlen)
										{
											int minPrevDiffInd = firstDiffInd == int.MinValue ? 0 : height - 1 - firstDiffInd;
											if (minPrevDiffInd < 0) minPrevDiffInd = 0;
											minPrevChanges = int.MaxValue;
											for (int prevFiddInd = height - 1; prevFiddInd >= minPrevDiffInd; prevFiddInd--)
											{
												var q = A[prevFiddInd, index - wlen];
												if (q != int.MaxValue && q < minPrevChanges)
												{
													minPrevChanges = q;
												}
											}
										}
										else
										{
											minPrevChanges = 0;
										}
										if (minPrevChanges == int.MaxValue) continue;
										for (var qq = lastDiffInd == int.MinValue ? height - 1 : Math.Min(wlen - 1 - lastDiffInd, height - 1); qq < height; qq++)
										{
											if (A[qq, index] > minPrevChanges + numChanges)
											{
												A[qq, index] = minPrevChanges + numChanges;
											}
										}
									}
								}
								var min = int.MaxValue;
								for (int i = 0; i < height; i++)
								{
									if (A[i, len - 1] < min)
									{
										min = A[i, len - 1];
									}
								}
								writer.WriteLine("Case #{0}: {1}", testIndex, min);
							}
						}
					}
				}
			}
		}
	}
}
