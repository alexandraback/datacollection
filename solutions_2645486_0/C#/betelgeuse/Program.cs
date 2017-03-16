using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static int T, e, emax, r, n,gain;
        static List<int> v = new List<int>();
        static List<int> result = new List<int>();
        static int max;

        static void recurse(int index)
        {
            int ec = e;
            e += r; if (e > emax) e = emax;
            int remain = e;
            for (int i = 0; i <= remain;i++ )
            {
                e -= i;
                gain += i * v[index];
                if (index < v.Count - 1) recurse(index + 1);
                else
                {
                    if (gain > max) max = gain;
                }
                e += i;
                gain -= i * v[index];
            }
            e = ec;
        }
        
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("y:/B-small-attempt0.in");
            StreamWriter sw = new StreamWriter("y:/output",false);
            
            T = sr.ReadLine().toInt();
            for (int i = 0; i < T;i++ )
            {
                v.Clear(); result.Clear(); gain = 0; max = 0;
                string[] s = sr.ReadLine().Split(' ');
                emax = e = s[0].toInt(); r = s[1].toInt(); n = s[2].toInt();
                s = sr.ReadLine().Split(' ');
                foreach (string ss in s) v.Add(ss.toInt());
                recurse(0);
                sw.WriteLine("Case #" + (i + 1).ToString() + ": " + max.ToString());
            }
            sw.Close();
            //Console.ReadLine();
        }
    }

    static class MyExt
    {
        public static int toInt(this string s)
        {
            return Int32.Parse(s);
        }
        public static double toDouble(this string s)
        {
            return Double.Parse(s);
        }
    }
}
