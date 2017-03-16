using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

// ReSharper disable AssignNullToNotNullAttribute
// ReSharper disable StringCompareToIsCultureSpecific

namespace ConsoleApplication2
{
	class C
	{
		public void Solve()
		{
			using (var sr = new StreamReader("C.in"))
			using (var sw = new StreamWriter("C.out"))
			{
				var t = int.Parse(sr.ReadLine());
				for (var testCase = 1; testCase <= t; ++testCase)
				{
					var n = int.Parse(sr.ReadLine());
					var qFisrt = new Dictionary<string, int>();
					var qSecond = new Dictionary<string, int>();
					var all = new List<Tuple<string, string>>();
					for (var i = 0; i < n; ++i)
					{
						var s = sr.ReadLine().Split(' ').ToArray();
						if (!qFisrt.ContainsKey(s[0]))
							qFisrt[s[0]] = 0;
						++qFisrt[s[0]];
						if (!qSecond.ContainsKey(s[1]))
							qSecond[s[1]] = 0;
						++qSecond[s[1]];
						all.Add(new Tuple<string, string>(s[0],s[1]));
					}
					all.Sort((tuple, tuple1) => Comparison(tuple, tuple1, qFisrt, qSecond));

					qFisrt = new Dictionary<string, int>();
					qSecond = new Dictionary<string, int>();
					var ans = 0;
					foreach (var stud in all)
					{
						if (qFisrt.ContainsKey(stud.Item1) && qSecond.ContainsKey(stud.Item2))
							++ans;
						qFisrt[stud.Item1] = 0;
						qSecond[stud.Item2] = 0;
					}
					sw.WriteLine("Case #{0}: {1}", testCase, ans);
				}
			}
		}

		private int Comparison(Tuple<string, string> first, Tuple<string, string> second, Dictionary<string, int> qFirst, Dictionary<string, int> qSecond)
		{
			if (qFirst[first.Item1] == 1 || qSecond[first.Item2] == 1)
			{
				if (qFirst[second.Item1] == 1 || qSecond[second.Item2] == 1)
				{
					return first.Item1 != second.Item1 ? first.Item1.CompareTo(second.Item1) : first.Item2.CompareTo(second.Item2);
				}
				return -1;
			}

			if (qFirst[second.Item1] == 1 || qSecond[second.Item2] == 1)
				return 1;

			var t1 = qFirst[first.Item1] + qSecond[first.Item2];
			var t2 = qFirst[second.Item1] + qSecond[second.Item2];
			if (t1 != t2)
				return -t1.CompareTo(t2);
			t1 = Math.Min(qFirst[first.Item1],qSecond[first.Item2]);
			t2 = Math.Min(qFirst[second.Item1],qSecond[second.Item2]);
			if (t1 != t2)
				return -t1.CompareTo(t2);
			return first.Item1 != second.Item1 ? first.Item1.CompareTo(second.Item1) : first.Item2.CompareTo(second.Item2);

		}
	}
}
