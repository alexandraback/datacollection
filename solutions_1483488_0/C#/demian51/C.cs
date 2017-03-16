using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace GCJ
{
    class C
    {
        static int rr(int s, int len)
        {
            return (s / 10) + (s % 10 * (int)Math.Pow(10, len - 1));
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"D:\input.txt");
            StreamWriter sw = new StreamWriter(@"D:\output.txt");

            int t;

            t = int.Parse(sr.ReadLine());

            for (int i = 0; i < t; i++)
            {
                int a, b, original, rotated, len, result = 0;
                string[] arg = sr.ReadLine().Split(' ');
                a = int.Parse(arg[0]);
                b = int.Parse(arg[1]);

                for (int j = a; j <= b; j++)
                {
                    List<int> checkedn = new List<int>();
                    original = j;
                    rotated = j;
                    checkedn.Add(rotated);
                    len = rotated.ToString().Length;

                    for (int k = 0; k < len - 1; k++)
                    {
                        rotated = rr(rotated, len);

                        if ((a <= rotated) && (rotated <= b) && (rotated > original) && (checkedn.Contains(rotated) != true))
                        {
                            checkedn.Add(rotated);
                            result++;
                        }
                    }
                }

                sw.WriteLine("Case #" + (i + 1) + ": " + result);
            }

            sr.Close();
            sw.Close();
        }
    }
}
