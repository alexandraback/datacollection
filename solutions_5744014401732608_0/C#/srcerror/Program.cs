using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamApp
{
    class Program
    {
        static void Main(string[] args)
        {
            var filenameIn = @"c:\Projects\test\CodeJamApp\Tasks\B-small-attempt5.in";
            var filenameOut = @"c:\Projects\test\CodeJamApp\Tasks\B-small-attempt5.out";
            var fileIn = File.ReadAllLines(filenameIn);
            using (var fout = new StreamWriter(filenameOut))
            {
                var L = int.Parse(fileIn[0]);
                for (int i = 1; i <= L; i++)
                {
                    var res = Task2(fileIn[i], i, fout);

                }
            }
        }

        public static BigInteger pow(int n)
        {
            if (n == 0) return 1;

            return 2 * pow(n - 1);
        }

        public static string Task2(string val, int cs, StreamWriter outf)
        {
            var res = "IMPOSSIBLE";
            var inp = val.Split(' ').Select(x => BigInteger.Parse(x)).ToList();
            var N = (int)inp[0];
            var M = inp[1];
            BigInteger n = N - 1;
            var mx = pow(N - 2);

            if (M > mx)
            {
                outf.WriteLine("Case #{0}: {1}", cs, "IMPOSSIBLE");
                return "";
            }

            // write result matrix
            int[,] matrix = new int[N, N];
            bool found = false;

            for (int i = 1; i < N; i++)
            {
                for (int j = i + 1; j < N; j++)
                {
                    matrix[i, j] = 1;
                }
            }

            int f = 0;
            if (M == mx)
            {
                for (int i = 1; i < N; i++)
                {
                    matrix[0, i] = 1;
                }
                found = true;
            }
            else
            {
                var s = ConvertToString(M, 2).ToList();
                for (int i = 0; i < s.Count; i++)
                {
                    matrix[0, (N - 2) - i] = s[i];
                }
                found = true;
            }
            if (found)
            {
                outf.WriteLine("Case #{0}: {1}", cs, "POSSIBLE");

                for (int i = 0; i < N; i++)
                {
                    var sb = new StringBuilder();
                    for (int j = 0; j < N; j++)
                    {
                        sb.AppendFormat("{0}", matrix[i, j]);

                    }
                    var ss = sb.ToString().TrimEnd();
                    outf.WriteLine(ss);
                }
                return "";
            }
            else
            {
                outf.WriteLine("Case #{0}: {1}", cs, "IMPOSSIBLE");

                return "";
            }
        }

        private static IEnumerable<int> ConvertToString(BigInteger m, int v)
        {
            var s = m;
            while (s > 0)
            {
                var r = (int)(s % v);
                s = s / v;
                yield return r;
            }
        }

        //public class Party
        //{
        //    public int Index { get; set; }
        //    public char Name { get { return Alphabet[Index]; } }
        //    public int Count { get; set; }
        //}
        //static char[] Alphabet = new char[] { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
        //static string Task1(string sN, string parties)
        //{
        //    var N = int.Parse(sN);
        //    int cnt = 0;
        //    var pp = parties.Split(' ').Select(x => new Party() { Index = cnt++, Count = int.Parse(x) }).ToList();

        //    // step #1. Sort
        //    var sorted = pp.OrderByDescending(x => x.Count).ToList();
        //    // step #2. reduce top

        //    var sb = new StringBuilder();
        //    var p2 = sorted[1].Count;
        //    while (sorted[0].Count > p2)
        //    {
        //        var p1 = sorted[0];
        //        p1.Count--;
        //        sb.AppendFormat("{0} ", p1.Name);

        //    }
        //    for (int i = sorted.Count-1; i > 1; i--)
        //    {
        //        while (sorted[i].Count > 0)
        //        {
        //            var pi = sorted[i];
        //            pi.Count--;
        //            sb.AppendFormat("{0} ", pi.Name);
        //        }
        //    }
        //    // last step 2 parties
        //    for (int i = 0; i < sorted[0].Count; i++)
        //    {
        //        sb.AppendFormat("{0}{1} ", sorted[0].Name, sorted[1].Name);
        //    }


        //    return sb.ToString().TrimEnd();
        //}
    }
}
