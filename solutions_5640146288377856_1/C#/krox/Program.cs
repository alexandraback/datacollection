using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CJ15Round1C_First
{
	class Program
	{
		static void Main(string[] args)
		{
			var cases = Read.Int();

			using (var s = new StreamWriter(@"c:\users\krox\Downloads\CodeJam\first.large.out", false))
			{
				for (var t = 0; t < cases; t++)
				{
					var x = new X();

					var answer = "Case #" + (t + 1) + ": " + x.Solve() + "\n";
					Console.Write(answer);
					s.Write(answer);
				}
			}

			Console.ReadLine();
		}
	}


	public class X
	{	

		public string Solve()
		{
			var R = Read.Int();
			var C = Read.Int();
			var W = Read.Int();

			var count = C/W * (R-1); // Rows above

			if (W == 1)
			{
				return (count + C) + "";
			}

			var thisRowCount = (C/W) - 1;

			count += thisRowCount;

			count += W;

			if (C % W != 0)
			{
				count++;
			}

			return count + string.Empty;
		}
	}

	public static class Read
	{
		private static string[] input = ReadAllText().Split(new[] { ' ', '\r', '\n', '\t' }, StringSplitOptions.RemoveEmptyEntries);

		private static int indexer = 0;

		public static int Int()
		{
			return int.Parse(input[indexer++]);
		}

		public static int[] Ints(int c)
		{
			return Enumerable.Range(0, c).Select(t => Int()).ToArray();
		}

		public static long Long()
		{
			return long.Parse(input[indexer++]);
		}

		public static string String()
		{
			return input[indexer++];
		}

		private static string ReadAllText()
		{
			return File.ReadAllText(@"c:\users\krox\Downloads\CodeJam\first.large.in");
		}
	}
}
