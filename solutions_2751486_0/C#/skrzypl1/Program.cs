using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace A
{
    public class Program
    {
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            string L = tmp[0];
            int n = Convert.ToInt32(tmp[1]);

            long res = 0;

            for (int i = 0; i < L.Length; i++)
            {
                for (int j = i; j < L.Length; j++)
                {
                    int cnt = 0;
                    for (int k = i; k <= j; k++)
                    {
                        if (L[k] != 'a' && L[k] != 'e' && L[k] != 'i' && L[k] != 'o' && L[k] != 'u')
                        {
                            cnt++;
                            if (cnt == n)
                                break;
                        }
                        else
                            cnt = 0;
                    }
                    if (cnt == n)
                        res++;
                }
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
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
