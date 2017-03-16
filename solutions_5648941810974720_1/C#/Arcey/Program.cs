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
                char[] s = Console.ReadLine().ToCharArray();
                int[] nap = new int['z' - 'a' + 1];
                for (int i = 'a'; i <= 'z'; i++) {
                    nap[i - 'a'] = 0;
                }
                    for (int i = 0; i < s.Length; i++) {
                        nap[s[i] - 'A']++;
                    }
                int[] nb = new int[10];
                for (int i = 0; i < 10; i++) {
                    nb[i] = 0;
                }

                nb[0] = nap['Z' - 'A'];
                nap['Z' - 'A'] -= nb[0];
                nap['E' - 'A'] -= nb[0];
                nap['R' - 'A'] -= nb[0];
                nap['O' - 'A'] -= nb[0];

                nb[2] = nap['W' - 'A'];
                nap['T' - 'A'] -= nb[2];
                nap['W' - 'A'] -= nb[2];
                nap['O' - 'A'] -= nb[2];

                nb[4] = nap['U' - 'A'];
                nap['F' - 'A'] -= nb[4];
                nap['O' - 'A'] -= nb[4];
                nap['U' - 'A'] -= nb[4];
                nap['R' - 'A'] -= nb[4];

                nb[8] = nap['G' - 'A'];
                nap['E' - 'A'] -= nb[8];
                nap['I' - 'A'] -= nb[8];
                nap['G' - 'A'] -= nb[8];
                nap['H' - 'A'] -= nb[8];
                nap['T' - 'A'] -= nb[8];

                nb[1] = nap['O' - 'A'];
                nap['O' - 'A'] -= nb[1];
                nap['N' - 'A'] -= nb[1];
                nap['E' - 'A'] -= nb[1];

                nb[5] = nap['F' - 'A'];
                nap['F' - 'A'] -= nb[5];
                nap['I' - 'A'] -= nb[5];
                nap['V' - 'A'] -= nb[5];
                nap['E' - 'A'] -= nb[5];

                nb[3] = nap['H' - 'A'];
                nap['T' - 'A'] -= nb[3];
                nap['H' - 'A'] -= nb[3];
                nap['R' - 'A'] -= nb[3];
                nap['E' - 'A'] -= nb[3];
                nap['E' - 'A'] -= nb[3];

                nb[7] = nap['V' - 'A'];
                nap['S' - 'A'] -= nb[7];
                nap['E' - 'A'] -= nb[7];
                nap['V' - 'A'] -= nb[7];
                nap['E' - 'A'] -= nb[7];
                nap['N' - 'A'] -= nb[7];

                nb[9] = nap['E' - 'A'];
                nap['N' - 'A'] -= nb[9];
                nap['I' - 'A'] -= nb[9];
                nap['N' - 'A'] -= nb[9];
                nap['E' - 'A'] -= nb[9];

                nb[6] = nap['S' - 'A'];
                nap['S' - 'A'] -= nb[6];
                nap['I' - 'A'] -= nb[6];
                nap['X' - 'A'] -= nb[6];

                Console.Write("Case #{0}: ", tt);
                for (int i = 0; i < 10; i++) {
                    if (nb[i] != 0) {
                        for (int j = 0; j < nb[i]; j++) {
                            Console.Write(i);
                        }
                    }
                }
                Console.WriteLine();
            }
            

            //Console.ReadKey();
        }
    }
}
