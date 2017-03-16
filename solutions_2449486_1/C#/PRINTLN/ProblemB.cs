using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

class ProblemB
{
    public struct Point
    {
        public int X { get; set; }
        public int Y { get; set; }
        public int Value { get; set; }

        public override string ToString()
        {
            return String.Format("({0}, {1}): {2}", X, Y, Value);
        }
    }

    static void Main(string[] args)
    {
        StreamReader reader = new StreamReader(@"D:\codejam\B-large.in");
        StreamWriter writer = new StreamWriter(@"D:\codejam\B-large.out");
        var inputPool = reader.ReadToEnd()
                              .Trim()
                              .Split(new[] { ' ', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries)
                              .Select(Int32.Parse).ToArray();

        var index = 0;
        int T = inputPool[index++];
        for (int t = 1; t <= T; t++)
        {
            int n = inputPool[index++];
            int m = inputPool[index++];
            Point[] points = new Point[n * m];
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < m; y++)
                {
                    points[x * m + y] = new Point
                    {
                        X = x,
                        Y = y,
                        Value = inputPool[index++]
                    };
                }
            }

            var orderPoints = points.OrderBy(p => p.Value);
            var possible = true;
            foreach (var point in orderPoints)
            {
                var possibleX = true;
                var possibleY = true;
                for (int x = 0; x < n; x++)
                {
                    if (points[x * m + point.Y].Value > point.Value)
                    {
                        possibleX = false;
                        break;
                    }
                }
                for (int y = 0; y < m; y++)
                {
                    if (points[point.X * m + y].Value > point.Value)
                    {
                        possibleY = false;
                        break;
                    }
                }
                // if one case is OK, then continue
                if (possibleX || possibleY)
                {
                    continue;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
            writer.WriteLine(String.Format("Case #{0}: {1}", t, possible ? "YES" : "NO"));
        }

        writer.Flush();
        writer.Close();
        reader.Close();
    }
}
