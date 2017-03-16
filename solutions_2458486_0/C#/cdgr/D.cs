using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace RAVE
{
	class TestCase
	{
		// Following an old map, you have stumbled upon the Dread Pirate Larry's secret treasure trove!

		// The treasure trove consists of N locked chests, each of which can only be opened by a key of a specific type.
		// Furthermore, once a key is used to open a chest, it can never be used again.
		// Inside every chest, you will of course find lots of treasure, and you might also find one or more keys
		// that you can use to open other chests.
		// A chest may contain multiple keys of the same type, and you may hold any number of keys.

		// You already have at least one key and your map says what other keys can be found inside the various chests.
		// With all this information, can you figure out how to unlock all the chests?

		// For example, suppose the treasure trove consists of four chests as described below,
		// and you began with exactly one key of type 1:

		// Chest Number  |  Key Type To Open Chest  |  Key Types Inside
		// --------------+--------------------------+------------------
		// 1             |  1                       |  None
		// 2             |  1                       |  1, 3
		// 3             |  2                       |  None
		// 4             |  3                       |  2

		// You can open all the chests in this example if you do them in the order 2, 1, 4, 3.
		// If you start by opening chest #1 first, then you will have used up your only key, and you will be stuck.

		// Each test case begins with a single line containing two positive integers K and N,
		// representing the number of keys you start with and the number of chests you need to open.
		// This is followed by a line containing K integers, representing the types of the keys that you start with.
		// After that, there will be N lines, each representing a single chest.
		// Each line will begin with integers Ti and Ki, indicating the key type needed to open the chest and the number
		// of keys inside the chest.
		// These two integers will be followed by Ki more integers, indicating the types of the keys contained within the chest.

		public TestCase(TextReader input)
		{
			var x = input.ReadInts();
			K = x[0]; N = x[1];
			Keys = input.ReadInts().ToArray();
			Chests = Enumerable.Range(0, N).Select(i => new Chest(i, input)).ToArray();
		}

		class Chest
		{
			public readonly int ChestNumber;
			public readonly int OpenKey;
			public readonly int[] KeysInside;

			public Chest(int i, TextReader input)
			{
				ChestNumber = i;
				var x = input.ReadInts();
				OpenKey = x[0]; int k = x[1];
				KeysInside = x.Skip(2).Take(k).ToArray();
			}
		}

		int K; // 1 ≤ K
		int N; // 1 ≤ N ≤ 20|200
		int[] Keys;
		Chest[] Chests;
		// All chest types and key types will be integers between 1 and 200 inclusive.
		// At most 40|400 keys altogether.

		public string GetResult()
		{
			// Return "C1 C2 ... CN", where Ci represents the index (starting from 1) of the ith chest that you should open.
			// If there are multiple ways of opening all the chests, choose the "lexicographically smallest" way.
			// In other words, you should choose to make C1 as small as possible, and if there are multiple ways of making C1 as small
			// as possible, choose the one that makes C2 as small as possible, and so on.
			// If there is no way to open all the chests, return "IMPOSSIBLE".

			foreach (var chest in Chests)
				++Need[chest.OpenKey];

			return EnoughKeysExist() && IsSolvable(0)
				? string.Join(" ", GetSolution().Select(c => (c.ChestNumber + 1).ToString()))
				: "IMPOSSIBLE";
		}

		private bool EnoughKeysExist()
		{
			return Need.Zip(CountKeys((1 << N) - 1), (n, e) => e >= n).All(b => b);
		}

		private int[] CountKeys(int openedChests)
		{
			int[] have = new int[201];
			foreach (var key in Keys)
				++have[key];
			foreach (var chest in Chests)
				if (IsOpened(chest, openedChests))
					foreach (var key in chest.KeysInside)
						++have[key];
			return have;
		}

		private IEnumerable<Chest> GetSolution()
		{
			int allChests = (1 << N) - 1, openedChests = 0;
			int[] have = CountKeys(0), used = new int[201];
			while (openedChests != allChests)
			{
				var chestToOpen = Chests.First(chest => !IsOpened(chest, openedChests) &&
					(have[chest.OpenKey] >= Need[chest.OpenKey] ||
						have[chest.OpenKey] - used[chest.OpenKey] > 0 && IsSolvable(openedChests | (1 << chest.ChestNumber))));
				yield return chestToOpen;
				openedChests |= 1 << chestToOpen.ChestNumber;
				foreach (var key in chestToOpen.KeysInside)
					++have[key];
				++used[chestToOpen.OpenKey];
			}
		}

		private bool IsOpened(Chest chest, int openedChests)
		{
			return (openedChests & (1 << chest.ChestNumber)) != 0;
		}

		Dictionary<int, bool?> Solvable = new Dictionary<int, bool?>();
		int[] Need = new int[201]; // Includes those for opened chests

		private bool IsSolvable(int openedChests)
		{
			bool? result = Solvable.GetValueOrDefault(openedChests);
			if (result.HasValue)
				return result.Value;

			int originalOpenedChests = openedChests;

			int allChests = (1 << N) - 1;

			int[] have = CountKeys(openedChests); // Includes keys used to open chests already.
			Chest[] chestsToOpen;
			while (openedChests != allChests && (chestsToOpen = Chests.Where(chest => !IsOpened(chest, openedChests) && have[chest.OpenKey] >= Need[chest.OpenKey]).ToArray()).Any())
				foreach (var chest in chestsToOpen)
				{
					foreach (var key in chest.KeysInside)
						++have[key];
					openedChests |= 1 << chest.ChestNumber;
				}

			if (openedChests == allChests)
				return (Solvable[originalOpenedChests] = true).Value;

			result = Solvable.GetValueOrDefault(openedChests);
			if (result.HasValue)
				return (Solvable[originalOpenedChests] = result).Value;

			int[] used = new int[201];
			Chests.Where(chest => IsOpened(chest, openedChests)).ForEach(chest => ++used[chest.OpenKey]);
			chestsToOpen = Chests.Where(chest => !IsOpened(chest, openedChests) && have[chest.OpenKey] - used[chest.OpenKey] != 0)
				.Select(chest => new { Chest = chest, Value = CountUsefulKeys(chest.KeysInside, have) })
				.OrderBy(x => x.Value).Select(x => x.Chest)
				.ToArray();
			foreach (var chest in chestsToOpen)
				if (IsSolvable(openedChests | (1 << chest.ChestNumber)))
					return (Solvable[originalOpenedChests] = Solvable[openedChests] = true).Value;

			return (Solvable[originalOpenedChests] = Solvable[openedChests] = false).Value;
		}

		private int CountUsefulKeys(int[] keysInside, int[] have)
		{
			int[] newKeys = new int[201];
			keysInside.ForEach(k => ++newKeys[k]);

			return Enumerable.Range(1, 200).Sum(i => Math.Min(newKeys[i], Math.Max(0, Need[i] - have[i])));
		}

		//public string GetResultS()
		//{

		//   int[] keyCounts = new int[201];
		//   foreach (var key in Keys)
		//      ++keyCounts[key];
		//   int[] chests = Enumerable.Range(0, N).ToArray();
		//   var s = Solve(chests, keyCounts);
		//   return s == null ? "IMPOSSIBLE" : string.Join(" ", s.Select(c => (c + 1).ToString()));
		//}

		//private LinkedList<int> Solve(int[] chests, int[] keyCounts)
		//{
		//   for (int chest = 0; chest != chests.Length; ++chest)
		//   {
		//      if (keyCounts[Chests[chests[chest]].OpenKey] != 0)
		//      {
		//         int[] keyCounts2 = keyCounts.ToArray();
		//         --keyCounts2[Chests[chests[chest]].OpenKey];
		//         foreach (var key in Chests[chests[chest]].KeysInside)
		//            ++keyCounts2[key];
		//         int[] chests2 = chests.Take(chest).Concat(chests.Skip(chest + 1)).ToArray();
		//         var s = Solve(chests2, keyCounts2);
		//         if (s != null)
		//         {
		//            s.AddFirst(chests[chest]);
		//            return s;
		//         }
		//      }
		//   }
		//   return chests.Length == 0 ? new LinkedList<int>() : null;
		//}
	}
}