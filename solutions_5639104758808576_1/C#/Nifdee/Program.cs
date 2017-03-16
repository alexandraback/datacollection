using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StandingOvation {
	class Program {
		static void Main(string[] args) {
			var input = System.IO.File.ReadAllLines("input.txt");

			System.IO.File.WriteAllLines("output.txt", getFriendsNeeded(input));			
		}

		private static IEnumerable<string> getFriendsNeeded(string[] testCases) {
			for (int i = 1; i < testCases.Length; i++) {
				yield return string.Format("Case #{0}: {1}", i, getFriendsNeeded(testCases[i]));
			}
		}

		private static int getFriendsNeeded(string testCase) {
			var parts = testCase.Split(' ');
			int maxShyness = int.Parse(parts[0]);
			var amounts = parts[1].ToCharArray().Select(ch => int.Parse(ch.ToString())).ToArray();

			int friendsNeeded = 0;
			int sumStanding = amounts[0];
			for (int j = 1; j <= maxShyness; j++) {
				if (sumStanding < j) {
					friendsNeeded = Math.Max(friendsNeeded, j - sumStanding);
				}
				sumStanding += amounts[j];
			}
			return friendsNeeded;
		}
	}
}
