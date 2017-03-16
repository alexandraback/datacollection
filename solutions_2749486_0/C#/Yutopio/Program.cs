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

	static string Solve()
	{
		var read = Console.ReadLine();
		var data = read.Split(' ').ToArray();
		var x = int.Parse(data[0]);
		var y = int.Parse(data[1]);

		var X = Math.Abs(x);
		var Y = Math.Abs(y);
		var ret = Solve2(X, Y);

		if (x < 0)
		{
			ret = ret.Replace('E', '_');
			ret = ret.Replace('W', 'E');
			ret = ret.Replace('_', 'W');
		}
		if (y < 0)
		{
			ret = ret.Replace('N', '_');
			ret = ret.Replace('S', 'N');
			ret = ret.Replace('_', 'S');
		}
		return ret;
	}

	static string Solve2(int X, int Y)
	{
		var ret = "";
		for (var i = 0; i < X; i++)
			ret += "WE";
		for (var i = 0; i < Y; i++)
			ret += "SN";
		return ret;
	}
}
