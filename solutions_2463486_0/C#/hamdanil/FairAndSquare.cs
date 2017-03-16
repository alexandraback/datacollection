using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Numerics;
using System.Text;
using System.IO;
using System.Linq;

namespace CodeJam
{
    class FairAndSquare
    {
        static void Main(string[] args)
        {
            new FairAndSquare().Solve();
        }

        void Solve()
        {
            //new FairAndSquarePrinter().Print();
            BigInteger[] numbers = File.ReadAllLines("fnsnumbers.data").Select(BigInteger.Parse).ToArray();
            using (var sc = new StreamReader("C-small-attempt0.in"))
            using (var sout = new StreamWriter("C-small.out"))
            {
                int cas = sc.Next<int>();
                for (int zz = 1; zz <= cas; zz++)
                {
                    long ans = 0;
                    var lo = BigInteger.Parse(sc.Next());
                    var high = BigInteger.Parse(sc.Next());

                    ans = numbers.Count(i => i >= lo && i <= high);


                    sout.WriteLine("Case #" + (zz) + ": " + ans);
                }
            }
        }

    }

    public static class Extensions
    {
        public static string Next(this StreamReader sr)
        {
            if (sr.EndOfStream) return null;
            StringBuilder sb = new StringBuilder();
            char ch;
            while (!Char.IsWhiteSpace(ch = (char)sr.Read()))
            {
                sb.Append(ch);
            }
            if (sb.Length == 0) return sr.Next();
            return sb.ToString();
        }

        public static T Next<T>(this StreamReader sr) where T : IConvertible
        {
            string s = sr.Next();
            if (s == null) throw new EndOfStreamException();
            return (T)Convert.ChangeType(s, typeof(T));
        }
    }

    internal class FairAndSquarePrinter
    {
        public void Print()
        {
            //Stopwatch sw = Stopwatch.StartNew();
            int c = 0;
            foreach (var n in GetFairAndSquareNumbers(GetNumbers().Concat(GetNumbersFrom2())).Concat(GetNumbersFrom1()).Distinct().OrderBy(i => i))
                Console.WriteLine(n);
            //Console.Error.WriteLine(sw.ElapsedMilliseconds);
        }

        private IEnumerable<string> GetNumbers()
        {
            return Enumerable.Range(0, 1 << 16).Select(i => i.ToString());
        }

        private IEnumerable<BigInteger> GetNumbersFrom1()
        {
            //Stopwatch sw = Stopwatch.StartNew();
            foreach (int i in Enumerable.Range(0, 1 << 18) )
            {
                //if(i % 100000 ==0) Console.Error.WriteLine(i + " " + sw.ElapsedMilliseconds);
                var s = Convert.ToString(i, 2);
                var p = Square(GetEvenPalindrome(s));
                if (IsPalindrome(p.ToString())) yield return p;
                foreach (var a in app.Select(a => s + a))
                {
                    var p2 = Square(GetOddPalindrome(a));
                    if (IsPalindrome(p2.ToString())) yield return p2;
                }
            }
            //Console.Error.WriteLine(sw.ElapsedMilliseconds);
        }

        private string[] app = new[] {"0", "1", "2"};
        private IEnumerable<string> GetNumbersFrom2()
        {
            BigInteger bi = 2;
            for(int i =0; i<= 26; i++)
            {
                yield return bi.ToString();
                foreach (var n in app.Select(s => bi.ToString() + s))
                    yield return n;
            }
        }

        private IEnumerable<BigInteger> GetFairAndSquareNumbers(IEnumerable<string> input)
        {
            foreach (var number in input)
            {
                var p1 = Square(GetEvenPalindrome(number));
                if (IsPalindrome(p1.ToString())) yield return p1;

                var p2 = Square(GetOddPalindrome(number));
                if (IsPalindrome(p2.ToString())) yield return p2;
            }
        }

        private BigInteger Square(BigInteger i)
        {
            return i*i;
        }

        private bool IsPalindrome(string nu)
        {
            return nu.Reverse().SequenceEqual(nu);
        }

        private BigInteger GetEvenPalindrome(string number)
        {
            return BigInteger.Parse(number + 
                new string(number.Reverse().ToArray()));
        }

        private BigInteger GetOddPalindrome(string number)
        {
            return BigInteger.Parse(number +
                new string(number.Reverse().Skip(1).ToArray()));
        }
    }
}
