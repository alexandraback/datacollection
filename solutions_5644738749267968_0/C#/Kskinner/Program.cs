using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D
{
    public class Problem
    {
        int N;
        double[] naomi;
        double[] ken;

        public string Solve()
        {
            ReadData();

            int z = War();
            int y = DeceitfulWar();

            return string.Format("{0} {1}", y, z);
        }

        private int DeceitfulWar()
        {
            int naomis_score = 0;
            var kens_blocks = new List<double>(ken);

            for (int i = 0; i < N; i++)
            {
                double cn = naomi[i];

                double k_min = kens_blocks.Min();
                double k_max = kens_blocks.Max();

                // Naomi can bluff and win only if cn > k_min
                if (cn > k_min)
                {
                    naomis_score++;
                    kens_blocks.Remove(k_min);
                }
                else
                {
                    kens_blocks.Remove(k_max);
                }
            }
            return naomis_score;
        }

        private int War()
        {
            int kens_score = 0;
            int j = 0;
            for (int i = 0; i < N; i++)
            {
                double cn = naomi[i];
                while (j < N && ken[j] < cn)
                {
                    j++;
                }
                if (j >= N)
                    break;
                kens_score++;
                j++;
            }
            return N - kens_score;
        }

        private void ReadData()
        {
            N = ReadInt();
            naomi = ReadArray<double>();
            ken = ReadArray<double>();
            Array.Sort(naomi);
            Array.Sort(ken);
        }

        static StreamReader reader;

        static void Main(string[] args)
        {
            string filename = args.Length > 0 ? args[0] : "test.in";
            string outFileName = filename.Replace(".in", ".out");

            using (reader = File.OpenText(filename))
            using (var outFile = File.CreateText(outFileName))
            {
                int T = ReadInt();
                Console.WriteLine("{0} test cases", T);

                for (int tc = 1; tc <= T; tc++)
                {
                    Console.WriteLine("Starting test case {0}", tc);
                    var problem = new Problem();
                    string solution = problem.Solve();

                    outFile.WriteLine("Case #{0}: {1}", tc, solution);
                    Console.WriteLine("Case #{0}: {1}", tc, solution);
                }
            }
        }

        #region Readers

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
