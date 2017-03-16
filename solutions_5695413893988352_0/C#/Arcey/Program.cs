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
        static string nr1 = "";
        static string nr2 = "";
        static int min = 0, s1 = 0, s2 = 0;

        static void bt(int n1, int n2, int ind, int nc) {
            if (nc == 1) {
                if (ind == nr1.Length) {
                    bt(n1, n2, 0, 2);
                } else {
                    if (nr1[ind] == '?') {
                        int aux = n1;
                        for (int i = 0; i < 10; i++) {
                            n1 = aux * 10 + i;
                            bt(n1, n2, ind + 1, 1);
                        }
                        n1 = aux;
                    } else {
                        int aux = n1;
                        n1 = aux * 10 + nr1[ind] - '0';
                        bt(n1, n2, ind + 1, 1);
                        n1 = aux;
                    }
                }
            } else {
                if (ind == nr2.Length) {
                    if (Math.Abs(n1 - n2) < min) {
                        min = Math.Abs(n1 - n2);
                        s1 = n1;
                        s2 = n2;
                    } else if (Math.Abs(n1 - n2) == min && n1 < s1) {
                        s1 = n1;
                        s2 = n2;
                    } else if (Math.Abs(n1 - n2) == min && n1 == s1 && n2 < s2) {
                        s1 = n1;
                        s2 = n2;
                    }
                } else {
                    if (nr2[ind] == '?') {
                        int aux = n2;
                        for (int i = 0; i < 10; i++) {
                            n2 = aux * 10 + i;
                            bt(n1, n2, ind + 1, 2);
                        }
                        n2 = aux;
                    } else {
                        int aux = n2;
                        n2 = aux * 10 + nr2[ind] - '0';
                        bt(n1, n2, ind + 1, 2);
                        n2 = aux;
                    }
                }
            }
        }
        static void Main(string[] args) {

            Console.SetIn(new StreamReader("file.in"));
            
            FileStream filestream = new FileStream("out.txt", FileMode.Create);
            var streamwriter = new StreamWriter(filestream);
            streamwriter.AutoFlush = true;
            Console.SetOut(streamwriter);

            int t = int.Parse(Console.ReadLine());
            for (int tt = 1; tt <= t; tt++) {
                string[] s = Console.ReadLine().Split(' ');
                nr1 = s[0];
                nr2 = s[1];
                min = 1000;
                bt(0, 0, 0, 1);
                char[] h1 = new char[nr1.Length];
                int aux = nr1.Length - 1;
                while (aux >= 0) {
                    h1[aux] = (char)(s1 % 10 + '0');
                    s1 /= 10;
                    aux--;
                }
                char[] h2 = new char[nr2.Length];
                aux = nr2.Length - 1;
                while (aux >= 0) {
                    h2[aux] = (char)(s2 % 10 + '0');
                    s2 /= 10;
                    aux--;
                }
                Console.WriteLine("Case #{0}: {1} {2}", tt, new string(h1),  new string(h2));
            }
            

            //Console.ReadKey();
        }
    }
}
