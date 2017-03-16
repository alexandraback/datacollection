﻿using System;
using System.IO;
using System.Collections.Generic;
namespace CodejamAttempt
{
	class MainClass
	{
		public static HashSet<ulong> possible;
		public static List<ulong> coins;
		public static int repeats;
		public static ulong bigV;
		public static void getPossible(int highest, int depth, ulong total){
			if (total > bigV) {
				return;
			}
			possible.Add (total);
			if (depth == repeats) {
				if (highest == 0) {
					return;
				}
				depth = 0;
				highest--;
			}
		//	Console.WriteLine ("{0} : {1}", total, highest);
		//	Console.WriteLine (coins [highest]);
			getPossible (highest, depth + 1, total + coins [highest]);
			for (int i = highest - 1; i >= 0; i--) {
				getPossible (i, 1, total + coins [i]);
			}
		}
		public static ulong largestImpossible;
		public static void Main (string[] args)
		{
			string[] lines = File.ReadAllLines ("test.txt");
			int total = Convert.ToInt32 (lines [0]);
			for (int i = 1; i <= total; i++) {
				possible = new HashSet<ulong> ();
				coins = new List<ulong> ();
				largestImpossible = 1;
				string[] cdv = lines [(i - 1) * 2 + 1].Split (new char[]{ ' ' }, 3);
				int c = Convert.ToInt32 (cdv [0]);
				int d = Convert.ToInt32 (cdv [1]);
				ulong v = Convert.ToUInt64 (cdv [2]);
				bigV = v;
				repeats = c;
				//Console.WriteLine (repeats);
				string[] theCoins = lines [(i - 1) * 2 + 2].Split (new char[]{ ' ' }, d);
				for (int q = 0; q < d; q++) {
					coins.Add (Convert.ToUInt64 (theCoins [q]));
				}
				for (int q = 0; q < coins.Count; q++) {
					getPossible (q, 1, coins[q]);	
				}
				int totalAdded = 0;
				for (ulong q = largestImpossible; q <= v + 1; q++) {
					if (!possible.Contains (q)) {
						largestImpossible = q;
						break;
					}
				}
			//	Console.WriteLine (largestImpossible);
			//	Console.WriteLine (v);
			//	Console.WriteLine ();
				foreach (ulong n in possible) {
				//	Console.WriteLine (":{0}", n);
				}
				while (largestImpossible <= v) {
					ulong oldLargest = largestImpossible;
					largestImpossible = v + 1;
					for (ulong q = oldLargest; q <= v + 1; q++) {
						if (!possible.Contains (q)) {
							largestImpossible = q;
							break;
						}
					}
					if (largestImpossible > v) {
						break;
					}
					totalAdded++;
					coins.Add (largestImpossible);
					for (int q = 0; q < coins.Count; q++) {
						getPossible (q, 1, coins[q]);	
					}
				//	Console.WriteLine (largestImpossible);
				//	Console.WriteLine (v);
					foreach (ulong n in possible) {
				//		Console.WriteLine (n);
					}
				}
				Console.WriteLine ("Case #{0}: {1}", i, totalAdded);
			}
		}
	}
}