

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemB(), Console.In, Console.Out);
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


    public class ProblemB : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int N = input.GetInt();
            int X = input.GetInt();
            int Y = input.GetInt();

            X = Math.Abs(X);
            int k = (X + Y)/2;


            if (quad(k) <= N)
                return "1.0";
            if (quad(k - 1) >= N)
                return "0.0";

            if (X == 0)
                return "0.0";


            int L = N - quad(k - 1);

            int yp = Y + 1;

            if (yp > L)
                return "0.0";

            if( L >= 2*k+1)
            {
                int e = L - (2*k );
                yp = yp - e;
                L = L - 2*e;
            }

            if (yp <= 0)
                return "1.0";

            decimal fact = 1;
            for (int i = 0; i < L; i++)
            {
                fact /= 2;
            }


            decimal[,] choose = new decimal[L+1,L+1];

            for (int i = 0; i <= L; i++)
            {
                for (int j = 0; j <= i; j++)
                {
                    if( j== 0)
                    {
                        choose[i,j] = 1;
                        continue;
                    }

                    choose[i, j] = choose[i - 1, j] + choose[i - 1, j - 1];
                }
            }

            decimal prob = 0;

            for (int i = yp; i <= L; i++)
            {
                prob += choose[L, i];
            }

            prob *= fact;

            return prob.ToString();
        }

        private int quad(int k)
        {
            return 2*k*k + 3*k + 1;
        }
    }
}﻿

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