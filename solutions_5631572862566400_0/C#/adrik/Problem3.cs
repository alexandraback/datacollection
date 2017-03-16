using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Utils;

namespace Round1A
{
    public class Problem3 : AbstractProblem<Problem3.Input, int>
    {
        public class Input
        {
            public int N { get; set; }

            public int[] Bff { get; set; }
        }

        private readonly char[] _splitters = { ' ' };

        protected override IEnumerable<Input> ReadTestCases(IEnumerable<string> lines, int testCases)
        {
            var l = lines.ToArray();
            var res = new List<Input>();
            for (var i = 0; i < testCases; i++)
            {
                var n = int.Parse(l[i*2]);
                var bffs = l[i*2+1].Split(_splitters, StringSplitOptions.RemoveEmptyEntries).Select(int.Parse).ToArray();
                res.Add(new Input { N = n, Bff = bffs });
            }
            return res;
        }

        protected override IEnumerable<string> CreateOutput(int output, int index)
        {
            return Enumerable.Repeat($"Case #{index + 1}: {output}", 1);
        }

        protected override int Solve(Input input)
        {
            var n = input.N;
            var bff = input.Bff.Select(x=>x-1).ToArray();

            var pairs = new List<int>();
            var incycle = new bool[n];

            var check = new bool[n];

            var maxcycle = 0;
            for (var i = 0; i < n; i++)
            {
                if (check[i]) continue;
                var kids = Enumerable.Repeat(-1, n).ToArray();
                var j = i;
                var k = 0;
                var isnew = true;
                while (kids[j] < 0)
                {
                    if (check[j])
                    {
                        isnew = false;
                        break;
                    }
                    check[j] = true;
                    kids[j] = k;
                    j = bff[j];
                    k++;
                }

                if (isnew)
                {
                    var len = k - kids[j];
                    if (len == 2)
                    {
                        pairs.Add(j);
                    }
                    maxcycle = Math.Max(len, maxcycle);
                    while (!incycle[j])
                    {
                        incycle[j] = true;
                        j = bff[j];
                    }
                }
            }

            var maxcycleman = new int[n];
            for (var i = 0; i < n; i++)
            {
                if (incycle[i]) continue;
                var j = i;
                var k = 0;
                while (!incycle[j])
                {
                    k++;
                    j = bff[j];
                }
                maxcycleman[j] = Math.Max(maxcycleman[j], k);
            }

            var withpairs = 0;

            foreach (var first in pairs)
            {
                withpairs += maxcycleman[first] + maxcycleman[bff[first]] + 2;
            }

            return Math.Max(withpairs, maxcycle);
        }
    }

}
