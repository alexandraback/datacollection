

namespace Contest
{
    using System;
    using System.IO;

    public class Program
    {
        static void Main(string[] args)
        {
            Wrapper.Solve(new ProblemA(), Console.In, Console.Out);
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

    public class ProblemA : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            long N = input.GetLong();

            if (N <= 20)
                return N.ToString();

            long count = 10;
            long NN = 10;

            while( length(NN) < length(N))
            {
                var half = length(NN)/2;

                var p = 0;
                for (int i = 0; i < half; i++)
                {
                    p = p*10 + 1;
                }

                if( length(NN) % 2 == 1) // odd
                {
                    count += 1 + p*9 + (p*10 + 1)*9;
                }
                else
                {
                    count += 2 * p *9 + 1;
                }

                NN *= 10;
            }

            if( NN == N)
                return count.ToString();


            long opt = count + N-NN;

            var str = N.ToString();
            bool end0 = str[str.Length - 1] == '0';
            if (end0) N--;

            var half2 = length(N)/2;

            
            var stt = N.ToString().Substring(0, half2);
            var rev = Reverse(stt);
            var add = long.Parse(rev);

            var NN_p = NN + add;
            var NN_r = long.Parse(Reverse(NN_p.ToString()));

            count += N - NN_r + 1 + add;

            if (end0) count++;
//            bool end0 = str[str.Length - 1] == '0';
//
//            for (int i = 1; i <= length(N); i++)
//            {
//                var stt = str.Substring(0, i);
//                var rev = Reverse(stt);
//                var add = long.Parse(rev);
//
//                if (end0) add--;
//
//                var NN_p = NN + add;
//                var NN_r = long.Parse(Reverse(NN_p.ToString()));
//
//                if (NN_r > N)
//                    continue;
//
//                var opt2 = (N - NN_r) + 1 + add + count;
//
//                opt = Math.Min(opt, opt2);
//
//                if (end0)
//                    break;
//            }
            opt = Math.Min(count, opt);

            return opt.ToString();
        }

        private int length(long a)
        {
            return a.ToString().Length;
        }

        public static string Reverse(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
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