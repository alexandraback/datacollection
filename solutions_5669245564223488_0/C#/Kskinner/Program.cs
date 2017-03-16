using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    public class Program
    {
        int N;
        string[] cars;

        public void ReadData()
        {
            N = ReadInt();
            cars = ReadArray<string>();
        }

        public string Solve()
        {
            int[] s = new int[N];

            return Solve(s, 0).ToString();
        }

        public long Solve(int[] s, int k)
        {
            if (k == N)
                return IsValid(s) ? 1 : 0;

            long count = 0;
            for (int i = 0; i < N; i++)
            {
                if (!Contains(s, k, i))
                {
                    s[k] = i;
                    count += Solve(s, k + 1);
                }
            }
            return count;
        }

        private bool IsValid(int[] s, int k)
        {
            string train = string.Join("", s.Select(i => cars[i]));
            bool[] seen = new bool[26];
            char last = train[0];
            for (int i = 0; i < train.Length; i++)
            {
                if (i == 0 || train[i] != last)
                {
                    if (seen[train[i] - 'a'])
                        return false;
                    seen[train[i] - 'a'] = true;
                    last = train[i];
                }
            }
            return true;
        }

        private bool Contains(int[] s, int k, int i)
        {
            for (int j = 0; j < k; j++)
                if (s[j] == i)
                    return true;
            return false;
        }

        static StreamReader reader;

        static void Main(string[] args)
        {
            string filename = args.Length > 0 ? args[0] : "test.in";
            string outFileName = filename.Replace(".in", ".out");
            string expectedFileName = filename.Replace(".in", ".expected");

            using (reader = File.OpenText(filename))
            using (var outFile = File.CreateText(outFileName))
            {
                int T = ReadInt();
                Console.WriteLine("{0} test cases", T);

                for (int tc = 1; tc <= T; tc++)
                {
                    Console.WriteLine("Starting test case {0}", tc);
                    var problem = new Program();
                    problem.ReadData();
                    string solution = problem.Solve();

                    outFile.WriteLine("Case #{0}: {1}", tc, solution);
                    Console.WriteLine("Case #{0}: {1}", tc, solution);
                }
            }

            if (File.Exists(expectedFileName))
            {
                CompareOutputToExpected(outFileName, expectedFileName);
            }
        }

        private static void CompareOutputToExpected(string outFileName, string expectedFileName)
        {
            string[] expected = File.ReadAllLines(expectedFileName);
            string[] actual = File.ReadAllLines(outFileName);
            for (int i = 0; i < Math.Max(expected.Length, actual.Length); i++)
            {
                string lineActual = i < actual.Length ? actual[i] : "** missing **";
                string lineExpected = i < expected.Length ? expected[i] : "** missing **";
                if (lineActual != lineExpected)
                {
                    Console.WriteLine("{0}: Expected: {1} Actual: {2}", (i + 1), lineExpected, lineActual);
                }
            }
        }

        #region Readers

        private static string ReadWord()
        {
            StringBuilder word = new StringBuilder();
            while (reader.Peek() >= 0)
            {
                char c = (char)reader.Read();
                if (Char.IsControl(c) || Char.IsWhiteSpace(c))
                    break;
                word.Append(c);
            }
            return word.ToString();
        }

        private static string ReadLine()
        {
            return reader.ReadLine();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(ReadLine(), typeof(T));
        }

        private static T[] ReadArray<T>()
        {
            return ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToArray();
        }

        #endregion
    }
}
