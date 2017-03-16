using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam3
{
    class Program
    {
        static readonly string small = "small.txt";
        static readonly string large = "large.txt";
        static void Main(string[] args)
        {
            Problem(small);
        }

        static void Problem(string file)
        {
            using (var fsi = new FileStream(file, FileMode.Open))
            {
                using (var sr = new StreamReader(fsi))
                {
                    var fspl = file.Split('.');
                    using (var fso = new FileStream(fspl[0] + "-output." + fspl[1], FileMode.Create))
                    {
                        using (var sw = new StreamWriter(fso))
                        {
                            int T = int.Parse(sr.ReadLine());
                            for (int i = 1;i <= T; i++)
                            {
                                sw.WriteLine("Case #{0}: {1}", i, findFakers(sr));
                            }
                        }
                    }
                }
            }
        }

        static int findFakers(StreamReader sr)
        {
            int N = int.Parse(sr.ReadLine());
            int fakers = 0;
            Dictionary<string, List<string>> first = new Dictionary<string, List<string>>();
            Dictionary<string, List<string>> second = new Dictionary<string, List<string>>();
            List<string> subject = new List<string>();
            for (int j = 0; j < N; j++)
            {
                var line = sr.ReadLine().Split(' ');
                subject.Add(line[0] + " " + line[1]);
                if (!first.ContainsKey(line[0]))
                    first[line[0]] = new List<string>();
                if (!second.ContainsKey(line[1]))
                    second[line[1]] = new List<string>();
                first[line[0]].Add(line[1]);
                second[line[1]].Add(line[0]);
            }

            fakers = findFakers(first, second, subject, 0);

            return fakers;
        }

        static int findFakers(Dictionary<string, List<string>> first, Dictionary<string, List<string>> second, List<string> subject, int start)
        {
            int fakers = 0;
            for (int i = start; i < subject.Count; i++)
            {
                int fak = 0;
                var sub = subject[i].Split(' ');
                // it is not a fake, we continue.
                if (first[sub[0]].Count == 1 || second[sub[1]].Count == 1) continue;
                first[sub[0]].Remove(sub[1]);
                second[sub[1]].Remove(sub[0]);
                fak = findFakers(first, second, subject, i + 1) + 1;
                first[sub[0]].Add(sub[1]);
                second[sub[1]].Add(sub[0]);
                if (fak > fakers) fakers = fak;
            }

            return fakers;
        }
    }
}
