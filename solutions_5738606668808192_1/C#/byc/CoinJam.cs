using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CJ2016QualRound {
	public class CoinJam {
		public static void Main(string[] args) {
			new CoinJam().Solve(Console.In, Console.Out);
		}

		public void Solve(TextReader reader, TextWriter writer) {
			int maxSmallPrime = 50;
			HashSet<long> smallPrimesSet = new HashSet<long>(Enumerable.Range(2, maxSmallPrime - 2).Select(x => (long)x));

			for (int prime = 2; prime * prime <= maxSmallPrime; prime++) {
				if (smallPrimesSet.Contains(prime)) {
					for (int multiple = prime * prime; multiple < maxSmallPrime; multiple += prime) {
						smallPrimesSet.Remove(multiple);
					}
				}
			}

			long[] smallPrimes = smallPrimesSet.OrderBy(x => x).ToArray();

			// writer.WriteLine($"generated {smallPrimes.Length} primes up to {maxSmallPrime}");

			int numTests = int.Parse(reader.ReadLine());
			for (int i = 0; i < numTests; i++) {
				string[] line = reader.ReadLine().Split();
				int N = int.Parse(line[0]);
				int numRemaining = int.Parse(line[1]);

				writer.WriteLine($"Case #{i + 1}:");

				foreach (string binString in GetBinaryStrings(N)) {
					bool valueDefinitelyCoinJam = true;

					List<long> divisors = new List<long>();

					for (int fromBase = 2; fromBase <= 10; fromBase++) {
						long value = ParseBase(binString, fromBase);
						bool valueDefinitelyComposite = false;
						foreach (long prime in smallPrimes) {
							if (prime * prime > value) {
								divisors.Add(prime);
								break;
							} else if (Divides(value, prime)) {
								divisors.Add(prime);
								valueDefinitelyComposite = true;
								break;
							}
						}
						if (!valueDefinitelyComposite) {
							valueDefinitelyCoinJam = false;
							break;
						}
					}

					if (valueDefinitelyCoinJam) {
						writer.WriteLine($"{binString} " + string.Join(" ", divisors));
						numRemaining -= 1;
					}

					if (numRemaining == 0) {
						Console.Error.WriteLine("stderr: found solution");
						break;
					}
				}
			}
		}

		private bool Divides(long value, long divisor) {
			return (value % divisor) == 0;
		}

		private long ParseBase(string s, int fromBase) {
			long value = 0;
			foreach (char c in s) {
				value *= fromBase;
				value += (c - '0');
			}
			return value;
		}

		private IEnumerable<string> GetBinaryStrings(int size) {
			long offset = ((long)1 << (size - 1)) + 1;
			for (long i = 0; i < (long)1 << (size - 2); i++) {
				yield return Convert.ToString(offset + i * 2, 2);
			}
		}
	}
}