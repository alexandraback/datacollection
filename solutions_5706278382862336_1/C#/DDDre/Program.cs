using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace jam14_1c_a
{
    class Program
    {
        static void Main(string[] args)
        {
            var a = GCD(2564548782, 31488);
            StreamReader SR = new StreamReader(@"A-large.in");
            StreamWriter SW = new StreamWriter("out.out");
            var s = SR.ReadLine();
            var n = Int32.Parse(s);
            for (var i = 0; i < n; i++)
            {
                StringBuilder sb = new StringBuilder();
                sb.Append(String.Format("Case #{0}: ", i + 1));
                s = SR.ReadLine();
                var ss = s.Split('/');
                var P = Int64.Parse(ss[0]);
                var Q = Int64.Parse(ss[1]);
                var gcd = GCD(P, Q);
                P = P / gcd;
                Q = Q / gcd;
                long bb = 1;
                long power = 0;
                long answ = 1;
                while (Q > bb)
                {
                    bb *= 2;
                    power++;
                    if (Q == bb) break;
                }
                if (Q == bb)
                {
                    bb = bb / 2;

                    while (bb > P)
                    {
                        answ++;
                        bb = bb / 2;
                    }
                    sb.Append(answ.ToString());
                }
                else
                    sb.Append("impossible");
                SW.WriteLine(sb);
            }
            SW.Close();
            SR.Close();
        }

        static Int64 GCD(Int64 firstNumber, Int64 secondNumber)
        {
            if (firstNumber > secondNumber)
            {

                var a = secondNumber;

                secondNumber = firstNumber;

                firstNumber = a;



            }




            while (secondNumber != 0)
            {

                var GCD = firstNumber % secondNumber;

                firstNumber = secondNumber;

                secondNumber = GCD;



            }
            return firstNumber;
        }
    }
}
