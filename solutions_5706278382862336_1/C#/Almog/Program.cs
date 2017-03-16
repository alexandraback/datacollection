using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;
using System.IO;

namespace _1_PartElf
{
    class Program
    {
        static ulong GCD(ulong a, ulong b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }

        static void Main(string[] args)
        {
            FileStream fsInput = new FileStream(args[0], FileMode.Open, FileAccess.Read);
            StreamReader reader = new StreamReader(fsInput);
            FileStream fsOutput = new FileStream(args[0] + ".out", FileMode.Create, FileAccess.Write);
            StreamWriter writer = new StreamWriter(fsOutput);


            string sCases = reader.ReadLine();

            int iCases = int.Parse(sCases);

            for (int i = 0; i < iCases; i++)
            {
                string[] line = reader.ReadLine().Split('/');
                ulong P = ulong.Parse(line[0]);
                ulong Q = ulong.Parse(line[1]);

                ulong gcd = GCD(P, Q);
                P /= gcd;
                Q /= gcd;

                if ((Q & (Q - 1)) != 0)
                {
                    writer.WriteLine("Case #{0}: impossible", i + 1);
                    continue;
                }

                //ulong D = 1;
                int j = 0;
                for (j = 1; j < 40; j++)
                {
                    P *= 2;
                    if (P >= Q)
                    {
                        break;
                    }
                }

                writer.WriteLine("Case #{0}: {1}", i + 1, j);
            }

            reader.Close();
            writer.Close();

        }
    }
}
