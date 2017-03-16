

namespace CodeJam
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

namespace CodeJam
{
    using System.Linq;
    using System;

    public class ProblemB : ProblemBase
    {
        protected override string SolveOneCase(InputHelper input)
        {
            int N = input.GetInt();
            int M = input.GetInt();

            int[][] lawn = new int[N][];
            for (int i = 0; i < N; i++)
                lawn[i] = input.GetIntArray();

            int[] maxRow = new int[N]; 
            int[] maxCol = new int[M];

            for (int i = 0; i < N; i++)
                maxRow[i] = lawn[i].Max();

            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++)
                    maxCol[i] = Math.Max(lawn[j][i], maxCol[i]);

            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                {
                    if (lawn[i][j] < Math.Min(maxRow[i], maxCol[j]))
                        return "NO";
                }


            return "YES";
        }
    }
}
     ﻿

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