using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace CodeJam2010_1A
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> phrases = new List<string>();
            using (StreamReader objReader = new StreamReader("c:\\test.in"))
            {
                string sLine = "";
                while (sLine != null)
                {
                    sLine = objReader.ReadLine();
                    if (sLine != null)
                        phrases.Add(sLine);
                }
            }
            phrases.Remove(phrases[0]);

            char [,] matriz=new char[,];

        }

        public static void rotar(int n, char[,] a)
        {
            char[,] b = new char[n, n];

            for (int i = 0; i < n; i++)
            {
                for (int j = n-1; j >=0; j--)
                {
                    b[n - j - 1, i] = a[i, j];
                }
            }
            gravedad(n, b);
            a = b;
        }
        public static void gravedad(int n, char[,] a)
        {
            for (int i = 0; i < n; i++)
            {
                for(int j=n-1;j>0;j--)
                if (a[i, j] == '.')
                {
                    for (int m = j; m > 0; m--)
                    {
                        a[i, m] = a[i, m-1];
                    }
                    a[i, 0] = '.';
                    j++;
                }
            }
        }
        public static int hayGanador(int n, int k, char[,] a)
        {
            bool ganoRojo=false;
            bool ganoAzul=false;

            for (int i = 0; i <= n - k; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    char b = a[i, j]; bool gano=false;
                    if(b!='.')
                    for (int m = j + 1; m < k + j + 1; m++)
                    {
                        if (a[i, m] == b)
                            gano = true;
                        else
                        {
                            gano = false;
                            break;
                        }
                    }
                    if (gano == true && b == 'R')
                        ganoRojo = true;
                    if (gano == true && b == 'B')
                        ganoAzul = true;
                }
            }
        }
    }
}
