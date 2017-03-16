using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace B
{
	class Program
	{
		static int Solve(List<int> data)
		{
			int n = data.Count;
			bool[] used1 = new bool[n];
			bool[] used2 = new bool[n];

			int res = 0;
			int c = 0;
			int rem = n;

			while (rem > 0)
			{
				bool found = false;
				int max = 0;
				int imax = -1;

				res++;

				for (int i = 0; i < n; i++)
				{
					if (!used2[i] && data[i] % 10000 <= c)
					{
						found = true;
						used2[i] = true;
						

						if (!used1[i])
							c += 2;
						else
							c++;
						used1[i] = true;
						rem--;
						break;
					}
				}

				if (found)
					continue;

				for (int i = 0; i < n; i++)
				{
					if (!used1[i] && data[i] / 10000 <= c)
					{
						if (data[i] % 10000 > max)
						{
							max = data[i] % 10000;
							imax = i;
						}
					}
				}

				if (imax >= 0)
				{
					c++;
					used1[imax] = true;
					continue;
				}

				return -1;
			}
			return res;

		}

		static void Main(string[] args)
		{
			using (StreamReader sr = new StreamReader("b.in"))
			{
				using (StreamWriter sw = new StreamWriter("b.out"))
				{
					int n = Int32.Parse(sr.ReadLine());

					for (int i = 0; i < n; i++)
					{
						string s = sr.ReadLine();

						int N = Int32.Parse(s);

						List<int> data = new List<int>();

						for (int j = 0; j < N; j++)
						{
							s = sr.ReadLine();
							string[] spl = s.Split(' ');

							data.Add(10000 * Int32.Parse(spl[0]) + Int32.Parse(spl[1]));
						}

						int res = Solve(data);
						sw.WriteLine("Case #" + (i + 1) + ": {0}",  res == -1 ? "Too Bad" : res.ToString());
					}
				}
			}
		}
	}
}
