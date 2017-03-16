using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace GCJ.P2
{
    class Program
    {
        static char[] Clone(char[] C)
        {
            var r = new char[C.Length];
            for(int i = 0; i < C.Length; ++i)
            {
                r[i] = C[i];
            }
            return r;
        }

        static bool less(Tuple<long, long >r1, Tuple<long, long> r2)
        {
            var diff1 = Math.Abs(r1.Item1 - r1.Item2);
            var diff2 = Math.Abs(r2.Item1 - r2.Item2);
            if(diff1 < diff2)
            {
                return true;
            }
            if(diff1 == diff2 && r1.Item2 < r2.Item2)
            {
                return true;
            }
            return false;
        }

        static Tuple<long, long> Solve2(char[] C, char[] J)
        {
            var best = Tuple.Create(0L, long.MaxValue);
            for (int i = 0; i < C.Length; ++i)
            {
                if(C[i] == '?')
                {
                    for(int j = 0; j < 10; ++j)
                    {
                        C[i] = (char)(j + '0');
                        var res = Solve2(C, J);
                        if(less(res, best))
                        {
                            best = res;
                        }
                    }
                    C[i] = '?';
                    return best;
                }
            }

            for (int i = 0; i < C.Length; ++i)
            {
                if (J[i] == '?')
                {
                    for (int j = 0; j < 10; ++j)
                    {
                        J[i] = (char)(j + '0');
                        var res = Solve2(C, J);
                        if (less(res, best))
                        {
                            best = res;
                        }
                    }
                    J[i] = '?';
                    return best;
                }
            }
            return Tuple.Create(long.Parse(new string(C)), long.Parse(new string(J)));

        }

        static Tuple<long, long > Solve (char[] C, char[] J)
        {
            for (int i = 0; i < C.Length; ++i)
            {
                if (C[i] == '?' && J[i] == '?')
                {
                    if (i < C.Length - 1 && C[i + 1] == '?' && J[i + 1] == '?')
                    {
                        C[i] = '0';
                        J[i] = '0';
                        continue;
                    }

                    var best = Tuple.Create(0L, long.MaxValue);
                    for (int c = 0; c <= 9; ++c)
                    {
                        for (int j = 0; j <= 9; ++j)
                        {
                            C[i] = (char)(c + '0');
                            J[i] = (char)(j + '0');
                            var r = Solve(Clone(C), Clone(J));
                            if (less(r, best))
                            {
                                best = r;
                            }
                        }
                    }
                    return best;
                    /*
                    C[i] = '0';
                    J[i] = '0';
                    var r1 = Solve(Clone(C), Clone(J));

                    var best = r1;
                    C[i] = '9';
                    var r2 = Solve(Clone(C), Clone(J));
                    if(less(r2, best))
                    {
                        best = r2;
                    }
                    J[i] = '9';
                    C[i] = '0';
                    var r3 = Solve(Clone(C), Clone(J));
                    if(less(r3, best))
                    {
                        best = r3;
                    }

                    C[i] = '1';
                    J[i] = '0';
                    var r4 = Solve(Clone(C), Clone(J));
                    if(less(r4, best))
                    {
                        best = r4;
                    }

                    C[i] = '0';
                    J[i] = '1';
                    var r5 = Solve(Clone(C), Clone(J));
                    if (less(r5, best))
                    {
                        best = r5;
                    }*/



                    /*
                    var d1 = Math.Abs(r1.Item1 - r1.Item2);
                    var d2 = Math.Abs(r2.Item1 - r2.Item2);
                    var d3 = Math.Abs(r3.Item1 - r3.Item2);

                    bool d1Lessd2 = d1 < d2 || (d1 == d2 && r1.Item2 < r2.Item2);
                    bool d2Lessd3 = d2 < d3 || (d2 == d3 && r2.Item2 < r3.Item2);
                    bool d1Lessd3 = d1 < d3 || (d1 == d3 && r1.Item2 < r3.Item2);

                    if (d1Lessd2 && d1Lessd3)
                    {
                        return r1;
                    }
                    else if (d2Lessd3 && !d1Lessd2)
                    {
                        return r2;
                    }
                    else
                    {
                        return r3;
                    }
                }*/
                }
                else
                {
                    break;
                }
            }

            for (int i = 0; i < C.Length; ++i)
            {

                if (C[i] == '?' || J[i] == '?')
                {
                    long bestJ = -1;
                    long bestC = -1;
                    long bestDiff = long.MaxValue;
                    long bestTb = long.MaxValue;

                    int startC = 0;
                    int endC = 9;
                    int startJ = 0;
                    int endJ = 9;
                    if(C[i] != '?')
                    {
                        startC = C[i] - '0';
                        endC = startC;
                    }

                    if(J[i] != '?')
                    {
                        startJ = J[i] - '0';
                        endJ = startJ;
                    }

                    for (int c = startC; c <= endC; ++c)
                    {
                        for (int j = startJ; j <= endJ; ++j)
                        {
                            C[i] = (char)('0' + c);
                            J[i] = (char)('0' + j);
                            String sC = new string(C);
                            String sJ = new string(J);


                            bool eq = true;
                            bool cBigger = false;
                            for(int k = 0; k < sC.Length; ++k)
                            {
                                if(sC[k] == '?' || sJ[k] == '?')
                                {
                                    break;
                                }
                                else if(sC[k] != sJ[k])
                                {
                                    eq = false;
                                    cBigger = sC[k] > sJ[k];
                                    break;
                                }
                            }

                            long curDiff = long.MaxValue;
                            var lJ = 0L;
                            if(eq && (startC != 0 || c == 0) && (startJ != 0 || j == 0) )
                            {
                                var res = Solve(sC.ToCharArray(), sJ.ToCharArray());
                                curDiff = Math.Abs(res.Item1 - res.Item2);
                                /*sJ = sJ.Replace('?', '0');*/
                                /*curDiff = 0;*/
                                lJ =  res.Item2;

                                if (curDiff < bestDiff
                                    || curDiff == bestDiff && lJ < bestTb)
                                {
                                    bestDiff = curDiff;
                                    bestTb = lJ;
                                    bestJ = j;
                                    bestC = c;
                                }
                            }
                            var sC1 = sC.Replace('?', '0');
                            var sJ1 = sJ.Replace('?', '9');
                            var lC = long.Parse(sC1);
                            lJ = long.Parse(sJ1);
                            curDiff = Math.Abs(lC - lJ);
                            if (curDiff < bestDiff
                                || curDiff == bestDiff && lJ < bestTb)
                            {
                                bestDiff = curDiff;
                                bestTb = lJ;
                                bestJ = j;
                                bestC = c;
                            }

                            var sC2 = sC.Replace('?', '9');
                            var sJ2 = sJ.Replace('?', '0');
                            lC = long.Parse(sC2);
                            lJ = long.Parse(sJ2);
                            curDiff = Math.Abs(lC - lJ);
                            if (curDiff < bestDiff
                                || curDiff == bestDiff && lJ < bestTb)
                            {
                                bestDiff = curDiff;
                                bestTb = lJ;
                                bestJ = j;
                                bestC = c;
                            }





                        }
                    }

                    C[i] = (char)('0' + bestC);
                    J[i] = (char)('0' + bestJ); 
                }
            }



            return Tuple.Create(long.Parse(new string(C)), long.Parse(new string(J)));
        }


        static void Main(string[] args)
        {
            var root = @"C:\projects\comp\gcj\p3\";


            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            IEnumerator<string> scanner = input.AsEnumerable<string>().GetEnumerator();
            scanner.MoveNext();
            long numCases = long.Parse(scanner.Current);


            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                string[] P = scanner.Current.Split(new char[] { ' ' } );
                string C= P[0];
                string J = P[1];

                var res = Solve(C.ToCharArray(), J.ToCharArray());

                String cs = res.Item1.ToString();
                String js = res.Item2.ToString();

                while(cs.Length != C.Length)
                {
                    cs = "0" + cs;
                }

                while(js.Length != J.Length)
                {
                    js = "0" + js;
                }

                output.WriteLine("Case #{0}: {1} {2}", nc + 1, cs, js);
                Console.WriteLine("Case #{0}: {1} {2}", nc + 1, cs, js);
            }

            output.Close();

            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }
        }
    }
}
