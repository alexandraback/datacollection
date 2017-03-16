using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Text;
using System.Threading;

namespace C
{
    public class Program
    {
        public void TestCase(int testCase, TextReader inputStream, TextWriter outputStream)
        {
            int N = Convert.ToInt32(inputStream.ReadLine());

            int[] d = new int[N];
            int[] n = new int[N];
            int[] w = new int[N];
            int[] e = new int[N];
            int[] s = new int[N];
            int[] delta_d = new int[N];
            int[] delta_p = new int[N];
            int[] delta_s = new int[N];

            List<Pair> wall = new List<Pair>();

            for (int i = 0; i < N; i++)
            {
                string[] tmp = inputStream.ReadLine().Split(' ');

                d[i] = Convert.ToInt32(tmp[0]);
                n[i] = Convert.ToInt32(tmp[1]);
                w[i] = Convert.ToInt32(tmp[2]) + 200;
                e[i] = Convert.ToInt32(tmp[3]) + 200;
                s[i] = Convert.ToInt32(tmp[4]);
                delta_d[i] = Convert.ToInt32(tmp[5]);
                delta_p[i] = Convert.ToInt32(tmp[6]);
                delta_s[i] = Convert.ToInt32(tmp[7]);
            }

            int res = 0;

            while (true)
            {
                bool found = false;

                int day = int.MaxValue;
                for (int i = 0; i < N; i++)
                {
                    if (n[i] > 0 && d[i] < day)
                    {
                        day = d[i];
                        found = true;
                    }
                }

                if (!found)
                    break;

                List<Pair> newWall = new List<Pair>(wall);

                for (int i = 0; i < N; i++)
                {
                    bool breach = false;
                    if (n[i] > 0 && d[i] == day)
                    {
                        if (!Check(wall, w[i], e[i], s[i]))
                        {
                            breach = true;
                            newWall.Add(new Pair(w[i], e[i], s[i]));
                        }

                        n[i]--;
                        d[i] += delta_d[i];
                        w[i] += delta_p[i];
                        e[i] += delta_p[i];
                        s[i] += delta_s[i];
                    }

                    if (breach)
                        res++;
                }

                wall = newWall;
                wall.Sort();
            }

            outputStream.WriteLine("Case #{0}: {1}", testCase, res);
        }

        public bool Check(List<Pair> wall, int w, int e, int s)
        {
            for (int i = 0; i < wall.Count; i++)
            {
                if (wall[i].Strength < s)
                    continue;

                if (wall[i].W > w)
                    return false;

                if (wall[i].E > w)
                    w = wall[i].E;
            }

            return w >= e;
        }

        public class Pair : IComparable<Pair>
        {
            public int W;
            public int E;
            public int Strength;

            public Pair(int w, int e, int strength)
            {
                this.W = w;
                this.E = e;
                this.Strength = strength;
            }

            public int CompareTo(Pair other)
            {
                int c = this.W.CompareTo(other.W);

                if (c == 0)
                    return other.E.CompareTo(this.E);

                return c;
            }
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
