using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014_1C_A
{
    public struct Fraction : IEquatable<Fraction>, IComparable<Fraction>
    {
        private long numerator;
        private long denominator;

        public long Numerator { get { return numerator; } }
        public long Denominator { get { return denominator; } }

        public Fraction(long num) : this(num, 1L) { }

        public Fraction(long num, long den)
        {
            if (den == 0L)
                throw new DivideByZeroException("Fraction cannot have zero denominator");
            var gcd = Gcd(num, den);
            numerator = num / gcd;
            denominator = den / gcd;
            if (numerator == 0L)
                denominator = 1L;
            else if (denominator < 0)
            {
                denominator = -denominator;
                numerator = -numerator;
            }
        }

        public bool Equals(Fraction other)
        {
            return this == other;
        }

        public int CompareTo(Fraction other)
        {
            if (this == other)
                return 0;
            return this < other ? -1 : 1;
        }

        public override bool Equals(object obj)
        {
            return Equals((Fraction)obj);
        }

        public override int GetHashCode()
        {
            unchecked { return numerator.GetHashCode() * 29 + denominator.GetHashCode(); }
        }

        public override string ToString()
        {
            return denominator == 1L ? numerator.ToString() : string.Format("{0}/{1}", numerator, denominator);
        }

        #region Operators
        public static implicit operator Fraction(long n)
        {
            return new Fraction(n);
        }

        public static explicit operator long(Fraction f)
        {
            return f.Numerator / f.Denominator;
        }

        public static explicit operator double(Fraction f)
        {
            return (double)f.Numerator / f.Denominator;
        }

        public static bool operator <(Fraction a, Fraction b)
        {
            return a.numerator * b.denominator < b.numerator * a.denominator;
        }

        public static bool operator <=(Fraction a, Fraction b)
        {
            return a.numerator * b.denominator <= b.numerator * a.denominator;
        }

        public static bool operator >(Fraction a, Fraction b)
        {
            return a.numerator * b.denominator > b.numerator * a.denominator;
        }

        public static bool operator >=(Fraction a, Fraction b)
        {
            return a.numerator * b.denominator >= b.numerator * a.denominator;
        }

        public static bool operator ==(Fraction a, Fraction b)
        {
            return a.numerator == b.numerator && a.denominator == b.denominator;
        }

        public static bool operator !=(Fraction a, Fraction b)
        {
            return a.numerator != b.numerator || a.denominator != b.denominator;
        }

        public static Fraction operator *(Fraction a, Fraction b)
        {
            return new Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
        }

        public static Fraction operator /(Fraction a, Fraction b)
        {
            return new Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
        }

        public static Fraction operator +(Fraction a, Fraction b)
        {
            return new Fraction(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
        }

        public static Fraction operator -(Fraction a, Fraction b)
        {
            return new Fraction(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
        }

        public static Fraction operator -(Fraction a)
        {
            return new Fraction(-a.numerator, a.denominator);
        }
        #endregion

        public static long Gcd(long a, long b)
        {
            while (b != 0)
            {
                var t = b;
                b = a % b;
                a = t;
            }
            return a;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            var testCount = int.Parse(Console.ReadLine());
            for (var testN = 1; testN <= testCount; testN++)
            {
                var parts = Console.ReadLine().Split(new []{'/'}).Select(long.Parse).ToArray();
                var P = parts[0];
                var Q = parts[1];

                var f = new Fraction(P, Q);

                var c = f.Denominator;
                var p = 0;
                while ((c & 1) == 0)
                {
                    c >>= 1;
                    p++;
                }
                String result = "impossible";
                if (c == 1)
                {
                    var p1 = 0;
                    var c1 = f.Numerator;
                    while (c1 != 0)
                    {
                        c1 >>= 1;
                        p1++;
                    }
                    result = (p - p1 + 1).ToString();
                }

                Console.WriteLine("Case #{0}: {1}", testN, result);
            }
        }
    }
}
