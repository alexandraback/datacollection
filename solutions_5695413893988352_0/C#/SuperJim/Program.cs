using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace B_brute
{
    class Program
    {
        static void Main(string[] args)
        {
            const string FileName = "C:\\Jam\\B-small-attempt0";
            FileStream fs = File.OpenRead(FileName + ".in");
            StreamReader sr = new StreamReader(fs);
            FileStream fout = File.OpenWrite(FileName + ".out");
            StreamWriter sw = new StreamWriter(fout);
            int ti, t;

            char[] c, j, oc, oj;
            string[] ts;

            t = int.Parse(sr.ReadLine());
            for (ti = 1; ti <= t; ti++)
            {
                Console.WriteLine(ti);
                ts = sr.ReadLine().Split(' ');
                oc = ts[0].ToArray<char>();
                oj = ts[1].ToArray<char>();
                c = oc;
                j = oj;
                for (int i = 0; i < c.Length; i++){
                    if(c[i] == '?'){c[i] = '0';}
                }
                for (int i = 0; i < c.Length; i++){
                    if(j[i] == '?'){j[i] = '0';}
                }

                int min = 9999;
                for (int i = 0; i < oc.Length; i++)
                {
                    if (oc[i] == '?')
                    {

                    }
                }

                    sw.WriteLine("Case #{0}: {1}", ti, 1);
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

        private int min(char[] oc, char[] oj, char[] c, char[] j, int amin, int depth)
        {
            int d = 0;
            for (int i = 0; i < oc.Length; i++)
            {
                if (oc[i] == '?')
                {
                    d++;
                    if (d > depth){
                        for (int k = 0; k < 10; k++)
                        {
                            c[i] = k.ToString()[0];
                            int tmin = min(oc, oj, c, j, amin, depth + 1);
                            if (tmin < amin)
                            {
                                amin = tmin;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < oj.Length; i++)
            {
                if (oj[i] == '?')
                {
                    d++;
                    if (d > depth)
                    {
                        for (int k = 0; k < 10; k++)
                        {
                            j[i] = k.ToString()[0];
                            int tmin = min(oc, oj, c, j, amin, depth + 1);
                            if (tmin < amin)
                            {
                                amin = tmin;
                            }
                        }
                    }
                }
            }
            return amin;
        }

    }
}
