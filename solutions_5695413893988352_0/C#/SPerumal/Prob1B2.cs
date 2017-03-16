using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;

namespace CodeJam
{
    class Prob1B2
    {
        const int len = 3;
        List<Solution> solutions;
        int i;
        internal void Run()
        {
            var lines = File.ReadAllLines("B-small-attempt4.in");

            var n = int.Parse(lines[0]);

            i = 1;
            using (var sw = File.CreateText("B.out"))
                foreach (var line in lines.Skip(1))
                {
                    var parts = line.Split(' ');
                    var left = parts[0].Select(c => c == '?' ? -1 : int.Parse(c.ToString())).ToList();
                    var right = parts[1].Select(c => c == '?' ? -1 : int.Parse(c.ToString())).ToList();

                    var leftlen = left.Count;
                    var rightlen = right.Count;

                    for (int j = left.Count; j < len; j++)
                        left.Insert(0, 0);

                    for (int j = right.Count; j < len; j++)
                        right.Insert(0, 0);

                    solutions = new List<Solution>();
                    Process(left, right, 0);

                    var soln = solutions.OrderBy(s => s.Diff).ThenBy(s => s.Left).ThenBy(s => s.Right).First();

                    var check = solutions.GroupBy(s => s.Diff).OrderBy(g => g.Key).First();
                    //if (check.Count() > 10) Debugger.Break();

                    sw.WriteLine("Case #{0}: {1} {2}", i, soln.Left.ToString(PadString(leftlen)), soln.Right.ToString(PadString(rightlen)), soln.Diff);

                    i++;
                }
        }

        private string PadString(int rightlen)
        {
            var sb = new StringBuilder();
            for (int k = 0; k < rightlen; k++)
                sb.Append("0");

            return sb.ToString();
        }

        private void Process(List<int> left, List<int> right, int p)
        {
            if (p == len)
            {
                var sol = new Solution(left, right);
                solutions.Add(sol);
                return;
            }

            var l = left[p];
            var r = right[p];
            if (l == -1 && r == -1)
            {
                //foreach (int lo in new[] { 0, 1, 9 })
                //    foreach (int ro in new[] { 0, 1, 9 })
                foreach (int lo in new[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 })
                    foreach (int ro in new[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 })
                    {
                        left[p] = lo; right[p] = ro; Process(left, right, p + 1);
                    }

                left[p] = -1; right[p] = -1;
            }
            else if (l == -1)
            {
                //if (r > 0) { left[p] = r - 1; Process(left, right, p + 1); }
                //else { left[p] = 9; Process(left, right, p + 1); }
                //left[p] = r; Process(left, right, p + 1);
                //if (r < 9) { left[p] = r + 1; Process(left, right, p + 1); }
                //else { left[p] = 0; Process(left, right, p + 1); }
                foreach (int lo in new[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 })
                {
                    left[p] = lo; Process(left, right, p + 1);
                }

                left[p] = -1;
            }
            else if (r == -1)
            {
                //if (l > 0) { right[p] = l - 1; Process(left, right, p + 1); }
                //else { right[p] = 9; Process(left, right, p + 1); }
                //right[p] = l; Process(left, right, p + 1);
                //if (l < 9) { right[p] = l + 1; Process(left, right, p + 1); }
                //else { right[p] = 0; Process(left, right, p + 1); }

                foreach (int ro in new[] { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 })
                {
                    right[p] = ro; Process(left, right, p + 1);
                }

                right[p] = -1;
            }
            else Process(left, right, p + 1);
        }

        class Solution
        {
            public BigInteger Left, Right, Diff;

            public Solution(List<int> left, List<int> right)
            {
                Left = new BigInteger();
                Right = new BigInteger();
                for (int m = 0; m < len; m++)
                {
                    Left = Left * 10 + left[m];
                    Right = Right * 10 + right[m];
                }
                Diff = BigInteger.Abs(Left - Right);
            }
        }

    }

}
