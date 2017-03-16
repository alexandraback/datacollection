using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1C_Consonants
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader inps = new StreamReader("data_in.txt");
            StreamWriter outps = new StreamWriter("data_out.txt");
            int T = int.Parse(inps.ReadLine());
            for (int t = 0; t < T; ++t)
            {
                string line = inps.ReadLine();
                string[] lineEl = line.Split(' ');
                int n = int.Parse(lineEl[1]);
                string word = lineEl[0];
                string res = Resolve(word, n);
                outps.WriteLine("Case #" + (t + 1) + ": " + res);
            }
            inps.Close();
            outps.Close();
        }

        public static bool isVovel(char ch)
        {
            return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');

        }
        
        public static string Resolve(string word, int n)
        {
            long res = 0;
            bool[] wordB = new bool[word.Length];
            int wordLen = word.Length;
            for (int i = 0; i < word.Length; ++i)
                wordB[i] = !isVovel(word[i]);
            for (int left=0;left<wordLen;++left)
                for (int right = left + 1; right <= wordLen; ++right)
                {
                    if (isGoodSubstr(wordB, n, left, right))
                        ++res;
                }
            return res.ToString();
        }

        private static bool isGoodSubstr(bool[] wordB, int n, int left, int right)
        {
            int count1 = 0;
            for (int i = left; i < right; ++i)
            {
                if (wordB[i])
                {
                    ++count1;
                    if (count1 >= n)
                        return true;
                }
                else
                    count1 = 0;
            }
            return false;
        }
    }
}
