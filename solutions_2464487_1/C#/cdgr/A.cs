using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace RAVE
{
	class TestCase
	{
		// Maria has been hired by the Ghastly Chemicals Junkies (GCJ) company to help them manufacture bullseyes.
		// A bullseye consists of a number of concentric rings (rings that are centered at the same point), and it usually represents an archery target.
		// GCJ is interested in manufacturing black-and-white bullseyes. 

		// Maria starts with t millilitres of black paint, which she will use to draw rings of thickness 1cm (one centimetre).
		// A ring of thickness 1cm is the space between two concentric circles whose radii differ by 1cm.

		// Maria draws the first black ring around a white circle of radius r cm.
		// Then she repeats the following process for as long as she has enough paint to do so:
		// - Maria imagines a white ring of thickness 1cm around the last black ring.
		// - Then she draws a new black ring of thickness 1cm around that white ring.
		// Note that each "white ring" is simply the space between two black rings.

		// The area of a disk with radius 1cm is π cm2. One millilitre of paint is required to cover area π cm2.
		// What is the maximum number of black rings that Maria can draw? Please note that:
		// - Maria only draws complete rings. If the remaining paint is not enough to draw a complete black ring, she stops painting immediately.
		// - There will always be enough paint to draw at least one black ring.

		// Each test case consists of a line containing two space separated integers: r and t.

		// Return is the maximum number of black rings that Maria can draw.

		// 1 ≤ # test cases ≤ 1000|6000
		long R; // Radius of inner white circle; 1 ≤ R ≤ 1000|10^18
		long T; // Volume of paint; each unit covers π area; 1 ≤ T ≤ 1000|2*10^18

		public TestCase(TextReader input)
		{
			var x = input.ReadLongs();
			R = x[0];
			T = x[1];
		}

		public long GetResultX()
		{
			// Ring 1 costs 2R + 1 mls of paint, ring 2 costs 2R + 5, ring 3 costs 2R + 9, and so on.
			// For the small dataset, can just count it.
			long used = 0;
			long drawn = 0;
			long i = 1;
			while (used + 2 * R + i <= T)
			{
				used += 2 * R + i;
				++drawn;
				i += 4;
			}
			return drawn;
		}
		public long GetResult()
		{
			long min = 1; // answer is this or higher
			long max = 707106780; // answer is this or lower
			while (min != max)
			{
				long mid = (min + max + 1) / 2;
				if (PaintNeeded(mid) <= T)
					min = mid;
				else
					max = mid - 1;
			}
			return min;
		}

		public BigInteger PaintNeeded(BigInteger n)
		{
			return n * (2 * R + 2 * n - 1);
		}
	}
}