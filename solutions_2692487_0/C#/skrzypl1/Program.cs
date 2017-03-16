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

            long A = Convert.ToInt64(tmp[0]);
            int N = Convert.ToInt32(tmp[1]);

            int[] motes = new int[N];

            tmp = inputStream.ReadLine().Split(' ');

            for (int i = 0; i < N; i++)
            {
                motes[i] = Convert.ToInt32(tmp[i]);
            }

            Array.Sort<int>(motes);

            int result = N;
            int added = 0;

            if (A > 1)
            {
                for (int i = 0; i < N; i++)
                {
                    if (motes[i] < A)
                        A += motes[i];
                    else
                    {
                        if (added + N - i < result)
                            result = added + N - i;

                        while (A <= motes[i])
                        {
                            A += A - 1;
                            added++;
                        }

                        A += motes[i];
                    }
                }

                if (added < result)
                    result = added;
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, result);
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
