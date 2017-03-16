using System;
using System.Globalization;
using System.IO;
using System.Threading;
using System.Collections.Generic;
using System.Linq;

namespace BFFs
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            const string filename = @"..\..\C-small-attempt1.in";
            //const string filename = @"..\..\B-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
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

       
        static int[] color;
        static int Dfs(int index, int from, int last)
        {
            if (index == last)
                return 1;

            color[index] = 1;
            int max = last==-1?1:-10000;
            foreach (int i in frs[index])
            {
                if (from == i || color[i]!=0)
                    continue;

                max = Math.Max(max, 1 + Dfs(i, index, last));
            }
            
            color[index] = 0;
            return max;
        }
        static List<int>[] frs;

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            int n = int.Parse(reader.ReadLine());

            string[] ss = reader.ReadLine().Split(' ');

            int[] friends = new int[n + 1];
            
            frs= new List<int>[n + 1];
            for (int i = 0; i < frs.Length; i++)
                frs[i] = new List<int>();
            for (int i = 1; i <= n; i++)
            {
                int a = int.Parse(ss[i - 1]);
                friends[i] = a;
                frs[a].Add(i);
            }
            
            int time = 0;
            color = new int[n + 1];
            for (int i = 1; i <= n; i++)
            {
                
                if (friends[friends[i]]==i)
                    time = Math.Max(time, Dfs(i, friends[i], -1) + Dfs(friends[i], i, -1));
                else
                    time = Math.Max(time, Dfs(i, friends[i], friends[i]));
            }

            Console.WriteLine("Case #{0}: {1}", Case, time);
            writer.WriteLine("Case #{0}: {1}", Case, time);
        }
    }
}