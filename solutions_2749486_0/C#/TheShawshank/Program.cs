using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;
using System.Diagnostics;
using System.IO;


namespace ProjectEuler
{
    class Program
    {

        //This will return the first million primes bit array.
        public static BitArray primeBitArray(int Max = 20000000)
        {
            int max = Max;
            int j, count = 0;
            BitArray primes = new BitArray(max + 1);
            for (int i = 2; i < max + 1; i++)
            {
                if (primes[i] == false)
                {
                    count++;
                    //Console.WriteLine("{0} is Prime", i);
                    j = i;
                    while (j + i <= max)
                    {
                        j = j + i;
                        primes[j] = true;
                    }
                }
            }
            Console.WriteLine("Number of primes {0}", count);
            return primes;
        }


        //Return the 1 million prime numbers array
        public static long[] primefunctionality(int max = 20000000)
        {
            long[] primeArray = new long[1000000];

            BitArray primes = primeBitArray(max);

            int j = 0;
            for (int i = 2; (i < max + 1) && (j != 1000000); i++)
            {
                if (!primes[i])
                {
                    primeArray[j] = i;
                    j++;
                }
            }
            return primeArray;
        }

        //checks if a number is prime.
        public static bool checkPrime(int n)
        {
            BitArray primes = primeBitArray(n + 1);
            return primes[n];
        }

        //It takes approx 2.6 seconds to compute divisors for n= 1billion( Int32.MaxValue/2)
        public static int divisors(int n)
        {
            int[] divisors = new int[1000];
            int j = 0;
            //BitArray primes = primeBitArray();
            for (int i = 2; i < (n / 2 + 1); i++)
            {
                if ((n % i) == 0)
                {
                    //Console.WriteLine("{0} is divisor",i);
                    divisors[j] = i;
                    j++;
                    // Remember: that there is different method to calculate the sum of divisors.
                }
            }
            return j;
        }

        //You can only find upto 87 fibonacci number due to the limitation of the long value
        public static void Fibonacci()
        {
            long f1 = 1;
            long f2 = 2;
            long f3 = 3;
            long sum = 2;
            int count = 0;

            while (f3 < (long.MaxValue / 2))
            {
                f1 = f2;
                f2 = f3;
                f3 = f2 + f1;
                /* if ((f3 % 2) == 0)
                 {
                     sum = sum + f3;
                 }*/
                count++;
                Console.WriteLine("Fibinacci number ={0}", f3);
            }
            Console.WriteLine("sum numbers={0}, number of numbers={1}", sum, count);
            Console.Read();
        }

        public static StringBuilder fibonacciString(int n = 100000)
        {
            StringBuilder f1 = new StringBuilder("1");
            StringBuilder f2 = new StringBuilder("1");
            StringBuilder f3 = new StringBuilder(); ;
            for (int i = 3; i < n; i++)
            {
                f3 = reverseAdd(f1, f2);

                f1 = f2;
                f2 = f3;
                //Console.WriteLine(" N= {0}, Length= {1}, number = {2}", i, f3.Length, f3.ToString());
                if (f3.Length >= 1000)
                {

                    Console.WriteLine(" N= {0}, Length= {1}, ", i, f3.Length);
                    break;
                }
            }

            return f3;
        }

        public static bool checkPalindrome(long num)
        {
            long init = num;
            long rev = 0;

            int k;

            while (num != 0)
            {
                k = (int)(num % 10);
                num = num / 10;
                rev = rev * 10 + k;
            }
            if (init == rev)
            {
                return true;
            }
            else return false;
        }


        public static void trianglenumber()
        {
            int trianglenumber = 3, count;
            int value = 3;
            int numofdiv;
            long j, x;
            long[] primes = primefunctionality();

            while (true)
            {
                //Console.WriteLine("triangle number ={0}", trianglenumber);
                trianglenumber = trianglenumber + value;
                x = trianglenumber;
                j = 0;
                numofdiv = 1;
                while (x != 1)
                {
                    count = 0;
                    while ((primes[j] != 0) && ((x % primes[j]) == 0))
                    {
                        x = x / primes[j];
                        count++;
                    }
                    numofdiv *= (count + 1);
                    j++;

                }

                Console.WriteLine("answer={0},{1}", numofdiv, trianglenumber);
                if (numofdiv > 500)
                {
                    Console.WriteLine("answer={0},{1}", numofdiv, trianglenumber);
                    break;
                }
                value++;
            }

        }

