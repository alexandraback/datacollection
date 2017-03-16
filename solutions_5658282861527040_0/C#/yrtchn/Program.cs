//#define ONLINE_JUDGE
#define DEBUG

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
    static string path = @"C:\Y\Prog\GoogleCodeJam\02\";
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
            int cases = Convert.ToInt32(r.ReadLine());
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

    public static void solve(int cs)
    {
        string[] buff = r.ReadLine().Split(' ');
        long a = Convert.ToInt64(buff[0]);
        long b = Convert.ToInt64(buff[1]);
        long k = Convert.ToInt64(buff[2]);  
        
        long res = 0;
        for (long i = 0; i < a; i++)
            for (long j = 0; j < b; j++)
                if ((i & j) < k) 
                    res++;

        w.WriteLine("Case #{0}: {1}", cs, res); 
    }
}

