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

        private static ArrayList smallPrimes = new ArrayList(new int[] {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97});

        static BigInteger IsNonPrime(BigInteger x) {    // doesnt capture all of them!
            if(x <= 1) {
                return -1;
            } else {
                foreach (int i in smallPrimes)
                {
                    if (x%i == 0)
                    {
                        return i;
                    }
                }
                return 1;
            }
        }

        static BigInteger binaryStringToIntWithBase(string value, BigInteger baseNumber) {
            char[] cArray = value.ToCharArray();
            int temp = cArray.Length - 1;
            BigInteger multiplier = 1;
            BigInteger result = 0;
            while(temp >= 0) {
                result += multiplier * Convert.ToInt32(new string(cArray[temp], 1));
                multiplier = multiplier * baseNumber;
                temp--;
            }
            return result;
        }



        static void Main(string[] args) {

            string input = "1\n32 500";
            char[] delimiterChars = { '\n' };
            string[] inputs = input.Split(delimiterChars);

            int numberOfCases = Int32.Parse(inputs[0]);

            for(int i = 1; i <= numberOfCases; i++) {
                char[] spaceDelimiterChars = { ' ' };
                string[] subinputs = inputs[i].Split(spaceDelimiterChars);
                int N = Int32.Parse(subinputs[0]);
                int J = Int32.Parse(subinputs[1]);
                int counter = 2;
                int found = 0;
                Console.Out.WriteLine("Case #" + i + ":");
                while(counter < Math.Pow(2, N - 2) && found < J) {
                    // get binary representation
                    BigInteger[] result = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
                    string temp = Convert.ToString(counter, 2);
                    int x = N - 2 - temp.Length;
                    string binary = "1";
                    for(int a = 0; a < x; a++) {
                        binary += "0";
                    }
                    binary += temp;
                    binary += "1";




                    for(int j = 2; j <= 10; j++) {
                        result[j - 2] = IsNonPrime(binaryStringToIntWithBase(binary, j));
                        if(result[j - 2] < 1) {
                            break;
                        }
                    }
                    // if all of the values in result >= 2, then binary is a jamcoin
                    if(result[0] >= 2 && result[1] >= 2 && result[2] >= 2 && result[3] >= 2 && result[4] >= 2 &&
                        result[5] >= 2 && result[6] >= 2 && result[7] >= 2 && result[8] >= 2) {
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
