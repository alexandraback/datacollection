using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace JamCoin
{
	public static class PrimeChecker
	{
		private const int BufferSize = 64 * 1024; // 256K * sizeof(long) == 2MB
		public const long NOT_FOUND = -1;

		private static long[] primes;
		public static long MaxPrime { get; private set; }

		static PrimeChecker()
		{
			primes = new long[BufferSize];
			primes[0] = 2;
			for (long i = 1, x = 3; i < primes.Length; x += 2)
			{
				if (IsPrime(x, i))
					primes[i++] = x;
			}
			MaxPrime = primes[primes.Length - 1];
		}

		public static long GetDivisor(long value)
		{
			if (value <= MaxPrime && Array.BinarySearch(primes, value) >= 0)
				return NOT_FOUND; // It's a known prime.

			long divisor = GetDivisor(value, primes.Length);
			if (divisor == NOT_FOUND)
				divisor = GetDivisorForLarger(value);

			return divisor;
		}

		public static bool IsPrime(long value)
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

		private static bool IsPrime(long value, long primesLength)
		{
			return GetDivisor(value, primesLength) == NOT_FOUND;
		}

		private static long GetDivisor(long value, long primesLength)
		{
			for (long i = 0; i < primesLength; ++i)
			{
				if (value % primes[i] == 0)
					return primes[i];
			}
			return NOT_FOUND;
		}

		private static bool IsLargerPrime(long value)
		{
			return GetDivisorForLarger(value) == NOT_FOUND;
		}

		private static long GetDivisorForLarger(long value)
		{
			long max = (long)Math.Sqrt(value);
			for (long i = MaxPrime + 2; i <= max; i += 2)
			{
				if (value % i == 0)
					return i;
			}
			return NOT_FOUND;
		}
	}
}
