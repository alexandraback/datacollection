using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;

namespace ProblemA
{
	class Program
	{
		static void Main(string[] args)
		{
			using (var reader = new StreamReader(args[0]))
			using (var writer = new StreamWriter(args.Length > 1 ? args[1] : args[0].Replace(".in", ".out")))
			{
				var t = reader.Next<int>();
				for (int i = 1; i <= t; i++)
				{
					var pq = reader.ReadLine().Split('/').Select(long.Parse).ToList();

					var res = Solve(pq[0], pq[1]);

					writer.WriteLine("Case #{0}: {1}", i, res != null ? res.ToString() : "impossible");
				}
			}
		}

		private static int? Solve(long p, long q)
		{
			var k = 0;
			var pp = p;
			while (pp % 2 == 0) { pp /= 2; k++; }
			var l = 0;
			var qq = q;
			while (qq % 2 == 0) { qq /= 2; l++; }
			if (qq != 1 && pp % qq != 0) return null;

			double val = 1d;
			double pq = ((double)p) / q;
			for (int i = 1; i <= 40; i++)
			{
				val *= 0.5;
				if (val <= pq) return i;
			}

			return null;
		}
	}

	public static class StreamReaderExtensions
	{
		private static List<string> currLine;

		public static T Next<T>(this StreamReader reader)
		{
			if (currLine == null || !currLine.Any()) currLine = reader.ReadLine().Split(' ').ToList();
			var res = (T)Convert.ChangeType(currLine[0], typeof(T), CultureInfo.InvariantCulture);
			currLine.RemoveAt(0);
			return res;
		}

		public static T[] Next<T>(this StreamReader reader, int count)
		{
			if (currLine == null || !currLine.Any()) currLine = reader.ReadLine().Split(' ').ToList();
			if (count == 0) count = currLine.Count;
			var res = currLine.Take(count).Select(i => (T)Convert.ChangeType(i, typeof(T), CultureInfo.InvariantCulture)).ToArray();
			currLine.RemoveRange(0, count);
			return res;
		}
	}
}
