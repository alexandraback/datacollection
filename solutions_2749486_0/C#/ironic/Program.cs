using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Threading.Tasks;

namespace JamPlayground
{

    class Program
    {
        static List<int> max<T>(T[] values, int from, int to)
            where T : IComparable<T>
        {
            if (to <= from) throw new ArgumentException();


            T max = values[from];
            for (int i = from + 1; i < to; i++)
            {
                if (values[i].CompareTo(max) > 0) max = values[i];
            }
         
            var maximums = new List<int>();
            for (int i = from; i < to; i++)
            {
                if (values[i].CompareTo(max) == 0) maximums.Add(i);
            }

            return maximums;
        }

        static bool v(char c)
        {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        }

        [DebuggerDisplay("Length = {Length}")]
        class Group
        {
            public int Length;
            public Group Next;
            public bool Cons;
        }

        static bool isN(string name, int n)
        {
            int g = 0;
            for (int i = 0; i < name.Length; i++)
            {
                bool isV = v(name[i]);
                if (isV)
                {
                    g = 0;
                }
                else
                {
                    g++;
                    if (g >= n) return true;
                }
            }
            return false;
        }

        class Point
        {
            public int X;
            public int Y;

            public Point(int x, int y)
            {
                X = x;
                Y = y;
            }

            protected bool Equals(Point other)
            {
                return X == other.X && Y == other.Y;
            }

            public override bool Equals(object obj)
            {
                if (ReferenceEquals(null, obj)) return false;
                if (ReferenceEquals(this, obj)) return true;
                if (obj.GetType() != this.GetType()) return false;
                return Equals((Point) obj);
            }

            public override int GetHashCode()
            {
                unchecked
                {
                    return (X*397) ^ Y;
                }
            }
        }

        [DebuggerDisplay("({X}; {Y}): {Direction}; {StepS}")]
        class Step
        {
            public Step From;
            public char Direction;
            public int StepS;
            public Point Point;
            public int X { get { return Point.X; } }
            public int Y { get { return Point.Y; } }

            public int Length
            {
                get { 
                    var s = this;
                    int x = 0;
                    while (s != null)
                    {
                        x++;
                        s = s.From;
                    }
                    return x;
                }
            }

            public string Path
            {
                get
                {
                    var step = this;
                    var r = string.Empty;
                    while (step.From != null)
                    {
                        r += step.Direction;
                        step = step.From;
                    }
                    return new string(r.Reverse().ToArray());
                }
            }
        }

        class cc : IComparer<Step>
        {
            private Point _t;

            public cc(Point t)
            {
                _t = t;
            }

            public int Compare(Step x, Step y)
            {
                float dxx = (float) x.X - _t.X;
                float dxy = (float) x.Y - _t.Y;
                float dyx = (float) y.X - _t.X;
                float dyy = (float) y.Y - _t.Y;
                float dX = dxx*dxx + dxy*dxy;
                float dy = dyx*dyx + dyy*dyy;

                return dX.CompareTo(dy);
            }
        }

        static string way(int x, int y)
        {
            var steps = new SortedSet<Step>(new cc(new Point(x, y)));
            steps.Add(new Step{StepS = 1, Point = new Point(0,0)});
            var ways = new Dictionary<Point, Step>();

            while (true)
            {
                var step = steps.First();
                steps.Remove(step);
                Step value;
                if (!ways.TryGetValue(step.Point, out value) || value.StepS > step.StepS)
                {
                    ways[step.Point] = step;
                }

                if (step.X == x && step.Y == y)
                {
                    return step.Path;
                }
                if (step.Length < 500)
                {
                    var nP = new Point(step.X, step.Y + step.StepS);
                    var sP = new Point(step.X, step.Y - step.StepS);
                    var eP = new Point(step.X + step.StepS, step.Y);
                    var wP = new Point(step.X - step.StepS, step.Y);
                    if (!ways.ContainsKey(nP))
                        steps.Add(new Step {From = step, Direction = 'N', StepS = step.StepS + 1, Point = nP});
                    if (!ways.ContainsKey(sP))
                        steps.Add(new Step { From = step, Direction = 'S', StepS = step.StepS + 1, Point = sP });
                    if (!ways.ContainsKey(eP))
                        steps.Add(new Step { From = step, Direction = 'E', StepS = step.StepS + 1, Point = eP });
                    if (!ways.ContainsKey(wP))
                        steps.Add(new Step { From = step, Direction = 'W', StepS = step.StepS + 1, Point = wP });
                }
            }
        }

        static void Main(string[] args)
        {
            string input = "in.in";
            string output = "out.out";
            File.Delete(output);

            var lines = File.ReadAllLines(input);
            int t = int.Parse(lines[0]);
            for (int i = 0; i < t; i++)
            {

                var strings = lines[i+1].Split();
                int x = int.Parse(strings[0]);
                int y = int.Parse(strings[1]);

                var value = way(x, y);

                var cs = string.Format("Case #{0}: ", (i + 1));
                File.AppendAllText(output, cs + value + Environment.NewLine);

            }
        }
    }
}
