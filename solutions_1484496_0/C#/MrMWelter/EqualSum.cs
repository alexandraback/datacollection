using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Dynamic;

namespace CodeJam0505
{
    class EqualSum
    {
        public static void equalsum(string[] args)
        {
            string inputFile = "C-small-attempt0.in";
            string outputFile = "C-small_result0.out";

            TextReader reader = new StreamReader(inputFile);
            TextWriter writer = new StreamWriter(outputFile);
            dynamic inputResult = new ExpandoObject();

            inputResult.TestCases = int.Parse(reader.ReadLine());
            inputResult.Cases = new List<dynamic>();

            for (int caseCount = 0; caseCount < inputResult.TestCases; caseCount++)
            {
                string line = reader.ReadLine();
                string[] words = line.Split(' ');
                int integercount = int.Parse(words[0]);

                int[]  integers = new int[integercount];

                for (int counter = 0; counter < integercount; counter++)
                {
                    integers[counter] = int.Parse(words[counter + 1]);
                }

                bool result = false;
                Random rand = new Random();
                int runs = 100000;
                for (int run = 0; run < runs; run++)
                {
                    int sumA = 0;
                    int sumB = 0;
                    List<int> ints = integers.ToList<int>();    
                    LinkedList<int> A = new LinkedList<int>();
                    LinkedList<int> B = new LinkedList<int>();

                    int index = rand.Next(ints.Count);
                    sumA += ints[index];
                    A.AddLast(ints[index]);
                    ints.RemoveAt(index);

                    while (sumA != sumB && ints.Count > 0)
                    {
                        index = rand.Next(ints.Count);

                        if (rand.NextDouble() > 0.5)
                        {
                            sumA += ints[index];
                            A.AddLast(ints[index]);
                        }
                        else
                        {
                            sumB += ints[index];
                            B.AddLast(ints[index]);
                        }

                        
                        ints.RemoveAt(index);
                    }

                    if (sumA == sumB)
                    {
                        result = true;
                        string sout = "Case #" + (caseCount + 1) + ":";

                        writer.WriteLine(sout);
                        Console.WriteLine(sout);

                        sout = string.Empty;
                        foreach (var item in A)
                        {
                            sout += " " + item;
                        }
                        writer.WriteLine(sout.Substring(1));
                        Console.WriteLine(sout.Substring(1));

                        sout = string.Empty;
                        foreach (var item in B)
                        {
                            sout += " " + item;
                        }
                        writer.WriteLine(sout.Substring(1));

                        Console.WriteLine(sout.Substring(1));
                        writer.Flush();
                        break;
                    }

                }

                //output:
                if (result == false)
                {
                    string sout = "Case #" + (caseCount + 1) + ": ";
                    writer.WriteLine(sout);
                    writer.WriteLine("Impossible");
                    Console.WriteLine(sout);
                    Console.WriteLine("Impossible");
                    writer.Flush();
                }
            }


            Console.ReadLine();

        }
    }
}
