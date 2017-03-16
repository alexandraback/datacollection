using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
	class Program
	{

		static double Solve(int a, int b, List<double> p)
		{
			double res = 1 + b + 1;

			for (int i = 0; i < a; i++)
			{
				double cp = 1.0;

				for (int j = 0; j < a - i; j++)
					cp *= p[j];

				double cres = cp * (b - a + 2 * i + 1) + (1.0 - cp) * (b - a + 2 * i + 1 + b + 1.0);
				res = Math.Min(cres, res);
			}

			return res;
		}

		static void Main(string[] args)
		{
			using (StreamReader sr = new StreamReader("a.in"))
			{
				using (StreamWriter sw = new StreamWriter("a.out"))
				{
					int n = Int32.Parse(sr.ReadLine());
					int k = 1;
					while (n-- > 0)
					{
						string s = sr.ReadLine();

						string[] spl = s.Split(' ');

						int a = Int32.Parse(spl[0]);
						int b = Int32.Parse(spl[1]);

						s = sr.ReadLine();

						spl = s.Split(' ');

						List<double> p = new List<double>();
						for (int i = 0; i < spl.Length; i++)
							p.Add(Double.Parse(spl[i]));

						sw.WriteLine("Case #{0}: {1:F9}", k++, Solve(a, b, p));
					}
				}
			}
		}
	}
}
