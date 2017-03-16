using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qualification2016
{
	class Program
	{
		static int ReadIntLine()
		{
			string line = Console.ReadLine();
			return int.Parse(line);
		}

		static void Main()
		{
			int T = ReadIntLine();

			for(int t = 1; t <= T; t++) {
				string S = Console.ReadLine().Trim();

				
				char last = 'X';
				int flips = 0;
				foreach (char c in S.TrimEnd('+'))
				{
					if (c != last)
						flips++;
					last = c;
				}
				
				Console.WriteLine("Case #" + t + ": " + flips);
			}
		}
	}
}
