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
                foreach (var r in GetCases().AsParallel().Select(t => Tuple.Create(t.CaseNumber, Solve(t))).OrderBy(t => t.Item1))
                //foreach (var r in GetCases().Select(t => Tuple.Create(t.CaseNumber, Solve(t))).OrderBy(t => t.Item1))
                {
                    Console.WriteLine("Case #" + r.Item1 + ": " + r.Item2);
                    sw.WriteLine("Case #" + r.Item1 + ": " + r.Item2);
                }
            }
        }

        IEnumerable<Input> GetCases()
        {
            //using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\A-small-attempt0 (2).in"))
            using (StreamReader sr = new StreamReader(@"C:\Users\MarvinMiao\Downloads\A-large (2).in"))
            //using (StreamReader sr = new StreamReader(@"input_A.txt"))
            {
                int caseCount = int.Parse(sr.ReadLine());

                for (int i = 1; i <= caseCount; i++)
                {
                    var parts = sr.ReadLine().Split('/');

                    yield return new Input()
                    {
                        CaseNumber = i,
                        P = long.Parse(parts[0]),
                        Q = long.Parse(parts[1]),
                    };
                }
            }
        }

        public class Input
        {
            public int CaseNumber { get; set; }
            public long P { get; set; }
            public long Q { get; set; }
        }

        public string Solve(Input input)
        {
            long gcd = GCD(input.P, input.Q);

            long P = input.P / gcd;
            long Q = input.Q / gcd;

            //long P = input.P;
            //long Q = input.Q;


            int gen = 0;
            int i = 0;

            while (Q > 1)
            {
                if ((Q % 2) != 0)
                    return "impossible";
                Q = Q / 2;
                i++;
            }

            while (P > 0)
            {
                if (P % 2 == 1)
                {
                    gen = i;
                }

                P = P / 2;
                i--;
            }

            return "" + gen;
        }

        static bool Check(long Q)
        {

            while (Q > 1)
            {
                if ((Q % 2) != 0)
                    return false;
                Q = Q / 2;

            }
            return true;
        }

        static long GCD(long a, long b)
        {
            return b == 0 ? a : GCD(b, a % b);
        }
 
    }
}
