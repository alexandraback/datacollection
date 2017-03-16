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
     

        static void Main(string[] args)
        {
            var root = @"C:\projects\comp\gcj\p4\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long[] data = input.SelectMany(x => x.Split(' ').Select(y => Int64.Parse(y))).ToArray();
            IEnumerator<long> scanner = data.AsEnumerable<long>().GetEnumerator();
            scanner.MoveNext();
            long numCases = scanner.Current;
            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                long K = (int)scanner.Current;
                scanner.MoveNext();
                long C = (int)scanner.Current;
                scanner.MoveNext();
                long S = (int)scanner.Current;

                if(C * S >= K)
                {
                    long V = 0;
                    string res = "";
                    
                    while(V < K)
                    {
                        long P = V;
                        V++;
                        for(int i = 1; i < C; ++i)
                        {
                            long newPos = P * K;
                            if(V < K)
                            {
                                newPos += V;
                                V++;
                            }
                            P = newPos;
                        }
                        if(res.Length != 0)
                        {
                            res += " ";
                        }
                        res += (P+1).ToString();
                    }

                    output.WriteLine("Case #{0}: {1}", nc + 1, res);
                    Console.WriteLine("Case #{0}: {1}", nc + 1, res);
                }
                else
                {
                    output.WriteLine("Case #{0}: {1}", nc + 1, "IMPOSSIBLE");
                    Console.WriteLine("Case #{0}: {1}", nc + 1, "IMPOSSIBLE");
                }


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
