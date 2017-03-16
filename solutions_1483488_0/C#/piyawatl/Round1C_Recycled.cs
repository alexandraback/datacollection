using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GoogleCodeJam2012
{
    class Round1C_Recycled
    {
        public Round1C_Recycled()
        {
            StreamReader reader = new StreamReader("C-small-attempt0.in");
            StreamWriter writer = File.CreateText("C-small-attempt0.out");

            string s = reader.ReadLine();
            int t = Int32.Parse(s);
            int a, b, x;
            int i, j, k;
            int count;
            char[] d = { ' ' };
            string[] tokens;
            string dup;
            int len;
            for (i = 1; i <= t; i++)
            {
                count = 0;
                s = reader.ReadLine();
                tokens = s.Split(d);
                a = Int32.Parse(tokens[0]);
                b = Int32.Parse(tokens[1]);
                for (j = a; j <= b; j++)
                {
                    len = j.ToString().Length;
                    dup = j.ToString() + j.ToString();
                    for (k = 1; k < len; k++)
                    {
                        x = Int32.Parse(dup.Substring(k, len));
                        if (x == j) break;
                        if ((x > j) && (x <= b))
                        {
                            count++;
                            //Console.WriteLine("j = " + j + ", x = " + x);
                        }
                    }
                }
                writer.WriteLine("Case #" + i + ": " + count);
            }
            reader.Close();
            writer.Close();
            //Console.Read();
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
