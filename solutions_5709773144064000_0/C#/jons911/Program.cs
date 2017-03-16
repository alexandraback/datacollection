using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1 {
    class Program {
        static void Main(string[] args) {
            DateTime now = DateTime.Now;
            string filename = @"c:\users\jshea\desktop\B-small-attempt0.in";
            if (args.Length >= 1) {
                filename = args[0].ToString();
            }


            using (StreamReader file = new System.IO.StreamReader(filename)) {

                int cases = Int32.Parse(file.ReadLine());
                for (int testCase = 0; testCase < cases; testCase++) {
                    var result = "";
                    try {
                        var line = file.ReadLine().Split(' ');
                        var c = Double.Parse(line[0]);
                        var f = Double.Parse(line[1]);
                        var x = Double.Parse(line[2]);
                        double cookiesPerSecond = 2;
                        double totalTime = 0;

                        while (true) {
                            var secondsToNextFarm = c / cookiesPerSecond;
                            var secondsToWin = x / cookiesPerSecond;
                            var secondsToWinWithNextFarm = x / (cookiesPerSecond + f) + secondsToNextFarm;

                            if (secondsToWinWithNextFarm > secondsToWin) {
                                totalTime += secondsToWin;
                                break;
                            } else {
                                totalTime += secondsToNextFarm;
                                cookiesPerSecond += f;
                            }
                        }

                        Console.WriteLine("Case #{0}: {1:0.0000000}", testCase + 1, totalTime);
                    } catch (Exception ex) {
                        Console.Write(ex.Message);
                    }
                }

            }
        }
    }
}