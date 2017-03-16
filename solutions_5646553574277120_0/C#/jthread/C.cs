using System;
using System.Collections.Generic;
using System.Text;
using System.Threading;
using System.Globalization;
using System.Linq;

public class C
{
	public static void Main(string[] args)
	{
		Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;
		int CASES = int.Parse(Console.ReadLine());
		for (int CASE = 1; CASE <= CASES; CASE++)
		{
			Console.Error.WriteLine("Case " + CASE);
			string[] parts = Console.ReadLine().Split();
			int C = int.Parse(parts[0]);
			int D = int.Parse(parts[1]);
			int V = int.Parse(parts[2]);
			HashSet<int> nums = new HashSet<int>();
			parts = Console.ReadLine().Split();
			for (int i = 0; i < D; i++)
				nums.Add(int.Parse(parts[i]));

			for (int i = 1; i <= V; i++)
				if (!canMake(i, C, nums))
					nums.Add(i);

			Console.WriteLine("Case #" + CASE + ": " + (nums.Count - D));
		}
	}

	public static bool canMake(int x, int C, HashSet<int> nums)
	{
		bool[] can = new bool[x + 1];
		can[0] = true;
		foreach (int i in nums)
		{
			for (int j = x; j >= 0; j--)
			{
				if (!can[j]) continue;
				for (int k = 1; k <= C; k++)
					if (j + i * k <= x)
						can[j + i * k] = true;
			}
		}
		return can[x];
	}
}