        public static StringBuilder reverseAdd(StringBuilder intA, StringBuilder intB)
        {
            StringBuilder small, large, result;
            if (intA.Length < intB.Length)
            {
                small = intA;
                large = intB;
            }
            else
            {
                small = intB;
                large = intA;
            }

            result = new StringBuilder();
            int tempVar, carry = 0, i;
            for (i = 0; i < small.Length; i++)
            {
                tempVar = (small[i] - '0') + (large[i] - '0') + carry;
                carry = tempVar / 10;
                tempVar = tempVar % 10;
                result.Append((char)(tempVar + '0'));
                //Console.WriteLine("appending= {0}", (char)(tempVar + '0'));
            }

            while (i < large.Length)
            {
                tempVar = (large[i] - '0') + carry;
                carry = tempVar / 10;
                tempVar = tempVar % 10;
                result.Append((char)(tempVar + '0'));
                i++;
                //Console.WriteLine("appending= {0}", (char)(tempVar + '0'));
            }
            if (carry != 0)
                result.Append(carry);

            // Console.WriteLine("answer = {0}",result);
            return result;
        }

        public static StringBuilder reverseMultiply(StringBuilder intA, StringBuilder intB)
        {
            //if both intA and intB are not zero.
            StringBuilder result = new StringBuilder("000");
            StringBuilder temp = new StringBuilder();
            int tempVar = 0, carry = 0, shift = 0, count = 0;

            for (int indexB = 0; indexB < intB.Length; indexB++)
            {
                if (intB[indexB] == 0)
                { continue; }

                carry = 0;
                temp.Length = 0;
                for (int indexA = 0; indexA < intA.Length; indexA++)
                {
                    tempVar = ((intA[indexA] - '0') * (intB[indexB] - '0')) + carry;
                    carry = tempVar / 10;
                    tempVar = tempVar % 10;
                    temp.Append(tempVar);
                }
                if (carry != 0)
                {
                    temp.Append(carry);
                }


                carry = 0;
                for (int i = 0; i < temp.Length; i++)
                {

                    if ((shift + i) < result.Length)
                    {
                        tempVar = (result[shift + i] - '0') + (temp[i] - '0') + carry;
                        result[shift + i] = (char)((tempVar % 10) + '0');
                        carry = tempVar / 10;

                    }
                    else
                    {
                        tempVar = (temp[i] - '0') + carry;
                        carry = tempVar / 10;
                        tempVar = tempVar % 10;
                        result.Append(tempVar);
                    }
                }
                if (carry != 0)
                {
                    result.Append(carry);
                }
                shift++;
            }

            tempVar = result.Length - 1;
            while ((tempVar >= 0) && (result[tempVar] == '0'))
            {
                count++;
                tempVar--;
            }
            result.Remove(tempVar + 1, count);
            if (result.Length == 0)
                result.Append(0);
            return result;
        }

        public static int countChar()
        {

            Dictionary<int, int> unitPlace = new Dictionary<int, int>();
            Dictionary<int, int> tenPlace = new Dictionary<int, int>();
            Dictionary<int, int> special = new Dictionary<int, int>();

            unitPlace.Add(1, 3);
            unitPlace.Add(2, 3);
            unitPlace.Add(3, 5);
            unitPlace.Add(4, 4);
            unitPlace.Add(5, 4);
            unitPlace.Add(6, 3);
            unitPlace.Add(7, 5);
            unitPlace.Add(8, 5);
            unitPlace.Add(9, 4);


            tenPlace.Add(2, 6);
            tenPlace.Add(3, 6);
            tenPlace.Add(4, 5);
            tenPlace.Add(5, 5);
            tenPlace.Add(6, 5);
            tenPlace.Add(7, 7);
            tenPlace.Add(8, 6);
            tenPlace.Add(9, 6);

            special.Add(10, 3);
            special.Add(11, 7);
            special.Add(12, 6);
            special.Add(13, 8);
            special.Add(14, 8);
            special.Add(15, 7);
            special.Add(16, 7);
            special.Add(17, 9);
            special.Add(18, 8);
            special.Add(19, 8);

            int sum = 0, sumUnderHundered = 0;
            foreach (KeyValuePair<int, int> temp in unitPlace)
            {
                sum = sum + temp.Value;
            }
            Console.WriteLine("sumUnderTen = {0}", sum);
            foreach (KeyValuePair<int, int> temp in special)
            {
                sum = sum + temp.Value;
            }
            for (int i = 2; i <= 9; i++)
            {
                sum = sum + tenPlace[i];
                for (int j = 1; j <= 9; j++)
                {
                    sum = sum + tenPlace[i] + unitPlace[j];
                    Console.WriteLine("Number = {0}{1}, count = {2}", i, j, tenPlace[i] + unitPlace[j]);
                }
            }


            sumUnderHundered = sum;
            Console.WriteLine(sumUnderHundered);
            for (int i = 1; i <= 9; i++)
            {
                sum = sum + unitPlace[i] + 7;
                sum = sum + (99 * (unitPlace[i] + 7 + 3)) + sumUnderHundered;
            }

            sum = sum + 3 + 8; // for one thousand

            return sum;
        }

