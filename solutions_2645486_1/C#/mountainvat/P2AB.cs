using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace codejam2013
{
    public class P2AB
    {
        private const string mInputFile = @"E:\work\codejam2013\data\B-large.in";
        private StreamWriter mOutput;
        private StreamReader mInput;

        static void Main(string[] args)
        {
            var p = new P2AB();
            p.Run();
            Console.WriteLine("Done");
            Console.ReadLine();
        }

        public void Run()
        {
            Console.WriteLine(mInputFile);
            Console.WriteLine(mInputFile + ".out");
            using (mOutput = new StreamWriter(mInputFile + ".out"))
            using (mInput = new StreamReader(mInputFile))
            {
                int testNum = int.Parse(mInput.ReadLine());
                for (int i = 0; i < testNum; i++)
                {
                    WriteResult(i + 1, RunTest());
                }
            }
        }

        private string RunTest()
        {
            var ints = ReadIntsFromLine();
            var E = ints[0];
            var R = ints[1];
            var N = ints[2];

            var V = ReadIntsFromLine();

            decimal gain = 0;
            int e = E;
            for (int i = 0; i < N; i++)
            {
                int save = 0;
                int maxV = 0;
                int maxJ = 0;
                int maxSpend = int.MaxValue;

                bool foundMax = false;
                for (int j = i + 1; j < N; j++)
                {
                    if (V[i] < V[j])
                    {
                        // if can reach j
                        var g = e + (j - i)*R;
                        if (g >= E)
                        {
                            if (g - E <= maxSpend)
                            {
                                maxSpend = g - E;
                                foundMax = true;
                            }

                        }
                    }
                }
                if (!foundMax)
                    maxSpend = e;

                maxSpend = Math.Min(maxSpend, e);
                //Console.WriteLine(string.Format("spending {0}, gain: {1}", maxSpend, maxSpend * V[i]));
                e = e - maxSpend;
                e = Math.Min(E, e + R);
                gain += maxSpend*V[i];
            }

            return "" + gain;
        }

        #region Utilities Methods

        private int[] ReadIntsFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => int.Parse(x)).ToArray();
        }

        private double[] ReadDoublesFromLine()
        {
            string[] splits = mInput.ReadLine().Split();
            return splits.Select(x => double.Parse(x)).ToArray();
        }

        private IEnumerator<string> ReadStrings()
        {
            string line = null;
            while ((line = mInput.ReadLine()) != null)
            {
                foreach (string split in line.Split())
                    yield return split;
            }
        }

        private void WriteResult(int testNum, string result)
        {
            mOutput.WriteLine(string.Format("Case #{0}: {1}", testNum, result));
        }

        #endregion
    }
}
