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

            //0000000
            for (ulong i = 1; i < 1000; i++)
            {
                if (isPalindrome(i))
                {

                    ulong sqrt = (ulong)Math.Sqrt(i);

                    if (isPalindrome(sqrt))
                    {
                        if (sqrt * sqrt == i)
                        {
                            fairAndSquare.Add(i);
                        }
                    }
                }
            }

            int lineCount = lines.Length;
            for (int line = 1, tc = 1; line < lineCount; tc++)
            {

                ulong[] temp = lines[line++].Split(' ').Select(x => ulong.Parse(x)).ToArray();
                ulong a = temp[0];
                ulong b = temp[1];
                ulong sqr,counter=0;
                ulong sqrt;
                for (ulong n = a; n <= b; n++)
                {
                      if (fairAndSquare.Contains(n))
                        counter++;
                }

                solution.AppendLine("Case #" + tc + ": " + counter);
            }

            File.WriteAllText(outputfile, solution.ToString());
            return;
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
