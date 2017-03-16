using System;
using System.Collections;
using System.IO;

namespace Recycled_Numbers
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            string filename = @"C-large.in.txt";

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (StreamReader reader = new StreamReader(filename))
            {
                using (StreamWriter writer = new StreamWriter(filename.Replace(".in.", ".out."), false))
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

        private static void Process(int C, TextReader reader, TextWriter writer)
        {
            string[] s = reader.ReadLine().Split(' ');
            int A = int.Parse(s[0]);
            int B = int.Parse(s[1]);

            int swap = 0;

            Hashtable h = new Hashtable();
            for (int i = A; i <= B; i++)
            {
                h.Clear();
                string ss = i.ToString();
                char[] cc = ss.ToCharArray();
                for (int j = 0; j < ss.Length; j++)
                {
                    char last = cc[cc.Length - 1];
                    for (int l = cc.Length - 1; l > 0; l--)
                        cc[l] = cc[l - 1];
                    cc[0] = last;
                    int k = int.Parse(new string(cc));
                    if (k > i && k <= B)
                    {
                        
                        //writer.WriteLine(i + "->" + k);
                        if (h[k] != null)
                            Console.WriteLine(i + "->" + k);
                        else
                        {
                            swap++;
                            h[k] = 1;
                        }
                    }
                }
            }

            Console.WriteLine("Case #{0}: {1}", C, swap);
            writer.WriteLine("Case #{0}: {1}", C, swap);
        }
    }
}