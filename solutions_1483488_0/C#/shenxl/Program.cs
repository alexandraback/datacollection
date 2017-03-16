using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Recycled_Numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            var inputtext = @"E:\Document\JamCode\Recycled_Numbers\C-small-attempt1.in";
            readLine(inputtext);
            Console.WriteLine("OK!!!");
            Console.Read();
        }

        static void readLine(string path)
        {
            string A = "";
            string B = "";
            System.IO.StreamReader file = new System.IO.StreamReader(path);
            StreamWriter testfile = File.CreateText(@"E:\Document\JamCode\Recycled_Numbers\C-small.txt");
            var N = Convert.ToInt32(file.ReadLine());
            for (int i = 0; i < N; i++)
            {
                var str = file.ReadLine().Split(' ');
                A = str[0];
                B = str[1];
                int number = Count(A, B);
                testfile.WriteLine(String.Format("Case #{0}: {1}", i + 1, number));
            }
            testfile.Flush();
            testfile.Close();
            file.Close();
        }

        private static int Count(string A, string B)
        {
            var digits = A.Length;
            int[] intN = new int[digits];
            var count = 0;
            var inta = Convert.ToInt32(A); 
            var intb = Convert.ToInt32(B);

            for (int num = inta; num < intb; num++)
            {
                var templist = new List<int>();
                for(int d = 1;d< digits;d++)
                {
                   templist.Add(Convert.ToInt32(MoveString(num.ToString(), d)));
                   var temp = Convert.ToInt32(MoveString(num.ToString(), d));            
                   if (templist.Where(a=>a==temp).Count() == 1 && num < temp  && temp <= intb)
                   {
                        count ++;
                   }
                }
               
            }
            return count;
        }

        private static string MoveString(string s,int step)
        {
            var str = s.Substring(step, s.Length - step);
            str = str + s.Substring(0, step);
            return str;
        }
    }
}
