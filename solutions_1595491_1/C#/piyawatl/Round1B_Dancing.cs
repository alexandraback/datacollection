using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012
{
    class Round1B_Dancing
    {
        public Round1B_Dancing()
        {
            StreamReader reader = new StreamReader("B-large.in");
            StreamWriter writer = File.CreateText("B-large.out");

            string s = reader.ReadLine();
            int t = Int32.Parse(s);
            int n, sur, p, x;
            int i, j;
            int count;
            char[] d = {' '};
            string[] tokens;
            for (i = 1; i <= t; i++)
            {
                s = reader.ReadLine();
                count = 0;
                tokens = s.Split(d);
                n = Int32.Parse(tokens[0]);
                sur = Int32.Parse(tokens[1]);
                p = Int32.Parse(tokens[2]);
                for (j = 0; j < n; j++)
                {
                    x = Int32.Parse(tokens[3 + j]);
                    if (Best1(x) >= p)
                    {
                        count++;
                    }
                    else if ((Best2(x) >= p) && (sur > 0))
                    {
                        count++;
                        sur--;
                    }
                }
                writer.WriteLine("Case #" + i + ": " + count);
            }
            reader.Close();
            writer.Close();
        }

        public int Best1(int x)
        {
            return (x + 2) / 3;
        }

        public int Best2(int x)
        {
            return (x == 0) ? 0 : (x + 4) / 3;
        }
    }
}
