using System.IO;
using System.Linq;
using System;

namespace RAVE
{
	class TestCase
	{
		Level[] Levels;

		public TestCase(TextReader input)
		{
			int n = input.ReadInts()[0];
			Levels = Enumerable.Range(0, n).Select(i => new Level(input)).ToArray();
		}

		public string GetResult()
		{
			int stars = 0;
			int levels = 0;
			while (stars != Levels.Length * 2)
			{
				// Go for a 2-star that has never been 1-starred
				var avail = Levels.FirstOrDefault(l => l.B <= stars && !l.DoneA);
				if (avail != null)
				{
					avail.DoneA = avail.DoneB = true;
					stars += 2;
					++levels;
					continue;
				}

				// Go for a 2-star that has never been 2-starred
				avail = Levels.FirstOrDefault(l => l.B <= stars && !l.DoneB);
				if (avail != null)
				{
					avail.DoneA = avail.DoneB = true;
					stars += 1;
					++levels;
					continue;
				}

				// Find the doable 1-stars.  Pick the one with the highest 2-star cost.
				//var onestarable = Levels.Where(l => l.A <= stars && !l.DoneA).ToArray();
				//if (onestarable.Any())
				//{
				//   avail = onestarable.Max();
				//   stars += 1;
				//   ++levels;
				//   continue;
				//}
				avail = Levels.Where(l => l.A <= stars && !l.DoneA).OrderByDescending(l => l.B).FirstOrDefault();
				if (avail != null)
				{
					avail.DoneA = true;
					stars += 1;
					++levels;
					continue;
				}

				return "Too Bad";
			}
			return levels.ToString();
		}

		class Level : IComparable<Level>
		{
			public Level(TextReader input)
			{
				var r = input.ReadInts();
				A = r[0]; B = r[1];
				DoneA = false;
				DoneB = false;
			}

			public int A, B;
			public bool DoneA, DoneB;

			public int CompareTo(Level other)
			{
				return B.CompareTo(other.B);
			}
		}
	}
}