

using System;
using System.Collections.Generic;

namespace CodeJam
{
    public class ProblemC : ProblemBase
    {

        private List<long> pals = new List<long>();
        protected override string SolveOneCase(InputHelper input)
        {
            string A = input.GetString();
            string B = input.GetString();

            long a = long.Parse(A);
            long b = long.Parse(B);

            int count = 0;

            if( pals.Count == 0)
            for (long i = 1; i <= 10000000; i++ )
            {
                long t = i*i;

                if (isPal(i) && isPal(t))
                {
                    pals.Add(t);
                }

            }

            for (int i = 0; i < pals.Count; i++ )
            {
                if (pals[i] >= a && pals[i] <= b)
                    count++;
            }


                return count.ToString();
        }


        private bool isPal(long b)
        {
            var s = b.ToString();

            for (int i = 0; i <= s.Length /2 ; i++)
            {
                if (s[i] != s[s.Length - i - 1])
                    return false;
            }
            return true;
        }
    }
}

namespace CodeJam
{
    using System;

    public class Program
    {
        static void Main(string[] args)
        {
            var problem = new ProblemC();

            problem.Solve(new InputHelper(Console.In), Console.Out);
        }
    }
}﻿

namespace CodeJam
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
namespace CodeJam
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

        // use this to get other types. Not tested yet.
        public T Get<T>()
        {
            MethodInfo method = typeof (T).GetMethod("Parse", new[] {typeof (string)});

            return (T) method.Invoke(null, new[] {GetString()});
        }
    }
}