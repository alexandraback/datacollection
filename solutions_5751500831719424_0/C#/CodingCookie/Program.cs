using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2014_1B_A
{
    class Program
    {
        const string root = @"B:\Users\Justin\Desktop\Temp\Google Code\2014_1B_A\";

        static void Main(string[] args)
        {
            var reader = new StreamReader(root + "in.txt");
            var writer = new StreamWriter(root + "out.txt", false);

            int numCases = int.Parse(reader.ReadLine());

            for (int cc = 1; cc <= numCases; cc++)
            {
                int n = int.Parse(reader.ReadLine());
                List<string> strings = new List<string>();
                for (int i = 0; i < n; i++)
                {
                    strings.Add(reader.ReadLine().Trim());
                }

                int totalDistance = 0;
                while (strings[0].Length > 0)
                {
                    int[] vector = Step(strings, strings[0][0]);
                    if (vector == null)
                    {
                        // unsolvable
                        totalDistance = -1;
                        break;
                    }
                    
                    int min = vector.Min();
                    int max = vector.Max();

                    int runningMinDist = int.MaxValue;
                    for (int j = min; j <= max; j++)
                    {
                        int subtotal = 0;
                        for (int vi = 0; vi < vector.Length; vi++)
                        {
                            subtotal += Math.Abs(vector[vi] - j);                            
                        }
                        if (subtotal < runningMinDist)
                            runningMinDist = subtotal;
                    }

                    totalDistance += runningMinDist;
                }

                bool found = true;
                foreach (var str in strings)
                {
                    if (str != string.Empty)
                        found = false;
                }

                writer.WriteLine("Case #{0}: {1}", cc, !found || totalDistance == -1 ? "Fegla Won" : totalDistance.ToString());

            }
            writer.Close();
        }

        public static int[] Step(List<string> strings, char collapsingLetter)
        {
            var distance = new List<int>();
            for (int j = 0; j < strings.Count; j++)
            {
                var newString = strings[j].TrimStart(collapsingLetter);
                int dist = strings[j].Length - newString.Length -1;
                if (dist == -1)
                    return null;
                distance.Add(dist);
                strings[j] = newString;
            }
            return distance.ToArray();
        }
    }
}
