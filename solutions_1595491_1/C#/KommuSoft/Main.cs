using System;
using System.Collections.Generic;
using System.Linq;

namespace GCJ2
{
	class MainClass
	{
		public static void Main (string[] args) {
			int t = int.Parse(Console.ReadLine());
			for(int i = 1; i <= t; i++) {
				int[] cas = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
				//int n = cas[0];
				int s = cas[1];
				int p = cas[2];
				int p3 = 3*p;
				int N = 0;
				for(int j = 3; j < cas.Length; j++) {
					int l = cas[j];
					//Console.WriteLine("eval {0}",j);
					if(p3 <= l+2 && p <= l) {
						N++;
					}
					else if(s > 0 && p3 <= l+4 && p <= l) {
						s--;
						N++;
					}
				}
				Console.WriteLine("Case #{0}: {1}",i,N);
			}
		}
	}
}
