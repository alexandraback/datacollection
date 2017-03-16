

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
    using System.Collections.Generic;
    using System.Linq;
    using System.Text;

    public class ProblemB : IProblem
    {
        public string SolveOneCase(InputParser input)
        {
            int B = input.GetInt();
            var M = input.GetLong();

            var ar = new int[B,B];

            long max = 1 << (B - 2);

            if (M > max) return "IMPOSSIBLE";

            var list = new List<long>();
            var left = M;

            while (left > 0)
            {
                if (max > left)
                {
                    max = max/2;
                    continue;
                }

                list.Add(max);
                left = left - max;
            }

            list.Sort();

//            for (int i = 0; i < B - 1; i++)
//            {
//                ar[i, i + 1] = 1;
//            }

            var largest = list.Max();
            var curr = 1;

            for (int i = B-2; i >=0 ; i--)
            {
                if (curr > largest)
                    break;

                for (int j = i+1; j < B; j++)
                {
                    ar[i, j] = 1;
                }

                if( list.Contains(curr))
                {
                    if( i!= 0)
                        ar[0, i] = 1;
                }

                    curr *= 2;

            }

            var sb = new StringBuilder();
            sb.AppendLine("POSSIBLE");

            for (int i = 0; i < B; i++)
            {
                for (int j = 0; j < B; j++)
                {
                    sb.Append(ar[i, j]);
                }
                sb.AppendLine();
            }
            //Console.WriteLine(sb.ToString());

            return sb.ToString();
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