using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.IO;
using System.Numerics;
using System.Globalization;
using System.Threading;


namespace probleme {
    class Program {
        static void Main(string[] args) {
            Console.SetIn(new StreamReader("file.in"));
            FileStream filestream = new FileStream("out.txt", FileMode.Create);
            var streamwriter = new StreamWriter(filestream);
            streamwriter.AutoFlush = true;
            Console.SetOut(streamwriter);

            int totalTest = int.Parse(Console.ReadLine());
            for (int test = 1; test <= totalTest; test++) {
                int n = int.Parse(Console.ReadLine());
                Console.Write("Case #{0}: ", test);
                if (n == 0) {
                    Console.Write("INSOMNIA");
                } else {
                    int[] digit = new int[10];
                    int tn = n;
                    while (true) {
                        int aux = tn;
                        while (aux > 0) {
                            digit[aux % 10] = 1;
                            aux /= 10;
                        }
                        if (digit.Sum() == 10) {
                            break;
                        }
                        tn += n;
                    }
                    Console.Write(tn);
                }
                Console.WriteLine();
            }

            //Console.ReadKey();
        }
    }
}
