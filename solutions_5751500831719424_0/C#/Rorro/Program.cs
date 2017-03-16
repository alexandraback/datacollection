using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2014
{
    class A { 
        public string sCad;
        public List<int> counts = new List<int>();
        public string normal;
        public A(string cad)
        {
            normal = cad;
            sCad = cad[0].ToString();
            char last = cad[0];
            int cont = 0;
            foreach (var c in cad)
            {
                if (c != last)
                {
                    sCad += c;
                    counts.Add(cont);
                    cont = 1;
                }
                else
                {
                    cont++;
                }
                last = c;
            }
            counts.Add(cont);
        }
    }
    class Program
    {
        static List<A> strings = new List<A>();

        static int minChanges(int pos)
        {
            int min = int.MaxValue;
            int lim = strings[0].sCad.Length;
            for (int i = 1; i < 105;i++)
            {
                int res = 0;
                foreach (var a in strings)
                {
                    res += Math.Abs(a.counts[pos] - i);
                }
                if (res < min)
                    min = res;
                else
                    break;
            }
            return min;
        }
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("C:/cjam/A1.in");
            StreamWriter writer = new StreamWriter("C:/cjam/A1.txt");
            int N = int.Parse(reader.ReadLine());
            for (int i = 1; i <= N; i++)
            {
                strings.Clear();
                int K = int.Parse(reader.ReadLine());
                for (int j = 0; j < K; j++)
                {
                    strings.Add(new A(reader.ReadLine()));
                }
                string baseString = strings[0].sCad;
                bool valid = true;

                foreach (var c in strings)
                {
                    if (baseString != c.sCad)
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid)
                {
                    int res = 0;
                    for(int j=0; j<baseString.Length;j++)
                        res+=minChanges(j);
                    
                    writer.WriteLine("Case #"+i.ToString()+": "+res.ToString());
                }
                else
                {
                    writer.WriteLine("Case #"+i.ToString()+": Fegla Won");
                }
            }
            reader.Close();
            writer.Close();
            //Console.WriteLine(change("mmaw", "maw"));
            //Console.WriteLine(change("gcj", "cj"));
            //Console.WriteLine(change("mmaw", "maw"));
        }
    }
}
