using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemB {
    class Program {
        static void Main(string[] args) {
            int T;
            int N;
            int[] missing;
            string[] tokens;
            int[] H = new int[2501];
            int m;
            string output;

            //string ioPath = @"D:\Aleaimo\Downloads\input";
            string ioPath = @"D:\Aleaimo\Downloads\B-small-attempt0";
            //string ioPath = @"D:\Aleaimo\Downloads\B-large";

            StreamReader sr = new StreamReader(ioPath + ".in");
            StreamWriter sw = new StreamWriter(ioPath + ".out", true);


            T = int.Parse(sr.ReadLine());
            for (int t = 0; t < T; t++) {
                for(int h = 1; h < 2501; h++) {
                    H[h] = 0;
                }

                N = int.Parse(sr.ReadLine());

                missing = new int[N];

                for (int l=0; l < 2*N-1; l++) {
                    tokens = sr.ReadLine().Split(' ');
                    for(int n=0; n< N; n++) {
                        H[int.Parse(tokens[n])]++;
                    }
                }

                m = 0;
                for (int h = 1; h < 2501; h++) {
                    if (H[h] % 2 == 1) {
                        missing[m] = h;
                        m++;
                    };
                }

                Array.Sort(missing);
                output = missing[0].ToString();
                for(int n = 1; n < N; n++) {
                    output = output + " " + missing[n].ToString();
                }

                sw.WriteLine("Case #{0}: {1}", t + 1, output);
            }

            sw.Close();

        }
    }
}
