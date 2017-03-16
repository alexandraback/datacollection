using System;
using System.IO;
using System.Collections.Generic;


namespace C
{
	class Problem
	{
		int n;

		List<int> d, m;


		int [] getvec(string s)
		{
			int[] v;
			string[] x = s.Split (' ');

			v = new int[x.Length];

			for (int i = 0; i < v.Length; i++)
				v [i] = int.Parse (x [i]);

			return v;
		}

		public Problem(TextReader r)
		{
			n = int.Parse (r.ReadLine ());
			d = new List<int> ();
			m = new List<int> ();

			for (int i = 0; i < n; i++) {
				int[] v = getvec(r.ReadLine());
			
				for (int j = 0; j < v [1]; j++) {
					d.Add (v [0]);
					m.Add (v [2] + j);
				}
			}

			n = d.Count;


		}





		public string Solve()
		{

			int best = n;

			for (int i = 0; i < (1 << n); i++) {
				double min = 0;
				double max = 1000000;
				int count = 0;

				for (int j = 0; j < n; j++) {
		
					if (((1 << j) & i) != 0
					) {
						count++;
						continue;
					}
					double a = (360 - d [j]) / 360.0 * m [j];
					double b = (720 - d [j]) / 360.0 * m [j];

					if (a > min)
						min = a;
					if (b < max)
						max = b;
				}

				if (min < max && count < best)
					best = count;
				
			}
			

			return ""+best;
		}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			TextReader r = new StreamReader (args [0]);


			int t = int.Parse(r.ReadLine ());

			for (int i = 1; i <= t; i++) {
				Problem p = new Problem (r);

				string sol = p.Solve ();

				Console.WriteLine ("Case #{0}: {1}", i, sol);
			}

		}
	}
}
