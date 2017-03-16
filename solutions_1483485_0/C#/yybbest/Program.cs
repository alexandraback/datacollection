using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections;

namespace CandySplitting
{
    class Program
    {
        static void Main(string[] args)
        {
            string infilename = "A-small-attempt2.in", outfilename = "A-small-attempt2.out";
            StreamReader sr = new StreamReader(infilename);
            StreamWriter sw = new StreamWriter(outfilename);
            int T = int.Parse(sr.ReadLine().ToString());
            for (int i = 1; i <= T; ++i)
            {
                sw.WriteLine("Case #{0}: {1}", i, computeOneLine(sr.ReadLine().ToString())); 
            }
            sw.Flush();
        }
        static string computeOneLine(string inStr)
        {

            string mapstr = "yhesocvxduiglbkrztnwjpfmaq";
            string str = "";
            foreach (char c in inStr)
            {
                if (c == ' ') str += ' ';
                else str += mapstr[c-'a'];
            }
            return str;
        }

    }

   
}
