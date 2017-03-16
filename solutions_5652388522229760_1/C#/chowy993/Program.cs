using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace QuialifyingRound1 {
    class Program {
        static void Main(string[] args)
        {

            string input = "100\n0\n1\n2\n11\n1692\n452652\n7\n80139\n847767\n574462\n168724\n389414\n721974\n607658\n966241\n581843\n8\n533417\n999993\n999998\n125679\n999994\n125\n3\n496143\n555357\n469078\n966861\n643928\n958757\n405734\n566914\n284835\n628144\n305501\n999995\n641502\n40\n468007\n4\n6\n474102\n999991\n8420\n999992\n706958\n412291\n12500\n829738\n989530\n1000000\n999999\n124\n649921\n934380\n524408\n452026\n47241\n566779\n48575\n545212\n166\n176944\n685651\n995445\n660536\n910087\n427902\n336090\n882662\n528479\n125000\n434055\n749191\n461737\n270659\n155418\n26704\n883168\n200\n362135\n513729\n747709\n87897\n392284\n999996\n57048\n20\n25\n999997\n5\n147414\n195867\n34\n1250\n695602\n9\n10\n87817\n632395\n";
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
