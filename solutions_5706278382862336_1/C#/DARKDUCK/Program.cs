using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam2k14
{
    class Program
    {
        static Int64 decomposeBy2(Int64 Q)
        {
            while(Q%2 == 0)
            {
                Q /= 2;
            }
            return Q;
        }

        static Int64 answer(Int64 P, Int64 Q)
        {
            Int64 res = 0;
            while(P < Q)
            {
                res++;
                P *= 2;
            }
            return res;
        }
        static void Main(string[] args)
        {
            FileStream filestream = new FileStream(@"C:\Users\Guillaume\Documents\codeJam2k14\part3\ex1\out.txt", FileMode.Truncate);
            var streamwriter = new StreamWriter(filestream);
            streamwriter.AutoFlush = true;
            Console.SetOut(streamwriter);
            Console.SetError(streamwriter);
            System.IO.StreamReader file = new System.IO.StreamReader(@"C:\Users\Guillaume\Documents\codeJam2k14\part3\ex1\file.txt");
            int nbTestCases = Int32.Parse(file.ReadLine());
            for (int T = 1; T <= nbTestCases; T++)
            {
                Console.Write("Case #"+T+": ");
                String l = file.ReadLine();
                var parts = l.Split('/');
                Int64 P = Int64.Parse(parts[0]);
                Int64 Q = Int64.Parse(parts[1]);
                Int64 rest = decomposeBy2(Q);
                if (P % rest != 0)
                {
                     Console.WriteLine("impossible");
                }
                else
                {
                    P /= rest;
                    Q /= rest;
                    Int64 a = answer(P, Q);
                    if (a > 40) Console.WriteLine("impossible");
                    else Console.WriteLine(a);                    
                }
                
                   
            }
        }     
       
    }
}