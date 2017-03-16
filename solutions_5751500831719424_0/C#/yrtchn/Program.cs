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
    static string path = @"C:\Y\Prog\GoogleCodeJam\01\";
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
        int n = Convert.ToInt32(r.ReadLine());
        Tuple<char, int>[][] s = new Tuple<char, int>[n][];
        for (int i = 0; i < n; i++)
            s[i] = getAStr(r.ReadLine());
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                //res = Math.Max(res, getMoves(s[i], s[j]));
                if (s[i].Length != s[j].Length)
                {
                    w.WriteLine("Case #{0}: Fegla Won", cs);
                    return;
                }
        for (int p = 0; p < s[0].Length; p++)
        {
            int maxCnt = int.MinValue;
            int minCnt = int.MaxValue;
            for (int i = 0; i < n; i++)
            {
                if (s[0][p].Item1 != s[i][p].Item1)
                {
                    w.WriteLine("Case #{0}: Fegla Won", cs);
                    return;
                }
                maxCnt = Math.Max(maxCnt, s[i][p].Item2);
                minCnt = Math.Min(minCnt, s[i][p].Item2); 
            }

            int bestSum = int.MaxValue;
            for (int k = minCnt; k <= maxCnt; k++)
            {
                int curSum = 0;
                for (int z = 0; z < n; z++)
                    curSum += Math.Abs(k - s[z][p].Item2);
                bestSum = Math.Min(bestSum, curSum);
            }
            res += bestSum;
        }
        w.WriteLine("Case #{0}: {1}", cs, res); 
    }

    public static Tuple<char, int>[] getAStr(string s)
    {
        List<Tuple<char, int>> l = new List<Tuple<char, int>>();
        char prevC = s[0];
        int cnt = 0;
        for (int i = 0; i < s.Length; i++)
            if (s[i] == prevC)
                cnt++;
            else
            {                
                l.Add(new Tuple<char, int>(prevC, cnt));
                prevC = s[i];
                cnt = 1;
            }
        l.Add(new Tuple<char, int>(s[s.Length - 1], cnt));                
        return l.ToArray();    
    }

    public static int getMoves(Tuple<char, int>[] s1, Tuple<char, int>[] s2)
    {
        if (s1.Length != s2.Length) return int.MaxValue;
        int res = 0;
        for (int i = 0; i < s1.Length; i++)
        {
            
        }
        return res;
    }
}

