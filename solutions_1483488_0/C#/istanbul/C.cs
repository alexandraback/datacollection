using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace codejam.QualificationRound2012
{
	class C
	{
		static IOHelper io;
		static void Main(string[] args)
		{
			using (io = new IOHelper("C-small-attempt0"))
			{
				int nCases = io.ReadInt();
				for (int _case = 1; _case <= nCases; _case++)
				{
					int min, max, r=0;
					io.ReadTuple(out min, out max);
					for (int i = min; i < max; i++)
					{
						r += Calc(i, max);
					}
					io.WriteLine("Case #{0}: {1}", _case, r);
				}
			}
		}

		static int Calc(int n, int max)
		{
			var r = 0;
			var d = GetDigits(n);
			int[] duplicates = new int[d];
			for (int i = 0; i < d; i++)
			{
				var p = Pad(n, i, d);
				if (Array.IndexOf(duplicates, p) == -1)
				{
					duplicates[i] = p;
					if (n < p && p <= max) r++;
				}
			}
			return r;
		}

		static int Pad(int n, int p, int d)
		{
			int f = (int)Math.Pow(10, d - p);
			return n % f * (int)Math.Pow(10, p) + n / f;
		}

		static int GetDigits(int n)
		{
			int d;
			if (n > 1e8) d = 9;
			else if (n > 1e7) d = 8;
			else if (n > 1e6) d = 7;
			else if (n > 1e5) d = 6;
			else if (n > 1e4) d = 5;
			else if (n > 1e3) d = 4;
			else if (n > 1e2) d = 3;
			else if (n > 1e1) d = 2;
			else d = 1;
			return d;
		}
	}
}
