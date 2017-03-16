using System;
using System.IO;

namespace Sheeps
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("a.in");
            StreamWriter sw = new StreamWriter("a.out");
            int tryCnt = Convert.ToInt32(sr.ReadLine());
            //string[] N = new string[tryCnt];
            byte Aof = (byte)("A"[0]);
            for (int Tr = 0; Tr < tryCnt; Tr++)
            {
                string N= sr.ReadLine();
                int n = N.Length;
                string answer = "";
                int[] LetCounts = new int[26];
                int[] DigCounts = new int[10];

                for (int i = 0; i < n; i++)
                {
                    int letNum = (byte)N[i] - Aof;
                    LetCounts[letNum]++;
                }
                int x;
                //0
                x = LetCounts[25];
                DigCounts[0] = x;
                LetCounts[4] -= x;LetCounts[17] -= x;LetCounts[14] -= x;
                //8
                x = LetCounts[6];
                DigCounts[8] = x;
                LetCounts[4] -= x;LetCounts[8] -= x;LetCounts[7] -= x;LetCounts[19] -= x;
                //2
                x = LetCounts[22];
                DigCounts[2] = x;
                LetCounts[19] -= x;LetCounts[14] -= x;
                //3
                x = LetCounts[7];
                DigCounts[3] = x;
                LetCounts[19] -= x;LetCounts[17] -= x;LetCounts[4] -= 2 * x;
                //4
                x = LetCounts[20];
                DigCounts[4] = x;
                LetCounts[5] -= x;LetCounts[14] -= x;LetCounts[17] -= x;
                //6
                x = LetCounts[23];
                DigCounts[6] = x;
                LetCounts[18] -= x;LetCounts[8] -= x;
                //5
                x = LetCounts[5];
                DigCounts[5] = x;
                LetCounts[8] -= x;LetCounts[21] -= x;LetCounts[4] -= x;
                //9
                x = LetCounts[8];
                DigCounts[9] = x;
                //NoSence
                //1
                x = LetCounts[14];
                DigCounts[1] = x;
                //7
                x = LetCounts[21];
                DigCounts[7] = x;
                
                for (int i = 0; i < 10; i++)
                    for (int j = 0; j < DigCounts[i]; j++)
                        answer = answer + i;

                sw.WriteLine("Case #" + (Tr + 1) + ": " + answer);
            }

            sr.Close();
            sw.Close();
        }
    }
}
