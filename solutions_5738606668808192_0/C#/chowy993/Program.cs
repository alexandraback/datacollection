using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;

namespace QuialifyingRound1 {
    class Program
    {

        static Decimal IsPrime(Decimal x)
        {
            if (x <= 1)
            {
                return -1;
            } else if (x%2 == 0)
            {
                return 2;
            }
            else
            {
                bool temp = true;
                Decimal divisor = 0;
                for (Decimal i = 3; (i*i) <= x; i+= 2)
                {
                    if (x % i == 0)
                    {
                        temp = false;
                        divisor = i;
                        break;
                    }
                }
                if (temp)
                {
                    return 0;
                }
                else
                {
                    return divisor;
                }
            }
        }

        static Decimal binaryStringToIntWithBase(string value, Decimal baseNumber)
        {
            char[] cArray = value.ToCharArray();
            int temp = cArray.Length - 1;
            Decimal multiplier = 1;
            Decimal result = 0;
            while (temp >= 0)
            {
                result += multiplier* Convert.ToInt32(new string(cArray[temp], 1)); 
                multiplier = multiplier * baseNumber;
                temp--;
            }
            return result;

            /*int intValue = Convert.ToInt32(value, 10); 
            
            int temp = 0;
            while (intValue > 0)
            {
                temp += multiplier*(intValue%10);
                multiplier = multiplier*baseNumber;
                intValue = intValue/10;
            }
            return temp;*/
        }



        static void Main(string[] args)
        {

            string input = "1\n16 50";
            char[] delimiterChars = { '\n' };
            string[] inputs = input.Split(delimiterChars);

            int numberOfCases = Int32.Parse(inputs[0]);

            for (int i = 1; i <= numberOfCases; i++)
            {
                char[] spaceDelimiterChars = { ' ' };
                string[] subinputs = inputs[i].Split(spaceDelimiterChars);
                int N = Int32.Parse(subinputs[0]);
                int J = Int32.Parse(subinputs[1]);
                int counter = 2;
                int found = 0;
                Console.Out.WriteLine("Case #" + i + ":");
                while (counter < Math.Pow(2,N-2) && found < J)
                {
                    // get binary representation
                    Decimal[] result = {0, 0, 0, 0, 0, 0, 0, 0, 0};
                    string temp = Convert.ToString(counter, 2);
                    int x = N - 2 - temp.Length;
                    string binary = "1";
                    for (int a = 0; a < x; a++)
                    {
                        binary += "0";
                    }
                    binary += temp;
                    binary += "1";




                    for (int j = 2; j <= 10; j++)
                    {
                        result[j-2] = IsPrime(binaryStringToIntWithBase(binary, j));
                        if (result[j - 2] < 1)
                        {
                            break;
                        }
                    }
                    // if all of the values in result >= 2, then binary is a jamcoin
                    if (result[0] >= 2 && result[1] >= 2 && result[2] >= 2 && result[3] >= 2 && result[4] >= 2 &&
                        result[5] >= 2 && result[6] >= 2 && result[7] >= 2 && result[8] >= 2)
                    {
                        // is jamcoin
                        found++;
                        Console.Out.WriteLine(binary + " " + result[0]
                                                     + " " + result[1]
                                                     + " " + result[2]
                                                     + " " + result[3]
                                                     + " " + result[4]
                                                     + " " + result[5]
                                                     + " " + result[6]
                                                     + " " + result[7]
                                                     + " " + result[8]);
                    }
                    counter++;



                }



            }



            

        }
    }
}
