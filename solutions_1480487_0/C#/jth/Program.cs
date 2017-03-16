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
                using (StreamReader reader = new StreamReader(File.OpenRead(@"D:\input.txt")))
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

            var row = reader.ReadLine().Split(' ');
            var N = int.Parse(row[0]);
            var pointValues = new List<double[]>();
            var sum = 0.0;
            for (var i = 0; i < N; i++)
            {
                var val = double.Parse(row[i + 1]);
                pointValues.Add(new double[3] { val, 0, 0 });
                sum += val;
            }


            while (true)
            {
                foreach (var p in pointValues)
                {
                    if (p[1] != 0 && p[2] != 0)
                    {
                        p[1] = 0;
                        p[2] = 0;
                    }
                }

                var _sum = pointValues.Where(x => x[1] == 0).Sum(x => x[0]);
                var _count = pointValues.Count(x => x[1] == 0);

                if (_count == 0)
                    break;

                var _min = (_sum + sum) / _count;

                var flag = false;
                for (var i = 0; i < pointValues.Count; i++)
                {
                    if (pointValues[i][1] == 0.0)
                    {
                        if (pointValues[i][0] >= _min)
                        {
                            pointValues[i][1] = 1;
                            pointValues[i][2] = 0.0;
                            flag = true;
                        }
                        else
                        {
                            pointValues[i][1] = 1;
                            pointValues[i][2] = (_min - pointValues[i][0]) / sum;
                        }
                    }
                }

                if (!flag)
                    break;
            }

            var results = pointValues.Select(x => x[2] * 100).ToList();
            writer.WriteLine("Case #{0}: {1}", caseId, string.Join(" ", results));
        }
    }
}
