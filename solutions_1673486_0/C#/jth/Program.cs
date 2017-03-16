using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            using (StreamWriter writer = new StreamWriter(@"D:\output.txt"))
            {
                using (StreamReader reader = new StreamReader(File.OpenRead(@"D:\A-small-attempt2.in")))
                {
                    int cases = int.Parse(reader.ReadLine());
                    for (int i = 0; i < cases; i++)
                    {
                        Process(i, reader, writer);
                    }
                }
            }
        }

        private static void Process(int num, StreamReader reader, StreamWriter writer)
        {
            int caseId = num + 1;
            var row1 = reader.ReadLine().Split(' ');
            int A = int.Parse(row1[0]);
            int B = int.Parse(row1[1]);
            var row2 = reader.ReadLine().Split(' ');
            var pList = new List<double>();
            foreach (var p in row2)
            {
                pList.Add(double.Parse(p));
            }
            double[] rightPList = new double[A];
            rightPList[0] = pList[0];
            for (int i = 1; i < A; i++)
            {
                rightPList[i] = rightPList[i - 1] * pList[i];
            }

            double justEnter = B + 2;
            var min = justEnter;
            for (int i = 0; i < A + 1; i++)
            {
                if (i == A)
                {
                    min = Math.Min(min, A + B + 1);
                }
                else
                {
                    // back i times
                    var newStart = A - i;
                    var correctP = rightPList[newStart - 1];
                    var expected = correctP * (2 * i + B - A + 1) + (1 - correctP) * (2 * i + 2 * B - A + 2);
                    min = Math.Min(min, expected);
                }
            }

            writer.WriteLine("Case #{0}: {1:0.000000}", caseId, min);
        }
    }
}
