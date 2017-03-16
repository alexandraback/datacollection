using System;
using System.Linq;
using System.Collections.Generic;

namespace GCJ3
{
	class MainClass
	{
		public static void Main (string[] args) {
			int[] pow10s = new int[10];
			int p = 1;
			for(int i = 0; i < 10; i++) {
				pow10s[i] = p;
				p *= 10;
			}
			int T = int.Parse(Console.ReadLine());
			HashSet<int> cache = new HashSet<int>();
			for(int t = 1; t <= T; t++) {
				int[] cas = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
				int m = cas[0];
				int n = cas[1];
				int N = 0;
				if(m >= 10) {
					for(int i = m; i <= n; i++) {
						cache.Clear();
						int L = (int) Math.Floor(Math.Log10(i))+1;
						for(int l = 1; l < L; l++) {
							int ia = i/pow10s[l]+(i%pow10s[l])*pow10s[L-l];
							if(ia > i && ia <= n && !cache.Contains(ia)) {
								cache.Add(ia);
								N++;
							}
						}
					}
				}
				Console.WriteLine("Case #{0}: {1}",t,N);
			}
		}
	}
}
