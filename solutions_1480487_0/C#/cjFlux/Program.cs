using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace TaskA
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
            StreamReader sr = new StreamReader(@"inputA.txt");
            StreamWriter sw = new StreamWriter(@"outputA.txt");
            int Count = int.Parse(sr.ReadLine());
            for (int t = 1; t <= Count; t++)
            {
                double[] Arr = Array.ConvertAll(sr.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Skip(1).ToArray(), s => double.Parse(s));
                int cnt = Arr.Count(x => x > Arr.Average() * 2);
                var Less = Arr.Where(x => x < Arr.Average() * 2).ToArray();
                var Arr2 = Arr.Select(x => (x > Arr.Average() * 2) ? 0.0 : ((Arr.Sum() + Less.Sum()) / Less.Length - x) / Arr.Sum() * 100.0).ToArray();
                sw.Write("Case #{0}:", t);
                for (int i = 0; i < Arr.Length; i++) sw.Write(" {0:f6}", Arr2[i]);
                if (t != Count) sw.WriteLine();
            }


            sr.Close(); sw.Close();
        }
    }
}
