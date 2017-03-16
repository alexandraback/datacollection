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
			var answer = 0;
			var T = int.Parse(Console.In.ReadLine());

			using (var file = new StreamWriter("answer.txt"))
			{
				for (int test = 1; test <= T; test++)
				{
					input = Console.In.ReadLine().Split(separators, StringSplitOptions.RemoveEmptyEntries);

					var r = BigInteger.Parse(input[0]);
					var t = BigInteger.Parse(input[1]);

					var count = 0;
					while (t >= 0)
					{
						t -= (r + 1) * (r + 1) - r * r;
						count++;
						r += 2;
					}

					count--;

					answer = count;

					file.WriteLine(String.Format("Case #{0}: {1}", test, answer));
				}
			}
			//Console.WriteLine(DateTime.Now.Subtract(dt).TotalMilliseconds);
		}
	}
}