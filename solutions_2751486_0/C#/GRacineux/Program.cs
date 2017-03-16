using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace pb1c_a
{
    class Program
    {
        static void Main(string[] args)
        {
            //string filename = "test";
            string filename = "A-small-attempt0";
            
            string inputFile = filename + ".in";
            //string inputFile = "test.in";
            string outputFile = filename + ".out";
            Init();
            List<long> res = new List<long>();
            using (StreamReader reader = new StreamReader(inputFile))
            {
                string s = reader.ReadLine();
                int nbProblem = int.Parse(s);
                for (int i = 0; i < nbProblem; i++)
                {
                    string l1 = reader.ReadLine();
                    var split = l1.Split(' ');
                    string word = split[0];
                    int n = int.Parse(split[1]);
                    res.Add(Solve(word, n));

                }
            }
            using (StreamWriter writer = new StreamWriter(outputFile))
            {
                for (int i = 0; i < res.Count; i++)
                {
                    writer.WriteLine("Case #{0}: {1}", i + 1, res[i]);
                }
            }
        }


        static long Solve(string word, int n)
        {
            if (n > word.Length)
            {
                return 0;
            }

            List<int> index = new List<int>();
            var wordVowels = word.Select(c => IsVowels(c)).ToArray();
            for (int i = 0; i < wordVowels.Length - n + 1; i++)
            {
                bool b = true;
                for (int j = 0; j < n; j++)
                {
                    b = b && !wordVowels[i + j];
                }
                if (b)
                {
                    index.Add(i);
                }
            }
            long res = 0;
            if (index.Count == 0)
            {
                return 0;
            }
            for (int i = 0; i < wordVowels.Length; i++)
            {
                if (i <= index.Last())
                {
                    int first = index.First(o => o >= i);

                    res += wordVowels.Length - first - n + 1;
                }
            }
            return res;

        }

        static HashSet<char> _vowels = new HashSet<char>();

        static void Init()
        {
            _vowels.Add('a');
            _vowels.Add('e');
            _vowels.Add('i');
            _vowels.Add('o');
            _vowels.Add('u');
        }


        static bool IsVowels(char c)
        {
            return _vowels.Contains(c);
        }
    }
}
