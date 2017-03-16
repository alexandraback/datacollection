using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

namespace GCJ
{
    class Program
    {
        enum Val
        {
            o,
            i,
            j,
            k,
            mo,
            mi,
            mj,
            mk,
            NumVals
        };

        static Val FromChar(char c)
        {
            if (c == 'i') return Val.i;
            if (c == 'j') return Val.j;
            if (c == 'k') return Val.k;
            throw new Exception("assert");
        }

        static Val[,] mult = new Val[(int)Val.NumVals, (int)Val.NumVals];

        static void Main(string[] args)
        {
            mult[(int)Val.o, (int)Val.i] = Val.i;
            mult[(int)Val.o, (int)Val.j] = Val.j;
            mult[(int)Val.o, (int)Val.k] = Val.k;
            mult[(int)Val.o, (int)Val.o] = Val.o;

            mult[(int)Val.i, (int)Val.o] = Val.i;
            mult[(int)Val.j, (int)Val.o] = Val.j;
            mult[(int)Val.k, (int)Val.o] = Val.k;
            mult[(int)Val.o, (int)Val.o] = Val.o;

            mult[(int)Val.i, (int)Val.i] = Val.mo;
            mult[(int)Val.i, (int)Val.j] = Val.k;
            mult[(int)Val.i, (int)Val.k] = Val.mj;
            mult[(int)Val.j, (int)Val.i] = Val.mk;
            mult[(int)Val.j, (int)Val.j] = Val.mo;
            mult[(int)Val.j, (int)Val.k] = Val.i;
            mult[(int)Val.k, (int)Val.i] = Val.j;
            mult[(int)Val.k, (int)Val.j] = Val.mi;
            mult[(int)Val.k, (int)Val.k] = Val.mo;

            for (int i = 0; i < 8; ++i)
            {
                for (int j = 0; j < 8; ++j)
                {
                    if (i < 4 && j < 4)
                    {
                        continue;
                    }
                    int iIndex = i < 4 ? i : i - 4;
                    int jIndex = j < 4 ? j : j - 4;

                    int final = (int)mult[iIndex, jIndex];

                    if (i < 4 != j < 4)
                    {
                        final = (final + 4) % 8;
                    }

                    mult[i, j] = (Val)final;
                }
            }


            var root = @"D:\gcj\p3\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");

            long numCases = Int32.Parse(input[0]);
            int ln = 1;
            for (int nc = 0; nc < numCases; ++nc)
            {
                long x = long.Parse(input[ln++].Split(' ')[1]);
                string str = input[ln++];
                StringBuilder b = new StringBuilder();

                long xToLeave = Math.Min(15, x);
                if (x > xToLeave)
                {
                    xToLeave += (x - 15) % 4;
                }

                for (int i = 0; i < xToLeave; ++i)
                {
                    b.Append(str);
                }

                string fStr = b.ToString();

                bool encI = false;
                bool[] kLocl = new bool[fStr.Length];


               
                Val cur = Val.o;

                for (int i = fStr.Length - 1; i >= 0; --i )
                {
                    cur = mult[(int)FromChar(fStr[i]), (int)cur];
                    if (cur == Val.k)
                    {
                        kLocl[i] = true;
                    }
                }
                bool good = false;
                cur = Val.o;
                for (int i = 0; i < fStr.Length - 1; ++i)
                {
                    cur = mult[(int)cur, (int)FromChar(fStr[i])];
                    if (cur == Val.i)
                    {
                        encI = true;
                    }
                    else if (cur == Val.k && encI)
                    {
                        if (kLocl[i + 1])
                        {
                            good = true;
                            break;
                        }
                    }
                }



                output.WriteLine("Case #{0}: {1}", nc + 1, good ? "YES" : "NO");
                Console.WriteLine("Case #{0}: {1}", nc + 1, good ? "YES" : "NO");
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
