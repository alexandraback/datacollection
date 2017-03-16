using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;


namespace QuialifyingRound1 {
    class Program
    {

        static void Main(string[] args) {

            string input = "100\n2 3 2\n1 1 1\n2 1 1\n2 1 2\n3 2 3\n57 1 55\n10 10 5\n4 2 2\n3 1 2\n100 3 34\n93 1 52\n80 8 9\n1 78 1\n25 11 22\n2 4 1\n100 4 25\n4 1 3\n4 29 1\n64 1 59\n89 6 77\n15 2 3\n92 8 89\n1 85 1\n10 5 1\n100 2 50\n46 9 40\n95 6 6\n4 3 1\n25 1 24\n100 1 1\n12 2 8\n4 3 2\n1 3 1\n5 6 2\n72 3 45\n31 2 21\n3 4 1\n98 6 2\n1 100 1\n1 20 1\n64 9 7\n2 2 1\n100 3 33\n3 1 3\n12 12 3\n1 28 1\n64 1 64\n100 9 12\n68 9 21\n25 12 3\n60 6 9\n10 5 2\n64 9 8\n9 15 1\n14 7 1\n2 3 1\n3 20 3\n1 4 1\n1 96 1\n1 2 1\n25 7 8\n3 3 1\n64 1 63\n14 7 2\n25 5 16\n26 7 5\n19 1 19\n2 59 1\n4 4 1\n100 2 49\n100 1 99\n71 5 61\n100 9 11\n48 9 35\n25 12 2\n3 27 2\n5 24 3\n10 18 1\n3 2 2\n100 1 100\n3 37 1\n56 10 6\n39 10 27\n100 3 85\n3 2 1\n91 2 61\n1 15 1\n25 1 25\n40 3 30\n22 12 20\n69 7 30\n100 4 24\n29 5 4\n4 2 1\n80 8 10\n4 1 4\n52 7 26\n1 29 1\n33 3 22\n10 10 6\n";
            char[] delimiterChars = { '\n' };
            string[] inputs = input.Split(delimiterChars);

            int numberOfCases = Int32.Parse(inputs[0]);

            for(int i = 1; i <= numberOfCases; i++) {
                char[] spaceDelimiterChars = { ' ' };
                string[] subinputs = inputs[i].Split(spaceDelimiterChars);
                int K = Int32.Parse(subinputs[0]);
                int C = Int32.Parse(subinputs[1]);
                int S = Int32.Parse(subinputs[2]);
                
                // first check whether its possible or not!
                if (S < (K + 1 - C))
                {
                    Console.Out.WriteLine("Case #" + i + ": IMPOSSIBLE");
                }
                else
                {
                    BigInteger firstNum = 0;
                    for (BigInteger j = 1; j < C && j < K; j++)
                    {
                        firstNum = K* firstNum + j;
                    }
                    firstNum += 1;


                    for (BigInteger j = K; j < C; j++)
                    {
                        firstNum = firstNum*K;
                    }

                    BigInteger numOfValuesToOutput = (K + 1 - C);
                    if (numOfValuesToOutput < 1)
                    {
                        numOfValuesToOutput = 1;
                    }


                    string output = "Case #" + i + ": ";
                    for (BigInteger j = firstNum; j < firstNum + numOfValuesToOutput; j++)
                    {
                        output += j + " ";
                    }
                    Console.Out.WriteLine(output);
                }


            }





        }
    }
}
