using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace B
{
    public class Program
    {
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            int N = Convert.ToInt32(tmp[0]);
            int X = Convert.ToInt32(tmp[1]);
            int Y = Convert.ToInt32(tmp[2]);

            int sum = 0;
            int next = 1;
            int levels = 0;

            while (sum + next <= N)
            {
                sum += next;
                next += 4;
                levels++;
            }

            double result = 0;

            if (X + Y <= (levels - 1) * 2)
            {
                result = 1;
            }
            else
            {
                N -= sum;
                result = solve(0, 0, N, levels * 2, Y + 1, 1);
            }

            outputStream.WriteLine("Case #{0}: {1:0.0000000}", testCase, result);
        }

        private double solve(int normal, int other, int N, int otherMax, int normalMax, double prob)
        {
            if (normal == normalMax || other == otherMax)
                return prob;

            double res = solve(normal + 1, other, N, otherMax, normalMax, prob * 0.5);

            if (other + 1 + normalMax <= N)
                res += solve(normal, other + 1, N, otherMax, normalMax, prob * 0.5);

            return res;
        }

        #region Tests

        [TestCase]
        public void TestSmallInput()
        {
            TestInput("..\\..\\Input\\B-small.in", "..\\..\\Output\\B-small.out");
        }

        [TestCase]
        public void TestLargeInput()
        {
            TestInput("..\\..\\Input\\B-large.in", "..\\..\\Output\\B-large.out");
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
