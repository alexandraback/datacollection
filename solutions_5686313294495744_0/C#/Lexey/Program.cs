using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using NUnit.Framework;

namespace task3
{
	[TestFixture]
	public class Program
	{
		static void Main(string[] args)
		{
			using (var reader = new StreamReader(args[0], Encoding.ASCII))
			using (var writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII))
			{
				var cases = int.Parse(reader.ReadLine());
				Console.WriteLine("Cases {0}", cases);
				for (var i = 1; i <= cases; ++i)
				{
					var n = int.Parse(reader.ReadLine());
					var d = new HashSet<Tuple<string, string>>();
					var duplicates = 0;
					for (var j = 0; j < n; ++j)
					{
						var s = reader.ReadLine().Split(' ');
						var v = Tuple.Create(s[0], s[1]);
						if (!d.Add(v))
						{
							++duplicates;
						}
					}
					n -= duplicates;
					var l2r = d.GroupBy(_ => _.Item1).ToDictionary(_ => _.Key, _ => new HashSet<string>(_.Select(v => v.Item2)));
					var r2l = d.GroupBy(_ => _.Item2).ToDictionary(_ => _.Key, _ => new HashSet<string>(_.Select(v => v.Item1)));
					foreach (var k in l2r.Keys.ToList())
					{
						var vals = l2r[k];
						if (vals.Count == 1)
						{
							--n;
							var k2 = vals.First();
							l2r.Remove(k);
							if (r2l[k2].Count == 1)
							{
								r2l.Remove(k2);
							}
						}
					}
					foreach (var v in r2l)
					{
						if (v.Value.Count == 1)
						{
							--n;
						}
					}
					duplicates += n;
					writer.WriteLine(string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i, duplicates));
				}
			}
		}
	}
}
