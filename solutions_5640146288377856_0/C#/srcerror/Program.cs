using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;

namespace CJ_Q
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Projects\Sandbox\CJ-Q\CJ-Q\data\A-small-attempt0.in";
            string output = @"d:\Projects\Sandbox\CJ-Q\CJ-Q\data\A-small-attempt0.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task1(sin);
                        sout.Write("Case #{0}: ", i);
                        Console.Write("Case #{0}: ", i);
                        sout.Write(result);
                        Console.Write(result);
                        if (i != N)
                        {
                            sout.WriteLine();
                            Console.WriteLine();
                        }
                    }
                }
            }
        }

        private static string Task1(StreamReader sin)
        {
            var s = sin.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
            var R = s[0];
            var C = s[1];
            var W = s[2];

            var res = R*C/W;
            if (C%W == 0)
            {
                res += W - 1;
            }
            else
            {
                res += W;
            }

            return res.ToString();
        }

        private static string Task2(StreamReader sin)
        {
            return "";
        }

        private static string Task3(StreamReader sin)
        {
            return "";
        }

//        private static string Task22(StreamReader sin)
//        {
//            var s = sin.ReadLine().Split(' ').Select(x => int.Parse(x)).ToList();
//            var R = s[0];
//            var C = s[1];
//            var N = s[2];

//            var A1 = new int[5] {0,0,0,0,0};
//            var A2 = new int[5] {0,0,0,0,0};

//            // A1 a00 = taken
//            var Rodd = R%2;
//            var Codd = C%2;

//            if (R == 1)
//            {
//                var x = R;
//                R = C;
//                C = x;
//            }
//            if (R == 1)
//            {
//                return "0";
//            }
//            if (C == 1)
//            {
//                A1[0] = R/2 + Rodd;
//                A2[0] = R/2;
//                if (R%2 == 0)
//                {
//                    A1[1] = 1;
//                    A2[1] = 1;
//                    A1[2] = R - A1[0] - A1[1];
//                    A2[2] = R - A2[0] - A2[1];
//                }
//                else
//                {
//                    A1[1] = 0;
//                    A2[1] = 2;
//                    A1[2] = R - A1[0] - A1[1];
//                    A2[2] = R - A2[0] - A2[1];
//                }

//                var t1 = 0;
//                var n = N;
//                for (int i = 0; i < 3; i++)
//                {
//                    if (n <= A1[i])
//                    {
//                        t1 += i*n;
//                        break;
//                    }
//                    else
//                    {
//                        t1 += i*A1[i];
//                        n -= A1[i];
//                    }
//                }
//                var t2 = 0;
//                n = N;
//                for (int i = 0; i < 3; i++)
//                {
//                    if (n <= A2[i])
//                    {
//                        t2 += i * n;
//                        break;
//                    }
//                    else
//                    {
//                        t2 += i * A2[i];
//                        n -= A2[i];
//                    }
//                }
//                if (t1 < t2)
//                    return t1.ToString();
//                else
//                {
//                    return t2.ToString();
//                }
//            }

//            // chess cells
//            for (int i = 0; i < R; i++)
//            {
//                if (i%2 == 0)
//                {
//                    A1[0] += (C/2) + Codd;
//                }
//                else
//                {
//                    A1[0] += (C/2);
//                }
//            }
//            // corner cells
//            if (R%2 == 0)
//            {
//                if (C%2 == 0)
//                {
//                    A1[2] = 2;
//                    A1[3] += R - A1[2];
//                    A1[3] += C - A1[2];
//                }
//                else
//                {
//                    // C odd
//                    A1[2] = 2;
//                    if (C > 1)
//                    {
//                        A1[3] += R - A1[2];
//                        A1[3] += C - A1[2];
//                    }
//                    else
//                    {
//                        // 1
//                        A1[3] += (R/2) - 1;
//                    }
//                }
//            }
//            else
//            {
//                // R odd
//                if (C%2 == 0)
//                {
//                    A1[2] = 2;
//                    if (R > 1)
//                    {
//                        A1[3] += R - A1[2];
//                        A1[3] += C - A1[2];
//                    }
//                    else
//                    {
//                        // 1
//                        A1[3] += (C / 2) - 1;
//                    }
//                }
//                else
//                {
//                    // C odd
//                    A1[2] = 0;
//                    if (R == 1)
//                    {
//                        A1[3] += (C/2);
//                    }
//                    else if (C == 1)
//                    {
//                        A1[3] += (R / 2);
//                    }
//                    else
//                    {
//                        // both > 1
//                        A1[3] += (C / 2);
//                        A1[3] += (C / 2);
//                        A1[3] += (R / 2);
//                        A1[3] += (R / 2);
//                    }
//                }

//            }

//            // inner cells
//            if ((R-2) > 0 && (C - 2) > 0)
//            {
//                // there is something to count
//                var rr1 = (R - 2)/2 + Rodd;
//                var rr2 = (R - 2)/2;
//                var cc1 = (C - 2)/2 + Codd;
//                var cc2 = (C - 2)/2;
//                A1[4] += rr1*cc2 + rr2*cc1;
//            }

