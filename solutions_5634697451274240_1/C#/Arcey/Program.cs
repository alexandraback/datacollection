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

                char[] s = Console.ReadLine().ToCharArray();
                int ans = 0, l = s.Length - 1;
                while (true) {
                    while (l >= 0 && s[l] == '+') {
                        l--;
                    }
                    if (l == -1) {
                        break;
                    }
                    if (s[0] == '+') {
                        int st = 0;
                        while (st <= l && s[st] == '+') {
                            s[st] = '-';
                            st++;
                        }
                        ans++;
                    }
                    for (int i = 0; i + i <= l; i++) {
                        char aux = s[i];
                        s[i] = s[l - i];
                        s[l - i] = aux;
                    }
                    ans++;
                    for (int i = 0; i <= l; i++) {
                        if (s[i] == '+') {
                            s[i] = '-';
                        } else {
                            s[i] = '+';
                        }
                    }
                }
                Console.Write(ans);

                Console.WriteLine();
            }

            //Console.ReadKey();
        }
    }
}
