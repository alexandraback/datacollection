using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace ProblemC
{
    class ProblemCProgram
    {
        static void Main(string[] args) { (Activator.CreateInstance(MethodBase.GetCurrentMethod().DeclaringType) as dynamic).Run(); }
        void Run()
        {
            //using (TextReader tr = new StreamReader(@"c:\temp\testin.txt"))
            using (TextReader tr = new StreamReader(@"c:\temp\C-small-attempt2.in"))
            //using (TextReader tr = new StreamReader(@"c:\temp\c-large.in"))
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
            int C = inp[0], D = inp[1], V = inp[2];

            var d = rline().Split().Select(int.Parse).ToArray();
            if (Check(new HashSet<int>(d), V))
                return 0.ToString();

            var result = int.MaxValue;
            int deep = 0;
            while (result == int.MaxValue)
            {
                result = rec(new HashSet<int>(d), V, 1, deep++);
            }
                

            return result.ToString();
        }

        int rec(HashSet<int> d, int V, int total, int deep)
        {

            for (int i = 1; i <= V; i++)
            {
                if (!d.Contains(i))
                {
                    d.Add(i);
                    if (deep == 0)
                    {
                        if (Check(d, V))
                            return total;
                    }
                    else
                    {
                        int result = rec(d, V, total + 1, deep - 1);
                        if (result != int.MaxValue)
                            return result;
                    }

                    d.Remove(i);
                }
            }

            return int.MaxValue;
        }

        bool Check(HashSet<int> d, int V)
        {
            var v = new HashSet<int>[V + 1];
            for (int i = 1; i <= V; i++)
            {
                v[i] = new HashSet<int>();

                if (d.Contains(i))
                    v[i].Add(i);
                else
                {
                    bool found = false;
                    foreach (var currentD in d.OrderBy(x => x))
                    {
                        var index = i - currentD;
                        if (index >= 1)
                        {
                            if (!v[index].Contains(currentD))
                            {
                                v[i] = new HashSet<int>(v[index]);
                                v[i].Add(currentD);
                                found = true;
                                break;
                            }
                        }
                    }
                    if (!found)
                        return false;
                }
            }

            return true;
        }
    }
}
