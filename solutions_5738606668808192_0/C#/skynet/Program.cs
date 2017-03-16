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
                int n = Get<int>(splt[0]);
                int j = Get<int>(splt[1]);
                
                Console.WriteLine("Case #{0}:", i);
                var result = new []{'1'}.Concat(Enumerable.Repeat('0', n-2)).Concat(new[]{'1'}).ToArray();
                var st = 0;
                for (int k = 1; k <= j; ++k)
                {
                    Console.WriteLine("{0} 3 4 5 6 7 8 9 10 11", new String(result));
                    if (!Next(st, result, 3))
                    {
                        for (var b = n - 1; b >= 2; b -= 2)
                            result[b - 1] = '0';
                        for (var b = n - 1; b >= n - st; b -= 2)
                            result[b - 1] = '1';                        
                        if (!Next(st, result, 2))
                        {
                            result = new[] { '1' }.Concat(Enumerable.Repeat('0', n - 2)).Concat(new[] { '1' }).ToArray();
                            st += 2;
                            for (var b = n - 1; b >= n - st; --b)
                                result[b - 1] = '1';
                        }
                    }
                }
            }
            Console.Out.Flush();
        }
    }
}