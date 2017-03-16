using System;
using System.CodeDom;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2016
{
    class Program
    {

        /*
                static int toBase(int num, int toBase)
                {
                    for (int d = 0; d < 32; d++)
                    {
                        if ((start & (1 << d)) > 0)
                        {
                            upper = BigInteger.Add(upper, BigInteger.Pow(baseN, d));
                        }
                    }
                }*/

        private static bool test = false;
        // c:\users\erickul\documents\visual studio 2015\Projects\GCJ2016\GCJ2016\Program.cs
        static void Main(string[] args)
        {
            string file = "b-small-attempt3.in";
            if (test) file = "test.txt";

            string[] lines = File.ReadAllLines(@"c:\Users\erickul\Documents\Visual Studio 2015\Projects\GCJ2016\GCJ2016\" + file);
            StringBuilder output = new StringBuilder();
            int t = int.Parse(lines[0]);
            int nextLine = 1;
            for (int i = 1; i <= t; i++)
            {
                output.Append($"CASE #{i}: ");
                string n = lines[nextLine];
                nextLine++;
                char[] a = n.Split(' ')[0].ToCharArray();
                var b = n.Split(' ')[1].ToCharArray();

                int comp = 0;
                GetValue(0, a, b, comp);
                output.AppendLine(new string(a) + " " + new string(b));
            }
            Console.WriteLine(output.ToString());
            File.WriteAllText(@"c:\Users\erickul\Documents\Visual Studio 2015\Projects\GCJ2016\GCJ2016\a2.out", output.ToString());
        }

        private static int GetValue(int j, char[] a, char[] b, int comp)
        {
            if (j == a.Length)
            {
                return Math.Abs(int.Parse(new string(a)) - int.Parse(new string(b)));
            }

            if (a[j] == '?')
            {
                if (b[j] == '?')
                {
                    if (comp == 0)
                    {
                        a[j] = '0';
                        b[j] = '0';
                        int val = GetValue(j + 1, (char[])a.Clone(), (char[])b.Clone(), comp);
                        a[j] = '1';
                        b[j] = '0';
                        int val1 = GetValue(j + 1, (char[])a.Clone(), (char[])b.Clone(), 1);
                        a[j] = '0';
                        b[j] = '1';
                        int val2 = GetValue(j + 1, (char[])a.Clone(), (char[])b.Clone(), -1);
                        comp = -1;

                        if (val1 <= val2)
                        {
                            comp = 1;
                            val2 = val1;
                            a[j] = '1';
                            b[j] = '0';
                        }

                        if (val <= val2)
                        {
                            comp = 0;
                            a[j] = '0';
                            b[j] = '0';
                        }
                        return GetValue(j + 1, a, b, comp);

                    }
                    else if (comp < 0)
                    {
                        a[j] = '9';
                        b[j] = '0';
                        return GetValue(j + 1, a, b, comp);
                    }
                    else
                    {
                        b[j] = '9';
                        a[j] = '0';
                        return GetValue(j + 1, a, b, comp);
                    }
                }
                else
                {
                    if (comp == 0)
                    {
                        a[j] = b[j];
                        int val = GetValue(j + 1, (char[])a.Clone(), (char[])b.Clone(), comp);
                        if (b[j] != '9')
                        {
                            char old = a[j];
                            a[j] = (char)(b[j] + 1);
                            int val1 = GetValue(j + 1, (char[])a.Clone(), (char[])b.Clone(), 1);
                            if (val <= val1)
                            {
                                a[j] = old;
                            }
                            else
                            {
                                comp = 1;
                            }
                        }

                        if (b[j] != '0')
                        {
                            char old = a[j];
                            a[j] = (char)(b[j] - 1);
                            int val1 = GetValue(j + 1, (char[])a.Clone(), (char[])b.Clone(), -1);
                            if (val < val1)
                            {
                                a[j] = old;
                            }
                            else
                            {
                                comp = -1;
                            }
                        }

                        return GetValue(j + 1, a, b, comp);
                    }
                    else if (comp < 0)
                    {
                        a[j] = '9';
                        return GetValue(j + 1, a, b, comp);

                    }
                    else
                    {
                        a[j] = '0';
                        return GetValue(j + 1, a, b, comp);

                    }
                }
            }
            else if (b[j] == '?')
            {
                if (comp == 0)
                {
                    b[j] = a[j];
                    int val = GetValue(j + 1, (char[])a.Clone(), (char[])b.Clone(), comp);
                    if (a[j] != '9')
                    {
                        char old = b[j];
                        b[j] = (char)(a[j] + 1);
                        int val1 = GetValue(j + 1, (char[])a.Clone(), (char[])b.Clone(), -1);
                        if (val <= val1)
                        {
                            b[j] = old;
                        }
                        else
                        {
                            comp = -1;
                        }
                    }

                    if (a[j] != '0')
                    {
                        char old = b[j];
                        b[j] = (char)(a[j] - 1);
                        int val1 = GetValue(j + 1, (char[])a.Clone(), (char[])b.Clone(), 1);
                        if (val < val1)
                        {
                            b[j] = old;
                        }
                        else
                        {
                            comp = 1;
                        }
                    }

                    return GetValue(j + 1, a, b, comp);
                }
                else if (comp < 0)
                {
                    b[j] = '0';
                    return GetValue(j + 1, a, b, comp);

                }
                else
                {
                    b[j] = '9';
                    return GetValue(j + 1, a, b, comp);
                }
            }
            else if (comp == 0 && a[j] < b[j])
            {
                comp = -1;
                return GetValue(j + 1, a, b, comp);

            }
            else if (comp == 0 && a[j] > b[j])
            {
                comp = 1;
                return GetValue(j + 1, a, b, comp);

            }
            else
            {
                return GetValue(j + 1, a, b, comp);


            }
        }
    }
}
