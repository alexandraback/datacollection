using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace C
{
    [TestFixture]
    public class Program
    {
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            int C = Convert.ToInt32(tmp[0]);
            int D = Convert.ToInt32(tmp[1]);
            int V = Convert.ToInt32(tmp[2]);

            List<int> den = new List<int>();

            tmp = inputStream.ReadLine().Split(' ');

            for (int i = 0; i < D; i++)
            {
                den.Add(Convert.ToInt32(tmp[i]));
            }

            bool[] used = new bool[V + 1];
            bool[] nused = new bool[V + 1];

            for (int i = 0; i < den.Count; i++)
            {
                nused = new bool[V + 1];

                for (int j = 0; j <= V; j++)
                {
                    nused[j] = used[j];
                }

                nused[den[i]] = true;

                for (int j = 1; j <= V; j++)
                {
                    if (used[j] && j + den[i] <= V)
                        nused[j + den[i]] = true;
                }

                used = nused;
            }

            int res = 0;

            for (int i = 1; i <= V; i++)
            {
                if (!used[i])
                {
                    res++;

                    nused = new bool[V + 1];

                    for (int j = 0; j <= V; j++)
                    {
                        nused[j] = used[j];
                    }

                    nused[i] = true;

                    for (int j = 1; j <= V; j++)
                    {
                        if (used[j] && j + i <= V)
                            nused[j + i] = true;
                    }

                    used = nused;
                }
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
        }

        #region Tests

        [TestCase]
        public void TestSmallInput()
        {
            TestInput("..\\..\\Input\\C-small.in", "..\\..\\Output\\C-small.out");
        }

        [TestCase]
        public void TestLargeInput()
        {
            TestInput("..\\..\\Input\\C-large.in", "..\\..\\Output\\C-large.out");
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
