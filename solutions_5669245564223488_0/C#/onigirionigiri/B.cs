//using System;
//using System.IO;
//using System.Text;
//using System.Linq;
//using System.Collections;
//using System.Diagnostics;
//using System.Numerics;
//using System.Collections.Generic;

//public class ClassName
//{
//    public static void Main()
//    {
//        new ClassName().Entry();
//    }//Main

//    const string inputName = @"B-small-attempt0.in";
//    StreamReader sr = new StreamReader(@"C:\Users\onigiri\Downloads\" + inputName);
//    StreamWriter sw = new StreamWriter(@"C:\Users\onigiri\Documents\Visual Studio 2012\Projects\GCJ\GCJ\B.txt");

//    void Entry()
//    {
//        int T = intRead();
//        for (int i = 0; i < T; i++)
//        {
//            string res = Solve();
//            Write("Case #" + (i + 1) + ": " + res);
//        }//for i
//        sw.Close();
//        sr.Close();
//    }

//    const int mod = 1000000007;
//    const int alph = 26;
//    private string Solve()
//    {
//        int N = intRead();
//        var array = strSplit(' ');
//        var cnt = new int[alph, alph];
//        foreach (var cur in array)
//        {
//            int top = 0;
//            int last = cur.Length - 1;
//            while (top+1<cur.Length&&cur[top]==cur[top+1])
//            {
//                top++;
//            }//while
//            while (last-1>=0&&cur[last]==cur[last-1])
//            {
//                last--;
//            }//while
//            for (int i = top+1; i < last; i++)
//            {
//                foreach (var comp in array)
//                {
//                    if (comp.Contains(cur[i]))
//                    {
//                        return "0";
//                    }//if
//                }//foreach comp
//            }//for i
//            cnt[cur[0] - 'a', cur[cur.Length - 1] - 'a']++;
//        }//foreach cur
//        var next = Enumerable.Repeat(-1, alph).ToArray();
//        var perm = new int[alph];
//        for (int i = 0; i < alph; i++)
//        {
//            int sum = 0;
//            for (int j = 0; j < alph; j++)
//            {
//                if (j!=i&&cnt[i,j]>0)
//                {
//                    next[i] = j;
//                    sum += cnt[i, j];
//                }//if
//            }//for j
//            if (sum>1)
//            {
//                return "0";
//            }//if
//            perm[i] = cnt[i, i];
//        }//for i
//        for (int i = 0; i < alph; i++)
//        {
//            int cur = i;
//            int step = 0;
//            while (next[cur]>=0)
//            {
//                cur = next[cur];
//                step++;
//                if (step>50)
//                {
//                    return "0";
//                }//if
//            }//while
//        }//for i
//        var factArray = FactArray(N + 10, mod);
//        long res = 1;
//        for (int i = 0; i < alph; i++)
//        {
//            res *= factArray[perm[i]];
//            res %= mod;
//        }//for i
//        int p = alph;
//        for (int i = 0; i < alph; i++)
//        {
//            if (perm[i]==0||next[i]==0)
//            {
//                p--;
//            }//if
//        }//for i
//        res *= factArray[p];
//        res %= mod;
//        return res.ToString();
//    }

//    /// <summary>
//    /// varified by SRM 472 DIV1 Medium TwoSidedCards
//    /// varified by SRM 391 DIV1 Medium KeysInBoxes
//    /// 階乗のテーブルを作る
//    /// O( len )
//    /// </summary>
//    /// <param name="len">階乗をとる最大の値</param>
//    /// <param name="mod">mod を取る値</param>
//    /// <returns>階乗のテーブル</returns>
//    public static long[] FactArray(int len,int mod)
//    {
//        long[] factrial = new long[len + 1];
//        factrial[0] = 1;
//        for (int i = 1; i <= len; i++)
//        {
//            factrial[i] = factrial[i - 1] * i % mod;
//        }//for i
//        return factrial;
//    }//FactArray


//    void Write(string str)
//    {
//        Console.WriteLine(str);
//        sw.WriteLine(str);
//    }

//    string strRead()
//    {
//        return sr.ReadLine();
//    }

//    int intRead()
//    {
//        return int.Parse(sr.ReadLine());
//    }

//    long longRead()
//    {
//        return long.Parse(sr.ReadLine());
//    }

//    double doubleRead()
//    {
//        return double.Parse(sr.ReadLine());
//    }

//    string[] strSplit(char c)
//    {
//        return sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries);
//    }

//    int[] intSplit(char c)
//    {
//        return Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
//    }

//    long[] longSplit(char r)
//    {
//        return Array.ConvertAll<string, long>(sr.ReadLine().Split(new char[] { r }, StringSplitOptions.RemoveEmptyEntries), long.Parse);
//    }

//    double[] doubleSplit(char c)
//    {
//        return Array.ConvertAll<string, double>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), double.Parse);
//    }

//}//ClassName