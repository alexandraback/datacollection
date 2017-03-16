using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CodeJamQualA
{
    class Program
    {
        static void Main(string[] args)
        {
            string countstr = System.Console.ReadLine();
            int count = int.Parse(countstr);

            string outputstr = "";
            for (int i = 0; i < count; i++)
            {
                outputstr += ("Case #"+(i+1)+": "+Process()+"\n");
            }

            System.Console.WriteLine(outputstr);


            System.Console.ReadKey();
        }


        static string Process()
        {

            char[] comp = ("yhesocvxduiglbkrztnwjpfmaq").ToCharArray();

            string lang = System.Console.ReadLine();

            char[] charArr = lang.ToCharArray();
            string newStr = "";
            for (int i = 0; i < lang.Length; i++)
            {
                char c = charArr[i];
                if (c != ' ')
                {
                    if (c >= 'a')
                    {
                        c = comp[(int)c - (int)'a'];

                    }
                    else
                    {
                        c = (char)((int)c+ ((int)'a' - (int)'A'));

                        c = comp[(int)c - (int)'a'];

                        c = (char)((int)c - ((int)'a' - (int)'A'));
                    }
                 
     
                }
                newStr += c;
            }

            return newStr;
        }

    }
}
