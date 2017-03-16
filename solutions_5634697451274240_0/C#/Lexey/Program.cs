using System;
using System.IO;
using System.Linq;
using System.Text;
using NUnit.Framework;

namespace task2
{
	[TestFixture]
	public class Program
	{
		private static void Main(string[] args)
		{
			using (var reader = new StreamReader(args[0], Encoding.ASCII))
			using (var writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII))
			{
				var cases = int.Parse(reader.ReadLine());
				Console.WriteLine("Cases {0}", cases);
				for (var i = 1; i <= cases; ++i)
				{
					var s = reader.ReadLine().Trim();
					var result = Solve(s);
					writer.WriteLine("Case #{0}: {1}", i, result);
				}
			}
		}

		public static int Solve(string s)
		{
			var data = ConvertInput(s);
			return Solve(data, data.Length, true);
		}

		private static int Solve(bool[] data, int length, bool target)
		{
			while (length > 0)
			{
				var index = length - 1;
				if (data[index] != target)
				{
					return 1 + Solve(data, index, !target);

				}
				length = index;
			}
			return 0;
		}

		private static bool[] ConvertInput(string s)
		{
			return s.Select(_ => _ == '+').ToArray();
		}

		[Test]
		[TestCase("-", ExpectedResult = 1)]
		[TestCase("-+", ExpectedResult = 1)]
		[TestCase("+-", ExpectedResult = 2)]
		[TestCase("+++", ExpectedResult = 0)]
		[TestCase("--+-", ExpectedResult = 3)]
		public int Test01(string data)
		{
			return Solve(data);
		}

		[Test]
		public void Test02()
		{
			var rnd = new Random();
			for (var i = 0; i < 100; ++i)
			{
				var data = new string(Enumerable.Range(0, 100).Select(_ => rnd.Next(0, 2) == 1 ? '+' : '-').ToArray());
				var r = Solve(data);
				Console.WriteLine("{0}: {1}", data, r);
			}
		}
	}
}
