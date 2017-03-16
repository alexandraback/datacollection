using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Runtime;
using System.Runtime.CompilerServices;

namespace CodeJam {
	class C : CodeJamProblem {
		protected override string InputFile { get; } = "C-large.in";
		protected override string OutputFile { get; } = "C-large.out";
		protected override string OutputFormat { get; } = "Case #{0}:\r\n{1}";

		private C(Func<TestCase, IDictionary<object, object>, string> solverFunc) : base(solverFunc) {
		}

		private static BigInteger SqrtN(BigInteger n) {
			/*++
             *  Using Newton Raphson method we calculate the
             *  square root (N/g + g)/2
             */
			BigInteger rootN = n;
			int count = 0;
			int bitLength = 1; // There is a bug in finding bit length hence we start with 1 not 0
			while(rootN/2 != 0) {
				rootN /= 2;
				bitLength++;
			}
			bitLength = (bitLength + 1)/2;
			rootN = n >> bitLength;

			BigInteger lastRoot = BigInteger.Zero;
			do {
				if(lastRoot > rootN) {
					if(count++ > 1000) // Work around for the bug where it gets into an infinite loop
					{
						return rootN;
					}
				}
				lastRoot = rootN;
				rootN = (BigInteger.Divide(n, rootN) + rootN) >> 1;
			} while((rootN ^ lastRoot).ToString() != "0");
			return rootN;
		}

		private static BigInteger? GetFirstFactor(BigInteger number) {
			BigInteger max = SqrtN(number);  //round down
			for(BigInteger factor = 2; factor <= 20 /* Non-exhaustive check */; ++factor) { //test from 1 to the square root, or the int below it, inclusive.
				if(number % factor == 0) {
					return factor;
				}
			}
			return null;
		}

		private static BigInteger ParseInRadix(string number, int radix) {
			BigInteger result = 0;
			
			int pos = 0;
			while(pos < number.Length) {
				int digit = int.Parse(number.Substring(pos++, 1));
				result *= radix;
				result += digit;
			}
			// Return true if any characters processed
			return result;
		}

		private static bool IsPrime(BigInteger number) {
			if(number < 2) return false;
			if(number % 2 == 0) return (number == 2);
			BigInteger root = SqrtN(number);
			for(int i = 3; i <= root && i < 200000 /* Non-exhaustive check */; i += 2) {
				if(number%i == 0) {
					return false;
				}
			}
			return true;
		}

		private static BigInteger[] GetJamcoinProof(string number) {
			BigInteger[] proof = new BigInteger[9];
			for(var i = 2; i <= 10; i++) {
				BigInteger parsedNumber = ParseInRadix(number, i);
				if(IsPrime(parsedNumber)) {
					return null;
				}
				BigInteger? baseProof = GetFirstFactor(parsedNumber);
				if(baseProof.HasValue) {
					proof[i - 2] = baseProof.Value;
				} else {
					return null;
				}
			}
			return proof;
		}

		static void Main(string[] args) {
			CodeJamProblem c = new C((testCase, cache) => {
				var n = int.Parse(testCase.Input.Split(' ')[0]);
				var j = int.Parse(testCase.Input.Split(' ')[1]);

				var startString = '1' + new string('0', n - 2) + '1';
				var startNumber = Convert.ToInt64(startString, 2);
				var endString = new string('1', n);
				var endNumber = Convert.ToInt64(endString, 2);

				var jamcoins = new Dictionary<string, BigInteger[]>();
				for(var i = startNumber; i <= endNumber && jamcoins.Count < j; i++) {
					var jamcoin = Convert.ToString(i, 2);
					if(jamcoin.First() == '1' && jamcoin.Last() == '1') {
						BigInteger[] proof = GetJamcoinProof(jamcoin);
						if(proof != null) {
							jamcoins.Add(jamcoin, proof);
						}
					}
				}

				return string.Join("\r\n", jamcoins.Select(jc => jc.Key + " " + string.Join(" ", jc.Value)));
			});
		}
	}
}
