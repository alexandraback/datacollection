using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Problem_A
{
    class Program
    {
        static void Main(string[] args)
        {
            const string FileName = "C:\\Jam\\A-large";
            FileStream fs = File.OpenRead(FileName + ".in");
            StreamReader sr = new StreamReader(fs);
            FileStream fout = File.OpenWrite(FileName + ".out");
            StreamWriter sw = new StreamWriter(fout);
            int ti, t;


            t = int.Parse(sr.ReadLine());
            for (ti = 1; ti <= t; ti++)
            {
                Console.WriteLine(ti);
                String inp = sr.ReadLine();
                Dictionary<char, int> per = new Dictionary<char, int>();
                foreach(char c in inp)
                {
                    if (per.ContainsKey(c)){
                        per[c]++;
                    }
                    else
                    {
                        per.Add(c, 1);
                    }
                }

                int[] to = new int[10];
                if (per.ContainsKey('Z'))
                {
                    to[0] = per['Z'];
                }
                if (per.ContainsKey('W'))
                {
                    to[2] = per['W'];
                }
                if (per.ContainsKey('U'))
                {
                    to[4] = per['U'];
                }
                if (per.ContainsKey('X'))
                {
                    to[6] = per['X'];
                }
                if (per.ContainsKey('G'))
                {
                    to[8] = per['G'];
                }
                if (per.ContainsKey('S'))
                {
                    to[7] = per['S'] - to[6];
                }
                if (per.ContainsKey('V'))
                {
                    to[5] = per['V'] - to[7];
                }
                if (per.ContainsKey('H'))
                {
                    to[3] = per['H'] - to[8];
                }
                if (per.ContainsKey('O'))
                {
                    to[1] = per['O'] - to[0] - to[2] - to[4];
                }
                if (per.ContainsKey('I'))
                {
                    to[9] = per['I'] - to[5] - to[6] - to[8];
                }
                StringBuilder sol = new StringBuilder();
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < to[i]; j++)
                    {
                        sol.Append(i);
                    }
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
