using System;
using System.Linq;
using System.Collections.Generic;

class Program
{		
	static void Main()
	{
		var n = int.Parse(Console.ReadLine());
		for (var i = 0; i++ < n; )
			Console.WriteLine("Case #{0}: {1}", i, Solve());
	}

	static int Solve()
	{
		var read = Console.ReadLine();
		var data = read.Split(' ').ToArray();
		var A = int.Parse(data[0]);
		read = Console.ReadLine();
		var Ns = (
				from x in read.Split(' ')
				select int.Parse(x) into x
				orderby x
				select x).ToList();

		if (A == 1) return Ns.Count;

		while (Ns.Count != 0 && Ns[0] < A)
		{
			A += Ns[0];
			Ns.RemoveAt(0);
		}
		if (Ns.Count == 0) return 0;

		List<int> X = new List<int>(), Y = new List<int>();
		while (Ns.Count != 0)
		{
			int j;
			for (j = 0; A <= Ns[0]; j++)
			{
				A *= 2;
				A--;
			}
			X.Add(j);

			j = 0;
			while (Ns.Count != 0 && Ns[0] < A)
			{
				A += Ns[0];
				Ns.RemoveAt(0);
				j++;
			}
			Y.Add(j);
		}

		var XX = X.ToArray();
		var YY = Y.ToArray();
		var K = new int[XX.Length + 1];
		K[0] = Y.Sum();
		for (int i = 0, j = 0, z = K[0]; i < XX.Length; )
		{
			j += XX[i];
			z -= YY[i];
			K[++i] = j + z;
		}
		return K.Min();
	}
}