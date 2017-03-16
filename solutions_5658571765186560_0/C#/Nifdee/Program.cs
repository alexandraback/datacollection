using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ominoes {
	class Program {
		static void Main(string[] args) {
			var input = System.IO.File.ReadAllLines("input.txt");

			System.IO.File.WriteAllLines("output.txt", processInput(input));
		}

		private static IEnumerable<string> processInput(string[] testCases) {
			for (int i = 1; i < testCases.Length; i++) {
				yield return string.Format("Case #{0}: {1}", i, canRichardWin(testCases[i]) ? "RICHARD" : "GABRIEL");
			}
		}

		private static bool canRichardWin(string testCase) {
			var numbers = testCase.Split(' ').Select(ch => int.Parse(ch)).ToArray();
			int x = numbers[0];
			int r = numbers[1];
			int c = numbers[2];

			return !divisible(x, r, c) || !largeEnough(x, Math.Min(r, c), Math.Max(r, c));
		}

		private static bool divisible(int x, int r, int c) {
			return (r * c) % x == 0;
		}

		private static bool largeEnough(int x, int min, int max) {
			switch (x) {
				case 1:
					return true;
				case 2:
					return max >= 2;
				case 3:
					return min >= 2 && max >= 3;
				case 4:
					return min >= 3 && max >= 4;
				case 5:
					return min >= 4 && max >= 5;
				case 6:
					return min >= 4 && max >= 6;
				default:
					return false;
			}
		}
	}
}
