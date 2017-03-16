

namespace CodeJamB
{
    using System;
    using System.Collections.Generic;


    public class ProblemB : ProblemBase
    {
        protected override string SolveOneCase(InputHelper input)
        {
            int E = input.GetInt();
            int R = input.GetInt();
            R = Math.Min(E, R);
            int N = input.GetInt();

            int[] v = input.GetIntArray();
            int[] high = new int[v.Length];

            Stack<int> stack = new Stack<int>();


            for (int i = 0; i < N; i++)
            {

                while (stack.Count > 0 && v[i] > v[stack.Peek()])
                {
                    var n = stack.Pop();
                    high[n] = i;
                }

                stack.Push(i);
            }

            while (stack.Count > 0)
            {
                int n = stack.Pop();
                high[n] = n;
            }

            long gain = 0;
            int en = E;
            for (int i = 0; i < N; i++)
            {
                int val;
                int d = high[i] - i;
                if (d != 0)
                {
                    int left = en + d * R - E;
                    val = Math.Min(left, E);
                    val = Math.Max(val, 0);
                    //Console.Out.WriteLine(val);

                }
                else
                    val = Math.Min(en, E);

                gain += val * v[i];
                en -= val;
                en += R;
                en = Math.Min(en, E);
            }



            return gain.ToString();
        }

    }
}

namespace CodeJamB
{
    using System;

    public class Program
    {
        static void Main(string[] args)
        {
            var problem = new ProblemB();

            problem.Solve(new InputHelper(Console.In), Console.Out);
        }
    }
}﻿

namespace CodeJamB
{
    using System.IO;

    public abstract class ProblemBase
    {
        protected int NumberOfCases;

        protected abstract string SolveOneCase(InputHelper input);

        protected virtual void SetupAndGetNumberOfCases(InputHelper input)
        {
            NumberOfCases = input.GetInt();
        }

        public void Solve(InputHelper input, TextWriter output)
        {
            SetupAndGetNumberOfCases(input);

            for (int i = 0; i < NumberOfCases; i++)
            {
                output.WriteLine(string.Format("Case #{0}: {1}", i + 1, SolveOneCase(input)));
            }
        }
    }
}﻿
namespace CodeJamB
{
    using System.Collections;
    using System;
    using System.IO;
    using System.Reflection;


    public class InputHelper
    {
        private readonly TextReader textReader;

        private IEnumerator enumerator;

        public InputHelper(TextReader textReader)
        {
            this.textReader = textReader;
            this.enumerator = (new string[0]).GetEnumerator();
        }

        public string ReadLine()
        {
            return textReader.ReadLine();
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
            while (enumerator.MoveNext() == false)
            {
                enumerator = GetStringArray().GetEnumerator();
            }

            return (string)enumerator.Current;
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
}