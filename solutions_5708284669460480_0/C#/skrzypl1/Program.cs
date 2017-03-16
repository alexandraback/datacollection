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
        int K;
        int L;
        int S;

        double[] prob;
        string target;
        int max;
        Dictionary<char, int> alpha;

        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            string[] tmp = inputStream.ReadLine().Split(' ');

            K = Convert.ToInt32(tmp[0]);
            L = Convert.ToInt32(tmp[1]);
            S = Convert.ToInt32(tmp[2]);

            alpha = new Dictionary<char, int>();

            string t = inputStream.ReadLine();

            for (int i = 0; i < K; i++)
            {
                if (!alpha.ContainsKey(t[i]))
                    alpha.Add(t[i], 0);

                alpha[t[i]]++;
            }

            prob = new double[S + 1];
            target = inputStream.ReadLine();
            max = 0;

            Brute(string.Empty, 1);

            double res = max;

            for (int i = 1; i <= S; i++)
            {
                res -= i * prob[i];
            }

            outputStream.WriteLine("Case #{0}: {1:0.000000000}", testCase, res);
        }

        private void Brute(string str, double p)
        {
            if (str.Length == S)
            {
                int cnt = 0;

                for (int i = 0; i < S; i++)
                {
                    if (str.Substring(i).StartsWith(target))
                        cnt++;
                }

                max = Math.Max(max, cnt);
                prob[cnt] += p;
            }
            else
            {
                foreach (char k in alpha.Keys)
                {
                    Brute(str + k, p * alpha[k] / K);
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
