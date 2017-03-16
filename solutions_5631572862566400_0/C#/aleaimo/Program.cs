using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemC {
    class Program {
        static void Main(string[] args) {
            int T;
            int N;
            int[] f;
            string[] tokens;
            int count;
            int max;
            bool[] fbool;
            bool[] prevfbool;
            int nextStudent;
            int prevStudent;
            int newPrevStudent;
            int prevPrevStudent = 0;
            bool found;
            int prevCount;
            bool ok;
            int a;

            //string ioPath = @"D:\Aleaimo\Downloads\input";
            string ioPath = @"D:\Aleaimo\Downloads\C-small-attempt5";
            //string ioPath = @"D:\Aleaimo\Downloads\C-large";

            StreamReader sr = new StreamReader(ioPath + ".in");
            StreamWriter sw = new StreamWriter(ioPath + ".out", true);


            T = int.Parse(sr.ReadLine());
            for (int t = 0; t < T; t++) {
                N = int.Parse(sr.ReadLine());
                f = new int[N+1];
                fbool = new bool[N + 1];
                prevfbool = new bool[N + 1];

                tokens = sr.ReadLine().Split(' ');
                for(int n=0; n< N; n++) {
                    f[n + 1] = int.Parse(tokens[n]);
                }

                max = 0;
                for (int n = 1; n < N+1; n++) {
                    for (int fb = 1; fb < N + 1; fb++) {
                        fbool[fb] = false;
                    }

                    nextStudent = n;
                    prevStudent = 0;
                    count = 0;
                    while (!fbool[nextStudent]) {
                        count++;
                        fbool[nextStudent] = true;
                        prevPrevStudent = prevStudent;
                        prevStudent = nextStudent;
                        nextStudent = f[nextStudent];
                    }

                    if (prevPrevStudent == nextStudent) {
                        ok = true;
                        found = false;
                        newPrevStudent = 0;

                        prevCount = count;
                        for (int fb = 1; fb < N + 1; fb++) {
                            prevfbool[fb] = fbool[fb];
                        }

                        for (int j = 1; j < N + 1; j++) {
                            count = prevCount;
                            for (int fb = 1; fb < N + 1; fb++) {
                                fbool[fb] = prevfbool[fb];
                            }
                            found = false;

                            if (f[j] == prevStudent && !fbool[j]) {
                                newPrevStudent = j;
                                found = true;
                            }

                            while (found && !fbool[newPrevStudent]) {
                                count++;
                                fbool[newPrevStudent] = true;
                                found = false;
                                for (int k = 1; k < N + 1; k++) {
                                    if (f[k] == newPrevStudent && !fbool[k]) {
                                        newPrevStudent = k;
                                        found = true;
                                    }
                                }
                            }

                            if (max < count) {
                                max = count;
                            }
                        }
 

                    }
                    else {
                        ok = false;
                    }

                    if ((ok || nextStudent == n) && max < count) {
                        max = count;
                    }

                }
                sw.WriteLine("Case #{0}: {1}", t + 1, max);
            }

            sw.Close();

        }
    }
}
