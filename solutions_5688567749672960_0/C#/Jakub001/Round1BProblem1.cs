using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeAlgorithms.Problems
{
    class Round1BProblem1 : IProblem
    {
        public void Solve(TextReader input, TextWriter output)
        {
            int tests = int.Parse(input.ReadLine());

            for (int q = 0; q < tests; q++)
            {
                Console.WriteLine(q);
                int n = int.Parse(input.ReadLine());

                int[] h = new int[n + 1];
                for (int i = 0; i <= n; i++)
                {
                    h[i] = int.MaxValue;
                }

                h[0] = 0;
                for (int i = 1; i <= n; i++)
                {
                    int c = h[i - 1] + 1;
                    if (h[i] > c)
                        h[i] = c;

                    int rv = int.Parse(new string(i.ToString().Reverse().ToArray()));
                    if (rv <= n)
                    {
                        c++;
                        if (h[rv] > c)
                        {
                            h[rv] = c;
                        }
                    }

                }

                output.WriteLine("Case #{0}: {1}", q + 1, h[n]);
                Console.WriteLine("Case #{0}: {1}", q + 1, h[n]);
            }
        }

        public void SolveSlow(TextReader input, TextWriter output)
        {
            int tests = int.Parse(input.ReadLine());

            for (int q = 0; q < tests; q++)
            {
                Console.WriteLine(q);
                int n = int.Parse(input.ReadLine());

                int[] h = new int[n + 1];
                for (int i = 0; i <= n; i++)
                {
                    h[i] = int.MaxValue;
                }

                int x = 0;
                var s = new Stack<Tuple<int, int>>();
                s.Push(new Tuple<int, int>(1, 1));

                while (s.Count > 0)
                {
                    var data = s.Pop();

                    if (data.Item1 > n || data.Item2 >= h[data.Item1])
                        continue;

                    h[data.Item1] = data.Item2;

                    var nv = data.Item1 + 1;
                    var cost = data.Item2 + 1;
                    if (nv <= n && cost <= h[nv])
                        s.Push(new Tuple<int, int>(nv, cost));

                    int rv = int.Parse(new string(data.Item1.ToString().Reverse().ToArray()));
                    if (rv <= n && cost <= h[rv])
                        s.Push(new Tuple<int, int>(rv, cost));
                }

                output.WriteLine("Case #{0}: {1}", q + 1, h[n]);
            }
        }

        #region Support

        public IEnumerable<Action<TextReader, TextWriter>> Solvers
        {
            get
            {
                yield return Solve;
            }
        }

        public IEnumerable<KeyValuePair<string, string>> TestData
        {
            get
            {
                yield return new KeyValuePair<string, string>(@"4
11000
19
23
1999", @"Case #1: 1337
Case #2: 19
Case #3: 15
Case #4: 328");
            }
        }

       
        static void Main(string[] args)
        {
            var p = new Round1BProblem1();

            int testNumber = 1;
            string directory = @"c:\Downloads";
            string fileName = "A-small-attempt" + testNumber;

            string inputFile = Path.Combine(directory, fileName) + ".in";
            string outputFile = Path.Combine(directory, fileName) + ".out";

            using (var input = new StreamReader(inputFile))
            using (var output = new StreamWriter(outputFile))
            {
                p.Solve(input, output);
            }
        }
       

        #endregion
    }
}

