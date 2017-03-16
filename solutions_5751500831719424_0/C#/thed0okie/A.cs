using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ {
    public class A {
        public static void Run() {
            var sr = new StreamReader(@"C:\gcj\a-small-attempt0.in");
            var sw = new StreamWriter(@"C:\gcj\a-small-attempt0.out");

            var numtestcases = Convert.ToInt64(sr.ReadLine());
            for(long i = 0; i < numtestcases; i++) {
                int N = Convert.ToInt32(sr.ReadLine());
                var strings = new List<string>();
                for(int j = 0; j < N; j++) {
                    strings.Add(sr.ReadLine());
                }

                string noRepeatWord = NoRepeatWord(strings[0]);

                bool feglaWins = false;
                foreach(var s in strings) {
                    if(NoRepeatWord(s) != noRepeatWord) {
                        feglaWins = true;
                    }
                }

                if(feglaWins) {
                    var outputString = String.Format("Case #{0}: Fegla Won", i + 1);
                    sw.WriteLine(outputString);
                } else {
                    int numFlips = 0;
                    List<int> places = new List<int>();
                    List<int> count = new List<int>();
                    foreach(var s in strings) {
                        places.Add(0);
                        count.Add(0);
                    }
                    for(int idx = 0; idx < noRepeatWord.Length; idx++) {
                        char letter = noRepeatWord[idx];
                        int localFlips = Int32.MaxValue;
                        for(int n = 0; n < strings.Count; n++){
                            var str = strings[n];
                            while(places[n] < str.Length && str[places[n]] == letter) {
                                count[n]++;
                                places[n]++;
                            }
                        }

                        List<int> possCounts = count.Distinct().ToList();
                        int possLocalFlips = 0;
                        for(int pC = 0; pC < possCounts.Count; pC++) {
                            possLocalFlips = count.Select(ct => Math.Abs(ct - possCounts[pC])).Sum();
                            localFlips = Math.Min(possLocalFlips, localFlips);
                        }
                        numFlips += localFlips;

                        for(int n = 0; n < strings.Count; n++){
                            count[n] = 0;
                        }
                    }
                    var outputString = String.Format("Case #{0}: {1}", i + 1, numFlips);
                    sw.WriteLine(outputString);
                }
                
            }
            sr.Close();
            sw.Close();
        }

        public static string NoRepeatWord(string s) {
            string noRepeatWord = "";
            for(int j = 0; j < s.Length; j++) {

                if(noRepeatWord.Length == 0 || noRepeatWord.Last() != s[j]) {
                    noRepeatWord += s[j];
                }
            }
            return noRepeatWord;
        }
    }
}
