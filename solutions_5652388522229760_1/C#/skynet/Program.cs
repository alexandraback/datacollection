using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Program
    {
        static T Get<T>(object obj)
        {
            return (T)Convert.ChangeType(obj, typeof(T));
        }

        static void Add(int x, HashSet<int> keep)
        {
            while (x > 0)
            {
                keep.Add(x%10);
                x /= 10;
            }
        }

        static void Main(string[] args)
        {
#if !DEBUG
            Console.SetIn(new StreamReader("input.txt"));
            Console.SetOut(new StreamWriter("output.txt"));      
#endif
            int t = Get<int>(Console.ReadLine());
            for (var i = 1; i <= t; ++i)
            {
                var n = Get<int>(Console.ReadLine());
                if (n == 0)
                    Console.WriteLine("Case #{0}: INSOMNIA", i);
                else
                {
                    var stor = new HashSet<int>();
                    var a = 0;
                    while (stor.Count < 10)
                    {
                        a += n;
                        Add(a, stor);
                    }
                    Console.WriteLine("Case #{0}: {1}", i, a);
                }
            }
            Console.Out.Flush();
        }
    }
}