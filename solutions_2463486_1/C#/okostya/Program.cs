using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Fair_and_Square
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //string filename = @"sample.in.txt";
            //string filename = @"C-small-attempt0.in.txt";
            string filename = @"C-large-1.in.txt";
            
            for (long i = 1; i <= 10000000; i++)
            {
                if (isp(i) && isp(i * i))
                    pp.Add(i * i);
            }

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }
        static List<long> pp = new List<long>();
        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            long A = long.Parse(ss[0]);
            long B = long.Parse(ss[1]);

            int count = 0;
            foreach (long i in pp)
            {
                if (i >= A && i <= B)
                    count++;
            }

            Console.WriteLine("Case #{0}: {1}", C, count);
            writer.WriteLine("Case #{0}: {1}", C, count);
        }

        static bool isp(long n)
        {
            string s = n.ToString();
            if (s.Length == 1)
                return true;
            for(int i=0;i<s.Length/2;i++)
            {
                if (s[i] != s[s.Length - 1 - i])
                    return false;
            }
            return true;
        }
    }
}
