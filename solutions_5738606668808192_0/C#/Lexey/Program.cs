using System;
using System.Collections.Generic;
using System.Diagnostics;
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
		private static readonly List<long> Primes_ = new List<long> {2, 3, 5, 7};
		private static readonly long PrimePrecalcLimit = 0x40000;

		static void Main(string[] args)
		{
			using (var reader = new StreamReader(args[0], Encoding.ASCII))
			using (var writer = new StreamWriter(args[0] + ".out", false, Encoding.ASCII))
			{
				var cases = int.Parse(reader.ReadLine());
				Console.WriteLine("Cases {0}", cases);
				for (var i = 1; i <= cases; ++i)
				{
					var parameters = reader.ReadLine().Split(new[] { ' ' });
					var n = int.Parse(parameters[0]);
					var j = int.Parse(parameters[1]);
					var result = GenerateCandidates(n, j);
					writer.WriteLine("Case #{0}:", i);
					foreach (var r in result)
					{
						writer.WriteLine("{0} {1}", Convert.ToString(r.Number, 2), string.Join(" ", r.DivisorsByBase));
					}
				}
			}
		}

		private static List<Result> GenerateCandidates(int n, int maxCount)
		{
			UpdatePrimes(PrimePrecalcLimit); // in base 2 max is 2**32 - 1. So, primes are less than 2**16
			var r = new List<Result>();
			var limit = 1u << (n - 2);
			var candidate = (1u << (n - 1)) + 1;
			for (var i = 0; i < limit; ++i, candidate += 2)
			{
				var d = GetDivisor(candidate);
				if (d <= 0)
				{
					continue;
				}
				var divisors = new List<long> {d};
				for (var @base = 3; @base <= 10; ++@base)
				{
					var basedNumber = ToBaseN(candidate, @base);
					var d2 = GetDivisor(basedNumber);
					if (d2 <= 0)
					{
						break;
					}
					divisors.Add(d2);
				}
				if (divisors.Count < 9)
				{
					continue;
				}
				var v = new Result
				{
					Number = candidate,
					DivisorsByBase = divisors.ToArray()
				};
				r.Add(v);
				if (r.Count == maxCount)
				{
					return r;
				}
			}
			return r;
		}

		private static long GetDivisor(uint candidate)
		{
			var limit = Math.Ceiling(Math.Sqrt(candidate));
			foreach (var p in Primes_)
			{
				if (p > limit)
				{
					return 0; // number is prime
				}
				if (candidate % p == 0)
				{
					return p;
				}
			}
			return -1; //end of list reached
		}

		private static BigInteger Sqrt(BigInteger value)
		{
			return BigInteger.Pow(10, (int)Math.Ceiling(BigInteger.Log10(value) / 2));
		}

		private static long GetDivisor(BigInteger candidate)
		{
			
			var limit = Sqrt(candidate);
			foreach (var p in Primes_)
			{
				if (p > limit)
				{
					return 0; // number is prime
				}
				if (candidate % p == 0)
				{
					return p;
				}
			}
			return -1; //end of list reached
		}


		private static void UpdatePrimes(long limit)
		{
			for (var candidate = Primes_.Last() + 2; candidate < limit; candidate += 2)
			{
				var t = candidate;
				if (Primes_.AsParallel().All(_ => t % _ != 0))
				{
					Primes_.Add(t);
				}
			}
		}

		private static BigInteger ToBaseN(uint number, int @base)
		{
			var result = new BigInteger();
			const int maxBits = 32;
			var mask = 1u << (maxBits - 1);
			for (var i = 0; i < maxBits; ++i)
			{
				result *= @base;
				if ((number & mask) != 0)
				{
					result += 1;
				}
				mask >>= 1;
			}
			return result;
		}

		[Test]
		public void Test01()
		{
			UpdatePrimes(30);
			Assert.That(Primes_, Is.EquivalentTo(new [] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 }));
		}

		[Test]
		public void Test02()
		{
			Console.WriteLine("Benchmarking primes generation upto {0}", PrimePrecalcLimit);
			var sw = Stopwatch.StartNew();
			UpdatePrimes(PrimePrecalcLimit);
			Console.WriteLine("Generated {0} primes in {1}", Primes_.Count, sw.Elapsed);
		}

		[Test]
		[TestCase(0x3, 2, ExpectedResult = 3)]
		[TestCase(0x5, 2, ExpectedResult = 5)]
		[TestCase(0x3, 3, ExpectedResult = 4)]
		[TestCase(0x3, 7, ExpectedResult = 8)]
		[TestCase(0x3, 10, ExpectedResult = 11)]
		public long Test03(uint value, int @base)
		{
			return (long)ToBaseN(value, @base);
		}



		[Test]
		public void Test04()
		{
			const int n = 16;
			Console.WriteLine("Benchmarking candidates generation for N = {0}", n);
			var sw = Stopwatch.StartNew();
			var result = GenerateCandidates(n, 50);
			Assert.That(result.Count, Is.EqualTo(50));
			ValidateResults(result);
			Console.WriteLine("Generated {0} candidates {1}", result.Count, sw.Elapsed);
		}

		[Test]
		public void Test05()
		{
			const int n = 32;
			Console.WriteLine("Benchmarking candidates generation for N = {0}", n);
			var sw = Stopwatch.StartNew();
			var result = GenerateCandidates(n, 500);
			Console.WriteLine("Generated {0} candidates {1}", result.Count, sw.Elapsed);
		}

		private static void ValidateResults(IReadOnlyList<Result> results)
		{
			foreach (var r in results)
			{
				for (var @base = 2; @base <= 10; ++@base)
				{
					var v = ToBaseN(r.Number, @base);
					var t = v % r.DivisorsByBase[@base - 2];
					Assert.That(t, Is.EqualTo(BigInteger.Zero));
				}
			}
		}

		internal struct Result
		{
			public uint Number;
			public long[] DivisorsByBase;
		}
	}
}
