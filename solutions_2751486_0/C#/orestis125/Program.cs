using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam {
    class Program {
        static ulong CurrentCase = 1;
        static String Output = "";
        static HashSet<char> vowels = new HashSet<char>();
        static void Main(string[] args) {
            vowels.Add('a'); vowels.Add('e'); vowels.Add('i'); vowels.Add('o'); vowels.Add('u');
            using (StreamReader sR = new StreamReader("C:\\Users\\Orestis\\Desktop\\A-small-attempt0.in")) {
                ulong? testCasesCount = ulong.Parse(sR.ReadLine().Trim());
                for (ulong i = 0; i < testCasesCount; i++) {
                    String[] data = sR.ReadLine().Split(' ');
                    String name = data[0];
                    int n = int.Parse(data[1]);

                    if (n > name.Length) {
                        OutputCase("" + 0);
                        continue;
                    }

                    if (n == name.Length) {
                        foreach (char c in vowels) {
                            if (name.Contains(c)) {
                                OutputCase("" + 0);
                                goto Contains;
                            }
                        }
                        OutputCase("" + 1);
                    Contains: continue;
                    }

                    int nValue = 0;
                    

                    IEnumerable<String> substrings =
                    from k in Enumerable.Range(0, name.Length)
                    from j in Enumerable.Range(0, name.Length - k + 1)
                    where j >= n
                    select name.Substring(k, j);

                    foreach (String sub in substrings) {
                        int consontantsCount = 0;
                        for(int c = 0; c < sub.Length; c++) {
                            if (!vowels.Contains(sub[c])) {
                                consontantsCount++;
                                if (consontantsCount == n) {
                                    nValue++;
                                    break;
                                }
                            } else {
                                if (sub.Length - c - 1 < n) {
                                    break;
                                }
                                consontantsCount = 0;
                            }
                        }
                    }

                    OutputCase("" + nValue);
                    //Console.ReadKey();
                }
            }

            SaveToFile();
            Console.Read();
        }

        static void OutputCase(String result) {
            Console.WriteLine("Case #" + CurrentCase + ": " + result);
            Output += "Case #" + CurrentCase + ": " + result + Environment.NewLine;
            CurrentCase++;
        }

        static void OutputCase(String[] result) {
            String Result = "";
            foreach (String str in result) {
                Result += str + ' ';
            }

            OutputCase(Result.Substring(0, Result.Length - 1));
        }

        static void SaveToFile() {
            StreamWriter sW = File.CreateText("C:\\Users\\Orestis\\Desktop\\Output.txt");
            sW.Write(Output);
            sW.Close();
        }

        static int[] extractNumbers(String str) {
            IList<int> numbers = new List<int>();
            String sub = "";
            foreach (char ch in str.Trim()) {
                int n;
                if (int.TryParse("" + ch, out n) == false) {
                    if (sub.Length > 0) {
                        n = int.Parse(sub);
                        numbers.Add(n);
                        sub = "";
                    }
                } else {
                    sub += ch;
                }
            }

            return (numbers.ToArray());
        }
    }
}
