using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Round1B
{
    public class A
    {
        static void Main(string[] args)
        {
            var input = @"..\..\Round1B\A-small-attempt0.in";

            var result = Solver.Solve(File.ReadAllLines(input));
            File.WriteAllLines(Path.ChangeExtension(input, "out"), result);

            Console.WriteLine("Press ENTER to finish");
            Console.ReadLine();
        }

        public class Solver
        {
            public static IEnumerable<string> Solve(IEnumerable<string> input)
            {
                var reader = new Reader(input);
                var testCount = int.Parse(reader.Next());

                for (var i = 0; i < testCount; i++)
                {
                    var value = reader.Next();

                    yield return string.Format("Case #{0}: {1}", i + 1, SolveCase(value));
                }
            }

            public static long SolveCase(string value)
            {
                return L[int.Parse(value)];
            }

            static int[] L
            {
                get
                {
                    if (l == null)
                        CreateL();

                    return l;
                }
            }

            static int[] l;
            static void CreateL()
            {
                l = new int[1000002];

                for (var i = 0; i < l.Length; i++)
                    l[i] = int.MaxValue;

                l[0] = 0;
                var changed = true;

                while (changed)
                {
                    changed = false;
                    for (var i = 1; i < l.Length; i++)
                    {
                        var rev = long.Parse(string.Join("", i.ToString().Reverse()));
                        var li = l[i];
                        var lrev = l[rev];
                        l[i] = Math.Min(l[i - 1] + 1, l[i]);
                        l[rev] = Math.Min(l[rev], l[i] + 1);

                        if (li != l[i] || lrev != l[rev])
                            changed = true;
                    }
                }
                return;
            }
        }

        class Reader
        {
            readonly IEnumerator<string> _enumerator;

            public Reader(IEnumerable<string> lines)
            {
                _enumerator = lines.GetEnumerator();
            }

            public string NextOrNull()
            {
                if (!_enumerator.MoveNext())
                    return null;

                return _enumerator.Current;
            }

            public string Next()
            {
                if (!_enumerator.MoveNext())
                    throw new ApplicationException("End of input");

                return _enumerator.Current;
            }
        }
    }
}
