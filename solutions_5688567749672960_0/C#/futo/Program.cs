using System;
using System.IO;
using System.Collections.Generic;


namespace A
{
	class Problem
	{
		long n;

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
			n = long.Parse (r.ReadLine ());
		}

		public long reverse(long r)
		{
			while (r != 0 && r % 10 == 0)
				r = r / 10;

			long x = 0;

			while (r != 0) {
				x = x * 10 + r % 10;
				r = r / 10;
			}

			return x;
		}

		public string Solve()
		{
			System.Collections.Generic.Dictionary<long, int> map = new Dictionary<long, int> ();

			List<long> q = new List<long>();
			Dictionary<long, long> prev = new Dictionary<long, long> ();

			map [1] = 1;
			q.Add (1);

			int count = 2;

			List<long> w;


			while (q.Count > 0) {

				w = new List<long>();;
				q.Sort ();

				for(int i = Math.Max(0, q.Count - 1000); i<q.Count; i++)
				{
					long v = q [i];

					long x = v + 1;
					long y = reverse (v);

					if (!map.ContainsKey (x) && x <= n) {
						map [x] = count;
						w.Add (x);
						prev [x] = v;
					}

					if (!map.ContainsKey (y) && y <= n) {
						map [y] = count;
						w.Add (y);
						prev [y] = v;
					}
				}

				q = w;

			
				count++;
			}



			

			return ""+map[n];
		}
	}

	class MainClass
	{
		public static void Main (string[] args)
		{
			TextReader r = new StreamReader (args [0]);
			TextWriter w = new StreamWriter (args [0] + ".out");


			int t = int.Parse(r.ReadLine ());

			for (int i = 1; i <= t; i++) {
				Problem p = new Problem (r);

				string sol = p.Solve ();

				Console.WriteLine ("Case #{0}: {1}", i, sol);
			}

		}
	}
}
