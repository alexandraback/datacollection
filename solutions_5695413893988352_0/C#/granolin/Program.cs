using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Match
{
    class Program
    {

        static void Main(string[] args)
        {
            Reader reader = new Reader("B-small-attempt1.in");
            StreamWriter sw = new StreamWriter("out4.txt");

            int nTest = reader.ReadInt();
            for (int T = 1; T <= nTest; T++)
            {
                string coder = reader.Next();
                string jammer = reader.Next();
                string res = Compute(coder, jammer);
                sw.WriteLine("Case #" + T + ": " + res);
            }
            sw.Close();
        }


        private static List<string> GetPossibleScore(string score)
        {
            List<string> res = new List<string>();
            var idx = score.IndexOf('?');
            if (idx == -1)
            {
                res.Add(score);
            }else
            {
                var s = score.ToCharArray();
                for (int i = 0; i <= 9; i++)
                {
                    s[idx] = i.ToString()[0];
                    res = res.Concat(GetPossibleScore(new string(s))).ToList();
                }
            }
            return res;   
        }


        private static string Compute(string coder, string jammer)
        {

            var possiblesScores = GetPossibleScore(coder + " " + jammer);
            possiblesScores = possiblesScores.Distinct().ToList();
            Dictionary<string, int> diff = GetDiff(possiblesScores);
            int min = diff.Values.Min();
            var kes = diff.Keys.Where(k => diff[k] == min).ToList();

            return kes.Min();
        }

        private static Dictionary<string, int> GetDiff(List<string> possiblesScores)
        {
            Dictionary<string, int> res = new Dictionary<string, int>();
            foreach (string scores in possiblesScores)
            {
                var s = scores.Split(' ');
                var coder = int.Parse(s[0]);
                var jammer = int.Parse(s[1]);

                if (jammer > coder)
                    res.Add(scores, jammer - coder);
                else if (coder > jammer)
                    res.Add(scores, coder - jammer);
                else
                    res.Add(scores, 0);
            }
            return res;
        }
    }


    #region Commun

    public class Reader
    {
        string[] _content;
        int idx = 0;

        public Reader(string path)
        {
            string[] Separator = new string[] { " ", "\r\n", "\n" };
            string s = File.ReadAllText(path);
            _content = s.Split(Separator, StringSplitOptions.None);
        }

        public string Next()
        {
            return _content[idx++];
        }

        public int ReadInt()
        {
            return int.Parse(Next());
        }

        public int[] ReadInt(int N)
        {
            List<int> res = new List<int>();
            for (int i = 0; i < N; i++)
                res.Add(ReadInt());
            return res.ToArray();
        }
    }

    public static class Calc
    {

        public static long PPCM(long[] a)
        {
            return a.Aggregate(PPCM);
        }

        public static long PPCM(long a, long b)
        {
            return a * b / PGCD(a, b);
        }

        public static long PGCD(long[] a)
        {
            return a.Aggregate(PGCD);
        }

        public static long PGCD(long a, long b)
        {
            if (a < b)
                return PGCD(b, a);

            while (b != 0)
            {
                long r = a % b;
                a = b;
                b = r;
            }
            return a;
        }
    }

    #endregion
}
