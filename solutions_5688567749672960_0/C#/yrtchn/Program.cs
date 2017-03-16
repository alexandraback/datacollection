//#define ONLINE_JUDGE
//#define DEBUG

using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

class Program
{

    static int tests = 2;

#if (ONLINE_JUDGE)
    static TextReader r = Console.In;
    static TextWriter w = Console.Out;
#else
    static string path = @"C:\Y\Prog\GoogleCodeJam\2015\Этап2\1\";
    static string answerFile = "0{0}Answer.txt";
    static string resultFile = "0{0}Result.txt";
    static string sourceFile = "0{0}Source.txt";
    
    static TextReader r;
    static TextWriter w;
#endif

    static void Main(string[] args)
    {
        for (int i = 1; i <= tests; i++)
        {
#if (!ONLINE_JUDGE)
            r = new StreamReader(string.Format(path + sourceFile, i));
            w = new StreamWriter(string.Format(path + resultFile, i), false);
#endif
            string s = r.ReadLine();
            int cases = Convert.ToInt32(s);
            prepare();
            for (int j = 0; j < cases; j++)
                solve(j+1);
#if (!ONLINE_JUDGE)
            w.Flush(); w.Close();
            Console.WriteLine("CASE: {0}", i);
            string answer = File.ReadAllText(string.Format(path + answerFile, i));
            string result = File.ReadAllText(string.Format(path + resultFile, i));
            if (answer != result)
            {
                Console.WriteLine("FAIL:");
                Console.WriteLine("Result" + Environment.NewLine + result);
                Console.WriteLine("Answer" + Environment.NewLine + answer);
            }
            else
                Console.WriteLine("OK");
#endif
        }
    }

    public static long maxN = 1000009;

    public static long[] dp = new long[maxN + 2];
    public static long[] rev = new long[maxN + 2];

    public static void prepare()
    {
        dp[1] = 1;
        for (int i = 1; i < maxN; i++)
            rev[i] = getRev(i);
        while (true)
        {
            bool changed = false;
            for (int i = 1; i < maxN; i++)
            {
                if (dp[i] == 0) continue;
                if (dp[i + 1] > (dp[i] + 1) || dp[i + 1] == 0)
                {
                    changed = true;
                    dp[i + 1] = dp[i] + 1;
                }
                if (rev[i] < maxN && (dp[rev[i]] > (dp[i] + 1) || dp[rev[i]] == 0))
                {
                    changed = true;
                    dp[rev[i]] = dp[i] + 1;
                }
            }
            if (!changed) break;
        }
    }

    public static void solve(int c)
    {
        long n = Convert.ToInt64(r.ReadLine());        
        w.WriteLine("Case #{0}: {1}", c, dp[n]);
        if (dp[n] != getFast(n))
        {
            //Console.WriteLine("{0} {1} {2}", n, dp[n], getFast(n));
        }
    }

    public static long getFast(long n)
    {
        long res = 0;
        while (true)
        {
            if (n <= 9) { res += (n - 1); break; }
            long rev = getRev(n);
            if (rev < (n - 1) && n % 10 != 0)
            {
                n = rev;
                res++;
                continue;
            }
            n--;
            res++;
        }

        return res;
    }

    public static long getRev(long n)
    {
        long res = 0;
        long mult = 1;
        long n0 = n;
        do
        {
            n = n / 10;
            mult *= 10;
        } while (n > 0);
        mult /= 10;
        n = n0;
        do
        {
            res += Convert.ToInt32(n % 10) * mult;
            n = n / 10;
            mult /= 10;
        } while (n > 0);
        return res;
    }
}
