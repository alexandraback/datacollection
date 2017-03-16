/* C# Program
 * Google Code Jam 2012
 * Qualification Round
 * Problem C. Recycled Numbers
 * 
 * Copyright Craig Maher - 2012
 */
using System;
using System.IO;
using System.Collections.Generic;

namespace CodeJamQR12PC {
    class Program {
        static void Main(string[] args) {
            //files
            StreamReader input;
            StreamWriter output;
            input = new StreamReader("C-small-attempt0.in");
            output = new StreamWriter("C-small-attempt0.out");

            //if it fails porgram needs to exit anyway
            int TestCases = int.Parse(input.ReadLine());
            string outString;
            for (int i = 1; i <= TestCases; ++i) {
                outString = Process(input.ReadLine());
                output.WriteLine("Case #{0}: {1}", i, outString);
                Console.WriteLine("Case #{0}: {1}", i, outString);
            }

            input.Close();
            output.Close();


            Console.ReadLine();
        }

        private static string Process(string input) {
            string output = string.Empty;

            string[] numbers = input.Split(' ');
            int A = int.Parse(numbers[0]);
            int B = int.Parse(numbers[1]);
            int count = 0;
            char[] CharArray;
            //int recycle;
            char storage;
            int n;
            int i;
            int j;
            HashSet<int> set = new HashSet<int>();
            for (n = A; n < B; ++n) {
                CharArray = n.ToString().ToCharArray();
                //get all recycles of n
                for (i = 0; i < CharArray.Length; ++i) {
                    storage = CharArray[0];
                    for (j = 0; j < CharArray.Length - 1; ++j) {
                        CharArray[j] = CharArray[j + 1];
                    }
                    CharArray[CharArray.Length - 1] = storage;
                    set.Add(int.Parse(new string(CharArray)));
                    
                }
                //chck if recycle is greater then n and less then or equal to B if so add one to the count
                foreach (int k in set)
                {
                    if (k > n && k <= B)
                    {
                        //error 1212 gets repeated
                        //if (B == 2222) {
                        //    Console.WriteLine("count:{0}, n:{1}, m:{2}",count, n, k);
                        //}
                        count++;
                    }
                }
                set.Clear();
            }

            output = count.ToString();
            return output;
        }
    }
}
