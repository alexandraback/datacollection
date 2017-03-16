

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
        private int[,] jPair;
        private int[,] pPair;
        private int K;
        private int S;
        private List<string> list;
        private int ss;

        public string SolveOneCase(InputParser input)
        {
            //J, P, S, and K. 

            int J = input.GetInt();
            int P = input.GetInt();
            S = input.GetInt();
            K = input.GetInt();

            int count = 0;

            jPair = new int[J, S];
            pPair = new int[P, S];

            var sb = new StringBuilder();

            ss = -1;

            list = new List<string>();

            for (int i = 0; i < J; i++)
            {
                for (int j = 0; j < P; j++)
                {
                    for (int k = 0; k < K; k++)
                    {
                        var s = nextS(ss, i, j);

                        if( s == string.Empty)
                            continue;

                        count++;
                        sb.AppendLine(s);
                        list.Add(s);
                    }


                }
            }

        done:



            var res =  count.ToString() + "\r\n" + sb.ToString();

            //Console.WriteLine(res);
            return res;
        }

        public string nextS(int ss, int j, int p)
        {
            ss++;
            var start = ss;

            while(true)
            {
                if( jPair[j, ss] < K && pPair[p, ss] < K)
                {
                    string val = (j + 1).ToString() + " " + (p + 1).ToString() + " " + (ss + 1).ToString();

                    if (!list.Contains(val))
                    {

                        jPair[j, ss]++;
                        pPair[p, ss]++;
                        return val;

                    }

                }

                ss = (ss + 1)%S;

                if (ss == start)
                    return string.Empty;
            }


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