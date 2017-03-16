using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Impl.Round1C
{
	public class ProblemB : ProblemBase
	{
		public class Point
		{
			private readonly int x, y;

			public Point(TextReader input)
			{
				var parts = input.ReadLine().Split(' ');
				x = int.Parse(parts[0]);
				y = int.Parse(parts[1]);
			}

			public Point(int x, int y)
			{
				this.x = x;
				this.y = y;
			}

			public Point MoveBack(int step, StringBuilder sb)
			{
				var moves = new List<Tuple<Point, char>>
				{
					new Tuple<Point, char>(new Point(x + step, y + 0), 'W'),
					new Tuple<Point, char>(new Point(x - step, y + 0), 'E'),
					new Tuple<Point, char>(new Point(x + 0, y + step), 'S'),
					new Tuple<Point, char>(new Point(x + 0, y - step), 'N')
				}
					.OrderBy(t => t.Item1.Dist)
					.ToList();
				sb.Append(moves[0].Item2);
				return moves[0].Item1;
			}

			private long? dist;
			public long Dist { get { return (dist ?? (dist = Math.Abs(x) + Math.Abs(y))).Value; } }
			public override string ToString()
			{
				return string.Format("({0}, {1}) : {2}", x, y, Dist);
			}
		}

		protected override bool SolveOne(TextReader input, TextWriter output, int testNumber)
		{
			int res = 0, dst = 0;
			var p = new Point(input);
			while (dst < p.Dist || dst%2 != p.Dist%2)
			{
				res++;
				dst += res;
			}
			var sb = new StringBuilder();
			while (res > 0)
			{
				p = p.MoveBack(res, sb);
				--res;
			}
			var ans = new string(sb.ToString().Reverse().ToArray());
			return Write(output, testNumber, ans);
		}
	}
}