using System;
using System.Linq;

class B {
	public static void Main(String[] args) {
		int n = Int32.Parse(Console.ReadLine());

		for(int tc = 1; tc <= n; ++tc) {
			double C, F, X;
			String[] tokens = Console.ReadLine().Split();

			C = Double.Parse(tokens[0]);
			F = Double.Parse(tokens[1]);
			X = Double.Parse(tokens[2]);


			int S = Math.Max(-1, (int) Math.Floor((F * X - C * F - 2 * C) / (C * F)));
			double R = Enumerable.Range(0, S + 1).Select(i => C/(2.0 + i * F)).Sum() + X / (2 + (S + 1) * F);

			Console.WriteLine(String.Format("Case #{0}: {1:F12}", tc, R));
		}
	}
}
