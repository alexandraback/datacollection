using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam2012
{
    class Problem1b1
    {
        public static void Solve(string inFilePath, string outFilePath)
        {
            using (var inFile = File.OpenText(inFilePath))
            using (var outFile = File.OpenWrite(outFilePath))
            using (var outWriter = new StreamWriter(outFile))
            {
                var cases = int.Parse(inFile.ReadLine());

                for (int c = 0; c < cases; ++c)
                {
                    var inputLine1 = inFile.ReadLine();
                    var parts = inputLine1.Split(' ').Select(s => int.Parse(s)).ToList();

                    var n = parts[0];
                    var p = new double[n];
                    var j = new int[n];

                    for (int i = 0; i < n; ++i)
                        p[i] = 0;
                    var X = 0;
                    for (int i = 0; i < n; ++i)
                    {
                        var s = parts[i + 1];
                        j[i] = s;
                        X += s;
                    }

                    if (n < 2)
                    {
                        //TODO
                    }

                    var mins = j.OrderBy(t => t).Take(2).ToList();
                    var min1 = mins[0];
                    var min2 = mins[1];

                    var sum = 2 * X;
                    var ep = (double)sum / (double)n;
                    var pa = j.Where(ji => ji > ep).ToList();
                    var eq2 = ep;
                    if (pa.Any())
                    {
                        eq2 = (sum - pa.Sum())/ (double)(n - pa.Count);
                    }

                    for (int i = 0; i < n; ++i)
                    {
                        if (j[i] >= ep)
                        {
                            p[i] = 0;
                            continue;
                        }
                        double d = eq2 - j[i];
                        var q = (d * 100.0) / X;
                        p[i] = Math.Max(q, 0);
                        //Console.WriteLine(d / j[i]);
                    }

                    //for (int i = 0; i < n; ++i)
                    //{
                    //    List<double> pm = new List<double>();
                    //    var ji = j[i];
                    //    for (int k = 0; k < n; ++k)
                    //    {
                    //        if (i == k)
                    //            continue;
                    //        var jk = j[k];
                    //        if (ji > jk)
                    //        {

                    //        }
                    //    }
                    //}

                    //var mins = j.OrderBy(t => t).Take(2).ToList();
                    //int min1 = mins[0];
                    //int min2 = mins[1];
                    //double pi;
                    //if (min1 < min2)
                    //{
                    //    double d = min2 - min1;
                    //    pi = (d * 100) / X;
                    //    p[j.ToList().IndexOf(min1)] = pi;
                    //}
                    //else
                    //{
                    //    double d = min1 - min2;
                    //    pi = (d * 100) / X;
                    //    p[j.ToList().IndexOf(min2)] = pi;
                    //}

                    //double pa = (100 - pi) / (double)n;
                    //for (int i = 0; i < n; ++i)
                    //    p[i] += pa;
                    //for (int i = 0; i < n; ++i)
                    //{
                    //    var ji = j[i];
                    //    int min = int.MaxValue;
                    //    for (int k = 0; k < n; ++k)
                    //    {
                    //        if (k == i)
                    //            continue;
                    //        if (min > j[k])
                    //            min = j[k];
                    //    }
                    //    var d = (float)ji / min;
                    //    Console.WriteLine(d);
                    //    Console.WriteLine(100.0/(d+1));
                    //}
                    float ret = 0;

                    var outLine = string.Format("Case #{0}:", c + 1);
                    for (int i = 0; i < n; ++i)
                        outLine += string.Format(" {0:0.000000}", p[i]).Replace(',', '.');
                    Console.WriteLine(outLine);
                    outWriter.WriteLine(outLine);
                }
                outWriter.Flush();
            }
        }
    }
}
