using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RoundC_ProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var sr = File.OpenText("input.txt"))
            {
                var num_tests = Convert.ToInt32(sr.ReadLine());

                using (var sw = new StreamWriter(File.OpenWrite("output.txt")))
                {

                    for (int i = 0; i < num_tests; ++i)
                    {
                        var nums = sr.ReadLine().Split(' ').Select(k => Convert.ToInt32(k.Trim())).ToArray();

                        int s = nums[2];
                        string alphabet = sr.ReadLine().Trim();
                        string word = sr.ReadLine().Trim();

                        sw.WriteLine(String.Format("Case #{0}: {1}", i + 1, Math.Round(RemainingBananas(alphabet, word, s),6)));
                    }

                    sw.Flush();
                    sw.Close();
                }
            }
        }

        static double RemainingBananas(string alphabet, string word, int strokes)
        {
            Tuple<int, string> bananaInfo = DetermineBananasString(alphabet, word, strokes);
            Dictionary<char, double> probability = ComputeProbabilities(alphabet);

            double totalProbability = 1;

            foreach (var c in bananaInfo.Item2)
            {
                totalProbability *= probability[c];
            }

            if (bananaInfo.Item1 == 0) return 0;
            return (bananaInfo.Item1 - bananaInfo.Item1 * totalProbability); 
        }

        private static Dictionary<char, double> ComputeProbabilities(string alphabet)
        {
            Dictionary<char, int> occurences = new Dictionary<char, int>();

            foreach (var c in alphabet)
            {
                if (!occurences.ContainsKey(c))
                {
                    occurences.Add(c, 0);
                }

                ++occurences[c];
            }

            var probabilities = new Dictionary<char, double>();

            foreach (var k in occurences.Keys)
            {
                probabilities.Add(k, occurences[k] / ((double)alphabet.Length));
            }

            return probabilities;
        }

        private static Tuple<int, string> DetermineBananasString(string alphabet, string word, int strokes)
        {
            foreach (var c in word)
            {
                if (alphabet.IndexOf(c) == -1)
                {
                    return new Tuple<int, string>(0, "");
                }
            }

            string pref = GetPrefix(word);
            StringBuilder bananaString = new StringBuilder();
            int k = 0;

            int wordCount = 0;

            while (k + word.Length <= strokes)
            {
                bananaString.Append(pref);
                if (word.Length - 2 * pref.Length > 0)
                {
                    bananaString.Append(word.Substring(pref.Length, word.Length - 2 * pref.Length));
                }
                ++wordCount;
                k += word.Length - pref.Length;
            }

            return new Tuple<int, string>(wordCount, bananaString.ToString());
        }

        private static string GetPrefix(string word)
        {
            int k = word.Length;
            bool found = false;

            while (k > 0 && !found)
            {
                --k;

                if (word.EndsWith(word.Substring(0, k)))
                {
                    return word.Substring(0, k);
                }
            }

            return "";
        }
    }
}
