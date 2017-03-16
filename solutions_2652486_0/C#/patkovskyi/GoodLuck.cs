namespace GoodLuck
{
    using System;
    using System.Collections.Generic;
    using System.IO;
    using System.Linq;

    class GoodLuck
    {
        private static IEnumerable<int> GetFactors(int x, int factorLimit)
        {
            for (int i = 2; i <= factorLimit && x > 1; i++)
            {
                while (x % i == 0)
                {
                    yield return i;
                    x /= i;
                }
            }

            if (x != 1)
            {
                throw new Exception();
            }
        }

        private static int Guess(int[] set, int n, int m)
        {
            var factorDic = new Dictionary<int, int>();            

            foreach (int t in set)
            {
                foreach (var f in GetFactors(t, m))
                {
                    if (factorDic.ContainsKey(f))
                    {
                        factorDic[f] = factorDic[f] + 1;
                    }
                    else
                    {
                        factorDic.Add(f, 1);
                    }
                }                
            }

            if (factorDic.Count == 0)
            {
                factorDic.Add(2, 1);
            }
            
            while (factorDic.Count < n)
            {
                if (factorDic.Any(t => t.Value > 2 && !factorDic.ContainsKey(t.Key * t.Key)))
                {
                    int next = factorDic.First(t => t.Value > 2 && !factorDic.ContainsKey(t.Key * t.Key)).Key;
                    factorDic.Add(next * next, 1);
                }
                else
                {
                    break;
                }
            }            

            int res = 0;
            for (int i = 0; i < n; i++)
            {
                res = res * 10 + factorDic.ElementAt(i % factorDic.Count).Key;
            }

            return res;
        }

        static void Main(string[] args)
        {
            var inStream = File.OpenText("C-small-1-attempt1.in");
            var outStream = new StreamWriter("C-small-1-attempt1.out");
            Console.SetIn(inStream);
            Console.SetOut(outStream);

            int cases = int.Parse(Console.ReadLine());
            
            for (int tt = 1; tt <= cases; tt++)
            {
                Console.WriteLine("Case #1:");
                string[] rnmk = Console.ReadLine().Split(' ');
                int r = int.Parse(rnmk[0]);
                int n = int.Parse(rnmk[1]);
                int m = int.Parse(rnmk[2]);
                int k = int.Parse(rnmk[3]);
                int[][] sets = new int[r][];
                for (int i = 0; i < r; i++)
                {
                    sets[i] = Console.ReadLine().Split(' ').Select(int.Parse).ToArray();
                    int guess = Guess(sets[i], n, m);
                    Console.WriteLine(guess);
                }                
            }

            inStream.Close();
            outStream.Close();

            //string expected = File.ReadAllText("TestResult.txt");
            //string actual = File.ReadAllText("Out.txt");
            //if (expected != actual) throw new Exception();
        }
    }
}
