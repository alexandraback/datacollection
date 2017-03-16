using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Diagnostics;

namespace ConsoleApplication1
{
    class Program
    {
        static string X(string s)
        {
            string[] t = s.Split(' ');
            int[] a = new int[t.Length - 1];

            int sum = 0;

            int[] tmp = new int[a.Length];

            for (int i = 0; i < a.Length; i++)
            {
                a[i] = int.Parse(t[i + 1]);
                sum += a[i];
            }

            int[] b = new int[a.Length];

            for (int j = 0; j < a.Length; j++)
            {
                int min = int.MaxValue;
                int pos = 0;
                for (int i = 0; i < a.Length; i++)
                {
                    if (a[i] < min)
                    {
                        min = a[i];
                        pos = i;
                    }
                }

                a[pos] = int.MaxValue;
                tmp[j] = min;
                b[j] = pos;
            }

            a = tmp;

            double[] par = new double[a.Length];

            int m = sum;

            double h = a[0];

            for (int i = 0; i < a.Length - 1; i++)
            {
                int d = a[i + 1] - a[i];
                int u = d * (i + 1);

                if (m <= u)
                {
                    h = h + ((double)m / (double)(i + 1));
                    m = 0;
                    break;
                }
                else
                {
                    h = h + d;
                }

                m = m - u;
            }

            if (m > 0)
            {
                h = h + ((double)m / (double)a.Length);
            }

            for (int i = 0; i < a.Length; i++)
            {
                int index = b[i];
                double p = h - a[i];
                p = p / (double)sum;
                if (p > 0)
                {
                    par[index] = p * 100;
                }
            }

            string o = "";
            for (int i = 0; i < a.Length; i++)
            {
                if (i != 0)
                {
                    o = o + " ";
                }

                o = o + par[i].ToString("F10");
            }

            return o;
        }


        static void Main(string[] args)
        {
            string x = @"C:\Users\a\Desktop\google code jam\test.txt";
            StreamReader sr = new StreamReader(x, Encoding.ASCII);

            string s;
            string output = "";

            int n = 0;

            while ((s = sr.ReadLine()) != null)
            {
                if (s == "") continue;

                if (n > 0)
                {
                    string o = X(s);
                    output += String.Format("Case #{0}: {1}\n", n, o);

                }

                n++;
            }

            sr.Close();

            StreamWriter writer = new StreamWriter(@"C:\Users\a\Desktop\google code jam\out.txt", false, Encoding.ASCII);
            writer.Write(output);
            writer.Close();
        }
    }
}
