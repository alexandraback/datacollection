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
            // Console.SetIn(new StreamReader("file.in"));
            FileStream filestream = new FileStream("out.txt", FileMode.Create);
            var streamwriter = new StreamWriter(filestream);
            streamwriter.AutoFlush = true;
            Console.SetOut(streamwriter);

            /*
            int totalTest = int.Parse(Console.ReadLine());
            for (int test = 1; test <= totalTest; test++) {
                Console.Write("Case #{0}: ", test);

                

                Console.WriteLine();
            }
            */
            Console.WriteLine("Case #1:");
            int l = 32;
            char[] jam = new char[l];
            for (int i = 0; i < l; i++) {
                jam[i] = '0';
            }
            jam[0] = '1';
            jam[l - 1] = '1';
            int total = 500;
            while (total > 0) {
                BigInteger[] div = new BigInteger[11];
                bool sol = true;
                for (int b = 2; b <= 10; b++) {
                    BigInteger nr = new BigInteger(0);
                    BigInteger pow = 1;
                    for (int i = l - 1; i >= 0; i--) {
                        if (jam[i] == '1') {
                            nr += pow;
                        }
                        pow *= b;
                    }
                    bool divFound = false;
                    for (BigInteger i = 2; i <= 11; i++) {
                        if (nr % i == 0) {
                            divFound = true;
                            div[b] = i;
                            break;
                        }
                    }
                    if (!divFound) {
                        sol = false;
                        break;
                    }
                }
                if (sol) {
                    foreach (char c in jam) {
                        Console.Write(c);
                    }
                    Console.Write(" ");
                    for (int b = 2; b <= 10; b++) {
                        Console.Write("{0} ", div[b]);
                    }
                    Console.WriteLine();
                    total--;
                }
                int poz = l - 2;
                while (jam[poz] == '1') {
                    jam[poz] = '0';
                    poz--;
                }
                jam[poz] = '1';
                
            }

            //Console.ReadKey();
        }
    }
}
