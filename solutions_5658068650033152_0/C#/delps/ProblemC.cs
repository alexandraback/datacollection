

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
    using System;
    using System.Collections.Generic;
    using System.Text;

    public class ProblemC : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int N = input.GetInt();
            int M = input.GetInt();
            int K = input.GetInt();

            if(N>M)
            {
                int t = M;
                M = N;
                N = t;
            }

            if( N <= 2)
            {
                return K.ToString();
            }

            int best = K;

            for (int i = 3; i <= M; i++)
            {
                int w = i;
                for (int j = 3; j <= N; j++)
                {
                    int st = 2*(w - 2) + 2*(j - 2);
                    int kk = st + (w - 2)*(j - 2);

                    if (kk < K)
                    {
                        var st1 = st + K - kk;
                        var st2 = st1;
                        if( j<N && i<M)
                        {
                            st += 2;
                            kk += 3;
                            if (kk < K)
                                st2 += K - kk;
                        }

                        st = Math.Min(st1, st2);
                    }

                    if (st < best)
                        best = st;
                }
            }





            return best.ToString();
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