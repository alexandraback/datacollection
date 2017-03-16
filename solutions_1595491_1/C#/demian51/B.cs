using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace GCJ
{
    class B
    {
        static int cutoff(int n, int max)
        {
            if (n > max)
            {
                return max;
            }
            else
            {
                return n;
            }
        }

        static int getMax(int n)
        {
            return (int)(Math.Ceiling((double)n / 3.0));
        }

        static bool canbeSMax(int n)
        {
            return ((n % 3 != 1) && (n > 1) && (n < 29));
        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"D:\input.txt");
            StreamWriter sw = new StreamWriter(@"D:\output.txt");

            int n;

            n = int.Parse(sr.ReadLine());

            for (int i = 0; i < n; i++)
            {
                int result = 0;
                int s, p;
                string str;
                string[] strseq;
                List<int> seq = new List<int>();

                str = sr.ReadLine();
                strseq = str.Split(' ');

                s = int.Parse(strseq[1]);
                p = int.Parse(strseq[2]);

                for (int j = 3; j < strseq.Length; j++)
                {
                    seq.Add(int.Parse(strseq[j]));
                }

                seq.Sort();

                for (int j = 0; j < seq.Count; j++)
                {
                    if (cutoff(getMax(seq[j]), 10) >= p)
                    {
                        result++;
                    }
                    else if (canbeSMax(seq[j]) && (getMax(seq[j]) + 1 >= p) && s > 0)
                    {
                        result++;
                        s--;
                    }
                }

                sw.WriteLine("Case #" + (i + 1) + ": " + result);                
            }

            sr.Close();
            sw.Close();
        }
    }
}
