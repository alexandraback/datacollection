using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace googlecode
{
    enum Position
    { 
        first,
        intern,
        last,
        single
    }

    class Program
    {
        static long fact_m(int n)
        {
            long res = 1;
            for (int i = 1; i <= n; ++i)
            {
                res *= i;
                res %= 1000000007;
            }
            return res;
        }

        static void Main(string[] args)
        {
            
            int t;
            string line;
            System.IO.StreamReader file =
   new System.IO.StreamReader("d:\\temp.txt");
            System.IO.StreamWriter outfile =
   new System.IO.StreamWriter("d:\\out.txt");
            while ((line = file.ReadLine()) != null)
            {
                t = int.Parse(line);

                for (int i = 0; i < t; ++i)
                {
                    line = file.ReadLine();
                    line = file.ReadLine();
                    var lines = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    List<string> cars = new List<string>(lines.Length);
                    foreach (var l in lines)
                    {
                        cars.Add(String.Concat(l.Distinct().ToArray()));
                    }
                    long res = 1;

                    Dictionary<char, Dictionary<Position, int>> instring = new Dictionary<char, Dictionary<Position, int>>();
                    foreach (var l in cars)
                    {
                        int j = 0;
                        foreach (var c in l)
                        {
                            if (!instring.ContainsKey(c))
                            {
                                instring.Add(c, new Dictionary<Position, int>());
                                instring[c].Add(Position.single, 0);
                                instring[c].Add(Position.first, 0);
                                instring[c].Add(Position.intern, 0);
                                instring[c].Add(Position.last, 0);
                            }
                            if (l.Length == 1)
                            {
                                instring[c][Position.single] += 1;
                            }
                            else
                            {
                                if (j == 0)
                                {
                                    instring[c][Position.first] += 1;
                                }
                                else if (j < l.Length - 1)
                                {
                                    instring[c][Position.intern] += 1;
                                }
                                else 
                                {
                                    instring[c][Position.last] += 1;
                                }
                            }
                            ++j;
                        }
                    }
                    foreach (var v in instring.ToArray())
                    {
                        res *= fact_m(v.Value[Position.single]);
                        res %= 1000000007;
                        if (v.Value[Position.first] == 1 && v.Value[Position.last] == 1 && (v.Value[Position.intern] == 0))
                        {
                            instring.Remove(v.Key);
                        }
                    }
                    for (int j = 0; j < instring.Count - 2; ++j)
                    {
                        res *= (instring.Count - 1);
                        res %= 1000000007;
                    }
                    foreach (var v in instring.Values)
                    {
                        if (v[Position.first] > 1 || v[Position.last] > 1 || (v[Position.intern] * (v[Position.first] + v[Position.last] + v[Position.intern]) > 1))
                        {
                            res = 0;
                            break;
                        }
                    }
                    
                    outfile.WriteLine("Case #" + (i + 1) + ": " + res);
                }
                outfile.Close();
                return;
            }

        }
    }
}
