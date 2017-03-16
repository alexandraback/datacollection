using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pancakes {
	class Program {
		static void Main(string[] args) {
			var input = System.IO.File.ReadAllLines("input.txt");

			System.IO.File.WriteAllLines("output.txt", solveInput(input));
		}

		private static IEnumerable<string> solveInput(string[] testCases) {
			for (int i = 2; i < testCases.Length; i += 2) {
				yield return string.Format("Case #{0}: {1}", i / 2, solveTestCase(testCases[i]));
			}
		}

		private static int solveTestCase(string testData) {
			var amounts = testData.Split(' ').Select(c => int.Parse(c)).OrderByDescending(a => a);
			int maximum = amounts.First();
			int minimum = maximum;

			for (int i = maximum; i > 0; i--) {
				int numSpecialMinutes = amounts.Aggregate(0, (sum, amount) => sum + (amount - 1) / i);
				minimum = Math.Min(minimum, numSpecialMinutes + i);
			}

			return minimum;
		}
	}
}
