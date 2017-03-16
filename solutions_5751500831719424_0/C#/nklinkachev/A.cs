using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2014Round1B
{
	internal class A
	{
		private static List<KeyValuePair<char, int>> ToList(string str)
		{
			var res = new List<KeyValuePair<char, int>>();
			if (str.Length == 1)
			{
				res.Add(new KeyValuePair<char, int>(str[0], 1));
				return res;
			}
			char c = str[0];
			int s = 1;
			for (int i = 1; i < str.Length; i++)
			{
				if (c == str[i]) s++;
				else
				{
					res.Add(new KeyValuePair<char, int>(c, s));
					c = str[i];
					s = 1;
				}
			}
			res.Add(new KeyValuePair<char, int>(c, s));
			return res;
		} 

		private static void Main(string[] args)
		{
			string testsize = "small";

			TextReader tr = new StreamReader("A-" + testsize + ".in");
			TextWriter tw = new StreamWriter("A-" + testsize + ".out");

			int T = int.Parse(tr.ReadLine());

			for (int t = 0; t < T; t++)
			{
				var strs = new List<List<KeyValuePair<char, int>>>();
				int n = int.Parse(tr.ReadLine());
				for (int i = 0; i < n; i++)
				{
					strs.Add(ToList(tr.ReadLine()));
				}

				int l = strs[0].Count;

				if (!strs.All(x => x.Count == l)) goto felgawon;
				

				for (int i = 0; i < l; i++)
				{
					char c = strs[0][i].Key;
					if (!strs.All(x => x[i].Key == c)) goto felgawon;
				}

				int s = 0;

				for (int i = 0; i < l; i++)
				{
					int mn = int.MaxValue;
					for (int r = 0; r <= 100; r++)
					{
						mn = Math.Min(mn, strs.Sum(x => Math.Abs(x[i].Value - r)));
					}
					s += mn;
				}
				tw.WriteLine("Case #" + (t + 1) + ": " + s);
				continue;

			felgawon:
					tw.WriteLine("Case #" + (t + 1) + ": Fegla Won");
					continue;
			}
			tr.Close();
			tw.Close();
		}
	}
}
