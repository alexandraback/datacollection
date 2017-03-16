using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;

namespace GoogleCodeJam2014
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileName = "input.in";
            using (var reader = new StreamReader(fileName))
            {
                int cases = int.Parse(reader.ReadLine().Trim());
                using (var writer = new StreamWriter("output.out"))
                {
                    for (int i = 0; i < cases; i++)
                    {
                        var line = reader.ReadLine();
                        var lineValues = line.Split('/');

                        long a = long.Parse(lineValues[0]);
                        long b = long.Parse(lineValues[1]);

                        int? g = GetFirstGeneration(a, b);

                        writer.WriteLine(string.Format("Case #{0}: {1}", i + 1, g.HasValue ? g.Value.ToString() : "impossible"));
                    }
                }
            }
        }

        private static int? GetFirstGeneration(long a, long b)
        {
            int x = -1;
            int i = 0;
            bool valid = false;
            if (a == b)
            {
                x = 0;
                valid = true;
            }
            else
            {
                while (i < 42)
                {
                    a *= 2;
                    if (a >= b)
                    {
                        a -= b;
                        if (x == -1)
                            x = i;
                    }
                    i++;
                    if (a == 0)
                    {
                        valid = true;
                        break;
                    }
                }
            }
            return (valid) ? (x + 1) : (int?)null;
        }


    }
}
