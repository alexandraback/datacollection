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
            var root = @"C:\projects\comp\gcj\p1\";


            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            IEnumerator<string> scanner = input.AsEnumerable<string>().GetEnumerator();
            scanner.MoveNext();
            long numCases = long.Parse(scanner.Current);

            
            for (long nc = 0; nc < numCases; ++nc)
            {
                scanner.MoveNext();
                string S = scanner.Current;
                int[] counts = new int[30];

                int[] res = new int[10];

                foreach(char c in S)
                {
                    counts[c - 'A']++;
                }

                int[] orders = new int[] { 0, 2, 4, 5, 6, 7, 1, 3, 8, 9 };
                int[] letters = new int[] { 'Z', 'W', 'U', 'F', 'X', 'V', 'O', 'R', 'T', 'E'  };
                string[] strings = new string[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
                for (int i = 0; i < letters.Length; ++i) letters[i] -= 'A';

                for(int i = 0; i < orders.Length; ++i)
                {
                    int n = orders[i];
                    int l = letters[i];
                    int nums = counts[l];
                    res[n] += nums;

                    foreach(var c in strings[n])
                    {
                        if(counts[c -'A'] < nums)
                        {
                            throw new Exception("assert");
                        }
                        counts[c - 'A'] -= nums;
                    }

                }

                if(counts.Any(x => x != 0))
                {
                    throw new Exception("assert");
                }

                StringBuilder b = new StringBuilder();
                for(int i = 0; i < 10; ++i)
                {
                    for(int j = 0; j < res[i]; ++j)
                    {
                        b.Append(i);
                    }
                }


                output.WriteLine("Case #{0}: {1}", nc + 1, b.ToString() );
                Console.WriteLine("Case #{0}: {1}", nc + 1, b.ToString() );
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
