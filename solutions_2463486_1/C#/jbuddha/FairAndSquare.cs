/// <summary>
/// Solution for Code Jam Problem - FairAndSquare
/// Author - JSSVPrasad Buddha
/// </summary>
using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;
using System.Text;
using System.Linq;
using System.Collections.Generic;
using System.Diagnostics;

namespace CodeJam2013
{
    [TestClass]
    public class FairAndSquare
    {
        static string inputfile = @"C:\Documents\Dropbox\Code\BitBucket\Temp\CodeJam\IO\FairAndSquare-small.in";
        static string outputfile = @"C:\Documents\Dropbox\Code\BitBucket\Temp\CodeJam\IO\FairAndSquare-small.out";
        static StringBuilder solution = new StringBuilder();
        static string[] lines = File.ReadAllLines(inputfile);

        static FileStream fs = new FileStream(@"C:\Documents\Dropbox\Code\BitBucket\Temp\CodeJam\IO\Global.out", FileMode.Create);
        static StreamWriter sw = new StreamWriter(fs);
        static TextWriter tmp = Console.Out;

        [TestMethod]
        public void FairAndSquareSolver()
        {
            HashSet<ulong> fairAndSquare = new HashSet<ulong>();
            fairAndSquare.Add(1);
            fairAndSquare.Add(4);
            fairAndSquare.Add(9);
            fairAndSquare.Add(121);
            fairAndSquare.Add(484);
            fairAndSquare.Add(10201);
            fairAndSquare.Add(12321);
            fairAndSquare.Add(14641);
            fairAndSquare.Add(40804);
            fairAndSquare.Add(44944);
            fairAndSquare.Add(1002001);
            fairAndSquare.Add(1234321);
            fairAndSquare.Add(4008004);
            fairAndSquare.Add(100020001);
            fairAndSquare.Add(102030201);
            fairAndSquare.Add(104060401);
            fairAndSquare.Add(121242121);
            fairAndSquare.Add(123454321);
            fairAndSquare.Add(125686521);
            fairAndSquare.Add(400080004);
            fairAndSquare.Add(404090404);
            fairAndSquare.Add(10000200001);
            fairAndSquare.Add(10221412201);
            fairAndSquare.Add(12102420121);
            fairAndSquare.Add(12345654321);
            fairAndSquare.Add(40000800004);
            fairAndSquare.Add(1000002000001);
            fairAndSquare.Add(1002003002001);
            fairAndSquare.Add(1004006004001);
            fairAndSquare.Add(1020304030201);
            fairAndSquare.Add(1022325232201);
            fairAndSquare.Add(1024348434201);
            fairAndSquare.Add(1210024200121);
            fairAndSquare.Add(1212225222121);
            fairAndSquare.Add(1214428244121);
            fairAndSquare.Add(1232346432321);
            fairAndSquare.Add(1234567654321);
            fairAndSquare.Add(4000008000004);
            fairAndSquare.Add(4004009004004);
            fairAndSquare.Add(100000020000001);
            fairAndSquare.Add(100220141022001);
            fairAndSquare.Add(102012040210201);
            fairAndSquare.Add(102234363432201);
            fairAndSquare.Add(121000242000121);
            fairAndSquare.Add(121242363242121);
            fairAndSquare.Add(123212464212321);
            fairAndSquare.Add(123456787654321);
            fairAndSquare.Add(400000080000004);
            ulong sqrt;
            // use the below logic to find fair and square numbers below 10^14
            // to reduce the time of execution even further, I have collated and 
            // and added them to hashset manually. this works for numbers under 10^20 if we change 
            // d < 8 to d < 11; however for big integers larger than that, I still have to figure out
            // answer
            //for (int d = 1; d < 8; d++)
            //{
            //    ulong low = (ulong)Math.Pow(10, d)+1;
            //    ulong high = (ulong)Math.Pow(10, d+1);
            //    //odd digited palindromes
            //    for (ulong n = low; n < high; n++)
            //    {
            //        ulong x = n * (ulong)Math.Pow(10, d) + OddReverse(n);

            //        if (((x & 2) != 0) || ((x & 7) == 5) || ((x & 11) == 8))
            //            continue;

            //        // using John D. Cook's trick from Stack Overflow to skip 75% of the numbers
            //        //ulong lasthex = x & 0xF;  
            //        //if (lasthex > 9)
            //        //    continue;
            //        //if (lasthex == 2 || lasthex == 3 || lasthex == 5 || lasthex == 6 || lasthex == 7 || lasthex == 8)
            //        //    continue;

            //        sqrt = (ulong)Math.Sqrt(x);
            //        if(sqrt*sqrt==x)
            //            if (isPalindrome(sqrt))
            //            {
            //                fairAndSquare.Add(x);
            //                Console.WriteLine(x);
            //            }
            //    }

            //    //even digited palindromes
            //    for (ulong n = low; n < high; n++)
            //    {
            //        ulong x = n * (ulong)Math.Pow(10, d+1) + Reverse(n);

            //        if (((x & 2) != 0) || ((x & 7) == 5) || ((x & 11) == 8))
            //            continue;
            //        //ulong lasthex = x & 0xF;
            //        //if (lasthex > 9)
            //        //    continue;
            //        //if (lasthex == 2 || lasthex == 3 || lasthex == 5 || lasthex == 6 || lasthex == 7 || lasthex == 8)
            //        //    continue;
            //        sqrt = (ulong)Math.Sqrt(x);
            //        if (sqrt * sqrt == x)
            //            if (isPalindrome(sqrt))
            //            {
            //                fairAndSquare.Add(x);
            //                Console.WriteLine(x);
            //            }
            //    }
            //}

            int lineCount = lines.Length;
            for (int line = 1, tc = 1; line < lineCount; tc++)
            {

                ulong[] temp = lines[line++].Split(' ').Select(x => ulong.Parse(x)).ToArray();
                ulong a = temp[0];
                ulong b = temp[1];
                ulong sqr,counter=0;

                foreach (ulong fsnum in fairAndSquare)
                {
                    if (fsnum >= a && fsnum <= b)
                        counter++;
                }
                solution.AppendLine("Case #" + tc + ": " + counter);
            }

            File.WriteAllText(outputfile, solution.ToString());
            return;
        }

        public ulong OddReverse(ulong num)
        {
            ulong rev = 0;
            ulong orig = num;
            num = num / 10;
            while (num >= 1)
            {
                rev = rev * 10 + num % 10;

                num /= 10;
            }
            return rev;
        }

        public ulong Reverse(ulong num)
        {
            ulong rev = 0;
            ulong orig = num;
            while (num >= 1)
            {
                rev = rev * 10 + num % 10;

                num /= 10;
            }
            return rev;
        }

        public bool isPalindrome(ulong num)
        {
            ulong rev = 0;
            ulong orig = num;
            // if the number is divisible by 10, it is not palendrome, hence skpping reversal
            if (orig % 10 == 0)
                return false;
            while (num >= 1)
            {
                rev = rev*10+num % 10;
                
                num /= 10;
            }
            if (rev == orig)
                return true;
            else
                return false;
        }

        [TestCleanup]
        public void CleanUp()
        {
            // This method Sets the test output to a text file rather than Standard Output for seeing the output without indentation issues
            // To disable redirecting output to text file, comment next line
            Console.SetOut(tmp);
            sw.Close();
        }

        [TestInitialize]
        public void Initialize()
        {
            Console.SetOut(sw);
        }
    }
}
