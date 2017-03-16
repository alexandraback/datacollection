using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace A
{
    [TestFixture]
    public class Program
    {
        static int INF = 1000000000;

        int R;
        int C;
        int W;

        int[] dp1;
        int[] dp2;

        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            R = Convert.ToInt32(tmp[0]);
            C = Convert.ToInt32(tmp[1]);
            W = Convert.ToInt32(tmp[2]);

            dp1 = new int[C + 1];
            dp2 = new int[C + 1];

            for (int i = 0; i <= C; i++)
            {
                Solve1(i);
                Solve2(i);
            }

            int res = (R - 1) * dp1[C] + dp2[C];

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
        }

        private int Solve1(int x)
        {
            int res = 0;

            if (x < W)
                res = 0;
            else if (x < 2 * W)
                res = 1;
            else
            {
                for (int i = 0; i < x; i++)
                {
                    res = Math.Max(res, dp1[i] + dp1[x - i - 1] + 1);
                }
            }

            dp1[x] = res;
            return res;
        }

        private int Solve2(int x)
        {
            int res = INF;

            if (x < W)
                res = INF;
            else if (x == W)
                res = W;
            else if (x < 2 * W)
                res = W + 1;
            else
            {
                for (int i = 0; i < x; i++)
                {
                    int tmp = Math.Min(dp1[i] + dp2[x - i - 1] + 1, dp2[i] + dp1[x - i - 1] + 1);
                    res = Math.Min(res, tmp);
                }
            }

            dp2[x] = res;
            return res;
        }        

        #region Tests

        [TestCase]
        public void TestSmallInput()
        {
            TestInput("..\\..\\Input\\A-small.in", "..\\..\\Output\\A-small.out");
        }

        [TestCase]
        public void TestLargeInput()
        {
            TestInput("..\\..\\Input\\A-large.in", "..\\..\\Output\\A-large.out");
        }

        private void TestInput(string inputFile, string outputFile)
        {
            Thread.CurrentThread.CurrentCulture = new CultureInfo("");

            FileInfo input = new FileInfo(inputFile);
            TextReader inputStream = input.OpenText();

            FileInfo output = new FileInfo(outputFile);
            TextWriter outputStream = output.CreateText();

            int testCase = Convert.ToInt32(inputStream.ReadLine());

            for (int i = 1; i <= testCase; i++)
            {
                TestCase(i, inputStream, outputStream);
            }

            outputStream.Close();
            inputStream.Close();
        }

        #endregion
    }
}
