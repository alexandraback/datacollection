using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace GoogleCodeJamSolutions
{
    class OminousOmino
    {
        private const string Gabriel = "GABRIEL";
        private const string Richard = "RICHARD";

        public void Solve(string fileName)
        {
            var data = LoadData(fileName);
            var result = new string[data.Count];

            for (int i = 0; i < data.Count; ++i)
            {
                result[i] = SolveInternally(data[i]);
                Console.WriteLine("Test# {0}: {1}", i, result[i]);
            }

            WriteSolution(result, fileName);
        }

        private string SolveInternally(int[] data)
        {
            var x = data[0];
            var r = data[1];
            var c = data[2];

            if (x >= 8)
                return Richard;

            if ((r * c) % x != 0)
                return Richard;

            if (x == 1 || x == 2)
                return Gabriel;

            var min = Math.Min(r, c);
            var max = Math.Max(r, c);

            if (x > max)
                return Richard;

            if (x <= min)
                return Gabriel;

            if (x >= 2 * min + 1)
                return Richard;

            if (x == 3)
                return Gabriel;

            if (x > r * c / 3)
                return Richard;

            if(max != min && x < 2*min)
                return Gabriel;

            var leftBrics = (min - 1) * (x - min);
            var length = x - min + 1;
            for(int l = 1; l <= leftBrics; ++l)
            {
                var goodForRichard = true;
                for(int k = 0; k < max - length; ++k)
                {
                    if ((l + k * min) % x == 0 && r * c - x - l - k * min > 0)
                    {
                        goodForRichard = false;
                        break;
                    }
                }

                if (goodForRichard)
                    return Richard;
            }

            return Gabriel;
        }

        private List<int[]> LoadData(string fileName)
        {
            var res = new List<int[]>();
            using (var f = new StreamReader(fileName))
            {
                var testCases = int.Parse(f.ReadLine());
                for (int i = 0; i < testCases; ++i)
                {
                    var curLine = f.ReadLine().Split(' ');
                    res.Add(curLine.Select(x => int.Parse(x)).ToArray());
                }
            }

            return res;
        }

        private void WriteSolution(string[] result, string fileName)
        {
            fileName = fileName.Replace(".in", ".out");
            using (var o = new StreamWriter(fileName))
            {
                for (int i = 0; i < result.Length; ++i)
                {
                    if (i < result.Length - 1)
                        o.WriteLine("Case #{0}: {1}", i + 1, result[i]);
                    else
                        o.Write("Case #{0}: {1}", i + 1, result[i]);
                }

            }
        }
    }
}
