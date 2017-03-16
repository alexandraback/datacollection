using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Diagnostics;
using System.Collections.Generic;
using System.Numerics;
using System.Linq;

public class ClassName
{
    public static void Main()
    {
        new ClassName().Entry();
    }//Main

    StreamReader sr = new StreamReader(@"C:\Users\user1\Downloads\C-large.in");
    StreamWriter sw = new StreamWriter(@"C:\Users\user1\Documents\Visual Studio 2012\Projects\GCJ\GCJ\C.txt");

    const int repeat = 20;
    const int offset = 10;

    void Entry()
    {
        int T = intRead();
        for (int i = 0; i < T; i++)
        {
            string res = Solve();
            //sw.WriteLine("Case #1:\n");
            Write("Case #" + (i + 1) + ": " + res);
        }//for i
        sw.Close();
        sr.Close();
    }

    private string Solve()
    {
        var tmp = longSplit(' ');
        long L = tmp[0];
        long X = tmp[1];
        bool res = true;
        string str = strRead();
        var complex = str.ToCharArray().Select(x=>new Complex(1,x)).ToArray();
        var mult = new Complex();
        foreach (var item in complex)
    	{
            mult = mult * item;
    	}//foreach item
        int len = str.Length;
        Complex I = new Complex(1, 'i');
        Complex J = new Complex(1, 'j');
        Complex K = new Complex(1, 'k');

        long prevIndex = 0;
        Complex cur = new Complex();
        while (prevIndex < repeat*len && cur != I)
        {
            cur = cur * complex[prevIndex % len];
            prevIndex++;
        }//while
        res &= cur == I;

        long suffIndex = X * L - 1;
        cur = new Complex();
        while (suffIndex>=X*L-1-repeat*len&&cur!=K)
        {
            cur = complex[(suffIndex % len + len) % len] * cur;
            suffIndex--;
        }//while
        res &= cur == K;
        res &= prevIndex <= suffIndex;
        if (suffIndex-prevIndex>=repeat*len)
        {
            cur = new Complex();
            while (prevIndex%len!=0)
            {
                cur = cur * complex[prevIndex % len];
                prevIndex++;
            }//while
            suffIndex -=prevIndex;
            long rep = suffIndex / len - repeat / 2;
            suffIndex -= rep * len;
            cur = cur*Pow(mult, rep);
            for (int i = 0; i <= suffIndex; i++)
			{
			    cur = cur*complex[i%len];
			}//for i
        }//if
        else
        {
            cur = new Complex();
            while (prevIndex<=suffIndex)
            {
                cur = cur * complex[prevIndex % len];
                prevIndex++;
            }//while
        }//else
        res &= cur == J;
        return (res ? "YES" : "NO");
    }

    private Complex Pow(Complex a, long n)
    {
        Complex res = new Complex();
        Complex tmp = a;
        for (; n > 0; n >>= 1)
        {
            if ((n & 1) == 1)
                res = res * tmp;
            tmp = tmp * tmp;
        }
        return res;
    }//Pow


    public class Complex
    {
        public int sign ;
        public char num;

        public Complex()
        {
            sign = 1;
            num = '1';
        }

        public Complex(int sign,char num)
        {
            this.sign = sign;
            this.num = num;
        }

        public static Complex operator*(Complex a,Complex b)
        {
            var res = new Complex();
            res.sign = a.sign*b.sign;
            if (a.num =='1')
            {
                res.num = b.num;
            }//if
            else if (b.num=='1')
            {
                res.num = a.num;
            }//if
            else if (a.num ==b.num)
            {
                res.sign *= -1;
                res.num = '1';
            }//if
            else if (a.num > b.num)
            {
                res = b * a;
                res.sign *= -1;
            }//if
            else if (a.num=='i'&&b.num=='j')
            {
                res.num = 'k';
            }//if
            else if (a.num=='i'&&b.num=='k')
            {
                res.sign *= -1;
                res.num = 'j';
            }//if
            else if (a.num == 'j' && b.num == 'k')
            {
                res.num = 'i';
            }//if
            else
            {
                throw new ArgumentException();
            }
            return res;
        }

        public static bool operator==(Complex a,Complex b)
        {
            return a.sign == b.sign && a.num == b.num;
        }

        public static bool operator !=(Complex a, Complex b)
        {
            return a.sign != b.sign || a.num != b.num;
        }

    }


    void Write(string str)
    {
        Console.WriteLine(str);
        sw.WriteLine(str);
    }

    string strRead()
    {
        return sr.ReadLine();
    }

    int intRead()
    {
        return int.Parse(sr.ReadLine());
    }

    long longRead()
    {
        return long.Parse(sr.ReadLine());
    }

    double doubleRead()
    {
        return double.Parse(sr.ReadLine());
    }

    string[] strSplit(char c)
    {
        return sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries);
    }

    int[] intSplit(char c)
    {
        return Array.ConvertAll<string, int>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), int.Parse);
    }

    long[] longSplit(char r)
    {
        return Array.ConvertAll<string, long>(sr.ReadLine().Split(new char[] { r }, StringSplitOptions.RemoveEmptyEntries), long.Parse);
    }

    double[] doubleSplit(char c)
    {
        return Array.ConvertAll<string, double>(sr.ReadLine().Split(new char[] { c }, StringSplitOptions.RemoveEmptyEntries), double.Parse);
    }

}//ClassName