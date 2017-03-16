using System;
using System.IO;
using System.Text;

namespace Sheeps
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("a.in");
            StreamWriter sw = new StreamWriter("a.out");
            int tryCnt = Convert.ToInt32(sr.ReadLine());
            //string[] N = new string[tryCnt];
            byte Aof = (byte)("?"[0]);
            byte Zof = (byte)("0"[0]);
            for (int Tr = 0; Tr < tryCnt; Tr++)
            {
                string N= sr.ReadLine();
                int n = N.Length;
                //long c1, c2;
                StringBuilder p1 = new StringBuilder(N.Substring(0, N.IndexOf(' ')));
                StringBuilder p2 = new StringBuilder(N.Substring(N.IndexOf(' ') + 1));
                if (Tr==199)
                {

                }
                sw.WriteLine("Case #" + (Tr + 1) + ": " + Compare(p1, p2));
            }

            sr.Close();
            sw.Close();
        }

        static string Compare(StringBuilder _s1, StringBuilder _s2)
        {
            StringBuilder s1 = new StringBuilder(), s2=new StringBuilder();
            s1.Append(_s1); s2.Append(_s2);
            int indexOfQ = -1;
            for (int i = 0; i < s1.Length; i++)
                if (s1[i]=='?' || s2[i]=='?')
                {
                    indexOfQ = i;
                    break;
                }
            if (indexOfQ==-1)
                return s1 + " " + s2;

            int isBigger = 0;//-1 =r ; +1=l
            for (int i = 0; i < indexOfQ; i++)
            {
                if (s1[i] != s2[i])
                {
                    isBigger = s1[i] > s2[i] ? -1 : 1;
                    break;
                }
            }
            if (isBigger!=0)
            {
                if (isBigger==-1)
                {
                    if (s1[indexOfQ] == '?')
                        s1[indexOfQ] = '0';
                    if (s2[indexOfQ] == '?')
                        s2[indexOfQ] = '9';
                }
                else
                {
                    if (s1[indexOfQ] == '?')
                        s1[indexOfQ] = '9';
                    if (s2[indexOfQ] == '?')
                        s2[indexOfQ] = '0';
                }
                return Compare(s1, s2);
            }
            else //isBigger=0
            {
                if (s1[indexOfQ] == '?' && s2[indexOfQ]=='?')
                {
                    s1[indexOfQ] = '0';
                    s2[indexOfQ] = '0';
                    string v1 = Compare(s1, s2);
                    string v2 = "", v3 = "", v4="";
                    long v1Val = CountDifference(v1);
                    long v2Val = long.MaxValue, v3Val = long.MaxValue, v4Val=long.MaxValue;
                    s2[indexOfQ] = '1';
                    v2 = Compare(s1, s2);
                    v2Val = CountDifference(v2);
                    
                    s1[indexOfQ] = '1';
                    v3 = Compare(s1, s2);
                    v3Val = CountDifference(v3);

                    s2[indexOfQ] = '0';
                    v4 = Compare(s1, s2);
                    v4Val = CountDifference(v4);
                    if (v3Val < v2Val && v3Val < v1Val && v3Val < v4Val)
                        return v3;
                    else if (v4Val < v2Val && v4Val < v1Val)
                        return v4;
                    else if (v2Val < v1Val)
                        return v2;
                    else
                        return v1;
                }
                else
                {
                    if (s1[indexOfQ]=='?')
                    {
                        s1[indexOfQ] = s2[indexOfQ];
                        string v1 = Compare(s1, s2);
                        string v2="", v3="";
                        long v1Val = CountDifference(v1);
                        long v2Val = long.MaxValue, v3Val=long.MaxValue;
                        if (s2[indexOfQ]!='0')
                        {
                            s1[indexOfQ] = (char)(s2[indexOfQ] - 1);
                            v2 = Compare(s1, s2);
                            v2Val = CountDifference(v2);
                        }
                        if (s2[indexOfQ] != '9')
                        {
                            s1[indexOfQ] = (char)(s2[indexOfQ] + 1);
                            v3 = Compare(s1, s2);
                            v3Val = CountDifference(v3);
                        }
                        if (v3Val < v2Val && v3Val < v1Val)
                            return v3;
                        else if (v1Val < v2Val)
                            return v1;
                        else
                            return v2;
                    }
                    else
                    {
                        s2[indexOfQ] = s1[indexOfQ];
                        string v1 = Compare(s1, s2);
                        string v2 = "", v3 = "";
                        long v1Val = CountDifference(v1);
                        long v2Val = long.MaxValue, v3Val = long.MaxValue;
                        if (s1[indexOfQ] != '0')
                        {
                            s2[indexOfQ] = (char)(s1[indexOfQ] - 1);
                            v2 = Compare(s1, s2);
                            v2Val = CountDifference(v2);
                        }
                        if (s1[indexOfQ] != '9')
                        {
                            s2[indexOfQ] = (char)(s1[indexOfQ] + 1);
                            v3 = Compare(s1, s2);
                            v3Val = CountDifference(v3);
                        }
                        if (v3Val < v2Val && v3Val < v1Val)
                            return v3;
                        else if (v1Val < v2Val)
                            return v1;
                        else
                            return v2;
                    }
                }
            }

        }
        static long CountDifference(string v1)
        {
            string s1 = v1.Substring(0, v1.IndexOf(' '));
            string s2 = v1.Substring(v1.IndexOf(' ')+1);
            long n1 = Convert.ToInt64(s1);
            long n2 = Convert.ToInt64(s2);
            return (Math.Abs(n1 - n2));
        }
    }
}
