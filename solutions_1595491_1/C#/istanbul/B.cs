using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace codejam.QualificationRound2012
{
	class B
	{
		static IOHelper io;
		static void Main(string[] args)
		{
			using (io = new IOHelper("B-large-0"))
			{
				int nCases = io.ReadInt();
				for (int _case = 1; _case <= nCases; _case++)
				{
					var p = io.ReadIntArray();
					var N = p[0];
					var S = p[1];
					var P = p[2];
					var r = 0;
					for (int i = 0; i < N; i++)
					{
						var t = p[i + 3];
						if (t >= P)
						{
							if (t >= P * 3 - 2) r++;
							else if (t >= P * 3 - 4 && S-- > 0) r++;
						}
					}


					io.WriteLine("Case #{0}: {1}", _case, r);
				}
			}
		}
	}
}
