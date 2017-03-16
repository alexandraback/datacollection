using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Org.BouncyCastle.Math;
using System.IO;

namespace bullseye
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter tw = new StreamWriter("output.txt", true);
            TextReader tr = new StreamReader("A-large.in");
            tw.AutoFlush = true;


            int cases = Convert.ToInt32(tr.ReadLine());

            for (int _case = 1; _case <= cases; _case++)
            {
                Char _ch = Convert.ToChar(tr.Read());

                String _r = "";
                String _t = "";

                while (char.IsNumber(_ch))
                {
                    _r += _ch;
                    _ch = Convert.ToChar(tr.Read());
                }

                BigInteger r = new BigInteger(_r);
                _ch = Convert.ToChar(tr.Read());
                //_ch = Convert.ToChar(tr.Read());
                //tw.WriteLine("Arxiko : " + _start);
                Console.WriteLine("Arxiko : " + _r);

                while (char.IsNumber(_ch))
                {
                    _t += _ch;
                    //try
                    //{
                    _ch = Convert.ToChar(tr.Read());
                    //}
                    //catch
                    //{
                    //    break;
                    //}
                }
                BigInteger t = new BigInteger(_t);
                //tr.ReadLine();

                //tw.WriteLine("Teliko : " + _end);
                Console.WriteLine("Teliko : " + _t);

                BigInteger _delta = Delta(r, t);
                BigInteger _v = v(_delta, r);

                tw.WriteLine("Case #" + _case + ": " + _v );


            }

            Console.Read();
        }
        public static BigInteger Delta(BigInteger _r, BigInteger _t)
        {
            BigInteger a = _r.Multiply(new BigInteger("2"));
            BigInteger b = a.Add(new BigInteger("-1"));
            BigInteger c = b.Pow(2);

            BigInteger d = _t.Multiply(new BigInteger("8"));

            return c.Add(d);
        }

        public static BigInteger NewtonSqrt(BigInteger N)
        {
            BigInteger G = new BigInteger((N.ShiftRight((N.BitLength + 1) / 2)).ToString());

            BigInteger LastG = null;

            BigInteger One = new BigInteger("1");

            while (true)
            {
                LastG = G;
                G = N.Divide(G).Add(G).ShiftRight(1);
                int i = G.CompareTo(LastG);
                if (i == 0) return G;
                if (i < 0)
                {
                    if (LastG.Subtract(G).CompareTo(One) == 0)
                        if (G.Multiply(G).CompareTo(N) < 0 && LastG.Multiply(LastG).CompareTo(N) > 0) return G;

                }

                else
                {
                    if (G.Subtract(LastG).CompareTo(One) == 0)
                        if (LastG.Multiply(LastG).CompareTo(N) < 0 && G.Multiply(G).CompareTo(N) > 0) return LastG;
                }
            }
        }

        public static BigInteger v(BigInteger _delta, BigInteger _r)
        {
            BigInteger a = _r.Multiply(new BigInteger("2"));
            BigInteger b = a.Add(new BigInteger("-1")).Negate();

            BigInteger c = NewtonSqrt(_delta);

            BigInteger d = c.Add(b);

            return d.Divide(new BigInteger("4"));
        }
    }
}
