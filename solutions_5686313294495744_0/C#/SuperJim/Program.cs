using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Problem_C
{
    class Program
    {
        static void Main(string[] args)
        {
            const string FileName = "C:\\Jam\\C-small-attempt0";
            FileStream fs = File.OpenRead(FileName + ".in");
            StreamReader sr = new StreamReader(fs);
            FileStream fout = File.OpenWrite(FileName + ".out");
            StreamWriter sw = new StreamWriter(fout);
            int ti, t;



            t = int.Parse(sr.ReadLine());
            for (ti = 1; ti <= t; ti++)
            {
                Console.WriteLine(ti);
                int n = int.Parse(sr.ReadLine());
                List<string> a = new List<string>();
                List<string> b = new List<string>();
                int[] x = new int[n];
                int[] y = new int[n];
                string[] ts;
                for (int i = 0; i < n; i++)
                {
                    ts = sr.ReadLine().Split(' ');
                    if (!a.Contains(ts[0]))
                    {
                        a.Add(ts[0]);
                    }
                    x[i] = a.IndexOf(ts[0]);
                    if (!b.Contains(ts[1]))
                    {
                        b.Add(ts[1]);
                    }
                    y[i] = b.IndexOf(ts[1]);
                }
                for (int j = 0; j < a.Count; j++)
                {
                    //vertex
                    for (int k = 0; k < x.Length; k++)
                    {
                        if (x[k] == j)
                        {
                            for (int l = 0; l < y.Length; l++)
                            {
                                if (l != k && y[l] == y[k])
                                {
                                    for (int m = 0; m < x.Length; m++)
                                    {
                                        if (m != l && x[m] == x[l])
                                        {
                                            x[l] = -1;
                                            y[l] = -1;
                                            continue;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                int sol = 0;
                for (int i = 0; i < x.Length; i++)
                {
                    if (x[i] == -1) sol++;
                }


                    sw.WriteLine("Case #{0}: {1}", ti, sol);
            }
            sw.Close();
            sw.Dispose();
            sr.Close();
            sr.Dispose();
        }

        public int[] intar(string input)
        {
            string[] ts = input.Split(' ');
            int[] a_int = new int[ts.Length];
            for (int i = 0; i < ts.Length; i++)
            {
                a_int[i] = int.Parse(ts[i]);
            }
            return a_int;
        }

    }
}