        public static StringBuilder lastTenDigits(int n, int power)
        {
            char[] array = n.ToString().ToCharArray();
            Array.Reverse(array);
            StringBuilder input = new StringBuilder(new String(array));
            if (power == 1)
            {
                return input;
            }
            StringBuilder answer = new StringBuilder();
            if ((power % 2) == 0)
            {
                answer = lastTenDigits(n, power / 2);
                answer = reverseMultiply(answer, answer);
                if (answer.Length > 10)
                {
                    answer.Length = 10;
                }
            }
            else
            {
                power = power - 1;
                answer = lastTenDigits(n, power / 2);

                answer = reverseMultiply(answer, answer);
                if (answer.Length > 10)
                {
                    answer.Length = 10;
                }
                answer = reverseMultiply(answer, input);
                if (answer.Length > 10)
                {
                    answer.Length = 10;
                }
            }
            Console.WriteLine("answer= {0}", answer);
            return answer;
        }

        public static void reverseStringFromFile()
        {
            List<string> inputList = new List<string>();
            String line; int i = 0;
            char[] array;
            StringBuilder[] input = new StringBuilder[100];
            using (StreamReader reader = new StreamReader("C:\\users\\saib\\Desktop\\html.txt"))
            {
                i = 0;
                while ((line = reader.ReadLine()) != null)
                {
                    array = line.ToCharArray();
                    Array.Reverse(array);
                    input[i] = new StringBuilder(new String(array));
                    //Console.WriteLine(input[i].ToString() + "  " + "length= " + input[i].Length);
                    i++;
                }
            }
        }
        public static void countDiff()
        {
            long[] primes = primefunctionality();
            int x, k, count;
            List<KeyValuePair<long, int>> divisors = new List<KeyValuePair<long, int>>();
            Dictionary<string, int> d = new Dictionary<String, int>();


            for (int i = 2; i <= 100; i++)
            {

                x = i; k = 0;
                while (x != 1)
                {
                    count = 0;
                    while ((primes[k] != 0) && ((x % primes[k]) == 0))
                    {
                        x = (int)(x / primes[k]);
                        count++;
                    }
                    if (count > 0)
                    {
                        divisors.Add(new KeyValuePair<long, int>(primes[k], count));
                    }
                    k++;
                }
                foreach (KeyValuePair<long, int> p in divisors)
                {
                    Console.Write(p.Key + "*" + p.Value + "  ");
                }
                Console.WriteLine();

                StringBuilder temp = new StringBuilder();
                int value;
                for (int j = 2; j <= 100; j++)
                {
                    temp.Length = 0;
                    foreach (var entry in divisors)
                    {
                        temp.Append(entry.Key);
                        temp.Append(',');
                        temp.Append((entry.Value) * j);
                        temp.Append(';');
                    }
                    if (!d.TryGetValue(temp.ToString(), out value))
                    {
                        d.Add(temp.ToString(), 1);
                    }
                    else
                    {
                        Console.WriteLine("duplicazte entry - {0}", temp);
                    }
                }

                divisors.Clear();
            }

            Console.WriteLine("answer= {0}", d.Count);
        }

        public static int factorial(int n)
        {
            int result = 1;
            for (int i = 1; i <= n; i++)
            {
                result *= i;
            }
            return result;
        }

        public static bool checkPalindromeBitWise(int n)
        {
            int original = n;
            int size = sizeof(int) * 8;
            int rev = 0, temp = 0;
            while (size != 0)
            {
                rev = rev << 1;
                rev = rev | (n & 1);
                n = n >> 1;
                size--;
            }

            //Console.WriteLine("  rev = {0}", rev);
            temp = 1 << 31;
            while ((original & temp) == 0)
            {

                original = original << 1;
            }
            // Console.WriteLine(original);

            if (rev == original)
                return true;
            else return false;
        }
        // To get the first permutation pass n=0; to get 100th permutation pass n=99;
        public static void getPermutation(ArrayList inputlst, int n)
        {
            ArrayList lst = new ArrayList(inputlst);
            lst.Sort();
            List<int> result = new List<int>();
            int count = lst.Count, num, iter = 0;
            while (count != 0)
            {
                num = n / factorial(count - 1);
                n = n % factorial(count - 1);

                iter = iter + num * factorial(count - 1);
                result.Add((int)lst[num]);
                lst.RemoveAt(num);
                count = count - 1;
            }

            foreach (var x in result)
                Console.Write(x);
        }


        public static int circularPrimes()
        {
            long[] primes = primefunctionality();
            BitArray primeArray = primeBitArray();
            int count = 0, tmpcount = 0, k = 0;
            long x;
            long j = 0;
            for (int i = 0; primes[i] < 1000000; i++)
            {
                x = primes[i];
                j = 10;
                tmpcount = 0;
                while ((x / j != 0))
                {
                    tmpcount++;
                    j = 10 * j;
                }
                //Console.WriteLine(x + "   " +tmpcount);
                for (k = 0; (!primeArray[(int)x]) && (k <= tmpcount); k++)
                {
                    //Console.WriteLine(x);
                    x = (x / 10) + (x % 10) * (long)System.Math.Pow(10, tmpcount);

                }
                if (k == (tmpcount + 1))
                {
                    //Console.WriteLine("---"+x);
                    count++;
                }
            }
            return count;
        }

       
      
    }
}

