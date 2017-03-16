using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            var T = int.Parse(Console.ReadLine());
            for (int i = 0; i < T; i++)
            {
                // Read input
                var input = Console.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Select(s => long.Parse(s)).ToArray();
                var X = input[0];
                var Y = input[1];
                // Process
                var result = GetResult(X, Y);
                // Write Output

                Console.WriteLine("Case #{0}: {1}", i + 1, result);
            }
        }

        static string GetResult(long X, long Y)
        {
            Dictionary<Point, long> table = new Dictionary<Point, long>();
            Dictionary<long, List<Point>> reverseTable = new Dictionary<long, List<Point>>();
            var p0 = new Point { X = 0, Y = 0 };
            table[p0] = 0;
            reverseTable[0] = new List<Point> { p0 };
            for (int i = 1; i <= 15; i++)
            {
                reverseTable[i] = new List<Point>();
                {
                    foreach (var point in reverseTable[i - 1])
                    {
                        var pN = new Point { X = point.X + 0, Y = point.Y + i };
                        var pS = new Point { X = point.X + 0, Y = point.Y - i };
                        var pE = new Point { X = point.X + i, Y = point.Y + 0 };
                        var pW = new Point { X = point.X - i, Y = point.Y + 0 };

                        if (!table.ContainsKey(pN))
                        {
                            table[pN] = i;
                            reverseTable[i].Add(pN);
                        }
                        if (!table.ContainsKey(pS))
                        {
                            table[pS] = i;
                            reverseTable[i].Add(pS);
                        }
                        if (!table.ContainsKey(pE))
                        {
                            table[pE] = i;
                            reverseTable[i].Add(pE);
                        }
                        if (!table.ContainsKey(pW))
                        {
                            table[pW] = i;
                            reverseTable[i].Add(pW);
                        }
                    }
                }
            }
            var pointXY = new Point { X = X, Y = Y };
            StringBuilder s = new StringBuilder();
            if (table.ContainsKey(pointXY))
            {
                var n = table[pointXY];
                for (long x = n; x >= 1; x--)
                {
                   // Console.WriteLine("Point {0} {1}", pointXY.X, pointXY.Y);
                    var pN = new Point { X = pointXY.X, Y = pointXY.Y - x };
                    if (table.ContainsKey(pN) && table[pN] == x - 1)
                    {
                        pointXY = pN;
                        s.Append("N");
                        continue;
                    }
                    var pS = new Point { X = pointXY.X, Y = pointXY.Y + x };
                    if (table.ContainsKey(pS) && table[pS] == x - 1)
                    {
                        pointXY = pS;
                        s.Append("S");
                        continue;
                    }
                    var pE = new Point { X = pointXY.X - x, Y = pointXY.Y };
                    if (table.ContainsKey(pE) && table[pE] == x - 1)
                    {
                        pointXY = pE;
                        s.Append("E");
                        continue;
                    }
                    var pW = new Point { X = pointXY.X + x, Y = pointXY.Y };
                    if (table.ContainsKey(pW) && table[pW] == x - 1)
                    {
                        pointXY = pW;
                        s.Append("W");
                        continue;
                    }
                }
            }
            //Console.WriteLine("Point {0} {1}", pointXY.X, pointXY.Y);
            return new string(s.ToString().Reverse().ToArray());
        }
    }

    public struct Point
    {
        public long X;
        public long Y;

        public override bool Equals(object obj)
        {
            var pt = (Point)obj;
            return pt.X == this.X && pt.Y == this.Y;
        }

        public override int GetHashCode()
        {
            return (this.X * 1000000 + this.Y).GetHashCode();
        }
    }
}
