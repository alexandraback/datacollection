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

            int t = int.Parse(Console.ReadLine());
            for (int tt = 1; tt <= t; tt++) {
                int n = int.Parse(Console.ReadLine()), max = 0;
                string[] fn = new string[n];
                string[] sn = new string[n];
                for (int i = 0; i < n; i++) {
                    string[] s = Console.ReadLine().Split(' ');
                    fn[i] = s[0];
                    sn[i] = s[1];
                }
                int[] nf = new int[n];
                int[] ns = new int[n];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i == j) {
                            continue;
                        }
                        if (fn[i] == fn[j]) {
                            nf[i] += (1 << j);
                        }
                        if (sn[i] == sn[j]) {
                            ns[i] += (1 << j);
                        }
                    }
                }
                for (int i = 1; i < (1 << n); i++) {
                    int nc = 0, nb = 0;
                    for (int j = 0; j < n; j++) {
                        if ((i & (1 << j)) == 0) {
                            nc++;
                            if ((nf[j] & i) != 0 && (ns[j] & i) != 0) {
                                nb++;
                            }
                        }
                    }
                    if (nb == nc && nb > max) {
                        max = nb;
                    }
                }
                Console.WriteLine("Case #{0}: {1}", tt, max);
            }


            //Console.ReadKey();
        }
    }
}
