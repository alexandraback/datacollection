using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Text.RegularExpressions;
using System.Diagnostics;
using System.Numerics;

struct Point : IEquatable<Point>
{
    public int X; public int Y;
    public Point(int x, int y) { X = x; Y = y; }
    public bool Equals(Point p) { return p.X == X && p.Y == Y; }
    public override int GetHashCode() { unchecked { return (int)(X * 3137 + Y); } }
}

class Problem
{
    const string inFile = "..\\..\\blarge.in";
    const string outFile = "..\\..\\blarge.out";

    public void Process()
    {
        using (StreamReader sr = new StreamReader(inFile))
        {
            using (StreamWriter sw = new StreamWriter(outFile))
            {
                int numCases = int.Parse(sr.ReadLine());
                Console.WriteLine("There are {0} test cases.", numCases);
                for (int @case = 1; @case <= numCases; @case++)
                {
                    int n = int.Parse(sr.ReadLine());
                    int[] a = new int[n];
                    int[] b = new int[n];

                    for (int i = 0; i < n; i++)
                    {
                        int[] ss = Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries), int.Parse);

                        a[i] = ss[0];
                        b[i] = ss[1];
                    }

                    string res = Solve(n, a, b);
                    sw.WriteLine("Case #{0}: {1}", @case, res);
                    Console.WriteLine("Done test case {0}...", @case);
                }
            }
        }
    }

   
    private string Solve(int n, int[] a, int[] b)
    {
        //Point[] c = new Point[n];
        //for (int i = 0; i < n; i++)
        //{
        //    c[i] = new Point(a[i], b[i]);
        //}

        //Array.Sort(c, (x, y) =>
        //              {
        //                  if (x.Y != y.Y)
        //                  {
        //                      return x.Y.CompareTo(y.Y);
        //                  }
        //                  return y.X.CompareTo(x.X);
        //              });

        //for (int i = 0; i < n; i++)
        //{
        //    a[i] = c[i].X;
        //    b[i] = c[i].Y;
        //}

        Array.Sort(b, a);

        Point[] f = new Point[n];
        for (int i = 0; i < n; i++)
        {
            f[i] = new Point(i, a[i]);
        }

        Array.Sort(f, (x, y) =>
                      {
                          if (x.Y != y.Y)
                          {
                              return x.Y.CompareTo(y.Y);
                          }

                          return y.X.CompareTo(x.X);
                      });

        bool[] used = new bool[n];
   
        int res = 0;

        for (int level = 0, point = 0; level < n; level++)
        {
            if (point >= b[level])
            {
                if (used[level])
                    point += 1;
                else 
                    point += 2;

                res += 1;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (used[f[i].X] || f[i].X < level)
                    {
                        continue;
                    }

                    if (point < f[i].Y)
                    {
                        break;
                    }

                    point += 1;
                    used[f[i].X] = true;
                    res += 1;

                    if (point >= b[level])
                    {
                        if (used[level])
                            point += 1;
                        else
                            point += 2;

                        res += 1;
                        break;
                    }
                }

                if (point < b[level])
                {
                    return "Too Bad";
                }
            }
        }

        return res.ToString();
    }

    public static void Main()
    {
        Problem p = new Problem();
        p.Process();
    }
}