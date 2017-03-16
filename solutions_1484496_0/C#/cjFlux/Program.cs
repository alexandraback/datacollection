using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace TaskC
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
            StreamReader sr = new StreamReader(@"inputC.txt");
            StreamWriter sw = new StreamWriter(@"outputC.txt");
            int Count = int.Parse(sr.ReadLine());
            for (int t = 1; t <= Count; t++)
            {
                int[] Arr = Array.ConvertAll(sr.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries).Skip(1).ToArray(), s => int.Parse(s));
                sw.WriteLine(@"Case #{0}:", t);

                Array.Sort(Arr);
                Dictionary<int, SortedSet<int>> Dict = new Dictionary<int, SortedSet<int>>();
                int upperBound = (1 << Arr.Length) - 1;
                for (int mask = 0; mask < upperBound; mask++)
                {
                    var p = mask;
                    int sum = 0;
                    SortedSet<int> items = new SortedSet<int>();
                    for (int i = 0; i < Arr.Length; i++)
                    {
                        if (p % 2 == 1) { sum += Arr[i]; items.Add(Arr[i]); }
                        p /= 2;
                    }
                    if (Dict.ContainsKey(sum))
                    {
                        sw.WriteLine(string.Join(" ", Dict[sum]));
                        sw.Write(string.Join(" ", items));
                        goto fin;
                    }
                    else Dict.Add(sum, items);
                }
                sw.Write("Impossible");
            fin: ;
                if (t != Count) sw.WriteLine();
                Console.WriteLine(@"Case #{0} solved", t);
            }
            sr.Close(); sw.Close();
        }
    }
}