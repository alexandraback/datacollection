using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fs = new FileStream("A-small-attempt0.in", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(fs, System.Text.Encoding.Default);
            sr.BaseStream.Position = 0;
            StreamWriter sw = new StreamWriter("A-small-attempt0.txt");

            int T = int.Parse(sr.ReadLine());
            for (int Ti = 0; Ti < T; Ti++)
            {
                string[] str = sr.ReadLine().Split(' ');
                string name = str[0];
                int L = name.Length;
                int n = int.Parse(str[1]);

                int count = 0;
                for (int i = 0; i < L - n + 1; i++)
                {
                    for (int j = n; j < L - i + 1; j++)
                    {
                        string part = name.Substring(i, j);
                        int temp = 0;
                        for (int k = 0; k < part.Length; k++)
                        {
                            if (isvowel(part[k]))
                            {
                                temp = 0;
                            }
                            else
                            {
                                temp++;
                            }
                            if (temp >= n)
                            {
                                count++;
                                break;
                            }
                        }
                    }
                }
                sw.WriteLine("Case #" + (Ti + 1) + ": " + count.ToString());
            }
            sr.Dispose();
            sw.Dispose();
        }
        static bool isvowel(char a)
        {
            if (a == 'a')
            {
                return true;
            }
            else if (a == 'e')
            {
                return true;
            }
            else if (a == 'i')
            {
                return true;
            }
            else if (a == 'o')
            {
                return true;
            }
            else if (a == 'u')
            {
                return true;
            }
            return false;
        }
    }
}
