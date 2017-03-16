using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace GCJ.P1
{
    class Program
    {
        public static string Reverse(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }

        static void Main(string[] args)
        {
            var root = @"D:\gcj\p1\";

            long[] l = new long[16];
            l[1] = 9;

            for (long i = 2; i < 16; ++i)
            {
                long half = (i) / 2;
                long steps = 1;

                long exp = 1;
                for (int j = 0; j < half; ++j)
                {
                    exp *= 10;
                }

                steps += (exp - 1) * 2;

                if ((i + 1) / 2 != half)
                {
                    long bHalf = (i + 1) / 2;
                    exp = 1;
                    for (int j = 0; j < bHalf; ++j)
                    {
                        exp *= 10;
                    }
                    steps += (exp * 9) / 10;
                }

                l[i] = steps;

                Console.WriteLine("For {0} steps are {1}", i, l[i]);
            }

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            int[] data = input.SelectMany(x => x.Split(' ').Select(y => Int32.Parse(y))).ToArray();
            IEnumerator<int> scanner = data.AsEnumerable<int>().GetEnumerator();
            scanner.MoveNext();
            int numCases = scanner.Current;
            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                long n = (long)scanner.Current;

                int numDig = n.ToString().Length;
                long res = 0;

                HashSet<long> vis = new HashSet<long>();

                Queue<Tuple<long, long>> queue = new Queue<Tuple<long, long>>();
                queue.Enqueue(new Tuple<long, long>(1, 1));
                vis.Add(1);

                while (queue.Count > 0)
                {
                    var cur = queue.Dequeue();
                    if (cur.Item1 == n)
                    {
                        res = cur.Item2;
                        break;
                    }

                    long curRev = long.Parse(Reverse(cur.Item1.ToString()));
                    if (!vis.Contains(curRev))
                    {
                        queue.Enqueue(new Tuple<long, long>(curRev, cur.Item2 + 1));
                        vis.Add(curRev);
                    }
                    long curInc = cur.Item1+1;
                    if (!vis.Contains(curInc) && curInc.ToString().Length <= numDig)
                    {
                        queue.Enqueue(new Tuple<long, long>(curInc, cur.Item2 + 1));
                        vis.Add(curInc);
                    }
                }

                

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
