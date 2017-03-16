using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

class C
{
    static void Main(string[] args)
    {
        StreamReader sr = new StreamReader("c:\\codejam\\2013\\qual\\C-large-1.in");
        StreamWriter sw = new StreamWriter("c:\\codejam\\2013\\qual\\C-large-1.out");


        //find all palindromes first
        List<long> palindromes = new List<long>();
        //lower bound is CEIL[sqrt(A)] and upper FLOOR[sqrt(B)]
        //not sure how to do these with big ints
        long lower = 0;
        long upper = 10000000;

        int count = 0;
        for (long n = lower; n <= upper; n++)
        {
            //is it a palindrome
            //and is its square a palindrome
            long sqr = n * n;
            if (isPalindrome(n) && isPalindrome(sqr))
            {
                palindromes.Add(n*n);
            }
        }


        int T = Int32.Parse(sr.ReadLine());
        foreach (int caseN in Enumerable.Range(1, T))
        {
            var tmp = sr.ReadLine().Split(' ');

            long A = long.Parse(tmp[0]);
            long B = long.Parse(tmp[1]);


            sw.WriteLine("Case #{0}: {1}", caseN, palindromes.Count(n => n >= A && n <= B));

            sw.Flush();
        }
    }

    private static bool isPalindrome(long n)
    {
        var str = n.ToString();
        int digits = str.Length;
        for (int x = 0; x < digits; x++)
        {
            if (str[x] != str[digits - x - 1])
                return false;
        }
        return true;
    }
}