using System.Collections.Generic;
using System.IO;
using System.Linq;

// ReSharper disable PossibleNullReferenceException

// ReSharper disable AssignNullToNotNullAttribute

namespace ConsoleApplication2
{
	class A
	{
		private string[] text = new[] {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
		private int[] order = new[] {0, 8, 3, 2, 4, 6, 7, 1, 9, 5};

		public void Solve()
		{
			using (var sr = new StreamReader("A.in"))
			using (var sw = new StreamWriter("A.out"))
			{
				var t = int.Parse(sr.ReadLine());
				for (var testCase = 1; testCase <= t; ++testCase)
				{
					var s = sr.ReadLine();
					var dict = new Dictionary<char, int>();
					foreach (var c in s)
					{
						if (!dict.ContainsKey(c))
							dict[c] = 0;
						++dict[c];
					}
					var ans = new List<int>();
					foreach (var number in order)
					{
						while (true)
						{
							if (text[number].All(c => dict.ContainsKey(c) && dict[c] != 0))
							{
								ans.Add(number);
								foreach (var c in text[number])
								{
									--dict[c];
								}
							}
							else
							{
								break;
							}
						}
					}
					sw.Write("Case #{0}: ", testCase);
					ans.Sort();
					foreach (var n in ans)
					{
						sw.Write(n);
					}
					sw.WriteLine();
				}
			}
		}
	}
}
