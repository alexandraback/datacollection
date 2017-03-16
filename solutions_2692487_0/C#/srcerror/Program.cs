using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace BaseApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Work\Current\CodeJam\2\A-small-attempt0.in";
            string output = @"d:\Work\Current\CodeJam\2\A-small-attempt0.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task1(sin);
                        sout.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
        }

        private static string Task1(StreamReader sin)
        {
            var s = sin.ReadLine().Split(' ');
            var A = BigInteger.Parse(s[0]);
            var N = int.Parse(s[1]);
            var sn = sin.ReadLine().Split(' ').Select(t => BigInteger.Parse(t)).OrderBy(t => t).ToList();
            if (sn.Count != N) Console.WriteLine("Error - wrong number of motes");

            int count = 0;
            int left = N;
            int removeSolution = N;
            bool foundRemove = false;

            for (int i = 0; i < sn.Count; i++)
            {
                var m = sn[i];
                if (A > m)
                {
                    A += m;
                    left--;
                    continue;
                }
                else
                {
                    int cnt = 0;
                    while (true)
                    {
                        A += A - 1;
                        cnt++;
                        if (cnt > left)
                        {
                            var newSolution = count + left;
                            if (foundRemove && removeSolution < newSolution)
                                return removeSolution.ToString();
                            return newSolution.ToString();
                        } 
                        
                        if (A > m)
                        {
                            // after adding next one can eat
                            A += m;
                            break;
                        }
                    }
                    if (cnt > 1 && !foundRemove)
                    {
                        removeSolution = left;
                        foundRemove = true;
                    }
                    count += cnt;
                    left--;
                }
            }
            var solution = count;
            if (foundRemove && removeSolution < solution)
                return removeSolution.ToString();
            return solution.ToString();
        }
    }
}
