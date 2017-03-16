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
            string filename = @"C-small-attempt0.in.txt";
            //string filename = @"B-large.in.txt";
            
            for (int i = 1; i <= 32; i++)
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
 static List<int> pp = new List<int>();
        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            int A = int.Parse(ss[0]);
            int B = int.Parse(ss[1]);

            int count = 0;
            foreach (int i in pp)
            {
                if (i >= A && i <= B)
                    count++;
            }

            Console.WriteLine("Case #{0}: {1}", C, count);
            writer.WriteLine("Case #{0}: {1}", C, count);
        }

        static bool isp(int n)
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
