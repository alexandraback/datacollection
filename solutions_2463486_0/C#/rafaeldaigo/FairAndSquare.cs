using System;
using System.IO;
using System.Collections.Generic;

namespace Application
{
	public class FairAndSquare
	{
		public static bool IsFair(long a)
		{
			string s = a.ToString();
			for (int i = 0; 2 * i < s.Length; i++)
			{
				if (s[i] != s[s.Length - 1 - i])
					return false;
			}
			return true;
		}
		
		public static List<long> Generate()
		{
			List<long> resp = new List<long>();
			for (long i = 1; i <= 2001002; i++)
			{
				long sq = i * i;
				if (IsFair(i))
				{
					if (IsFair(sq))
					{
						resp.Add(sq);
					}
				}
			}
			return resp;
		}
		
		public static long SolveSimple(List<long> fsList, long a, long b)
		{
			long resp = 0;
			for (int i = 0; i < fsList.Count; i++)
			{
				if (a > fsList[i]) continue;
				if (fsList[i] > b) break;
				resp++;
			}
			return resp;
		}
		
		public static void Main()
		{
			List<long> fsList = Generate();
			int n = int.Parse(System.Console.ReadLine());
			for (int t = 0; t < n; t++)
			{
				string line = System.Console.ReadLine();
				string[] p = line.Split();
				long a = long.Parse(p[0]);
				long b = long.Parse(p[1]);
				long resp = SolveSimple(fsList, a, b);
				System.Console.WriteLine("Case #" + (t + 1) + ": " + resp);
			}
		}
	}
}

