using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam2015Q1C_3
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
                        string[] lines = sr.ReadLine().Split(' ');
                        long C = long.Parse(lines[0]);
                        long D = long.Parse(lines[1]);
                        long V = long.Parse(lines[2]);
                        long result = 0;

                        var values = sr.ReadLine().Split(' ').ToArray().Select(s => long.Parse(s)).ToList<long>();

                        List<long> reached = new List<long>();
                        long[] val = new long[V + 1];

                        foreach (var v in values)
                        {
                            List<long> newReached = new List<long>();
                            foreach (var r in reached)
                            {
                                if (r + v > V)
                                    break;
                                if (val[r + v] == 0)
                                {
                                    newReached.Add(r + v);
                                    val[r + v] = 1;
                                }
                            }
                            if (val[v] == 0)
                            {
                                reached.Add(v);
                                val[v] = 1;
                            }
                            reached.AddRange(newReached);
                        }

                        for (int v = 1; v <= V; v++)
                        {
                            if (val[v] == 0)
                            {
                                result++;
                                List<long> newReached = new List<long>();
                                foreach (var r in reached)
                                {
                                    if (r + v > V)
                                        break;
                                    if (val[r + v] == 0)
                                    {
                                        newReached.Add(r + v);
                                        val[r + v] = 1;
                                    }
                                }
                                if (val[v] == 0)
                                {
                                    reached.Add(v);
                                    val[v] = 1;
                                }
                                reached.AddRange(newReached);
                                reached.Sort();
                            }
                        }

                        sw.WriteLine("Case #{0}: {1}", sc, result);
                    }
                    sw.Flush();
                }

            }
        }


    }
}
