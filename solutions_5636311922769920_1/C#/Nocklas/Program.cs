using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qualification2016
{
	class ProgramB
	{
		static int ReadIntLine()
		{
			string line = Console.ReadLine();
			return int.Parse(line);
		}


		static int[] ReadIntsLine()
		{
			string line = Console.ReadLine();
			return line.Trim().Split(' ').Select(x => int.Parse(x)).ToArray();
		}

		static void Main()
		{

			int T = ReadIntLine();

			for(int t = 1; t <= T; t++) {
				var line = ReadIntsLine();
				int K = line[0];
				int C = line[1];
				int S = line[2];

				long E = 1;
				for(int p = 0; p < C; p++)
				{
					E *= K; 
				}

				int min = K / C + (K % C > 0 ? 1 : 0);

				string result = " IMPOSSIBLE";
				if (S >= min)
				{
					result = "";
               for (int x = 0; x < min; x++)
					{
						int i = x * C;

						long step = E;
						long from = 0;

						int c = C;
						while(c >= 1 && i < K)
						{
							step /= K;

							from += i * step;

							c--;
							i++;
						}

						result += " " + (from + 1);
					}
				}
				Console.WriteLine("Case #" + t + ":" + result);
			}
		}
	}
}
