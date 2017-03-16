

namespace CodeJam
{
    using System;
    using System.Collections.Generic;


    public class ProblemA : ProblemBase
    {
        protected override string SolveOneCase(InputHelper input)
        {
            long r = input.GetLong();
            long t = input.GetLong();

            double rdub = (double)r;
            double tdub = (double)t;

            double b = 2 * rdub - 1;
            double a = 2;
            double c = -tdub;

            double sol = -b + Math.Sqrt(b * b - 4 * a * c);
            sol /= 2*a;

            long s =(long)sol - 1;

            while( s*(2*s + 2*r-1) - t <= 0)
                s++;

            s = s - 1;

            return s.ToString();
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
            var problem = new ProblemA();

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
    }
}