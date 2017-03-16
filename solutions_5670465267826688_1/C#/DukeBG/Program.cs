using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Diagnostics;

namespace codejam03
{
    class Program
    {
        // ijk1!IJK
        static char multiply(char a, char b)
        {
            switch(a)
            {
                case 'i': switch(b)
                    {
                        case 'i': return '!';
                        case 'j': return 'k';
                        case 'k': return 'J';
                        case '1': return 'i';
                        case '!': return 'I';
                        case 'I': return '1';
                        case 'J': return 'K';
                        case 'K': return 'j';
                        default: return '.';
                    }
                case 'I': switch (b)
                    {
                        case 'i': return '1';
                        case 'j': return 'K';
                        case 'k': return 'j';
                        case '1': return 'I';
                        case '!': return 'i';
                        case 'I': return '!';
                        case 'J': return 'k';
                        case 'K': return 'J';
                        default: return '.';
                    }
                case '1': switch (b)
                    {
                        case 'i': return 'i';
                        case 'j': return 'j';
                        case 'k': return 'k';
                        case '1': return '1';
                        case '!': return '!';
                        case 'I': return 'I';
                        case 'J': return 'J';
                        case 'K': return 'K';
                        default: return '.';
                    }
                case '!': switch (b)
                    {
                        case 'i': return 'I';
                        case 'j': return 'J';
                        case 'k': return 'K';
                        case '1': return '!';
                        case '!': return '1';
                        case 'I': return 'i';
                        case 'J': return 'j';
                        case 'K': return 'k';
                        default: return '.';
                    }
                case 'j': switch (b)
                    {
                        case 'i': return 'K';
                        case 'j': return '!';
                        case 'k': return 'i';
                        case '1': return 'j';
                        case '!': return 'J';
                        case 'I': return 'k';
                        case 'J': return '1';
                        case 'K': return 'I';
                        default: return '.';
                    }
                case 'J': switch (b)
                    {
                        case 'i': return 'k';
                        case 'j': return '1';
                        case 'k': return 'I';
                        case '1': return 'J';
                        case '!': return 'j';
                        case 'I': return 'K';
                        case 'J': return '!';
                        case 'K': return 'i';
                        default: return '.';
                    }
                case 'k': switch (b)
                    {
                        case 'i': return 'j';
                        case 'j': return 'I';
                        case 'k': return '!';
                        case '1': return 'k';
                        case '!': return 'K';
                        case 'I': return 'J';
                        case 'J': return 'i';
                        case 'K': return '1';
                        default: return '.';
                    }
                case 'K': switch (b)
                    {
                        case 'i': return 'J';
                        case 'j': return 'i';
                        case 'k': return '1';
                        case '1': return 'K';
                        case '!': return 'k';
                        case 'I': return 'j';
                        case 'J': return 'I';
                        case 'K': return '!';
                        default: return '.';
                    }
                default: return '_';
            }

        }

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("in");
            FileStream fsOut = new FileStream("out", FileMode.Create);
            StreamWriter sw = new StreamWriter(fsOut);
            sw.AutoFlush = true;
            int testCount = int.Parse(sr.ReadLine());
            for (int i = 0; i < testCount; i++)
            {
                sw.Write(string.Format("Case #{0}: ", i + 1));
                string[] data1 = sr.ReadLine().Split(' ');
                int l = int.Parse(data1[0]);
                Int64 x = Int64.Parse(data1[1]);

                string data = sr.ReadLine(); Debug.Assert(data.Length == l);

                if (SolveTest(l, x, data))
                    sw.WriteLine("YES");
                else
                    sw.WriteLine("NO");
                    
            }
            fsOut.Close();
        }

        private static bool SolveTest(int l, Int64 x, string data)
        {
            char c = '1';
            char cTotal = '1';
            bool iCaptured = false;
            bool jCaptured = false;
            bool kCaptured = false;
            byte xPassed = 0;
            for (int jj = 0; jj < x; jj++)
            {
                for (int j = 0; j < l; j++)
                {
                    c = multiply(c, data[j]);
                    cTotal = multiply(cTotal, data[j]);
                    if (!iCaptured)
                    {
                        if (c == 'i')
                        {
                            iCaptured = true;
                            c = '1';
                            xPassed = 0;
                        }
                    }
                    else
                    {
                        if (!jCaptured)
                        {
                            if (c == 'j')
                            {
                                jCaptured = true;
                                c = '1';
                                xPassed = 0;
                            }
                        }
                        else
                        {
                            if (!kCaptured)
                            {
                                if (c == 'k')
                                {
                                    kCaptured = true;
                                    c = '1';
                                    xPassed = 0;
                                }
                            }
                            else
                            { /*omglol, we already captured everything*/ }
                        }
                    }
                }
                if (xPassed > 4) return false;
                xPassed++;
                if (kCaptured)
                {
                    //оставшееся должно домножиться до 1
                    var res = '1';
                    for (int t = 1; t <= (x - jj - 1) % 4; t++)
                        res = multiply(res, cTotal);
                    return multiply(c, res) == '1';
                }
            }
            return false;
            //if (kCaptured && c == '1')
            //    sw.WriteLine("YES");
            //else
            //    sw.WriteLine("NO");

            //if (kCaptured && c == '1')
            //{
            //    if (x % 2 == 1)
            //        sw.WriteLine("YES");
            //    else
            //        sw.WriteLine("NO");
            //}
            //if (cTotal == '1')
            //    sw.WriteLine("NO");
            //if (cTotal == '!' && (x % 2 == 0))
            //    sw.WriteLine("NO");
            //if ("ijkIJK".Contains(cTotal) && (x % 4 != 2))
            //    sw.WriteLine("NO");
        }
    }
}
