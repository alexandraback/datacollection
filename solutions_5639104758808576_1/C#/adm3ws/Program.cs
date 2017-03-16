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
            var root = @"D:\gcj\p1\";

            string[] input = System.IO.File.ReadAllLines(root + "small.txt");
            StreamWriter output = new StreamWriter(root + "out.txt");
            long numCases = Int32.Parse(input[0]);
            int ln = 1;
            for(long nc = 0; nc < numCases; ++nc)
            {
                string vals = input[ln++].Split(' ')[1];
                int curTotal = 0;
                int counter = 0;
                int friendsAdded = 0;
                foreach (char c in vals.ToCharArray())
                {
                    int val = (int)(c - '0');
                    curTotal += val;
                    counter++;
                    if (curTotal < counter)
                    {
                        if (curTotal != counter - 1)
                        {
                            throw new Exception("assert");
                        }
                        friendsAdded++;
                        curTotal++;
                    }
                }


                output.WriteLine("Case #{0}: {1}", nc + 1, friendsAdded);
                Console.WriteLine("Case #{0}: {1}", nc + 1, friendsAdded);
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
