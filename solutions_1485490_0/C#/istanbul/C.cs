// IOHelper.cs can be downloaded from http://kadiryazgan.com/codejam/IOHelper.cs.txt

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;

namespace codejam.Y2012.Round1C
{
	class C
	{
		struct AL
		{
			public long Type;
			public long Count;
		}

		static void Main(string[] args)
		{
			new C("test");
			new C("C-small-0");
			//new C("C-large-0");
		}

		IOHelper io;

		public C(string inputName)
		{
			using (io = new IOHelper(inputName))
			{
				int nCases = io.ReadInt();
				for (int _case = 1; _case <= nCases; _case++)
				{
					int nBoxes, nToys;
					io.ReadValues(out nBoxes, out nToys);

					var boxline = new AL[nBoxes];
					var toyline = new AL[nToys];
					{
						var boxData = io.ReadLongArray();
						var toyData = io.ReadLongArray();

						for (int i = 0; i < nBoxes; i++)
						{
							boxline[i].Count = boxData[i * 2];
							boxline[i].Type = boxData[i * 2 + 1];
						}

						for (int i = 0; i < nToys; i++)
						{
							toyline[i].Count = toyData[i * 2];
							toyline[i].Type = toyData[i * 2 + 1];
						}
					}


					//if (_case != 3) continue;
					io.WriteLine("Case #{0}: {1}", _case, Solve(boxline, toyline, 0, 0,  0));
				}
			}
		}

		long Solve(AL[] boxline, AL[] toyline, int boxIndex, int toyIndex, int r)
		{
			AL b, t;

			if (boxIndex > boxline.Length - 1 || toyIndex > toyline.Length - 1)
			{
				
				return 0;
			}

			long boxed = 0;
			b = boxline[boxIndex];
			t = toyline[toyIndex];
			long p0 = 0;
			bool cont = false;
			if (b.Type == t.Type)
			{
				boxed = Math.Min(b.Count, t.Count);
				boxline[boxIndex].Count -= boxed;
				toyline[toyIndex].Count -= boxed;

				//Console.WriteLine(new string(' ', r * 2) + "Boxing ti={0}, bi={1}, items={2}.", toyIndex, boxIndex, boxed);

				if (b.Count == 0) boxIndex++;
				if (t.Count == 0) toyIndex++;

				if (b.Count == 0 && t.Count == 0)
				{
					cont = true;
				}
				
			}

			if (cont)
			{
				long s = Solve(boxline.ToList().ToArray(), toyline.ToList().ToArray(), boxIndex, toyIndex, r + 1);
				//Console.WriteLine("s={0}", s);
				return boxed + s;
			}
			else
			{
				var p1 = boxIndex < boxline.Length - 1 ? Solve(boxline.ToList().ToArray(), toyline.ToList().ToArray(), boxIndex + 1, toyIndex, r + 1) : 0;
				var p2 = toyIndex < toyline.Length - 1 ? Solve(boxline.ToList().ToArray(), toyline.ToList().ToArray(), boxIndex, toyIndex + 1, r + 1) : 0;
				return boxed + Math.Max(p0, Math.Max(p1, p2));
			}
		}
	}
}
