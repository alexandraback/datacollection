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

            string input = "100\n2 3 2\n1 1 1\n2 1 2\n3 2 3\n100 1 100\n10 8 10\n48 5 48\n11 11 11\n6 15 6\n74 8 74\n12 10 12\n3 37 3\n43 4 43\n1 74 1\n3 1 3\n15 4 15\n73 2 73\n100 3 100\n43 11 43\n14 7 14\n2 10 2\n21 13 21\n17 11 17\n3 4 3\n68 4 68\n1 4 1\n4 3 4\n54 3 54\n34 11 34\n82 1 82\n5 5 5\n2 59 2\n100 6 100\n1 100 1\n51 9 51\n87 7 87\n1 2 1\n10 5 10\n34 10 34\n97 2 97\n4 4 4\n11 14 11\n51 5 51\n54 1 54\n4 1 4\n1 26 1\n89 4 89\n11 5 11\n29 6 29\n10 18 10\n42 8 42\n2 33 2\n9 9 9\n3 7 3\n59 6 59\n78 1 78\n34 8 34\n17 5 17\n51 10 51\n54 10 54\n35 4 35\n2 47 2\n25 5 25\n15 9 15\n6 21 6\n3 3 3\n2 4 2\n100 4 100\n4 2 4\n2 35 2\n30 10 30\n34 3 34\n50 6 50\n2 18 2\n58 2 58\n12 2 12\n100 9 100\n6 2 6\n2 53 2\n12 6 12\n2 52 2\n8 9 8\n28 8 28\n68 5 68\n90 5 90\n29 1 29\n18 5 18\n1 32 1\n26 7 26\n66 9 66\n4 29 4\n80 8 80\n29 12 29\n1 48 1\n51 3 51\n2 2 2\n1 6 1\n100 2 100\n1 3 1\n69 8 69\n";
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
