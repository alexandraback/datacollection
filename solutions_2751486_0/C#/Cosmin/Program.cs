using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {

        static string readLine()
        { return Console.ReadLine().TrimStart().TrimEnd(); }
        static long readLong()
        { return long.Parse(readLine()); }
        static string[] readStrings()
        { return readLine().Split(' '); }
        static long[] readLongs()
        { string[] inp = readLine().Split(' '); 
          long[] ret = new long[inp.Length];
          for (int i = 0; i < inp.Length; i++) ret[i] = long.Parse(inp[i]);
          return ret;               
        }

        static bool vowel(char c){
            return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
        }

        static int mx(string s)
        {
            int r = 0;
            for(int i=0;i<s.Length;i++)
                if(vowel(s[i]))
                    return r;
                else r++;
            return r;
        }

        static long solve(string S, int N)
        {
            int[] A = new int[S.Length];
            for (int i = 0; i < S.Length; i++)
                A[i] = mx(S.Substring(i));

            int r=0;
            for (int i=0;i<S.Length-N+1;i++)
                for(int j=i+N-1; j<S.Length;j++){                        
                        for(int k=i;k<=j;k++)
                            if (Math.Min(A[k], j - k + 1) >= N)
                            { r++; break; }
                    }
            return r;
        }

        static void Main(string[] args)
        {
            Console.SetIn(new System.IO.StreamReader(@"c:\jam\a\A-small-attempt1.in")); //@"c:\jam\a\A-small-attempt0.in"  //@"c:\jam\a\A-large.in"
            Console.SetOut(new System.IO.StreamWriter(@"c:\jam\a\out.txt"));
            int T = int.Parse(Console.ReadLine());
            for (int caseNo = 1; caseNo <= T; caseNo++)
            {
                string[] inp = readStrings();
                string S = inp[0];
                int N = int.Parse(inp[1]);
                
                long grade = solve(S, N);

                Console.WriteLine("Case #{0}: {1}", caseNo, grade);
            }
            Console.Out.Flush();
            //Console.ReadKey();
        }
    }
}
