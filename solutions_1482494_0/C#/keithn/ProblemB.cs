using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJamRound1A
{
    public class ProblemB
    {

        

        public void Execute(string[] args)
        {

            using (StreamReader read = new StreamReader(File.OpenRead(args[0])))
            {
                int numCases = int.Parse(read.ReadLine());

                for (int i = 0; i < numCases; i++)
                {

                    List<Tuple<int, int, int>> ls = new List<Tuple<int, int, int>>();

                    int numLevels = int.Parse(read.ReadLine());

                    for (int j = 0; j < numLevels; j++)
                    {
                        string[] lines = read.ReadLine().Split(' ');

                        ls.Add(Tuple.Create(int.Parse(lines[0]), 1, j));
                        ls.Add(Tuple.Create(int.Parse(lines[1]), 2, j));
                    }

                    int? answer = Solve(ls);

                    string sanswer = "Too Bad";

                    if (answer.HasValue)
                    {
                        sanswer = answer.Value.ToString();
                    }

                    Console.WriteLine("Case #" + (i + 1) + ": " + sanswer);

                }

            }

            //List<Tuple<int, int, int>> ls = new List<Tuple<int, int, int>>();

            //ls.Add(Tuple.Create(0, 1, 0));
            //ls.Add(Tuple.Create(0, 1, 1));
            //ls.Add(Tuple.Create(1, 2, 0));
            //ls.Add(Tuple.Create(2, 2, 1));

            //int? answer = Solve(ls);
            //Console.WriteLine(answer);


        }

        // greedy.  simple.
        public int? Solve(List<Tuple<int, int, int>> ls)
        {

            int starsSoFar = 0;
            int totalPlayed = 0;
            bool solved = false;

            List<int> levelsHit = new List<int>();

            while (ls.Count > 0)
            {

                var nextLevel =
                    ls.Where(l => l.Item1 <= starsSoFar).OrderByDescending(l => l.Item2).ThenByDescending(l=>levelsHit.Contains(l.Item3)).FirstOrDefault();

                if (nextLevel == null)
                {
                    return (int?)null;
                }

                levelsHit.Add(nextLevel.Item3);

                totalPlayed++;
                ls.Remove(nextLevel);
                int newStars = nextLevel.Item2;
                starsSoFar += newStars;

                var otherl = ls.Where(l => l.Item3 == nextLevel.Item3).FirstOrDefault();

                if (otherl != null)
                {
                    if (otherl.Item2 == 1)
                    {
                        // already completed the one star level
                        ls.Remove(otherl);
                    }
                    else if (otherl.Item2 == 2)
                    {
                        var newotherl = Tuple.Create(otherl.Item1, 1, otherl.Item3);
                        ls.Remove(otherl);
                        ls.Add(newotherl);
                    }
                }

                //ls.Remove(nextLevel);

            }

            return totalPlayed;
            

        }


    }
}
