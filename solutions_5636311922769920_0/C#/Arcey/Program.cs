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
                Console.Write("Case #{0}: ", test);

                string[] st = Console.ReadLine().Split(' ');
                long k = long.Parse(st[0]), c = long.Parse(st[1]), s = long.Parse(st[2]);
                if (c > k) {
                    c = k;
                }
                long nec = k - c + 1;
                if (nec > s) {
                    Console.Write("IMPOSSIBLE");
                } else {
                    long rem = c - 1;
                    long ans = 0;
                    for (long i = 1; i <= rem; i++) {
                        ans = (ans * k) + i;
                    }
                    ans++;
                    for (long i = 0; i < nec; i++) {
                        Console.Write("{0} ", ans);
                        ans++;
                    }
                }

                Console.WriteLine();
            }

            //Console.ReadKey();
        }
    }
}
