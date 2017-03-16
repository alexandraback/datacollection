using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Globalization;
using System.IO;
using System.Numerics;

namespace ConsoleApplication1
{
	class GoogleCodeJam_2012_Qual
	{
		static void Main(string[] args)
		{
			var dt = DateTime.Now;
			Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
			var separators = new char[] { ' ', '\n', '\t', '\r' };
			string[] input;
			long answer = 0;
			var T = int.Parse(Console.In.ReadLine());

			using (var file = new StreamWriter("answer.txt"))
			{
				for (int test = 1; test <= T; test++)
				{
					input = Console.In.ReadLine().Split(separators, StringSplitOptions.RemoveEmptyEntries);

					var r = BigInteger.Parse(input[0]);
					var t = BigInteger.Parse(input[1]);

					long lo = 0;
					long hi = int.MaxValue;
					long N = 0;
					while (lo <= hi)
					{
						long n = lo + (hi - lo) / 2;
						if (t < (2 * r - 1) * n + 2 * n * n)
						{
							hi = n - 1;
							N = hi;
						}
						else if (t > (2 * r - 1) * n + 2 * n * n)
						{
							lo = n + 1;
							N = hi;
						}
						else
						{
							N = n;
							break;
						}
					}

					while (t < (2 * r - 1) * N + 2 * N * N)
					{
						N--;
					}

					answer = N;

					file.WriteLine(String.Format("Case #{0}: {1}", test, answer));
				}
			}
			//Console.WriteLine(DateTime.Now.Subtract(dt).TotalMilliseconds);
		}
	}
}