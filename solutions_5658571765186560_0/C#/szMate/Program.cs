using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace XOminoesEasy
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter sw = new StreamWriter("D-small-attempt0.out");
            StreamReader sr = new StreamReader("D-small-attempt0.in");
            int T = Int32.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] line = sr.ReadLine().Split(' ');
                int X = Int32.Parse(line[0]);
                int R = Int32.Parse(line[1]);
                int C = Int32.Parse(line[2]);
                string name = who(X,R,C);
                sw.WriteLine("Case #{0}: {1}", i + 1, name);
            }
            sr.Close();
            sw.Flush();
            sw.Close();
        }

        private static string who(int X, int R, int C)
        {
            switch (X)
            {
                case 1:
                {
                    return "GABRIEL";
                }
                case 2:
                {
                    if (R * C % 2 == 0)
                    {
                        return "GABRIEL";
                    }
                    else
                    {
                        return "RICHARD";
                    }
                }
                case 3:
                {
                    if (R * C % 3 == 0 && R > 1 && C > 1)
                    {
                        return "GABRIEL";
                    }
                    else
                    {
                        return "RICHARD";
                    }
                }
                case 4:
                {
                    if (R * C == 16 || R * C == 12)
                    {
                        return "GABRIEL";
                    }
                    else
                    {
                        return "RICHARD";
                    }
                }
                default:
                {
                    return null;
                }
            }
        }
    }
}
