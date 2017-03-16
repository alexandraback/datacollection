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
    static string path = @"C:\Y\Prog\_СпортивноеПрограммирование\GoogleCodeJam\2016\1C\2\";
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

    public static void solve(int c)
    {
        string[] buff = r.ReadLine().Split(' ');
        int b = Convert.ToInt32(buff[0]);
        int m = Convert.ToInt32(buff[1]);

        int[] links = new int[ (b * b - b) / 2];
        int n = links.Length;
        //перебираем 2^n вариантов
        for (long i = 0; i < (1 << n); i++)
        {
            for (int j = 0; j <= n - 1; j++)
            {
                if ((i & (1 << j)) > 0)
                {
                    links[j] = 1;
                }
                else
                {
                    links[j] = 0;
                }
            }
            int[,] res = TransformLinks(links, b);
            if (Check(res, b, m))
            {
                w.WriteLine("Case #{0}: {1}", c, "POSSIBLE");
                StringBuilder sb = new StringBuilder();
                for (int y = 0; y < b; y++)
                {
                    for (int x = 0; x < b; x++)
                    {
                        sb.Append(res[y, x]);
                    }
                    sb.AppendLine();                    
                }
                w.Write(sb.ToString());
                return;
            }
        }   
        w.WriteLine("Case #{0}: {1}", c, "IMPOSSIBLE"); 
    }

    public static int[,] TransformLinks(int[] links, int b)
    {
        int[,] res = new int[b, b];
        int cnt = 0;
        for (int i = 0; i < b; i++)
            for (int j = 0; j < b; j++)        
            {
                if (j > i)
                {
                    res[i, j] = links[cnt];
                    cnt++;
                }
            }
        return res;
    }

    public static bool Check(int[,] res, int b, int m)
    {
        int[] ways = new int[b];
        ways[0] = 1;
        for (int i = 1; i < b; i++)
            ways[i] = -1;
        //int cnt = 0;
        while (true)
        {
            //cnt++;
            //if (cnt > 50)
            //    Console.WriteLine("test");
            bool changed = false;
            for (int i = 1; i < b; i++)
            {
                if (ways[i] > 0) continue;
                bool allPrevCalc = true;
                int sumWays = 0;
                for (int j = 0; j < b; j++)
                {
                    if (res[j, i] == 1 && ways[j] > 0)
                    {
                        sumWays += ways[j];
                    }
                    if (res[j, i] == 1 && ways[j] == -1)
                    {
                        allPrevCalc = false;    
                    }
                }
                if (allPrevCalc == true && sumWays > 0)
                {
                    ways[i] = sumWays;
                    changed = true;
                }
            }
            if (!changed) break;
        }
        //Console.WriteLine(ways[b - 1]);
        if (ways[b - 1] == m)
            return true;
        else
            return false;
    }
}
