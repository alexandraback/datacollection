using System;
using System.Collections.Generic;
using System.Configuration;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "A-large";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Solve();
				Debug.WriteLine(c);
			}
		}

		private static void Solve()
		{
			var n = cin.NextLong();
			//var visited = new bool[10 * 1000 * 1000 + 10];
			//var queue = new Queue<State>();
			//queue.Enqueue(new State { Count = 1L, N = 1L, Path = new List<long>() });
			//visited[1] = true;
			//while (queue.Any())
			//{
			//	var top = queue.Dequeue();
			//	if (top.N == n)
			//	{
			//		Console.WriteLine(top.Count);
			//		return;
			//	}
			//	top.Path.Add(top.N);
			//	var state1 = new State { Count = top.Count + 1, N = top.N + 1, Path = top.Path.ToList() };
			//	var state2 = new State { Count = top.Count + 1, N = Reverse(top.N), Path = top.Path.ToList() };
			//	if (state1.N < visited.Length && !visited[state1.N])
			//	{
			//		queue.Enqueue(state1);
			//		visited[state1.N] = true;
			//	}
			//	if (state2.N < visited.Length && !visited[state2.N])
			//	{
			//		queue.Enqueue(state2);
			//		visited[state2.N] = true;
			//	}
			//}
			if (n <= 10)
			{
				Console.WriteLine(n);
				return;
			}
			if (n == 30)
			{
				var z = 5;
			}
			var cur = 10L;
			var cnt = 10L;
			while (true)
			{
				var mag = cur;

				var tens = (n) / mag;
				var add = Math.Min(9, tens);
				if (tens > 9/* && mag >= 100*/)
				{
					var temp = mag;
					var zeros = 2;
					while (temp/10 > 0)
					{
						zeros++;
						temp /= 10;
					}
					var nine = long.Parse(new string('9', zeros/2));
					cur += nine;
					cnt += nine;
					cur = Reverse(cur);
					cnt++;
					var d = mag * 10 - cur;
					cur += d;
					cnt += d;
				}
				else// if (tens > 1)
				{
					//var best = long.MaxValue;
					var nn = n.ToString();
					
					var best = n - cur;
					for (var i = 1; i <= nn.Length; i++)
					{
						var cc = cur;
						var count = 0L;
						var sub = nn.Substring(0, i);
						sub = new string(sub.Reverse().ToArray());
						var dd = long.Parse(sub);
						count += dd;
						cc += dd;
						count++;
						cc = Reverse(cc);
						if (n > cc)
						{
							count += n - cc;
							best = Math.Min(best, count);
						}
					}

					var bestCnt = best + cnt;


					add = (n - 1) / mag;
					cur += add;
					cnt += add;
					var temp = cur;
					var rev = Reverse(cur); // 91
					if (rev > cur)
					{
						cur = rev;
					}
					if (cur != temp)
					{
						cnt++;
					}

					cnt += n - cur;
					best = Math.Min(bestCnt, cnt);
					Console.WriteLine(best);
					return;

					if (add == tens)
					{
						cnt += n - cur;
						Console.WriteLine(cnt);
						return;
					}
					var d = mag * 10 - cur;
					cur += d;
					cnt += d;
				}
				//else
				{
					//cnt += n - cur;
					//Console.WriteLine(cnt);
					//return;

					
				}
			}
		}

		public struct State
		{
			public long N { get; set; }
			public long Count { get; set; }
			public List<long> Path { get; set; } 
		}

		private static long Reverse(long num)
		{
			return long.Parse(new string(num.ToString().Reverse().ToArray()));
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