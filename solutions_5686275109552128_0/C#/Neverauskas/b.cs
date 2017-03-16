using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "B-small-attempt1";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
			}
		}

		private static void Solve()
		{
			var d = cin.NextInt();
			var p = new List<int>();
			for (var i = 0; i < d; i++)
			{
				p.Add(cin.NextInt());
			}
			var max = p.Max();
			var best = max;
			for (var i = 1; i <= max; i++)
			{
				var cnt = 0;
				for (var j = 0; j < p.Count; j++)
				{
					var c = p[j]/i + (p[j]%i == 0 ? 0 : 1) - 1;
					cnt += c;
				}
				best = Math.Min(best, cnt + i);
			}
			Console.WriteLine(best);
		}

		//private static void Solve()
		//{
		//	var d = cin.NextInt();
		//	var set = new MultiSet();
		//	for (var i = 0; i < d; i++)
		//	{
		//		set.Add(cin.NextInt());
		//	}
		//	var enumerator = set.GetEnumerator();
		//	enumerator.MoveNext();
		//	var value = enumerator.Current;
		//	var best = value;
		//	var splits = 0;
		//	while (value >= 4)
		//	{
		//		var cnt = set.Remove(value);
		//		var one = value/2;
		//		var two = one + (value%2);
		//		for (var i = 0; i < cnt; i++)
		//		{
		//			set.Add(one);
		//			set.Add(two);
		//		}
		//		splits += cnt;
		//		enumerator = set.GetEnumerator();
		//		enumerator.MoveNext();
		//		value = enumerator.Current;
		//		best = Math.Min(best, splits + value);
		//		if (splits >= best)
		//		{
		//			break;
		//		}
		//	}
		//	Console.WriteLine(best);
		//}

	}

	public class MultiSet
	{
		private readonly SortedSet<int> set = new SortedSet<int>(new Comparer());

		public static bool IsAdd = false;

		public void Add(int number)
		{
			IsAdd = true;
			set.Add(number);
			IsAdd = false;
		}

		public int Remove(int number)
		{
			var count = 0;
			while (set.Remove(number))
			{
				count++;
			}
			return count;
		}

		public SortedSet<int>.Enumerator GetEnumerator()
		{
			return set.GetEnumerator();
		} 
	}

	public class Comparer : IComparer<int>
	{
		public int Compare(int x, int y)
		{
			var comp = y.CompareTo(x);
			if (comp == 0 && MultiSet.IsAdd)
			{
				return -1;
			}
			return comp;
		}
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = { ' ' };

		public string NextString()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			if (line == string.Empty)
			{
				return NextString();
			}
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(NextString());
		}

		public int NextInt()
		{
			return int.Parse(NextString());
		}

		public long NextLong()
		{
			return long.Parse(NextString());
		}
	}
}