

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
    using System.Collections.Generic;
    using System.Text;

    public class ProblemA : IProblem
    {
        private Dictionary<char, int> dict;
        private StringBuilder sb;

        public string SolveOneCase(InputParser input)
        {
            var str = input.GetString();

            dict = new Dictionary<char, int>();
            sb = new StringBuilder();

            for (int i = 0; i < str.Length; i++)
            {
                var c = str[i];
                if (!dict.ContainsKey(c))
                {
                    dict.Add(c, 0);
                }

                dict[c]++;
            }

            parse("ZERO", 0);
            parse("TWO", 2);
            parse("EIGHT", 8);
            parse("SIX", 6);
            parse("FOUR", 4);
            parse("FIVE", 5);
            parse("SEVEN", 7);
            parse("THREE", 3);
            parse("ONE", 1);
            parse("NINE", 9);

            var res = sb.ToString();
            var cc = res.ToCharArray();
            Array.Sort(cc);


            return new string(cc);
        }

        private void parse(string word, int digit)
        {
            while(true)
            {
                bool miss = false;
                for (int i = 0; i < word.Length; i++)
                {
                    var c = word[i];

                    if( !dict.ContainsKey(c) )
                    {
                        dict.Add(c, -1);
                        miss = true;
                    }
                    else
                    {
                        if( dict[c] < 1)
                        {
                            miss = true;
                        }
                        dict[c]--;
                    }
                }

                if(miss == true)
                {
                    for (int i = 0; i < word.Length; i++)
                    {
                        var c = word[i];
                        dict[c]++;
                    }

                    return;
                }
                else
                {
                    sb.Append(digit);
                }
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