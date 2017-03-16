using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamQ23
{
    public class Problem
    {
        public Problem()
        {
            var pathname = "Sample.txt";
            using (FileStream fs = new FileStream(pathname, FileMode.Open))
            {
                StreamReader sr = new StreamReader(fs);
                using (FileStream fsout = new FileStream(pathname + ".out", FileMode.Create))
                {
                    StreamWriter sw = new StreamWriter(fsout);
                    int caseScenario = Int32.Parse(sr.ReadLine()); // Nb de scenario
                    for (int sc = 1; sc <= caseScenario; sc++)
                    {
                        string result = string.Empty;
                        string[] inputs = sr.ReadLine().Split(new char[] { ' ' });
                        int n = int.Parse(inputs[0]);
                        int m = int.Parse(inputs[1]);

                        Dictionary<string, int> zipToTown = new Dictionary<string, int>();
                        Dictionary<int, string> TownToZip = new Dictionary<int, string>();
                        Dictionary<int, List<int>> voyage = new Dictionary<int, List<int>>();
                        for (int i = 1; i <= n; i++)
                        {
                            string zip = sr.ReadLine();
                            zipToTown[zip] = i;
                            TownToZip[i] = zip;
                        }

                        // set the voyage
                        for (int i = 0; i < m; i++)
                        {
                            string[] voys = sr.ReadLine().Split(new char[] { ' ' });
                            int from = int.Parse(voys[0]);
                            int to = int.Parse(voys[1]);
                            if (!voyage.ContainsKey(from))
                                voyage[from] = new List<int>();
                            if (!voyage.ContainsKey(to))
                                voyage[to] = new List<int>();
                            voyage[from].Add(to);
                            voyage[to].Add(from);
                        }

                        // identify first town : smaller zip
                        string startingZip = FindMinZip(zipToTown.Keys.ToList<string>());
                        // start the result : 
                        result = startingZip;
                        List<int> visitedTown = new List<int>();
                        int startingTown = zipToTown[startingZip];
                        int currentTown = startingTown;
                        // fill the starting town
                        visitedTown.Add(startingTown);
                        List<int> nextPossibleTown = new List<int>();
                        List<string> nextPossibleZip = new List<string>();
                        while (visitedTown.Count < n)
                        {
                            foreach (int c in voyage[currentTown])
                            {
                                if (!visitedTown.Contains(c) && !nextPossibleTown.Contains(c))
                                {
                                    nextPossibleTown.Add(c);
                                    nextPossibleZip.Add(TownToZip[c]);
                                }
                            }
                            string nextZip = FindMinZip(nextPossibleZip);
                            result += nextZip;
                            currentTown = zipToTown[nextZip];
                            visitedTown.Add(currentTown);
                            nextPossibleZip.Remove(nextZip);
                            nextPossibleTown.Remove(currentTown);
                        }
                        
                        sw.WriteLine("Case #{0}: {1}", sc, result);
                    }

                    sw.Flush();
                }

            }
        }

        public string FindMinZip(List<string> list)
        {
            list.Sort();

            return list[0];
        }

 
    }
}
