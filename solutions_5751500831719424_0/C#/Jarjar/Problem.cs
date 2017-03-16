using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamQ21
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
                            int lines = Int32.Parse(sr.ReadLine()); // Nb of lines in the scenario
                            List<string> st = new List<string>();
                            List<string> stSimple = new List<string>();
                            string r = sr.ReadLine();
                            st.Add(r);
                            r = simplify(r);
                            for (int i = 1; i < lines; i++)
                            {
                                string cas = sr.ReadLine();
                                st.Add(cas);
                                if (simplify(cas) != r)
                                {
                                    result = "Fegla Won";
                                    break;
                                }

                                int counting = target(st[0], st[1]); // Small case, N=2;
                                result = counting.ToString();
                            }


                            sw.WriteLine("Case #{0}: {1}", sc, result);
                        }
                        sw.Flush();
                    }

                }
            }

            // We can go from a to b
            int target(string a, string b)
            {
                int count = 0;
                int i = 0;
                while (a != b)
                {
                    if (i == a.Length)
                    {
                        if (b[i] == a[i - 1])
                        {
                            b = b.Remove(i, 1);
                            count++;
                            continue;
                        }
                    }
                    if (i == b.Length)
                    {
                        if (a[i] == b[i - 1])
                        {
                            a = a.Remove(i, 1);
                            count++;
                            continue;
                        }
                    }
                    if (a[i] == b[i])
                    {
                        i++;
                        continue;
                    }
                    if (a[i] == a[i - 1])
                    {
                        a = a.Remove(i, 1);
                        count++;
                        continue;
                    }
                    if (b[i] == b[i - 1])
                    {
                        b = b.Remove(i, 1);
                        count++;
                        continue;
                    }
                    

                }

                return count;
            }

            string simplify(string input)
            {
                string output = string.Empty;
                char last = ' ';
                for (int i = 0; i < input.Length; i++)
                {
                    if (last == input[i])
                        continue;
                    last = input[i];
                    output += input[i];
                }
                return output;
            }

        
    }
}
