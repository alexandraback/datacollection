using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
// ReSharper disable PossibleNullReferenceException

// ReSharper disable AssignNullToNotNullAttribute

namespace ConsoleApplication2
{
	class B
	{
		public void Solve()
		{
			using (var sr = new StreamReader("B.in"))
			using (var sw = new StreamWriter("B.out"))
			{
				var t = int.Parse(sr.ReadLine());
				for (var testCase = 1; testCase <= t; ++testCase)
				{
					var s = sr.ReadLine().Split(' ').ToArray();

					var first = 0;
					var second = 0;
					var best = int.MaxValue;

					for (int i = 0; i < 1000; ++i)
					{
						if (!IsMatch(i, s[0]))
							continue;
						for (var j = 0; j < 1000; ++j)
						{
							if (!IsMatch(j, s[1]))
								continue;
							var diff = Math.Abs(i - j);
							if (diff < best)
							{
								best = diff;
								first = i;
								second = j;
							}
							else if (diff == best && j < second)
							{
								first = i;
								second = j;
							}
						}
					}

					var ans1 = first.ToString();
					while (ans1.Length < s[0].Length)
						ans1 = '0' + ans1;
					var ans2 = second.ToString();
					while (ans2.Length < s[0].Length)
						ans2 = '0' + ans2;

					sw.WriteLine("Case #{0}: {1} {2}", testCase, ans1, ans2);
				}
			}
		}

		private int[] pow10 = new[] {1, 10, 100, 1000, 10000};
		private bool IsMatch(int n, string s)
		{
			if (n >= pow10[s.Length])
				return false;
			for (var i = 0; i < s.Length; ++i)
			{
				if (s[i] != '?' && n/pow10[s.Length - i-1]%10 != s[i] - '0')
					return false;
			}
			return true;
		}
	}
}
