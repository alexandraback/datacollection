using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {            
            StreamReader sr = new StreamReader("c:/temp/input.txt");
            StreamWriter sw = new StreamWriter("c:/temp/output.txt");

            char[] inp, outp;
            string inl = "abcdefghijklmnopqrstuvwxyz";
            string outl = "ynficwlbkuomxsevzpdrjgthaq";

            inp = (inl+inl.ToUpper()).ToCharArray();
            outp =(outl+outl.ToUpper()).ToCharArray();
            Dictionary<char, char> trans = new Dictionary<char, char>();
            for (int i = 0; i < inp.Length; i++)
            {
                trans.Add(outp[i], inp[i]);
            }
            int n = int.Parse(sr.ReadLine());
            string token;
            for (int i = 0; i < n; i++) {
                sw.Write("Case #{0}: ", i + 1);
                token = sr.ReadLine();
                for (int index = 0; index < token.Length; index++)
                {
                    if (trans.ContainsKey(token[index])) {
                        sw.Write(trans[token[index]]);
                    } else {
                        sw.Write(token[index]);
                    }
                }
                sw.WriteLine();
            }
            sr.Close();
            sw.Close();
        }
    }
}
