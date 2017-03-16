using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Diagnostics;

namespace ConsoleApplication1
{
    class Program
    {
        static double M(double[] d)
        {
            double t = double.PositiveInfinity;
            foreach (double x in d)
            {
                if (x < t)
                {
                    t = x;
                }
            }
            return t;
        }


        static string X(int a, double[] b)
        {
            int n = b.Length;
            int m = a - n;

            double[] s = new double[n];

            s[0] = b[0];
            for (int i = 1; i < n; i++)
            {
                s[i] = s[i - 1] * b[i];
            }

            List<double> l = new List<double>();

            l.Add(a + 2);

            double t = (m + 1) * s[n - 1] + (2 * m + n + 2) * (1 - s[n - 1]);
            l.Add(t);

            for (int i = 1; i < n; i++)
            {
                int j = n - i - 1;
                t = s[j] * (2 * i + m + 1) + (1 - s[j]) * (2 * i + m + a + 2);
                l.Add(t);
            }

            double min = M(l.ToArray());

            return min.ToString("F6");
        }


        static void Main(string[] args)
        {
            string x = @"C:\Users\a\Desktop\test.txt";
            //string x = @"C:\Users\a\Desktop\B-small-practice.in";
            //string x = @"C:\Users\a\Desktop\B-large-practice.in";
            //string x = @"C:\Users\a\Desktop\A-large-practice.in";
            StreamReader sr = new StreamReader(x, Encoding.ASCII);

            string s;
            string output = "";

            int n = 0;

            string[] t = new string[2];

            int Case = 1;

            while ((s = sr.ReadLine()) != null)
            {
                if (s == "") continue;

                if (n > 0)
                {
                    t[1 - (n % 2)] = s;
                    if (n % 2 == 0)
                    {
                        int a = int.Parse(t[0].Split(' ')[1]);
                        double[] d = new double[int.Parse(t[0].Split(' ')[0])];
                        int j = 0;
                        foreach (string c in t[1].Split(' '))
                        {
                            d[j] = double.Parse(c);
                            j++;
                        }

                        string o = X(a, d);
                        output += String.Format("Case #{0}: {1}\n", Case, o);
                        Case++;
                    }
                }

                n++;
            }

            sr.Close();

            StreamWriter writer = new StreamWriter(@"C:\Users\a\Desktop\output.txt", false, Encoding.ASCII);
            writer.Write(output);
            writer.Close();
        }
    }
}
