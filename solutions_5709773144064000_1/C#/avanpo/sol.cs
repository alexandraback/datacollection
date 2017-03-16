using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

class CookieClicker
{
	public int n;

	public CookieClicker()
	{
		this.n = int.Parse(Console.ReadLine());
	}

	public void Run()
	{
		File.WriteAllText("out.txt", String.Empty);

		for (int i = 0; i < this.n; i++)
		{
			double[] nums = Console.ReadLine().Split(' ').Select(s => double.Parse(s)).ToArray();
			double C = nums[0], F = nums[1], X = nums[2];

			double t = 0, p = 2;

			while (true)
			{
				if (C/p + X/(p + F) < X/p)
				{
					t += C/p;
					p += F;
				}
				else
				{
					t += X/p;
					break;
				}
			}

			using (StreamWriter w = File.AppendText("out.txt"))
			{
				w.WriteLine("Case #{0}: {1}", i + 1, t.ToString("F7"));
			}
		}
	}
	
	static void Main(string[] args)
	{
		CookieClicker c = new CookieClicker();
		c.Run();
	}
}
