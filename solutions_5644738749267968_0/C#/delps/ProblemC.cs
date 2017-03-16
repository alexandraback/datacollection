

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemC(), Console.In, Console.Out);
        }
    }

    public class Wrapper
    {
        public static void Solve(IProblem problem, TextReader input, TextWriter output)
        {
            var parser = new InputParser(input);
            int T = parser.GetInt();

            for (int i = 0; i < T; i++)
            {
                output.WriteLine(string.Format("Case #{0}: {1}", i + 1, problem.SolveOneCase(parser)));
            }
        }
    }

    public interface IProblem
    {
        string SolveOneCase(InputParser input);
    }
}﻿

namespace Contest
{
    using System.Collections.Generic;

    public class ProblemC : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int t = input.GetInt();
            List<double> nam = new List<double>();
            List<double> ken = new List<double>();

            for (int i = 0; i < t; i++)
            {
                nam.Add(double.Parse(input.GetString()));
            }
            for (int i = 0; i < t; i++)
            {
                ken.Add(double.Parse(input.GetString()));
            }

            nam.Sort();
            ken.Sort();


            int w1 = war(nam, ken);
            int w2 = t-war(ken, nam);

            return w1 + " " + w2;
        }

        private int war(List<double> a, List<double> b )
        {
            a = new List<double>(a);
            b = new List<double>(b);

            int score = 0;

            for (int i = 0; i < b.Count; i++)
            {
                double v = b[i];
                bool found = false;

                for (int j = 0; j < a.Count; j++)
                {
                    if( a[j] > v )
                    {
                        found = true;
                        score++;
                        a.RemoveAt(j);
                        break;
                    }


                }
                if (!found)
                    a.RemoveAt(0);
            }

            return score;
        }
    }
}
﻿

namespace Contest
{
    using System.Collections;
    using System;
    using System.IO;

    public class InputParser
    {
        private readonly TextReader _textReader;

        private IEnumerator _enumerator;

        public InputParser(TextReader textReader)
        {
            this._textReader = textReader;
            this._enumerator = (new string[0]).GetEnumerator();
        }

        public string ReadLine()
        {
            return _textReader.ReadLine();
        }

        public string[] GetStringArray()
        {
            return ReadLine().Split(new string[0], StringSplitOptions.RemoveEmptyEntries);
        }

        public int[] GetIntArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new int[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = int.Parse(tokens[i]);
            }

            return values;
        }

        public long[] GetLongArray()
        {
            string[] tokens = GetStringArray();
            int length = tokens.Length;

            var values = new long[length];

            for (int i = 0; i < length; i++)
            {
                values[i] = long.Parse(tokens[i]);
            }

            return values;
        }

        public string GetString()
        {
            while (_enumerator.MoveNext() == false)
            {
                _enumerator = GetStringArray().GetEnumerator();
            }

            return (string)_enumerator.Current;
        }

        public int GetInt()
        {
            return int.Parse(GetString());
        }

        public long GetLong()
        {
            return long.Parse(GetString());
        }
    }
}