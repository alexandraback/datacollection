using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace GCJ.P3
{
    class Program
    {
        static int Solve(List<Tuple<int, int>> lines, int pos, bool[] fake, bool[] originals, bool[] originals2)
        {
            if(pos >= lines.Count)
            {
                int res = 0;
                for(int i = 0; i < lines.Count; ++i)
                {
                    if(fake[i])
                    {
                        if(originals[lines[i].Item1] && originals2[lines[i].Item2])
                        {
                            res++;
                        }
                        else
                        {
                            return 0;
                        }
                    }

                }
                return res;
            }

            var l = lines[pos];
            bool oldA = originals[l.Item1];
            bool oldB = originals2[l.Item2];

            int r1 = 0;
            //if (oldA && oldB)
            {
                fake[pos] = true;
                r1 = Solve(lines, pos + 1, fake, originals, originals2);
                fake[pos] = false;
            }

            originals[l.Item1] = true;
            originals2[l.Item2] = true;

            var r2 = Solve(lines, pos + 1, fake, originals, originals2);

            originals[l.Item1] = oldA;
            originals2[l.Item2] = oldB;


            return Math.Max(r1, r2);
        }


        static void Main(string[] args)
        {
            var root = @"C:\projects\comp\gcj\p3\";


            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            IEnumerator<string> scanner = input.AsEnumerable<string>().GetEnumerator();
            scanner.MoveNext();
            long numCases = long.Parse(scanner.Current);


            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                long N = long.Parse(scanner.Current);
                int wi = 0;
                Dictionary<string, int> words = new Dictionary<string, int>();
                var lines = new List<Tuple<int, int>>();
                for (int i = 0; i < N; ++i)
                {
                    scanner.MoveNext();
                    var tok = scanner.Current.Split(new char[] { ' ' });
                    if(!words.ContainsKey(tok[0]))
                    {
                        words.Add(tok[0], wi);
                        wi++;
                    }

                    if (!words.ContainsKey(tok[1]))
                    {
                        words.Add(tok[1], wi);
                        wi++;
                    }
                    lines.Add(Tuple.Create(words[tok[0]], words[tok[1]]));
                }

                var res = Solve(lines, 0, new bool[N], new bool[wi * 3], new bool[wi * 3]);


                output.WriteLine("Case #{0}: {1}", nc + 1, res);
                Console.WriteLine("Case #{0}: {1}", nc + 1, res);
            }

            output.Close();

            string readOut = File.ReadAllText(root + "out.txt");
            string pOut = File.ReadAllText(root + "outP.txt");

            if (readOut.Equals(pOut))
            {
                Console.WriteLine("Match found");
            }
            else
            {
                Console.WriteLine("Match not found");
                Console.WriteLine("v1 is: {0}\nv2 is: {1}", readOut, pOut);
            }
        }
    }
}
