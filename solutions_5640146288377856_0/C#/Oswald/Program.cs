using System;
using System.IO;
using System.Collections.Generic;
namespace CodejamAttempt
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			string[] lines = File.ReadAllLines ("test.txt");
			int total = Convert.ToInt32 (lines [0]);
			for (int i = 1; i <= total; i++) {
				int r;
				int c;
				int w;
				string[] rcw = lines [i].Split (new char[]{ ' ' }, 3);
				r = Convert.ToInt32 (rcw [0]);
				c = Convert.ToInt32 (rcw [1]);
				w = Convert.ToInt32 (rcw [2]);
				int perRow = (int) Math.Ceiling (((double)c) / ((double)w));
				int minimumChecks = perRow * r + w - 1;
				Console.WriteLine ("Case #{0}: {1}", i, minimumChecks);
			}
		}
	}
}
