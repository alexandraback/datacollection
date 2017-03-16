using System;
using System.Linq;

class Program
{		
	static void Main()
	{
		var n = int.Parse(Console.ReadLine());
		for (var i = 0; i++ < n; )
			Console.WriteLine("Case #{0}: {1}", i, Solve());
	}

	static double Solve()
	{
		var read = Console.ReadLine();
		var data = read.Split(' ').ToArray();
		var N = int.Parse(data[0]);
		var X = Math.Abs(int.Parse(data[1]));
		var Y = int.Parse(data[2]);
		var Z = (X + Y) / 2;

		var N_ = (int)Math.Floor((Math.Sqrt(8 * N + 1) - 3) / 4);
		var n = N - (N_ + 1) * (2 * N_ + 1);

		if (Z <= N_) return 1;
		else if (Z <= N_ + 1)
		{
			Y++;
			if (X == 0 || Y > n) return 0;
			else if (n - (N_ + 2) >= Y) return 1;
			else
			{
				double ret = 0, pow = Math.Pow(2, n);
				for (var i = Y; i <= n; i++)
				{
					var k = n / 2 < i ? n - i : i;
					var a = (double)1;
					for (var j = n; j > k; j--) a *= j;
					for (var j = n - k; j > 0; j--) a /= j;
					ret += a / pow;
				}
				return ret;
			}
		}
		else return 0;
	}
}
