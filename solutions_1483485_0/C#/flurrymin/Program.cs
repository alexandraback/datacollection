using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SpeakingInTongues
{
    class Program
    {
        static void Main(string[] args)
        {
            string allwords = "abcdefghijklmnopqrstuvwxyz ";
            string from = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
            string to = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";


            SortedDictionary<char, char> dic = new SortedDictionary<char, char>();
            for (int i = 0; i < from.Length; i++)
            {
                if (!dic.ContainsKey(from[i]))
                {
                    dic.Add(from[i], to[i]);
                }
            }
            dic.Add('q', 'z');
            dic.Add('z', 'q');

            string[] lines = File.ReadAllLines(@"C:\Users\wangran\Documents\visual studio 11\Projects\GoogleCodeJam\SpeakingInTongues\A-small-attempt3.in.txt");
            for (int i = 1; i < lines.Length; i++)
            {
                string line = "";
                for (int j = 0; j < lines[i].Length; j++)
                {
                    line += dic[lines[i][j]];
                }
                var resultLine = string.Format("Case #{0}: {1}\n", i, line);
                Console.WriteLine(resultLine);
                File.AppendAllText(@"C:\Users\wangran\Documents\visual studio 11\Projects\GoogleCodeJam\SpeakingInTongues\A-small-attempt3.out.txt", resultLine);
            }
        }
    }
}
