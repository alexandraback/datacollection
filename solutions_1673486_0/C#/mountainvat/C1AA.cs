using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2012
{
    public class C1AA
    {
        private string mInputFile = @"E:\work\codejam2012\data\1A\A-small-attempt0.in";

        static void Main(string[] args)
        {
            var p = new C1AA();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(mInputFile);
            Console.WriteLine(mInputFile + ".out");
            using (StreamWriter sw = new StreamWriter(mInputFile + ".out"))
            using (StreamReader sr = new StreamReader(mInputFile))
            {
                int testNum = int.Parse(sr.ReadLine());
                for (int i = 0; i < testNum; i++)
                {
                    RunTest(i + 1, sr, sw);
                }
            }
        }

        private int[] ReadIntsFromLine(StreamReader sr)
        {
            string[] splits = sr.ReadLine().Split();
            return splits.Select(x => int.Parse(x)).ToArray();
        }

        private decimal[] ReadDecimalsFromLine(StreamReader sr)
        {
            string[] splits = sr.ReadLine().Split();
            return splits.Select(x => decimal.Parse(x)).ToArray();
        }

        private IEnumerator<string> ReadStrings(StreamReader sr)
        {
            string line = null;
            while ((line = sr.ReadLine()) != null)
            {
                foreach (string split in line.Split())
                    yield return split;
            }
        }

        private void RunTest(int testNum, StreamReader sr, StreamWriter sw)
        {
            var ints = ReadIntsFromLine(sr);
            int A = ints[0];
            int B = ints[1];

            var P = ReadDecimalsFromLine(sr);

            Console.WriteLine(A + " : " + B + " : " + string.Join(",", P.Select(x => x.ToString()).ToArray()));

            sw.WriteLine(string.Format("Case #{0}: {1}", testNum, CalculateExpectedKeyStrokes(A, B, P)));
        }

        private decimal CalculateExpectedKeyStrokes(int A, int B, decimal[] P)
        {
            decimal[] AllRights = new decimal[P.Length+1];
            AllRights[0] = 1;
            for (int i = 0; i < P.Length; i++ )
            {
                AllRights[i + 1] = P[i]*AllRights[i];
            }

                if (A == 1)
                {
                    return Math.Min(B + 2, P[0] * B + (1 - P[0]) * (2 * B + 1));
                }
                //else if (A == 2)
                //{
                //    // press Enter
                //    decimal bestScore = 1 + 1 + B;

                //    // bsp 2
                //    bestScore = Math.Min(bestScore, 2 + B + 1);

                //    // bsp 1
                //    decimal score = (1 + B - (A - 1) + 1)*AllRight(P, A - 1) + (1 + B - (A-1) +1 + B + 1)* (1-AllRight(P, 1));
                //    bestScore = Math.Min(bestScore, score);

                //    // keep typing
                //    decimal allCorrect = AllRight(P, 2);
                //    bestScore = Math.Min(bestScore, allCorrect*(B - A + 1) + (1m - allCorrect)*(B - A + 1 + B + 1));

                //    return bestScore;
                //}
                else
                {
                    // press Enter
                    decimal bestScore = 1 + 1 + B;
                    // keep typing
                    decimal allCorrect = AllRights[A];
                    bestScore = Math.Min(bestScore, allCorrect * (B - A + 1) + (1m - allCorrect) * (B - A + 1 + B + 1));

                    for (int bsp = 1; bsp <= A; bsp++)
                    {
                        decimal allRight = AllRights[A - bsp];
                        decimal score = (bsp + B - (A - bsp) + 1) * allRight + (bsp + B - (A - bsp) + 1 + B + 1) * (1 - allRight);
                        bestScore = Math.Min(bestScore, score);
                    }
                    return bestScore;
                }
        }
    }

}
