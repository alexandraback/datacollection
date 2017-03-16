using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;

namespace GoogleCodeJam1
{
    class Program
    {
        private const string InputFilePath = @"C:\temp\input.txt";
        private const string OutputFilePath = @"C:\temp\output.txt";

        static void Main(string[] args)
        {
            Parser.ParseAndSolve(InputFilePath, OutputFilePath);

            Console.ReadKey();
        }

    }

    class Parser
    {
        private static Random _rand = new Random(System.DateTime.Now.Millisecond);

        public static void ParseAndSolve(string inputPath, string outputPath)
        {
            StreamReader input = new StreamReader(inputPath);
            StreamWriter output = new StreamWriter(outputPath);

            /* Parse number of cases */
            int numberOfCases;
            if (!int.TryParse(input.ReadLine(), out numberOfCases))
            {
                throw new Exception("Could not parse number of cases.");
            }

            /* Parse all cases and solve */
            for (long i = 0; i < numberOfCases; ++i)
            {
                string line = input.ReadLine();
                long r = long.Parse(line.Split(' ')[0]);
                long n = long.Parse(line.Split(' ')[1]);
                long m = long.Parse(line.Split(' ')[2]);
                long k = long.Parse(line.Split(' ')[3]);


                Console.WriteLine("Case #1:");
                output.WriteLine("Case #1:");

                var products = new long[k];

                for (long j = 0; j < r; j++)
                {
                    line = input.ReadLine();
                    var tokens = line.Split(' ');
                    for (long p = 0; p < k; p++)
                    {
                        products[p] = long.Parse(tokens[p]);
                    }

                    string result = Guess(r, n, m, k, products);
                    Console.WriteLine(result);
                    output.WriteLine(result);
                }

            }


            input.Close();
            output.Close();
        }

        private static string Guess(long r, long n, long m, long k, long[] products)
        {
            Stopwatch sw = new Stopwatch();
            sw.Start();

            long[] generated = new long[n];
            while (sw.ElapsedMilliseconds < 15)
            {
                GenerateRandomSet(generated, m);

                IList<long> allProductsPossible = new List<long>();

                // generate all possible products
                /*foreach (var subset in SubSetsOf(generated))
                {
                    allProductsPossible.Add(ProductOf(subset));
                }*/

                // check if all of the products are created from this random set
                if(AllInside(products, generated, n))
                {
                    return SolutionOf(generated);
                }
            }



            return Blank(n);
        }

        private static string Blank(long n)
        {
            long[] blankSol = new long[n];
            for (int i = 0; i < n; i++ )
            {
                blankSol[i] = 2;
            }
            return SolutionOf(blankSol);
        }

        private static string SolutionOf(long[] generated)
        {
            string res = "";
            foreach (long g in generated)
            {
                res += g;
            }
            return res;
        }

        private static bool AllInside(long[] products, IList<long> liste, long N)
        {
            IList<long> allProducts = new List<long>();
            for (int i = 0; i < Math.Pow(2, N+1); i++)
            {
                int val = i;
                int n = 0;
                long prod = 1;
                while(val != 0)
                {
                    val = val >> 1;
                    if(val %2 == 1)
                    {
                        prod *= liste[n];
                    }
                    n++;
                }
                allProducts.Add(prod);
            }

                foreach (long val in products)
                {
                    if (!allProducts.Contains(val))
                    {
                        return false;
                    }
                }
            return true;
        }

        private static long ProductOf(IEnumerable<long> subset)
        {
            return subset.Aggregate<long, long>(1, (current, l) => current*l);
        }

        private static long[] GenerateRandomSet(long[] tab, long m)
        {
            for (int i = 0; i < tab.Count(); ++i)
            {
                tab[i] = _rand.Next(2, (int) (m + 1));
            }
            return tab;
        }

        public static IEnumerable<IEnumerable<T>> SubSetsOf<T>(IEnumerable<T> source)
        {
            if (!source.Any())
                return Enumerable.Repeat(Enumerable.Empty<T>(), 1);

            var element = source.Take(1);

            var haveNots = SubSetsOf(source.Skip(1));
            var haves = haveNots.Select(set => element.Concat(set));

            return haves.Concat(haveNots);
        }
    }
}
