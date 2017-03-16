using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace JamCoin
{
	public static class PrimeChecker
	{
		public static readonly BigInteger NOT_FOUND = -1;

		private static BigInteger[] primes;
		public static BigInteger MaxPrime { get; private set; }

		static PrimeChecker()
		{
			// Preload list of prime numbers.
			List<BigInteger> tempList = new List<BigInteger>();
			for (int fileNumber = 1; fileNumber <= 6; fileNumber++)
			{
				string filename = "2T_part" + fileNumber + ".txt";
				Console.WriteLine("Reading " + filename);
				foreach (string line in File.ReadLines(filename, Encoding.Default))
				{
					foreach (string strprime in line.Split('\t'))
						tempList.Add(BigInteger.Parse(strprime));
				}
			}

			primes = tempList.ToArray();
			MaxPrime = primes[primes.Length - 1];


			/*
			primes = new BigInteger[BufferSize];
			primes[0] = 2;
			BigInteger x = 3;
			for (int i = 1; i < primes.Length; x += 2)
			{
				if (IsPrime(x, i))
					primes[i++] = x;
			}
			MaxPrime = primes[primes.Length - 1];
			 */ 
		}

		public static BigInteger GetDivisorWithFalseNegatives(BigInteger value)
		{
			if (value <= MaxPrime && Array.BinarySearch(primes, value) >= 0)
				return NOT_FOUND; // It's a known prime.

			BigInteger divisor = GetDivisor(value, primes.Length);
			return divisor;
		}

		public static BigInteger GetDivisor(BigInteger value)
		{
			if (value <= MaxPrime && Array.BinarySearch(primes, value) >= 0)
				return NOT_FOUND; // It's a known prime.

			BigInteger divisor = GetDivisor(value, primes.Length);
			if (divisor == NOT_FOUND)
				divisor = GetDivisorForLarger(value);

			return divisor;
		}

		public static bool IsPrime(BigInteger value)
		{
			if (value <= MaxPrime)
			{
				return Array.BinarySearch(primes, value) >= 0;
			}
			else
			{
				return IsPrime(value, primes.Length) && IsLargerPrime(value);
			}
		}

		private static bool IsPrime(BigInteger value, int primesLength)
		{
			return GetDivisor(value, primesLength) == NOT_FOUND;
		}

		private static BigInteger GetDivisor(BigInteger value, int primesLength)
		{
			for (int i = 0; i < primesLength; ++i)
			{
				if (value % primes[i] == 0)
					return primes[i];
			}
			return NOT_FOUND;
		}

		private static bool IsLargerPrime(BigInteger value)
		{
			return GetDivisorForLarger(value) == NOT_FOUND;
		}

		private static BigInteger GetDivisorForLarger(BigInteger value)
		{
			BigInteger max = (BigInteger)Math.Sqrt((double)value);
			for (BigInteger i = MaxPrime + 2; i <= max; i += 2)
			{
				if (value % i == 0)
					return i;
			}
			return NOT_FOUND;
		}
	}
}
