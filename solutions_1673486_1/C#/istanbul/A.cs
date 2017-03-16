// IOHelper.cs can be downloaded from http://kadiryazgan.com/codejam/IOHelper.cs.txt

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace codejam.Round1A2012
{
	class A
	{
		static IOHelper io;
		static void Main(string[] args)
		{
			using (io = new IOHelper("A-large-0"))
			{
				int nCases = io.ReadInt();
				for (int _case = 1; _case <= nCases; _case++)
				{
					int typed, total;
					io.ReadValues(out typed, out total);
					var ar = io.ReadDoubleArray();
					double result = total + 2.0;

					for (int b = 0; b < typed; b++)
					{
						double prob = 1;
						for (int i = 0; i < typed - b; i++)
						{
							prob = prob * ar[i];
						}
						var rest = total - typed + 1 + b * 2;
						double strokes = rest * prob + (rest + total + 1) * (1 - prob);
						if (strokes < result) result = strokes;
						else if (b > 1000 && strokes > result) break;
						//Console.WriteLine("rest={0}, a={1}, prop={2}", rest, strokes, prob);
					}
					//Console.WriteLine();					

					io.WriteLine("Case #{0}: {1:0.000000}", _case, result);
				}
			}
		}

		static int Solve()
		{
			return 0;
		}
	}
}
