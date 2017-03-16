using System;
using System.Globalization;
using System.IO;
using System.Threading;

namespace Dijkstra
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            //const string filename = @"..\..\sample.in.txt";
            //const string filename = @"..\..\C-small-attempt0.in";
            const string filename = @"..\..\C-large.in";

            Thread.CurrentThread.CurrentCulture = CultureInfo.InvariantCulture;

            DateTime begin = DateTime.Now;
            DateTime current = DateTime.Now;

            using (var reader = new StreamReader(filename))
            {
                using (var writer = new StreamWriter(filename.Replace(".in", ".out"), false))
                {
                    int n = int.Parse(reader.ReadLine());
                    for (int i = 1; i <= n; i++)
                    {
                        Console.Write("N=" + i + " Time=");
                        Process(i, reader, writer);
                        Console.WriteLine((DateTime.Now - current).ToString().Substring(4));
                        current = DateTime.Now;
                    }
                }
            }

            Console.WriteLine("Time=" + (DateTime.Now - begin));
            Console.ReadLine();
        }

        private static void Process(int Case, TextReader reader, TextWriter writer)
        {
            string[] ss = reader.ReadLine().Split(' ');
            int L = int.Parse(ss[0]);
            long X = long.Parse(ss[1]);

            long lx = L*X;

            string s = reader.ReadLine();

            if (L*X < 3)
            {
                Console.WriteLine("Case #{0}: NO", Case);
                writer.WriteLine("Case #{0}: NO", Case);
                return;
            }

            char one = s[0];
            {
                for (int i = 1; i < s.Length; i++)
                {
                    one = M(one, s[i]);
                }
            }
            char two = M(one, one);
            char three = M(one, two);

            int ii = -1;
            if (s[0] == 'i')
            {
                ii = 0;
            }
            else
            {
                char r = s[0];
                if (M(one, r) == 'i')
                    ii = L;
                else if (M(two, r) == 'i')
                    ii = 2*L;
                else if (M(three, r) == 'i')
                    ii = 3*L;

                for (int i = 1; i < s.Length; i++)
                {
                    r = M(r, s[i]);
                    if (r == 'i')
                    {
                        ii = i;
                        break;
                    }
                    if (M(one, r) == 'i')
                    {
                        if (ii == -1 || ii > L + i)
                            ii = L + i;
                    }
                    else if (M(two, r) == 'i')
                    {
                        if (ii == -1 || ii > 2*L + i)
                            ii = 2*L + i;
                    }
                    else if (M(three, r) == 'i')
                    {
                        if (ii == -1 || ii > 3*L + i)
                            ii = 3*L + i;
                    }
                }
            }

            long jj = -1;
            if (ii >= 0)
            {
                if (s[s.Length - 1] == 'k')
                {
                    jj = lx - 1;
                }
                else
                {
                    char r = s[s.Length - 1];
                    if (M(r, one) == 'k')
                        jj = lx - L - 1;
                    else if (M(r, two) == 'k')
                        jj = lx - 2*L - 1;
                    else if (M(r, three) == 'k')
                        jj = lx - 3*L - 1;

                    for (int i = s.Length - 2; i >= 0; i--)
                    {
                        r = M(s[i], r);
                        if (r == 'k')
                        {
                            jj = lx - L + i;
                            break;
                        }
                        if (M(r, one) == 'k')
                        {
                            if (jj == -1 || jj < lx - 2*L + i)
                                jj = lx - 2*L + i;
                        }
                        else if (M(r, two) == 'k')
                        {
                            if (jj == -1 || jj < lx - 3*L + i)
                                jj = lx - 3*L + i;
                        }
                        else if (M(r, three) == 'k')
                        {
                            if (jj == -1 || jj < lx - 4*L + i)
                                jj = lx - 4*L + i;
                        }
                    }
                }
            }

            bool fk = false;
            if (ii >= 0 && jj - ii > 1)
            {
                int iinterval = ii/L;
                long jinterval = jj/L;
                if (iinterval == jinterval)
                {
                    ii = ii%L;
                    jj = jj%L;

                    char r = s[ii + 1];
                    for (int i = ii + 2; i < jj; i++)
                    {
                        r = M(r, s[i]);
                    }
                    if (r == 'j')
                        fk = true;
                }
                else
                {
                    ii = ii%L;
                    char r = '1';
                    if (ii != s.Length - 1)
                        r = s[ii + 1];
                    for (int i = ii + 2; i < s.Length; i++)
                    {
                        r = M(r, s[i]);
                    }

                    jj = jj%L;

                    long delta = (jinterval - iinterval - 1)%4;

                    switch (delta)
                    {
                        case 0:
                            break;
                        case 1:
                            r = M(r, one);
                            break;
                        case 2:
                            r = M(r, two);
                            break;
                        case 3:
                            r = M(M(r, one), two);
                            break;
                    }

                    for (int i = 0; i < jj; i++)
                    {
                        r = M(r, s[i]);
                    }
                    if (r == 'j')
                        fk = true;
                }
            }


            if (fk)
            {
                Console.WriteLine("Case #{0}: YES", Case);
                writer.WriteLine("Case #{0}: YES", Case);
            }
            else
            {
                Console.WriteLine("Case #{0}: NO", Case);
                writer.WriteLine("Case #{0}: NO", Case);
            }
        }

        private static char M(char a, char b)
        {
            bool m = false;
            switch (a)
            {
                case '0':
                    a = '1';
                    m = true;
                    break;
                case 'I':
                    a = 'i';
                    m = true;
                    break;
                case 'J':
                    a = 'j';
                    m = true;
                    break;
                case 'K':
                    a = 'k';
                    m = true;
                    break;
            }
            switch (b)
            {
                case '0':
                    b = '1';
                    m = !m;
                    break;
                case 'I':
                    b = 'i';
                    m = !m;
                    break;
                case 'J':
                    b = 'j';
                    m = !m;
                    break;
                case 'K':
                    b = 'k';
                    m = !m;
                    break;
            }

            char res = '1';

            switch (a)
            {
                case '1':
                    switch (b)
                    {
                        case '1':
                            res = '1';
                            break;
                        case 'i':
                            res = 'i';
                            break;
                        case 'j':
                            res = 'j';
                            break;
                        case 'k':
                            res = 'k';
                            break;
                    }
                    break;
                case 'i':
                    switch (b)
                    {
                        case '1':
                            res = 'i';
                            break;
                        case 'i':
                            res = '0';
                            break;
                        case 'j':
                            res = 'k';
                            break;
                        case 'k':
                            res = 'J';
                            break;
                    }
                    break;
                case 'j':
                    switch (b)
                    {
                        case '1':
                            res = 'j';
                            break;
                        case 'i':
                            res = 'K';
                            break;
                        case 'j':
                            res = '0';
                            break;
                        case 'k':
                            res = 'i';
                            break;
                    }
                    break;
                case 'k':
                    switch (b)
                    {
                        case '1':
                            res = 'k';
                            break;
                        case 'i':
                            res = 'j';
                            break;
                        case 'j':
                            res = 'I';
                            break;
                        case 'k':
                            res = '0';
                            break;
                    }
                    break;
            }
            if (m)
            {
                switch (res)
                {
                    case '0':
                        res = '1';
                        break;
                    case '1':
                        res = '0';
                        break;
                    case 'i':
                        res = 'I';
                        break;
                    case 'j':
                        res = 'J';
                        break;
                    case 'k':
                        res = 'K';
                        break;
                    case 'I':
                        res = 'i';
                        break;
                    case 'J':
                        res = 'j';
                        break;
                    case 'K':
                        res = 'k';
                        break;
                }
            }

            return res;
        }
    }
}