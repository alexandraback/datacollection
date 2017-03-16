using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static int[,] rules = {{1,2,3,4},{2,-1,4,-3},{3,-4,-1,2},{4,3,-2,-1}};

        static int[] getvector(string s)
        {
            int[] ret = new int[s.Length];
            int product = 1;
            for (int i = 0; i < s.Length; i++)
            {
                switch(s[i])
                {
                    case 'i':
                    {
                        product = Math.Sign(product) * rules[Math.Abs(product) - 1,2 - 1];
                        break;
                    }
                    case 'j':
                    {
                        product = Math.Sign(product) * rules[Math.Abs(product) - 1, 3 - 1];
                        break;
                    }
                    case 'k':
                    {
                        product = Math.Sign(product) * rules[Math.Abs(product) - 1, 4 - 1];
                        break;
                    }
                }
                ret[i] = product;
            }
            return ret;
        }

       /* static int[][] getmatrix(string s)
        {
            int[][] m=new int[s.Length][];
            for (int i = 0; i < s.Length; i++)
            {
                m[i] = new int[s.Length];
                for (int j = 0; j < s.Length; j++)
                {
                    if (i <= j)
                    {
                        m[i][j] = getproduct(s.Substring(i, j - i + 1));
                    }
                    else
                    {
                        m[i][j] = getproduct(s.Substring(i)+s.Substring(0,j+1));
                    }
                }
            }
            return m;
        }*/

        /*static int[] getvector(string s)
        {
            int[] m = new int[s.Length];
            for (int i = 0; i < s.Length; i++)
            {
                m[i] =  getproduct(s.Substring(0, i + 1));
            }
            return m;
        }*/

        static void printm(int[][] m)
        {
            for (int i = 0; i < m.Length; i++)
            {
                for (int j = 0; j < m[i].Length; j++)
                {
                    Console.Write(" {0}",m[i][j]);
                }
                Console.WriteLine();
            }
        }

        static void Main(string[] args)
        {
           /* Console.WriteLine(getproduct("i"));
            Console.WriteLine(getproduct("ii"));
            Console.WriteLine(getproduct("iij"));
            Console.WriteLine(getproduct("iijk"));
            printm(getmatrix("iijk"));*/

            StreamWriter sw = new StreamWriter("C-large.out");
            StreamReader sr = new StreamReader("C-large.in");
            int T = Int32.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
                string[] line = sr.ReadLine().Split(' ');
                long L = Int64.Parse(line[0]);
                long X = Int64.Parse(line[1]);
                string name = yesorno(sr.ReadLine(), X);
                sw.WriteLine("Case #{0}: {1}", i + 1, name);
                sw.Flush();
            }
            sr.Close();
            sw.Flush();
            sw.Close();
            
            Console.ReadLine();
        }

        private static string yesorno(string s, long X)
        {
            //if (getproduct(s) != -1 || X%2==0) return "NO";

            string inc = s + s;

            int[] m = getvector(s);

            int usedX = 1;

            if (X % 2 == 1)
            {
                if (m[s.Length-1] == -1)
                {
                    while (usedX <= X && usedX <= 10)
                    {
                        for (int i = 0; i < s.Length - 2; i++)
                        {
                            if (m[i] == 2)
                            {
                                for (int j = i + 1; j < s.Length - 1; j++)
                                {
                                    if (m[j] == 4)
                                    {
                                        return "YES";
                                    }
                                }
                            }
                        }
                        s += inc;
                        usedX += 2;
                        m = getvector(s);
                    }
                }
            }
            else if ((X - 2) % 4 == 0)
            {
                s = s + s;
                usedX++;
                m = getvector(s);
                if (m[s.Length - 1] == -1)
                {
                    while (usedX <= X && usedX <= 10)
                    {
                        for (int i = 0; i < s.Length - 2; i++)
                        {
                            if (m[i] == 2)
                            {
                                for (int j = i + 1; j < s.Length - 1; j++)
                                {
                                    if (m[j] == 4)
                                    {
                                        return "YES";
                                    }
                                }
                            }
                        }
                        if ((X - 2) % 4 == 0)
                        {
                            s += (inc + inc);
                            usedX += 4;
                            m = getvector(s);
                        }
                        else
                        {
                            return "NO";
                        }
                    }
                }
            }
            return "NO";
        }
    }
}
