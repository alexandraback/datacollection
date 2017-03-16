using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static string _folderPath = Directory.GetCurrentDirectory() + @"/../../Questions/";
        static string _question = "CookieClickerAlpha";
        static string _dataSize = "S";   // T, S or L q

        static void Main(string[] args)
        {
            var data = File.ReadAllLines(_folderPath + _question + "_" + _dataSize + ".in");

            using (var outFile = File.CreateText(_folderPath + _question + "_" + _dataSize + ".out"))
            {
                Action<string> dualWriter = line =>
                {
                    Console.WriteLine(line);
                    outFile.WriteLine(line);
                };

                solve(data, dualWriter);
            }

            Console.WriteLine("Done!");
            Console.Read();
        }

        static void solve(IList<string> lines, Action<string> writeLine)
        {
            int numQs = int.Parse(lines[0]);

            int at = 1;

            for (int q = 0; q < numQs; q++)
            {
                var seq = lines[at++].Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries).Select(s => double.Parse(s)).ToList();
                
                string answer = solve1(seq[0], seq[1], seq[2]);

                writeLine(string.Format("Case #{0}: {1}", q + 1, answer));
            }
        }

        private static string solve1(double farmCost, double farmEarn, double goal)
        {
            double slope = 2;
            double tSpent = 0;

            while (true)
            {
                var tToGoal = goal / slope;
                var tToFarm = farmCost / slope;

                if (tToGoal <= tToFarm)
                {
                    tSpent += tToGoal;
                    break;
                }
                else
                {
                    var tToGoalWithFarm = tToFarm + goal / (slope + farmEarn);

                    if (tToGoalWithFarm > tToGoal)
                    {
                        tSpent += tToGoal;
                        break;
                    }
                    else
                    {
                        tSpent += tToFarm;
                        slope += farmEarn;
                    }
                }
            }

            return tSpent.ToString();
        }
    }
}
