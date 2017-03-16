using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplicationA
{
    class DDRes
    {
        public string word;
        public List<int> occurences;
    }

    class TestCase
    {
        public int id;
        public int numWords;
        public double result;
        public List<string> words;

        public TestCase()
        {
            words = new List<string>();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<TestCase> testCases = new List<TestCase>();
            int nTestCases;

            using (StreamWriter sw = new StreamWriter(@"C:\Users\Fred\documents\visual studio 2013\Projects\ConsoleApplicationA\ConsoleApplicationA\result.out", false))
            using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\ConsoleApplicationA\ConsoleApplicationA\A-small-attempt0.in"))
            //using (StreamReader sr = new StreamReader(@"C:\Users\Fred\documents\visual studio 2013\Projects\ConsoleApplicationA\ConsoleApplicationA\A-large-practice.in"))
            {
                string line = sr.ReadLine();
                //Console.WriteLine(line);
                nTestCases = int.Parse(line);

                for (int i = 0; i < nTestCases; i++)
                {
                    TestCase tempTestCase = new TestCase();

                    tempTestCase.id = i + 1;
                    tempTestCase.numWords = int.Parse(sr.ReadLine());

                    for (int j = 0; j < tempTestCase.numWords; j++)
                    {
                        tempTestCase.words.Add(sr.ReadLine().Trim());
                    }

                    List<DDRes> ddr = tempTestCase.words.Select(w => dedup(w)).ToList();

                    string firstdd = ddr.First().word;

                    if (ddr.All(ddritem => firstdd.Equals(ddritem.word, StringComparison.InvariantCultureIgnoreCase)))
                    {
                        int segs = firstdd.Length;
                        int totalpenalty = 0;

                        for (int k = 0; k < segs; k++)
                        {
                            List<int> occs = ddr.Select(d => d.occurences[k]).ToList();
                            totalpenalty += minpenalty(occs);
                        }

                        Console.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, totalpenalty));
                        sw.WriteLine(String.Format("Case #{0}: {1}", tempTestCase.id, totalpenalty));
                    }
                    else
                    {
                        Console.WriteLine(String.Format("Case #{0}: Fegla Won", tempTestCase.id, tempTestCase.result));
                        sw.WriteLine(String.Format("Case #{0}: Fegla Won", tempTestCase.id, tempTestCase.result));
                    }
                }

                Console.ReadLine();
            }
        }

        private static int minpenalty(List<int> occs)
        {
            int penalty = int.MaxValue;
            int max = occs.Max();

            for (int i = 1; i <= max; i++)
            {
                int temp = 0;
                occs.ForEach(num => temp += Math.Abs(num - i));
                if (temp < penalty)
                {
                    penalty = temp;
                }
            }

            return penalty;
        }

        static DDRes dedup(string s)
        {
            DDRes woot = new DDRes();
            StringBuilder res = new StringBuilder();
            char? temp = null;
            int count = 0;
            List<int> occurences = new List<int>();

            s.ToList().ForEach(c => {
                if (c != temp)
                {
                    if (count > 0)
                    {
                        occurences.Add(count);
                    }
                    res.Append(c);
                    count = 0;
                }
                temp = c;
                count++;
            });
            occurences.Add(count);

            woot.word = res.ToString();
            woot.occurences = occurences;

            return woot;
        }
    }
}
