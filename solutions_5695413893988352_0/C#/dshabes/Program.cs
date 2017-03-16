using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016_1B_B
{
    class Program
    {
        static long calc(int index, ref long c, ref long j)
        {
            if (index >= C.Length) return Math.Abs(c - j);
            for (int i = index; i < C.Length; i++)
            {
                if (C[i] != '?')
                {
                    if (J[i] != '?')
                    {
                        c = c * 10 + (C[i] - '0');
                        j = j * 10 + (J[i] - '0');
                    }
                    else
                    {
                        if (c == j)
                        {
                            c = c * 10 + (C[i] - '0');
                            j = j * 10 + (C[i] - '0');
                            var c1 = c;
                            var j1 = j;
                            var res = calc(i + 1, ref c1, ref j1);
                            var cc = c1;
                            var jj = j1;
                            if (C[i] > '0')
                            {
                                c1 = c;
                                j1 = j - 1;
                                var res1 = calc(i + 1, ref c1, ref j1);
                                if (res1 <= res)
                                {
                                    res = res1;
                                    cc = c1;
                                    jj = j1;
                                }
                            }
                            if (C[i] < '9')
                            {
                                c1 = c;
                                j1 = j + 1;
                                var res1 = calc(i + 1, ref c1, ref j1);
                                if (res1 < res)
                                {
                                    res = res1;
                                    cc = c1;
                                    jj = j1;
                                }
                            }
                            c = cc;
                            j = jj;
                            return res;
                        }
                        else if (c < j)
                        {
                            c = c * 10 + (C[i] - '0');
                            j = j * 10;
                        }
                        else
                        {
                            c = c * 10 + (C[i] - '0');
                            j = j * 10 + 9;
                        }
                    }
                }
                else
                {
                    if (J[i] != '?')
                    {
                        if (c == j)
                        {
                            c = c * 10 + (J[i] - '0');
                            j = j * 10 + (J[i] - '0');
                            var c1 = c;
                            var j1 = j;
                            var res = calc(i + 1, ref c1, ref j1);
                            var cc = c1;
                            var jj = j1;
                            if (J[i] > '0')
                            {
                                c1 = c - 1;
                                j1 = j;
                                var res1 = calc(i + 1, ref c1, ref j1);
                                if (res1 <= res)
                                {
                                    res = res1;
                                    cc = c1;
                                    jj = j1;
                                }
                            }
                            if (J[i] < '9')
                            {
                                c1 = c + 1;
                                j1 = j;
                                var res1 = calc(i + 1, ref c1, ref j1);
                                if (res1 < res)
                                {
                                    res = res1;
                                    cc = c1;
                                    jj = j1;
                                }
                            }
                            c = cc;
                            j = jj;
                            return res;
                        }
                        else if (c < j)
                        {
                            c = c * 10 + 9;
                            j = j * 10 + (J[i] - '0');
                        }
                        else
                        {
                            c = c * 10;
                            j = j * 10 + (J[i] - '0');
                        }
                    }
                    else
                    {
                        if (c == j)
                        {
                            c = c * 10;
                            j = j * 10;
                            var c1 = c;
                            var j1 = j;
                            var res = calc(i + 1, ref c1, ref j1);
                            var cc = c1;
                            var jj = j1;
                            if (true)
                            {
                                c1 = c;
                                j1 = j + 1;
                                var res1 = calc(i + 1, ref c1, ref j1);
                                if (res1 < res)
                                {
                                    res = res1;
                                    cc = c1;
                                    jj = j1;
                                }
                            }
                            if (true)
                            {
                                c1 = c + 1;
                                j1 = j;
                                var res1 = calc(i + 1, ref c1, ref j1);
                                if (res1 < res)
                                {
                                    res = res1;
                                    cc = c1;
                                    jj = j1;
                                }
                            }
                            c = cc;
                            j = jj;
                            return res;
                        }
                        else if (c < j)
                        {
                            c = c * 10 + 9;
                            j = j * 10;
                        }
                        else
                        {
                            c = c * 10;
                            j = j * 10 + 9;
                        }
                    }
                }
            }
            return Math.Abs(c - j);
        }

        static string C, J;

        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (int testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split();
                C = parts[0];
                J = parts[1];
                long c = 0;
                long j = 0;
                calc(0, ref c, ref j);
                Console.WriteLine("Case #{0}: {1} {2}", testN, c.ToString().PadLeft(C.Length, '0'), j.ToString().PadLeft(C.Length, '0'));
            }
        }
    }
}
