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
			int location = 1;
			for (int i = 1; i <= total; i++) {
				int k;
				int l;
				int s;
				string[] kls = lines [location++].Split (new char[]{ ' ' }, 3);
				k = Convert.ToInt32 (kls [0]);
				l = Convert.ToInt32 (kls [1]);
				s = Convert.ToInt32 (kls [2]);
				List<char> keys=new List<char>();
				Dictionary<char, int> appearances = new Dictionary<char, int> ();
				string theKeys = lines [location++];
				for (int q = 0; q < theKeys.Length; q++) {
					keys.Add (theKeys [q]);
				}
				double answer = 0;
				string goal = lines [location++];
				bool possible = true;
				for (int q = 0; q < goal.Length; q++) {
					if (!keys.Contains (goal [q])) {
						possible = false;
						break;
					}
				}
				double toBring=0;
				if (possible) {
					double probability = 1;
					foreach (char n in keys) {
						if (appearances.ContainsKey (n)) {
							appearances [n]++;
						} else {
							appearances.Add (n, 1);
						}
					}
					int overlap = 0;
					for (int q = 1; q < l; q++) {
						if (goal.Substring (0, q) == goal.Substring (l - q, q)) {
							overlap = q;
						}
					}
					toBring = (s - overlap) / (l - overlap);
					for (int q = 0; q < l; q++) {
						probability *= ((double)appearances [goal[q]]) / ((double)k);
					}
					//Console.WriteLine ("{0} : {1}", probability, toBring);
					//Console.WriteLine ("{0} : {1} : {2}", k, l, s);
					answer = probability;
				}
				double theResult = toBring - (answer * (s - l + 1));
				Console.WriteLine ("Case #{0}: {1:N7}", i, theResult);
			}
		}
	}
}
