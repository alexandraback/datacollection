using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using KEY = System.Tuple<int, int>;

// The solution might use the C5 C# library, available at http://www.itu.dk/research/c5/

namespace GCJ
{
    class Program
    {
      


        static void Main(string[] args)
        {

            var root = @"C:\projects\comp\gcj\p2\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long numCases = long.Parse(input[0]);

            for (long nc = 0; nc < numCases; ++nc)
            {
                string s = input[nc + 1];
                bool[] v = new bool[s.Length];
                bool[] temps = new bool[s.Length];
                for (int i = 0; i < s.Length; ++i)
                {
                    if(s[i] == '+')
                    {
                        v[i] = true;
                    }
                }

                int endIndex = s.Length - 1;

                int numFlips = 0;

                while(endIndex >= 0)
                {
                    if(v[endIndex])
                    {
                        endIndex--;
                        continue;
                    }


                    if(v[0])
                    {
                        numFlips++;
                        int t = 0;
                        while(v[t+1])
                        {
                            t++;
                            continue;
                        }

                        for(int i = 0; i <= t; ++i)
                        {
                            v[i] = false;
                        }
                    }

                    numFlips++;
                    Array.Copy(v, temps, s.Length);

                    for(int i = 0; i <= endIndex; ++i)
                    {
                        temps[i] = !v[endIndex - i];
                    }

                    var tm = temps;
                    temps = v;
                    v = tm;
                }

                output.WriteLine("Case #{0}: {1}", nc + 1, numFlips);
                Console.WriteLine("Case #{0}: {1}", nc + 1, numFlips);
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
