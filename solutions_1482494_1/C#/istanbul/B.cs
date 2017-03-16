// IOHelper.cs can be downloaded from http://kadiryazgan.com/codejam/IOHelper.cs.txt

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace codejam.Round1A2012
{
	class B
	{
		class Level : IComparable
		{
			public int Star1;
			public int Star2;
			public int Completion;

			public int CompareTo(object obj)
			{
				var l = obj as Level;
				if (this.Star2 == l.Star2)
				{
					return this.Star1.CompareTo(l.Star1) * -1;
				}
				else
				{
					return this.Star2.CompareTo(l.Star2) * -1;
				}
			}
		}

		static IOHelper io;
		static void Main(string[] args)
		{
			using (io = new IOHelper("B-large-0"))
			{
				int nCases = io.ReadInt();
				for (int _case = 1; _case <= nCases; _case++)
				{
					var nLevels = io.ReadInt();
					var levels = new List<Level>(nLevels);
					int nStars = 0, nPlays = 0;
					for (int i = 0; i < nLevels; i++)
					{
						int s1,s2;
						io.ReadValues(out s1, out s2);
						levels.Add(new Level { Star1 = s1, Star2 = s2, Completion = 0 });
					}
					levels.Sort();
					

					while (true)
					{
						//Console.WriteLine("plays={0}, stars={1}", nStars, nPlays);

						Level level; 
						if ((level = levels.Find(delegate(Level l) { return nStars >= l.Star2 && l.Completion == 0; })) != null)
						{
							level.Completion = 2;
							nPlays++;
							nStars += 2;
						}
						else if ((level = levels.Find(delegate(Level l) { return nStars >= l.Star2 && l.Completion == 1; })) != null)
						{
							level.Completion = 2;
							nPlays++;
							nStars++;
						}
						else if ((level = levels.Find(delegate(Level l) { return nStars >= l.Star1 && l.Completion == 0; })) != null)
						{
							level.Completion = 1;
							nPlays++;
							nStars++;
						}
						else
						{
							if (levels.Find(delegate(Level l) { return l.Completion < 2; }) != null)
							{
								nPlays = -1;
							}
							break;
						}
					}

					io.WriteLine("Case #{0}: {1}", _case, nPlays > -1 ? nPlays.ToString() : "Too Bad");
				}
			}
		}

		static int Solve()
		{
			return 0;
		}
	}
}
