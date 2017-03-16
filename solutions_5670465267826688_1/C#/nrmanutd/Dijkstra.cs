using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJamSolutions
{
    class Dijkstra
    {
        private const string Yes = "YES";
        private const string No = "NO";

        private Dictionary<string, string> _cache = new Dictionary<string, string>();
        private Dictionary<string, string> _rules = new Dictionary<string, string>
                        {
                            {"i", "i"},
                            {"j", "j"},
                            {"k", "k"},
                            {"ii", "-1"},
                            {"ij", "k"},
                            {"ik", "-j"},
                            {"ji", "-k"},
                            {"jj", "-1"},
                            {"jk", "i"},
                            {"ki", "j"},
                            {"kj", "-i"},
                            {"kk", "-1"},
                            
                            {"i-i", "1"},
                            {"i-j", "-k"},
                            {"i-k", "j"},
                            {"j-i", "k"},
                            {"j-j", "1"},
                            {"j-k", "-i"},
                            {"k-i", "-j"},
                            {"k-j", "i"},
                            {"k-k", "1"},

                            {"-i1", "-i"},
                            {"-j1", "-j"},
                            {"-k1", "-k"},

                            {"-1i", "-i"},
                            {"-1j", "-j"},
                            {"-1k", "-k"},

                            {"i-1", "-i"},
                            {"j-1", "-j"},
                            {"k-1", "-k"},

                            {"-i-1", "i"},
                            {"-j-1", "j"},
                            {"-k-1", "k"},

                            {"-ii", "1"},
                            {"-ij", "-k"},
                            {"-ik", "j"},
                            {"-ji", "k"},
                            {"-jj", "1"},
                            {"-jk", "-i"},
                            {"-ki", "-j"},
                            {"-kj", "i"},
                            {"-kk", "1"},

                            {"-i-i", "-1"},
                            {"-i-j", "k"},
                            {"-i-k", "-j"},
                            {"-j-i", "-k"},
                            {"-j-j", "-1"},
                            {"-j-k", "i"},
                            {"-k-i", "j"},
                            {"-k-j", "-i"},
                            {"-k-k", "-1"},
                            
                            {"1i", "i"},
                            {"1j", "j"},
                            {"1k", "k"},

                            {"i1", "i"},
                            {"j1", "j"},
                            {"k1", "k"},
                        };

        public void Solve(string fileName)
        {
            var data = LoadData(fileName);
            var result = new string[data.Count];

            for(int i = 0; i < data.Count; ++i)
            {
                Console.WriteLine("Test# {0}", i);
                result[i] = SolveInternally(data[i]);
            }

            WriteSolution(result, fileName);
        }

        private string SolveInternally(string d)
        {
            var v = CalculateValueOfString(d);
            var sv = CalculateValueOfString("iii" + v + "kkk");

            if (sv != "j")
                return No;

            var curCh = "";
            int startIndex = -1;
            for(int i = 0; i < d.Length; ++i)
            {
                curCh = curCh + d[i];
                curCh = _rules[curCh];
                if (curCh == "i")
                {
                    startIndex = i;
                    break;
                }
            }

            int finishIndex = -1;
            curCh = "";
            for (int i = d.Length - 1; i >= 0; --i)
            {
                curCh = d[i] + curCh;
                curCh = _rules[curCh];
                if (curCh == "k")
                {
                    finishIndex = i;
                    break;
                }
            }

            if(startIndex != -1 && finishIndex != -1 && startIndex < finishIndex)
            {
                return Yes;
            }

            return No;
        }

        private string CalculateValueOfString(string d)
        {
            var curCh = "";
            for (int i = 0; i < d.Length; ++i)
            {
                if(d[i] == '-')
                {
                    curCh = curCh + "-";
                    continue;
                }

                curCh = curCh + d[i];
                curCh = _rules[curCh];
            }

            return curCh;
        }

        private List<string> LoadData(string fileName)
        {
            var res = new List<string>();
            using (var f = new StreamReader(fileName))
            {
                var testCases = int.Parse(f.ReadLine());
                for (int i = 0; i < testCases; ++i)
                {
                    var curLine = f.ReadLine();
                    var repeats = long.Parse(curLine.Split(' ')[1]);

                    var line = f.ReadLine();
                    if(repeats > 12)
                    {
                        repeats = 12 + ((repeats - 12) % 4);
                    }
                                        
                    var resultLine = "";
                    for (int j = 0; j < repeats; ++j)
                        resultLine += line;
                    
                    res.Add(resultLine);
                }
            }

            return res;
        }

        private void WriteSolution(string[] result, string fileName)
        {
            fileName = fileName.Replace(".in", ".out");
            using (var o = new StreamWriter(fileName))
            {
                for (int i = 0; i < result.Length; ++i)
                {
                    if (i < result.Length - 1)
                        o.WriteLine("Case #{0}: {1}", i + 1, result[i]);
                    else
                        o.Write("Case #{0}: {1}", i + 1, result[i]);
                }

            }
        }
    }
}
