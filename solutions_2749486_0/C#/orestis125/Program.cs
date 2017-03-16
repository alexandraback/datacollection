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

        static void Main(string[] args) {
            using (StreamReader sR = new StreamReader("C:\\Users\\Orestis\\Desktop\\B-small-attempt0.in")) {
                ulong? testCasesCount = ulong.Parse(sR.ReadLine().Trim());
                for (ulong i = 0; i < testCasesCount; i++) {
                    int[] data = Array.ConvertAll(sR.ReadLine().Split(' '), int.Parse);
                    int x = data[0];
                    int y = data[1];
                    int currX = 0;
                    int currY = 0;
                    int Jump = 1;
                    String path = "";

                    while (currX != x) {
                        if (currX + Jump <= x) {
                            currX += Jump;
                            path += "E";
                            Jump++;
                        } else {
                            currX -= Jump;
                            path += "W";
                            Jump++;
                        }
                    }

                    while (currY != y) {
                        if (currY + Jump <= y) {
                            currY += Jump;
                            path += "N";
                            Jump++;
                        } else {
                            currY -= Jump;
                            path += "S";
                            Jump++;
                        }
                    }

                    OutputCase(path);
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
