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
            var root = @"C:\projects\comp\gcj\p1\";


            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long[] data = input.SelectMany(x => x.Split(' ').Select(y => Int64.Parse(y))).ToArray();
            IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
            scanner.MoveNext();
            long numCases = scanner.Current;
            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                long N = (int)scanner.Current;

                bool[] seen = new bool[10];

                long m = 1;

                long sc = 0;
                long curN = N;
                while (sc < 10)
                {
                    curN = N * m;
                    if (curN == 0)
                    {
                        break;
                    }
                    if (m > 100000)
                    {
                        Console.WriteLine("Number {0} is bad", curN);
                        break;
                    }
                    m++;

                    foreach (var c in curN.ToString())
                    {
                        if (!seen[(int)c - '0'])
                        {
                            seen[(int)c - '0'] = true;
                            sc++;
                        }
                    }
                }

                output.WriteLine("Case #{0}: {1}", nc + 1, sc == 10L ? curN.ToString() : "INSOMNIA");
                Console.WriteLine("Case #{0}: {1}", nc + 1, sc == 10L ? curN.ToString() : "INSOMNIA");
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
