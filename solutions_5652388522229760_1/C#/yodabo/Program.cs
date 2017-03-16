using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication6
{
    class Program
    {
        static int CountSheep(int N)
        {
            HashSet<char> seen = new HashSet<char>();

            for (int j = 1; true; j++)
            {
                bool done = true;
                int num = N * j;
                var digits = num.ToString().ToList();
                for (int i = 0; i < 10; ++i)
                {
                    if (digits.Contains(i.ToString()[0]))
                    {
                        seen.Add(i.ToString()[0]);
                    }
                    else if (!seen.Contains(i.ToString()[0]))
                    {
                        done = false;
                    }
                }

                if (done)
                {
                    N = j * N;
                    break;
                }
            }
            return N;
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; ++i)
            {
                int N = int.Parse(Console.ReadLine());
                if (N == 0)
                {
                    Console.WriteLine("Case #{0}: INSOMNIA", i);
                }
                else
                {
                    Console.WriteLine("Case #{0}: {1}", i, CountSheep(N));
                }
            }

            //int max = 0;
            //for (int i = 1; i < 1000000; ++i)
            //{
            //    max = System.Math.Max(max, CountSheep(i) / i);
            //    //if (i == 0)
            //    //{
            //    //    Console.WriteLine("{0}: INSOMNIA");
            //    //}
            //    //else
            //    //{
            //    //    Console.WriteLine("{0}: {1}", i, CountSheep(i));
            //    //}
            //    //if (i % 20 == 19)
            //    //{
            //    //    Console.ReadKey();
            //    //}
            //}
            //Console.WriteLine("{0}", max);
            //Console.ReadKey();
        }
    }
}
