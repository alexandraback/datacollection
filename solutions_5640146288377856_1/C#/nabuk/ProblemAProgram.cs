using System;
using System.IO;
using System.Linq;
using System.Reflection;

namespace ProblemA
{
    class ProblemAProgram
    {
        static void Main(string[] args) { (Activator.CreateInstance(MethodBase.GetCurrentMethod().DeclaringType) as dynamic).Run(); }
        void Run()
        {
            //using (TextReader tr = new StreamReader(@"c:\temp\testin.txt"))
            using (TextReader tr = new StreamReader(@"c:\temp\A-small-attempt0.in"))
            //using (TextReader tr = new StreamReader(@"c:\temp\a-large.in"))
            //using (TextReader tr = Console.In)

            using (TextWriter tw = new StreamWriter(@"c:\temp\out.txt"))
            //using (TextWriter tw = Console.Out)
            {
                var tCase = int.Parse(tr.ReadLine());

                for (var tiCase = 1; tiCase <= tCase; ++tiCase)
                {
                    tw.WriteLine("Case #{0}: {1}", tiCase, Solve(tr.ReadLine));
                }
            }
        }

        string Solve(Func<string> rline)
        {
            var inp = rline().Split().Select(int.Parse).ToArray();
            int R = inp[0], C = inp[1], W = inp[2];

            if (W == 1)
                return (R*C).ToString();

            return ((C - 1)/W + W + (R - 1)/W).ToString();
        }
    }
}
