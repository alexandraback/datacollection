using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuialifyingRound1 {
    class Program {
        static void Main(string[] args)
        {

            string input = "100\n0\n1\n2\n11\n196\n84\n9\n179\n32\n97\n180\n74\n194\n58\n186\n152\n111\n26\n42\n20\n166\n182\n109\n143\n82\n150\n138\n79\n108\n90\n156\n73\n67\n7\n163\n123\n24\n200\n173\n198\n13\n124\n165\n141\n8\n159\n184\n167\n87\n151\n121\n125\n88\n114\n130\n40\n68\n93\n191\n115\n193\n94\n95\n35\n16\n162\n145\n41\n25\n5\n44\n171\n10\n128\n4\n72\n66\n183\n39\n185\n129\n65\n92\n33\n91\n60\n153\n187\n21\n30\n142\n133\n34\n140\n3\n56\n46\n6\n148\n119";
            char[] delimiterChars = { '\n' };
            string[] inputs = input.Split(delimiterChars);

            int numberOfCases = Int32.Parse(inputs[0]);

            for (int i = 1; i <= numberOfCases; i++)
            {
                int caseValue = Int32.Parse(inputs[i]);
                if (caseValue == 0)
                {
                    Console.Out.WriteLine("Case #" + i + ": INSOMNIA");
                }
                else
                {

                    int[] digits = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



                    int sum = 0;
                    int counter = 0;
                    while (sum != 10)
                    {
                        counter++;
                        int temp = caseValue*counter;
                        while (temp > 0)
                        {
                            digits[temp%10] = 1;
                            temp = temp/10;
                        }
                        





                        sum = 0;
                        for (int y = 0; y < 10; y++)
                        {
                            sum += digits[y];
                        }
                    }
                    Console.Out.WriteLine("Case #" + i + ": " + caseValue*counter);
                }




            }



            

        }
    }
}
