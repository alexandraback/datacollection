using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Round1B_3
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = new StreamReader(@"C:\Users\Administrator\Documents\CodeJam\r1_3_2.txt");
            var outFile = new StreamWriter(@"C:\Users\Administrator\Documents\CodeJam\r1_3_2Out.txt");
            var total = long.Parse(file.ReadLine());

            for (long i = 1; i <= total; i++)
            {
                var lineSplit = file.ReadLine().Split(' ');
                var zipCodes = new List<int>();
                var races = new List<Tuple<int, int>>();

                var N = long.Parse(lineSplit[0]);
                var M = long.Parse(lineSplit[1]);

                for (int n = 0; n < N; n++)
                {
                    zipCodes.Add(int.Parse(file.ReadLine()));
                }

                var citiesList = new HashSet<int>();
                for (int m = 0; m < M; m++)
                {
                    var cities = file.ReadLine().Split(' ');
                    races.Add(Tuple.Create(int.Parse(cities[0]), int.Parse(cities[1])));
                    races.Add(Tuple.Create(int.Parse(cities[1]), int.Parse(cities[0])));
                    citiesList.Add(int.Parse(cities[0]));
                    citiesList.Add(int.Parse(cities[1]));
                }

                
                var frontier = new List<int>();
                var minCity = zipCodes.IndexOf(zipCodes.Min())+1;
                var result = zipCodes[minCity-1].ToString();
                citiesList.Remove(minCity);
                frontier.Add(minCity);

                while (citiesList.Count > 0 && frontier.Count > 0)
                {
                    var currentCity = frontier.Last();
                    var candidates = races.Where(x => (x.Item1 == currentCity) && citiesList.Contains(x.Item2)).Select(x => x.Item2).ToList();
                    if (candidates.Count == 0)
                    {
                        frontier.Remove(currentCity);
                    }
                    else
                    {
                        var minZipCode = candidates.Min(x => zipCodes[x-1]);
                        var newCity = zipCodes.IndexOf(minZipCode)+1;
                        frontier.Add(newCity);
                        citiesList.Remove(newCity);
                        result += minZipCode;
                    }
                }

                outFile.WriteLine(string.Format("Case #{0}: {1}", i, result));

            }

            file.Close();
            outFile.Close();
        }
    }
}
