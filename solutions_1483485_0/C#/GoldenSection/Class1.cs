using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace A
{
    class Program
    {
        static string[] exampleIn = {
                                 "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                                 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                                 "de kr kd eoya kw aej tysr re ujdr lkgc jv"
                             };

        static string[] exampleOut = {
                                         "our language is impossible to understand",
                                         "there are twenty six factorial possibilities",
                                         "so it is okay if you want to just give up"
                                     };

        static Dictionary<char, char> dic = new Dictionary<char, char>();


        static void makeDic()
        {
            for (int k = 0; k < exampleIn.Length; k++)
            {
                for (int i = 0; i < exampleIn[k].Length; i++)
                {
                    dic[exampleIn[k][i]] = exampleOut[k][i];
                }
            }
            dic['q'] = 'z';
            dic['z'] = 'q';

            /*
            for (char ch = 'a'; ch <= 'z'; ch++)
                if (dic.ContainsKey(ch)) Console.WriteLine("{0}\t->\t{1}", ch, dic[ch]);
                else Console.WriteLine("{0}\t->", ch);
             */
        }

        public static void Main(string[] args)
        {
            makeDic();

            StreamReader inFile = new StreamReader("a.in");
            StreamWriter outFile = new StreamWriter("a.out");

            int cCnt = Convert.ToInt32(inFile.ReadLine());
            for (int cId = 1; cId <= cCnt; cId++)
            {
                outFile.Write("Case #{0}: ", cId);
                string line = inFile.ReadLine();
                foreach (char ch in line)
                {
                    if (dic.ContainsKey(ch)) outFile.Write(dic[ch]);
                    else outFile.Write(ch);
                }
                outFile.WriteLine();
            }

            inFile.Close();
            outFile.Close();
        }
    }
}
