using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;
using System.Globalization;

namespace CodeJam2012
{
    class Program
    {
        static void Main(string[] args)
        {
            const string name = "A-small-attempt1";
            string path = @".\..\..\..\..\";
            var s = new StreamReader(path + name + ".in");
            var writer = new StreamWriter(path + name + ".out");
            var r = new Reader(s);

            //double[,] mat = new double[2, 4];
            //mat[0, 0] = 1;
            //mat[0, 1] = 0;
            //mat[0, 2] = 3;
            //mat[1, 0] = 0;
            //mat[1, 1] = 1;
            //mat[1, 2] = 2;

            //var res = gauss(mat, 2, 2);


            var testCases = int.Parse(s.ReadLine());

            for (int i = 1; i <= testCases; ++i)
            {
                string result = SolveTestCase(s, r);
                writer.WriteLine("Case #" + i + ": " + result);
                Console.WriteLine("Solved test case " + i + " of " + testCases + "  Result = " + result);

            }

            writer.Close();
            s.Close();

        }


        private static string SolveTestCase(StreamReader s, Reader r)
        {
            var points = r.ReadIntList();
            points.RemoveAt(0);
            int x = 0;

            //double[,] mat = new double[points.Count, points.Count + 2];


            foreach (int point in points)
            {
                x += point;
            }

            int N = points.Count;

            double totPoints = (2 * x);
            double avg = totPoints / N;

            var given = new List<bool>();
            var score = new List<double>();
            for (int i = 0; i < N; ++i)
            {
                score.Add(0);
                given.Add(false);
            }

            int numGiven = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (given[j] == false)
                    {
                        if (points[j] > avg)
                        {
                            given[j] = true;
                            totPoints = totPoints - points[j];
                            numGiven++;
                            score[j] = points[j];
                            avg = totPoints / (N - (float)numGiven);
                            break;
                        }
                    }
                }
            }

            for (int i = 0; i < N; ++i)
            {
                if (given[i] == false)
                {
                    score[i] = avg;
                }
            }


            string ans = string.Empty;
            for (int i = 0; i < N; ++i)
            {
                double frac = (score[i] - points[i]) / (float)x;
                ans += (frac * 100).ToString(CultureInfo.InvariantCulture) + " ";
            }


            return ans;

        }


   

        private class Reader
        {
            StreamReader _reader;
            public Reader(StreamReader streamReader)
            {
                _reader = streamReader;
            }

            public string ReadLine()
            {
                return _reader.ReadLine();
            }

            public string ReadToEnd()
            {
                return _reader.ReadToEnd();
            }

            public int ReadIntLine()
            {
                return int.Parse(_reader.ReadLine());
            }

            public double ReadDoubleLine()
            {
                return double.Parse(_reader.ReadLine());
            }

            public List<int> ReadIntList(char splitChar = ' ')
            {
                return _reader.ReadLine().Split(splitChar).ToList().ConvertAll<int>(delegate(string s) { return int.Parse(s); });
            }

            public StreamReader StreamReader { get { return _reader; } }

            internal List<Tuple<int, int>> ReadIntTupleList(bool firstElementIsCount = true)
            {
                List<int> intList = ReadIntList();
                int index = 0;
                if (firstElementIsCount)
                {
                    index = 1;
                }
                var tupleList = new List<Tuple<int, int>>();
                while (index < intList.Count)
                {
                    tupleList.Add(new Tuple<int, int>(intList[index], intList[index + 1]));
                    index += 2;
                }
                return tupleList;
            }
        }
    }
}
