// By the way, you need to use my optimised whenever compiler from http://esotericode.blogspot.co.uk/
// to allow my solution for b-small to run. In particular, input is neccessary.

using System;
public class ProbB
{
	public static void Main()
	{
		int n = int.Parse(Console.ReadLine());
		for (int i = 1; i <= n; ++i)
		{
			string[] words = Console.ReadLine().Split(' ');
			int N = int.Parse(words[0]);
			int S = int.Parse(words[1]);
			int p = int.Parse(words[2]);
			int score = 0;
			for (int j = 0; j < N; ++j)
			    {
				int k = int.Parse(words[3+j]);
				if ((k >= 1) && ((k == 3 * p - 3) || (k == 3 * p - 4)) && (S > 0))
				{
					--S;
					++score;
				} else if (k > (3 * p - 3))
				  ++score;
			    }
			Console.WriteLine("Case #{0}: {1}", i, score);
		}
	}
}