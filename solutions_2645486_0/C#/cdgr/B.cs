using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace RAVE
{
	class TestCase
	{
		// You've got a very busy calendar today, full of important stuff to do.
		// You worked hard to prepare and make sure all the activities don't overlap.
		// Now it's morning, and you're worried that despite all of your enthusiasm, you won't have the energy to do all of this with full engagement.

		// You will have to manage your energy carefully. You start the day full of energy - E joules of energy, to be precise.
		// You know you can't go below zero joules, or you will drop from exhaustion.
		// You can spend any non-negative, integer number of joules on each activity (you can spend zero, if you feel lazy),
		// and after each activity you will regain R joules of energy.
		// No matter how lazy you are, however, you cannot have more than E joules of energy at any time;
		// any extra energy you would regain past that point is wasted.

		// Now, some things (like solving Code Jam problems) are more important than others.
		// For the ith activity, you have a value vi that expresses how important this activity is to you.
		// The gain you get from each activity is the value of the activity, multiplied by the amount of energy you spent on the activity (in joules).
		// You want to manage your energy so that your total gain will be as large as possible.

		// Note that you cannot reorder the activities in your calendar.
		// You just have to manage your energy as well as you can with the calendar you have.

		// Each test case is described by two lines.
		// The first contains three integers:
		// - E, the maximum (and initial) amount of energy,
		// - R, the amount you regain after each activity,
		// - N, the number of activities planned for the day.
		// The second line contains N integers vi, describing the values of the activities you have planned for today.

		// Return the maximum gain you can achieve by managing your energy that day.

		int E; // Energy capacity; 1 ≤ E ≤ 5|10^7
		int R; // Boost after each activity; 1 ≤ R ≤ 5|10^7
		int N; // Activity count; 1 ≤ N ≤ 10|10^4
		long[] V; // Activity values; 1 ≤ V[i] ≤ 10|10^7

		public TestCase(TextReader input)
		{
			var x = input.ReadInts();
			E = x[0]; R = x[1]; N = x[2];
			V = input.ReadLongs();
		}

		public long GetResult()
		{
			long[,] a = new long[E + 1, N]; // a[e, i] is best value given energy e, and activities from i..N - 1 left.
			for (int e = 0; e <= E; ++e)
				a[e, N - 1] = e * V[N - 1];
			for (int i = N - 2; i >= 0; --i)
				for (int e = 0; e <= E; ++e)
				{
					long best = 0;
					for (int x = 0; x <= e; ++x)
					{
						long v = x * V[i] + a[Math.Min(e - x + R, E), i + 1];
						if (v > best)
							best = v;
					}
					a[e, i] = best;
				}
			return a.GetColumn(0).Max();
		}
	}
}