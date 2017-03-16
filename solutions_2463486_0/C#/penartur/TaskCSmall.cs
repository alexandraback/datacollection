using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace QualificationRound2013 {
	class TaskCSmall {
		private static readonly long[] precalc = new long[] {
			0,
			1,
			4,
			9,
			121,
			484,
			10201,
			12321,
			14641,
			40804,
			44944,
			1002001,
			1234321,
			4008004,
			100020001,
			102030201,
			104060401,
			121242121,
			123454321,
			125686521,
			400080004,
			404090404,
			10000200001,
			10221412201,
			12102420121,
			12345654321,
			40000800004,
			1000002000001,
			1002003002001,
			1004006004001,
			1020304030201,
			1022325232201,
			1024348434201,
			1210024200121,
			1212225222121,
			1214428244121,
			1232346432321,
			4000008000004,
			4004009004004,
			100000020000001,
		};

		public static int Test(long min, long max) {
			int result = 0;
			for(int i=0; i<precalc.Length; i++) {
				if(precalc[i] >= min && precalc[i] <= max) {
					result++;
				}
			}
			return result;
		}

		public static void Run() {
			int T = int.Parse(Console.ReadLine());
			for(int i=1; i<=T; i++) {
				string[] parts = Console.ReadLine().Split(' ');
				Console.WriteLine("Case #{0}: {1}", i, Test(long.Parse(parts[0]), long.Parse(parts[1])));
			}
		}
	}
}
