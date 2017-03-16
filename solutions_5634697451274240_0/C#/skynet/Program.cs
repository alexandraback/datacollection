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
                var s = Console.ReadLine();
                var r = 0;
                var sw = false;
                foreach (var c in s.Reverse())
                {
                    if (sw)
                    {
                        if (c == '+')
                        {
                            ++r;
                            sw = false;
                        }
                    }
                    else if (c == '-')
                    {
                        ++r;
                        sw = true;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", i, r);
            }
            Console.Out.Flush();
        }
    }
}