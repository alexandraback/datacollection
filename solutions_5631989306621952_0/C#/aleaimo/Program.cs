using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA {
    class Program {
        static void Main(string[] args) {
            int T;
            string S;
            string lastWord;

            //string ioPath = @"D:\Aleaimo\Downloads\input";
            string ioPath = @"D:\Aleaimo\Downloads\A-small-attempt0";
            //string ioPath = @"D:\Aleaimo\Downloads\A-large";

            StreamReader sr = new StreamReader(ioPath + ".in");
            StreamWriter sw = new StreamWriter(ioPath + ".out", true);


            T = int.Parse(sr.ReadLine());
            for (int t = 0; t < T; t++) {
                S = sr.ReadLine();
                lastWord = "";

                for (int i = 0; i < S.Length; i++) {
                    if (i == 0) {
                        lastWord = S[i].ToString();
                    }
                    else {
                        if (lastWord[0] > S[i]) {
                            lastWord = lastWord + S[i].ToString();
                        }
                        else {
                            lastWord = S[i].ToString() + lastWord;
                        }
                    }
                }

                sw.WriteLine("Case #{0}: {1}", t + 1, lastWord);
            }

            sw.Close();

        }
    }
}
