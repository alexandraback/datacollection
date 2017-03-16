using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Recycling
{
    class Recycling
    {
        static int CountPairs(int n, int b)
        {
            var str = n.ToString();
            int iLast = str.Length - 1;
            var result = new HashSet<int>();
            for (int i = 0; i < iLast; i++)
            {
                str = str[iLast] + str.Remove(iLast);
                int m = int.Parse(str);
                if ((m > n) && (m <= b))
                    result.Add(m);
            }
            return result.Count;
        }

        static string ProcessCase(TextReader rd)
        {
            var def = rd.ReadLine().Split(' ');

            int a = int.Parse(def[0]);
            int b = int.Parse(def[1]);

            int result = 0;
            for (int n = a; n < b; n++)
                result += CountPairs(n, b);

            return result.ToString();
        }

        static void Main(string[] args)
        {
            //const string InFile = @"C:\Users\Owen\Downloads\C-Eg.txt";
            //const string InFile = @"C:\Users\Owen\Downloads\C-small-attempt0.in";
            const string InFile = @"C:\Users\Owen\Downloads\C-large.in";

            using (var rd = File.OpenText(InFile))
            using (var wr = File.CreateText(@"C:\Users\Owen\Downloads\Out.txt"))
            {
                int t = int.Parse(rd.ReadLine());

                for (int i = 1; i <= t; i++)
                {
                    var result = ProcessCase(rd);
                    Console.WriteLine("Case #{0}: {1}", i, result);
                    wr.WriteLine("Case #{0}: {1}", i, result);
                }
            }
        }
    }
}
