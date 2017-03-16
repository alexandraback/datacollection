using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Deceitful_War {
    class Program {
        static void Main(string[] args) {
            string filename = @"c:\users\jshea\desktop\D-small-attempt0.in";
            if (args.Length >= 1) {
                filename = args[0].ToString();
            }

            using (StreamReader file = new System.IO.StreamReader(filename)) {
                int cases = Int32.Parse(file.ReadLine());
                for (int testCase = 0; testCase < cases; testCase++) {
                    try {
                        var result = String.Empty;

                        file.ReadLine();
                        var naomi = file.ReadLine().Split(' ').Select(d => Convert.ToDouble(d));
                        var ken = file.ReadLine().Split(' ').Select(d => Convert.ToDouble(d));

                        var fairWins = GetFairWins(naomi, ken);
                        var deceitfulWins = GetDeceitfulWins(naomi, ken);

                        result = String.Format("{0} {1}", deceitfulWins, fairWins);

                        Console.WriteLine("Case #{0}: {1}", testCase + 1, result);
                    } catch (Exception ex) {
                        Console.Write(ex.Message);
                    }
                }
            }
        }

        private static object GetDeceitfulWins(IEnumerable<double> naomi, IEnumerable<double> ken) {
            var wins = 0;

            var naomiSorted = naomi.OrderByDescending(d => d).ToList();
            var kenSorted = ken.OrderBy(d => d).ToList();


            while (naomiSorted.Count > 0) {
                var k_min = kenSorted.First();
                var k_max = kenSorted.Last();
                var n_min = naomiSorted.Last();
                var n_max = naomiSorted.First();
                if (n_max > k_max) {
                    wins++;

                    // if naomi will win, play his min, her lowest that will still beat him
                    naomiSorted.Remove(naomiSorted.Where(i => i > k_min).Min());
                    kenSorted.RemoveAt(0);

                } else {
                    // if naomi will lose, play her min, and his max
                    kenSorted.RemoveAt(kenSorted.Count - 1);
                    naomiSorted.RemoveAt(naomiSorted.Count - 1);
                }
            }


            return wins;
        }

        private static object GetFairWins(IEnumerable<double> naomi, IEnumerable<double> ken) {
            var wins = 0;

            var naomiSorted = naomi.OrderByDescending(d => d).ToList();
            var kenSorted = ken.OrderBy(d => d).ToList();

            while(naomiSorted.Count > 0) {
                var n = naomiSorted.Take(1).First();

                naomiSorted.RemoveAt(0);
                if (n > kenSorted.Last()) {
                    wins++;
                    kenSorted.RemoveAt(0);
                } else {
                    kenSorted.RemoveAt(kenSorted.Count - 1);
                }
            }

            return wins;
        }
    }
}
