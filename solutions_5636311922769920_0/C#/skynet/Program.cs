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

        static bool Next(int how, char[] val, int shift)
        {
            if (how == 0)
                return false;
            if (val[shift - 1] == '0')
            {
                for (var j = shift + 2; j <= val.Length - 1; j += 2)
                {
                    if (val[j - 1] == '1')
                    {
                        val[j - 1] = '0';
                        val[j - 3] = '1';
                        return true;
                    }
                }
            }
            if (Next(how - 1, val, shift + 2))
            {
                for (var j = shift + 2; j <= val.Length - 1; j += 2)
                {
                    if (val[j - 1] == '1')
                    {
                        val[shift - 1] = '0';
                        val[j - 3] = '1';
                        return true;
                    }
                }
            }
            return false;
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
                var splt = Console.ReadLine().Split(' ');
                var k = Get<uint>(splt[0]);
                var c = Get<uint>(splt[1]);
                var s = Get<uint>(splt[2]);

                if ((k + c - 1) / c > s)
                    Console.WriteLine("Case #{0}: IMPOSSIBLE", i);
                else 
                {
                    var answers = new List<ulong>();
                    uint cur = 1;
                    while (cur<=k)
                    {
                        ulong cand = 0;
                        for (var j = 1; j <= c; ++j)
                        {
                            uint val = cur;
                            if (val > k)
                                val = 1;
                            cand = cand * k + val - 1;
                            ++cur;
                        }
                        answers.Add(cand+1);
                    }
                    Console.WriteLine("Case #{0}: {1}", i, string.Join(" ", answers));
                }
            }
            Console.Out.Flush();
        }
    }
}