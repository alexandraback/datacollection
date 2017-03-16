using System;
using System.Collections;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Collections.Generic;
//using System.Numerics;

namespace CodeChefNet
{
    class Program
    {
        private static bool fromFile = true;
        private static TextReader tmpReader;
        private static TextWriter tmpWriter;

        static double comb(int n, int x)
        {
            var ans = 1.0;
            int nleft = n;
            int other = Math.Min(x, n - x);
            x = Math.Max(x, n - x);
            for(var i = x+1; i<=n;i++)
            {
                ans *= i;
                while(ans>1000 && other>0)
                {
                    ans /= other;
                    other--;
                }
                while(ans>1000 && nleft>0)
                {
                    ans /= 2;
                    nleft--;
                }
            }
            while ( other > 0)
            {
                ans /= other;
                other--;
            }
            while ( nleft > 0)
            {
                ans /= 2;
                nleft--;
            }
            return ans;
        }

        static void Main(string[] args)
        {
            if (fromFile)
            {
                tmpWriter = Console.Out;
                tmpReader = Console.In;
                Console.SetIn(new StreamReader(@"in.txt"));
                Console.SetOut(new StreamWriter(@"out.txt"));
            }
            
            var T = GetInt();

            for (var i = 0; i < T; i++)
            {
                double answer = 0;
                var nums = GetInts();
                var N = nums[0];
                var X = nums[1];
                var Y = nums[2];

                int n = 0;
                for (var j = 1; j < N;j++ )
                {
                    if(2*j*j-j>N)
                    {
                        n = j - 1;
                        break;
                    }
                }

                if (X == 0 && Y == 0) answer = 1;
                else if ((Math.Abs(X) + Math.Abs(Y) + 2) / 2 <= n) answer = 1;
                else if ((Math.Abs(X) + Math.Abs(Y) + 2) / 2 > n + 1) answer = 0;
                else if (Y == n * 2 && X == 0) answer = 0;
                else
                {
                    var E = N - 2 * n * n + n;
                    if (Y + 1 > E) answer = 0;
                    else if (2 * n + Y + 1 <= E) answer = 1;
                    else
                    {
                        var p = 0.0;

                        if (E > 2 * n)
                        {
                            for (var k = E + 1 - 2 * n; k < Y + 1; k++)
                            {
                                p += comb(E, k);
                            }
                        }
                        else if(E==2*n)
                        {
                            for (var k = 1; k < Y + 1; k++)
                            {
                                p += comb(E, k);
                            }
                        }
                        else
                        {
                            for (var k = 0; k < Y + 1; k++)
                            {
                                p += comb(E, k);
                            }
                        }
                        answer = 1 - p;
                    }
                }


                Console.WriteLine(string.Format("Case #{0}: {1}", i + 1, answer));
            }


                if (fromFile)
                {
                    Console.Out.Flush();
                    Console.Out.Close();
                    Console.SetOut(tmpWriter);
                    Console.SetIn(tmpReader);

                    //Console.WriteLine("TIME: " + DateTime.Now.Subtract(st).TotalMilliseconds);
                    //Console.ReadKey();
                }
        }

        #region Getting stuff from console

        static string GetLine()
        {
            var line = Console.ReadLine();
            while (string.IsNullOrEmpty(line))
            {
                line = Console.ReadLine();
            }
            return line;
        }

        static int GetInt()
        {
            return int.Parse(GetLine());
        }

        static List<int> GetInts()
        {
            return GetLine().Split(' ').Select(x => int.Parse(x)).ToList();
        }

        static long GetLong()
        {
            return long.Parse(GetLine());
        }

        static List<long> GetLongs()
        {
            return GetLine().Split(' ').Select(x => long.Parse(x)).ToList();
        }

        static string GetString()
        {
            return GetLine();
        }

        static string[] GetStrings()
        {
            return GetLine().Split(' ').ToArray();
        }

        #endregion
    }
}
