using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace B
{
    [TestFixture]
    public class Program
    {
        int diff = 1000000000;
        int bestC = 1000;
        int bestJ = 1000;
        string bestCs = String.Empty;
        string bestJs = String.Empty;

        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] temp = inputStream.ReadLine().Split(' ');
            string C = temp[0];
            string J = temp[1];

            diff = 1000000000;
            bestC = 1000;
            bestJ = 1000;

            Solve(C, J);

            outputStream.WriteLine("Case #{0}: {1} {2}", testCase, bestCs, bestJs);
        }

        private void Solve(string C, string J)
        {
            if (C.IndexOf('?') >= 0)
            {
                for (int i = 0; i < 10; i++)
                {
                    Solve(C.Substring(0, C.IndexOf('?')) + i.ToString() + C.Substring(C.IndexOf('?') + 1), J);
                }
            }                
            else if (J.IndexOf('?') >= 0)
            {
                for (int i = 0; i < 10; i++)
                {
                    Solve(C, J.Substring(0, J.IndexOf('?')) + i.ToString() + J.Substring(J.IndexOf('?') + 1));
                }
            }
            else
            {
                int c = Int32.Parse(C);
                int j = Int32.Parse(J);

                if (Math.Abs(c - j) < diff || (Math.Abs(c - j) == diff && j < bestJ))
                {
                    diff = Math.Abs(c - j);
                    bestC = c;
                    bestJ = j;
                    bestCs = C;
                    bestJs = J;
                }
            }
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
