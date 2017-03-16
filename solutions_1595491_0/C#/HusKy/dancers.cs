using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace ConsoleApplication1 {
	class Program {
		static void Main(string[] args) {
			String line;
			String[] split;
			int t, n, s, p, score;
			int g = 0;

			line = Console.ReadLine();
			t = Int32.Parse(line);

			for(int i = 0; i < t; i++) {
				line = Console.ReadLine();
				split = line.Split(' ');

				n = Int32.Parse(split[0]); // pocet googlerov
				s = Int32.Parse(split[1]); // prekvapive
				p = Int32.Parse(split[2]); // minimum

				for (int j = 3; j < split.Length; j++) {
					score = Int32.Parse(split[j]);

					if (score >= p) {
						if ((double)(score / 3) >= (double)p) {
							g++;
						} else {
							double rest = score - p;
							rest /= 2;
							if (rest >= (double)(p - 1)) {
								g++;
							} else if (rest >= (double)(p - 2) && s > 0) {
								g++; s--;
							}
						}
					}
				}

				Console.WriteLine("Case #{0}: {1}", i + 1, g);
				g = 0;
			}
		}
	}
}
