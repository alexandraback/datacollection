using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2014_PreRound
{
    class A
    {
        public A()
        {
            using (StreamWriter sw = new StreamWriter(@"D:\output.txt"))
            {
                //foreach (var r in GetCases().AsParallel().Select(t => Tuple.Create(t.Item1, Solve(t))).OrderBy(t => t.Item1))
                foreach (var r in GetCases().Select(t => Tuple.Create(t.Item1, Solve(t))).OrderBy(t => t.Item1))
                {
                    sw.WriteLine("Case #" + r.Item1 + ": " + r.Item2);
                    Console.WriteLine("Case #" + r.Item1 + ": " + r.Item2);
                }
            }
        }

        IEnumerable<Tuple<int, string[]>> GetCases()
        {
            using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\A-small-attempt0.in"))
            //using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\A-large.in"))
            //using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\A-small-attempt1.in"))
            //using (StreamReader sr = new StreamReader(@"input_A.txt"))
            {
                int caseCount = int.Parse(sr.ReadLine());

                for (int i = 1; i <= caseCount; i++)
                {
                    int n = int.Parse(sr.ReadLine());
                    string[] parts = new string[n];
                    for (int j = 0; j < n; j++)
                    {
                        parts[j] = sr.ReadLine();
                    }

                    yield return Tuple.Create(i, parts);
                }
            }
        }

        public string Solve(Tuple<int, string[]> input)
        {
            string common = null;
            int[,] charCount = new int[input.Item2.Length,100];

            int idx = 0; ;
            foreach (string s in input.Item2)
            {
                char prev = s[0];
                string sc = "" + prev;
                charCount[idx,0]++;

                for (int i = 1; i < s.Length; i++ )
                {
                    if (s[i] == prev)
                    {
                    }
                    else
                    {
                        sc += s[i];
                        prev = s[i];
                    }

                    charCount[idx, sc.Length - 1]++;
                }

                if (common == null)
                {
                    common = sc;
                }
                else
                {
                    if (common != sc)
                    {
                        return "Fegla Won";
                    }
                }

                idx++;
            }

            int sum_moves = 0;
            for (int i = 0; i < common.Length; i++)
            {
                var list = Enumerable.Range(0, input.Item2.Length).Select(j => charCount[j, i]).OrderBy(x => x);

                int median = list.ElementAt(list.Count()/2);

                sum_moves += list.Sum(x => Math.Abs(x - median));
            }


            return "" + sum_moves;
        }

    }
}
