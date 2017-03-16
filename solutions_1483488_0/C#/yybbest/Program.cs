using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;
namespace recycled
{
    class Program
    {
        const bool isDebug = true;
        static void Main(string[] args)
        {

            string infilename = "C-small-attempt0.in", outfilename = "C-small-attempt0.out";
            StreamReader sr=null;
            StreamWriter sw=null;
            int T = 0;
            string strLine = "";

            if (isDebug)
            {
                sr = new StreamReader(infilename);
                sw = new StreamWriter(outfilename);
                T = int.Parse(sr.ReadLine().ToString());
            }
            else
            {
                T = 1;
            }

            int A; int B;

            string[] str;
            int result = 0;

            int N = 0;
            int cycNum=0;
            for (int i = 1; i <= T; ++i)
            {
                if (isDebug)
                {
                    strLine = sr.ReadLine().ToString();
                }
                else
                {
                    strLine = "1111 2222";
                }

                str = strLine.Split(' ');
                A = int.Parse(str[0]);
                B = int.Parse(str[1]);
                result = 0;
                for (int n = A; n < B; ++n)
                {
                    result+=iscycleNum(n,A,B);
                }

                if (isDebug)
                {
                    sw.WriteLine("Case #{0}: {1}", i, result);
                }
            }
            if (isDebug)
            {
                sw.Flush();
            }
        }

        static int iscycleNum(int n,int A,int B)
        {
            int m = 0;
            string str = n.ToString();
            int N = str.Length;
            StringBuilder Str2=new StringBuilder(str);
            Str2.Append(str);
            string str2str = Str2.ToString();
            StringBuilder retStr;
            bool isfound = false;
            //int cnt = 0;
            HashSet<int> set = new HashSet<int>();
            for (int j = 1; j < N; ++j)
            {
                retStr = new StringBuilder(str2str, j, N, N);
                //if(retStr[0]=='0')continue;
                m=int.Parse(retStr.ToString());
                if (m <=n) continue;
                if (m <= B)
                {
                    set.Add(m);
                   // cnt++;
                }
            }
            return set.Count;
        }
    }
}
