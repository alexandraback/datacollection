using System;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Reflection;
using System.Text;
using NUnit.Framework;

namespace task1
{
	[TestFixture]
	public class Program
    {
		private const int TableSize = 10000;
		private static readonly short[] Table_ = new short[TableSize];
		private const short FullMask = 0x3FF;
		private static readonly short[] DigitToMask_ = new short[10];

		private static void Main(string[] args)
        {
			using (var reader = new StreamReader(args[0], Encoding.ASCII))
            {
	            using (var writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII))
	            {
					var cases = int.Parse(reader.ReadLine());
					Console.WriteLine("Cases {0}", cases);
					for (var i = 1; i <= cases; ++i)
					{
						var n = int.Parse(reader.ReadLine());
						var result = Solve(n);
						writer.WriteLine("Case #{0}: {1}", i, result == 0 ? "INSOMNIA" : result.ToString());
					}
				}
			}
        }

		private static long Solve(int n)
		{
			if (n == 0)
			{
				return 0;
			}
			long result = n;
			Console.WriteLine("Solving for {0}", n);
			var sw = Stopwatch.StartNew();
			var mask = NumberToMask(result);
			while (mask != FullMask)
			{
				result += n;
				mask |= NumberToMask(result);
			}
			Console.WriteLine("Solved in {0}ms", sw.ElapsedMilliseconds);
			return result;
		}

		private static short NumberToMask(long number)
		{
			short mask = 0;
			while (number >= TableSize)
			{
				long reminder;
				number = Math.DivRem(number, TableSize, out reminder);
				mask |= Table_[reminder];
			}
			mask |= Table_[number];
			return mask;
		}

	    static Program()
	    {
			Console.WriteLine("Initializing");
		    var sw = Stopwatch.StartNew();

			short mask = 0x001;
			for (var i = 0; i < DigitToMask_.Length; ++i)
			{
				DigitToMask_[i] = mask;
				mask <<= 1;
			}

			for (var i = 0; i < TableSize; ++i)
		    {
			    Table_[i] = NumberToMaskCore(i);
		    }
			Console.WriteLine("Initialized in {0}ms", sw.ElapsedMilliseconds);
	    }

	    private static short NumberToMaskCore(int number)
	    {
		    short mask = 0;
		    while (number > 0)
		    {
			    int digit;
			    number = Math.DivRem(number, 10, out digit);
			    mask |= DigitToMask_[digit];
		    }
		    return mask;
	    }

		[Test]
		[TestCase(0, ExpectedResult = 0)]
		[TestCase(1, ExpectedResult = 10)]
		[TestCase(2, ExpectedResult = 90)]
		[TestCase(11, ExpectedResult = 110)]
		[TestCase(1692, ExpectedResult = 5076)]
		[TestCase(100000, ExpectedResult = 900000)]
		[TestCase(200000, ExpectedResult = 9000000)]
		[TestCase(1100000, ExpectedResult = 9900000)]
		[TestCase(169200000, ExpectedResult = 507600000)]

		public long Test01(int n)
		{
			return Solve(n);
		}

		[Test]
		public void Test02()
		{
			for (var i = 10000; i < 1000000; ++i)
			{
				var r = Solve(i);
				Console.WriteLine("Result for N = {0}: {1}. Iterations = {2}", i, r, r / i);
			}
		}
	}
}
