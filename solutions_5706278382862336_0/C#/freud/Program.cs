using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace elf
{
    class Program
    {
        static long A, B;
        static long C=0, D=0;
        public static long gcd( long n,long m)
        {
            long gcdd, remainder;
            while (n != 0)
            {
                remainder = m % n;
                m = n;
                n = remainder;
            }

            gcdd = m;

            return gcdd;

        }
        public static void DoItLow()
        {
            long mygcd;
            mygcd = gcd(A, B);
            C = A / mygcd;
            D = B / mygcd;

        }
        public static bool IsPowerOfTwo(long x)
        {
            return (x != 0) && ((x & (x - 1)) == 0);
        }
        static void Main(string[] args)
        {

            // test
            /*
            int x;
            x = 0;
            Console.WriteLine("Test({0}) = {1}",x,(long)Math.Log((double)x, 2));
            x = 1;
            Console.WriteLine("Test({0}) = {1}", x, (long)Math.Log((double)x, 2));
            x = 2;
            Console.WriteLine("Test({0}) = {1}", x, (long)Math.Log((double)x, 2));
            x = 3;
            Console.WriteLine("Test({0}) = {1}", x, (long)Math.Log((double)x, 2));
            x = 4;
            Console.WriteLine("Test({0}) = {1}", x, (long)Math.Log((double)x, 2));
            x = 5;
            Console.WriteLine("Test({0}) = {1}", x, (long)Math.Log((double)x, 2));
            x = 6;
            Console.WriteLine("Test({0}) = {1}", x, (long)Math.Log((double)x, 2));
            x = 7;
            Console.WriteLine("Test({0}) = {1}", x, (long)Math.Log((double)x, 2));
            x = 8;
            Console.WriteLine("Test({0}) = {1}", x, (long)Math.Log((double)x, 2));
            x = 9;
            Console.WriteLine("Test({0}) = {1}", x, (long)Math.Log((double)x, 2));
            */

            int T;
            string[] textInput = System.IO.File.ReadAllLines(@"elf.in.txt");
            System.IO.StreamWriter textOutput = new System.IO.StreamWriter(@"elf.out.txt");

            T = Int32.Parse(textInput[0]);
            int linePosition = 1;

            for (int t = 1; t <= T; t++, linePosition++)
            {
                string[] temp;
                temp = textInput[linePosition].Split('/');
                A = long.Parse(temp[0]);
                B = long.Parse(temp[1]);

                

                DoItLow();
            //    Console.WriteLine("Before: {0} {1}", A, B);
           //     Console.WriteLine("After: {0} {1}", C, D);
           //     Console.WriteLine();

                // D is 2^n or not

                if (IsPowerOfTwo(D) == false)
                {
                    // Wrong
                    Console.WriteLine("Case #{0}: impossible", t);
                    textOutput.WriteLine("Case #{0}: impossible", t);
                    continue;
                }

                long all = (long)Math.Log((double)D, 2);
              //  Console.WriteLine("All:" + all);
                long god = (long)Math.Log((double)C, 2);
              //  Console.WriteLine("God:" + god);
                long answer = all - god;

                Console.WriteLine("Case #{0}: {1}", t, answer);
                textOutput.WriteLine("Case #{0}: {1}", t, answer);
            }

            Console.ReadLine();
            textOutput.Close();
        }
    }
}
