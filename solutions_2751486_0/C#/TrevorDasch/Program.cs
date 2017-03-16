using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamRound1CA
{
    class Program
    {


        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"C:\Users\Trevor\Downloads\input.txt");
            StreamWriter sw = new StreamWriter(@"C:\Users\Trevor\Downloads\output.txt");



            int count = int.Parse(sr.ReadLine());

            for (int x = 0; x < count; x++)
            {
                sw.Write("Case #" + (x + 1) + ": ");

                Do(sr, sw);
            }
            sw.Flush();
        }

        public static void Do(StreamReader sr, StreamWriter sw)
        {
            string[] splitstr = sr.ReadLine().Split(' ');

            string name = splitstr[0];
            int n = int.Parse(splitstr[1]);

            int count = 0;

            bool[] consonants = new bool[name.Length];

            for (int i = 0; i < name.Length; i++)
            {
                string ss = name.Substring(i, 1);
                consonants[i] = !(ss == "a" || ss == "e" || ss == "i" || ss == "o" || ss == "u");
                
            }

            for (int i = n; i <= name.Length; i++)
            {
                for (int j = 0; j <= name.Length - i; j++)
                {
                    int cons = 0;
                    
                    for (int k = j; k < j + i; k++)
                    {
                        if (consonants[k])
                        {
                            cons++;
                            if (cons >= n)
                            {
                                count++;
                                break;
                            }

                        }
                        else
                        {
                            cons = 0;
                        }
                    }
                }
            }

            sw.WriteLine(count);

        }
    }
}

