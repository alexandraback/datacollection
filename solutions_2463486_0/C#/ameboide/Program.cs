using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace c
{
	class Program
	{
		static void Main(string[] args)
		{
			List<long> nums = new List<long>();
			//4000000008000000004
			for (long i = 1; i < 100000; i++)
			{
				string p0 = i + "";
				string r = new string(p0.Reverse().ToArray());
				long p1 = long.Parse(p0 + r.Substring(1));
				long p2 = long.Parse(p0 + r);

				if (ispal(p1))
				{
					nums.Add(p1 * p1);
				}
				if (ispal(p2))
				{
					nums.Add(p2 * p2);
				}
			}

			int T = int.Parse(Console.ReadLine());
			for (int caso = 1; caso <= T; caso++)
			{
				string[] linea = Console.ReadLine().Split(' ');
				long min = long.Parse(linea[0]);
				long max = long.Parse(linea[1]);
				int ok = 0;
				foreach (long n in nums)
				{
					if (n >= min && n <= max)
					{
						ok++;
					}
				}

				Console.WriteLine("Case #{0}: {1}", caso, ok);
			}
		}

		static bool ispal(long p)
		{
			long n = p * p;
			string s = n + "";
			string s1 = s.Substring(0, s.Length / 2);
			string s2 = s.Substring(s.Length / 2);
			if (s2.Length > s1.Length)
			{
				s2 = s2.Substring(1);
			}
			return s1 == new string(s2.Reverse().ToArray());
		}
	}
}
