using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamQ22
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
                        int result = 0;
                        string[] inputs = sr.ReadLine().Split(new char[] { ' ' });
                        long a = long.Parse(inputs[0]);
                        long b = long.Parse(inputs[1]);
                        long k = long.Parse(inputs[2]);

                        for (long i = 0; i < a; i++)
                        {
                            for (long j = 0; j < b; j++)
                            {
                                long res = (i & j);

                                if (res < k)
                                {
                                    //Console.WriteLine("i={0}, j={1}, i&j={2}, k={3}", i, j, i & j, k);
                                    result++;
                                }
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
