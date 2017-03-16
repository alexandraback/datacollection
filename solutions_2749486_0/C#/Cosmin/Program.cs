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

        static string P = "";

        /*static void solver(int x, int y,int l,string s){
            if (P != "") return;
            if (l > 10) return;
            if(x==0 && y==0){
               P = s;
               return;
            }
            if(x<0) solver(x + l, y, l + 1, s + "E");
            if (P != "") return;
            if (x > 0) solver(x - l, y, l + 1, s + "W");
            if (P != "") return;
            if (y<0) solver(x, y + l, l + 1, s + "N");
            if (P != "") return;
            if (y >0) solver(x, y - l, l + 1, s + "S");
        }*/

        static string solve(int X, int Y)
        {
            string r = "";
            int l = 1;
            int x = 0, y = 0;
            while (x != X || y!=Y)
            {
                //int dx = Math.Abs(x - X);
                //int dy = Math.Abs(y - Y);

                if (x + l <= X || (x > X && x - l < X))
                {
                    x += l++;
                    r += "E";
                } else if (x - l >= X || x<X)
                {
                    x -= l++;
                    r += "W";
                }            
                if (y + l <= Y || (y>Y && y-l<Y))
                {
                    y += l++;
                    r += "N";
                } else if (y -l >= Y || y<Y)
                {
                    y -= l++;
                    r += "S";
                }
            }
            //P = "";
            //solver(-X, -Y, 1, "");
            //return P;
            return r;
        }

        static void Main(string[] args)
        {
            Console.SetIn(new System.IO.StreamReader(@"c:\jam\b\B-small-attempt1.in")); //@"c:\jam\b\B-small-attempt0.in"  //@"c:\jam\B\B-large.in"
            Console.SetOut(new System.IO.StreamWriter(@"c:\jam\b\out.txt"));
            int T = int.Parse(Console.ReadLine());
            for (int caseNo = 1; caseNo <= T; caseNo++)
            {
                string[] inp = readStrings();
                int X = int.Parse(inp[0]);
                int Y = int.Parse(inp[1]);
                    
                string moves = solve(X,Y);

                Console.WriteLine("Case #{0}: {1}", caseNo, moves);
            }
            Console.Out.Flush();
            //Console.ReadKey();
        }
    }
}