//            // A2 a00 = not taken
//;

//            // chess cells
//            for (int i = 0; i < R; i++)
//            {
//                if (i % 2 == 0)
//                {
//                    A2[0] += (C / 2);
//                }
//                else
//                {
//                    A2[0] += (C / 2) + Codd;
//                }
//            }
//            // corner cells
//            if (R % 2 == 0)
//            {
//                if (C % 2 == 0)
//                {
//                    A2[2] = 2;
//                    A2[3] += R - A2[2];
//                    A2[3] += C - A2[2];
//                }
//                else
//                {
//                    // C odd
//                    A2[2] = 2;
//                    if (C > 1)
//                    {
//                        A2[3] += R - A2[2];
//                        A2[3] += C - A2[2];
//                    }
//                    else
//                    {
//                        // 1
//                        A2[3] += (R / 2) - 1;
//                    }
//                }
//            }
//            else
//            {
//                // R odd
//                if (C % 2 == 0)
//                {
//                    A2[2] = 2;
//                    if (R > 1)
//                    {
//                        A2[3] += R - A2[2];
//                        A2[3] += C - A2[2];
//                    }
//                    else
//                    {
//                        // 1
//                        A2[3] += (C / 2) - 1;
//                    }
//                }
//                else
//                {
//                    // C odd
//                    A2[2] = 4;
//                    if (R == 1)
//                    {
//                        A2[3] += (C / 2);
//                    }
//                    else if (C == 1)
//                    {
//                        A2[3] += (R / 2);
//                    }
//                    else
//                    {
//                        // both > 1
//                        A2[3] += ((C-2) / 2);
//                        A2[3] += ((C-2) / 2);
//                        A2[3] += ((R-2) / 2);
//                        A2[3] += ((R-2) / 2);
//                    }
//                }

//            }

//            // inner cells
//            if ((R - 2) > 0 && (C - 2) > 0)
//            {
//                // there is something to count
//                var rr1 = (R - 2) / 2 + Rodd;
//                var rr2 = (R - 2) / 2;
//                var cc1 = (C - 2) / 2 + Codd;
//                var cc2 = (C - 2) / 2;
//                A2[4] += rr1 * cc1 + rr2 * cc2;
//            }

//            var tt1 = 0;
//            var nn = N;
//            for (int i = 0; i < 5; i++)
//            {
//                if (nn <= A1[i])
//                {
//                    tt1 += i * nn;
//                    break;
//                }
//                else
//                {
//                    tt1 += i * A1[i];
//                    nn -= A1[i];
//                }
//            }
//            var tt2 = 0;
//            nn = N;
//            for (int i = 0; i < 5; i++)
//            {
//                if (nn <= A2[i])
//                {
//                    tt2 += i * nn;
//                    break;
//                }
//                else
//                {
//                    tt2 += i * A2[i];
//                    nn -= A2[i];
//                }
//            }
//            if (tt1 < tt2)
//                return tt1.ToString();
//            else
//            {
//                return tt2.ToString();
//            }
//            return "".ToString();
//        }

        //private static string Task11(StreamReader sin)
        //{
        //    var N = sin.ReadLine();
        //    var c = new long[]
        //    {
        //        0, 9+1, 9+1+9, 99+1+9, 99+1+99, 999+1+99, 999+1+999, 9999+1+999,
        //        9999+1+9999, 99999+1+9999, 99999+1+99999, 999999+1+99999, 999999+1+999999,
        //        9999999+1+999999, 9999999+1+9999999, 99999999+1+9999999
        //    };

        //    var l = N.Length;
        //    BigInteger basis = 0;

        //    var NN = BigInteger.Parse(N);
        //    if (NN <= 19) return N;

        //    if (N.Last() == '0')
        //    {
        //        basis += 1;
        //        NN--;
        //        N = NN.ToString();
        //        l = N.Length;
        //    }

        //    for (int i = 0; i < l; i++)
        //    {
        //        basis += c[i];
        //    }
        //    if (l%2 == 0)
        //    {
        //        // even
        //        var L = l/2;
        //        var N1 = N.Substring(L, L);
        //        var N2a = N.Substring(0, L).Reverse().ToArray();
        //        var N2 = new string(N2a);

        //        var NN1 = BigInteger.Parse(N1);
        //        var NN2 = BigInteger.Parse(N2)-1;
        //        basis += NN2;
        //        basis += 1;
        //        basis += NN1;
        //        if (NN2 == 0) basis--;
        //    }
        //    else
        //    {
        //        // odd
        //        var L = l / 2;
        //        var N1 = N.Substring(L, L+1);
        //        var N2a = N.Substring(0, L).Reverse().ToArray();
        //        var N2 = new string(N2a);

        //        var NN1 = BigInteger.Parse(N1);
        //        var NN2 = BigInteger.Parse(N2)-1;
        //        basis += NN2;
        //        basis += 1;
        //        basis += NN1;
        //        if (NN2 == 0) basis--;
        //    }

        //    return basis.ToString();
        //}

    }
}
