using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2016
{
    class Program
    {
        static void Main(string[] args)
        {
            var filename = new[] { "test.in", "B-small-attempt3.in", "B-large.in" }[2];
            using (var output = new StreamWriter(Path.ChangeExtension(filename, ".out")))
            using (var input = new StreamReader(filename))
            {
                Round1BA(input, output);
            }
            Console.Read();
        }

        static void Round1BA(StreamReader fileInput, StreamWriter fileOutput)
        {
            var T = int.Parse(fileInput.ReadLine());
            for (int t = 0; t < T; t++)
            {
                var items = fileInput.ReadLine().Split(' ');
                var C = items[0];
                var J = items[1];
                var L = C.Length;

                int k;
                for (k = 0; k < L; k++)
                {
                    if (C[k] == J[k]) continue;
                    if (C[k] == '?' || J[k] == '?') continue;
                    break;
                }
                var C0 = C.Cast<char>().ToArray();
                var C1 = C.Cast<char>().ToArray();
                var C2 = C.Cast<char>().ToArray();
                var J0 = J.Cast<char>().ToArray();
                var J1 = J.Cast<char>().ToArray();
                var J2 = J.Cast<char>().ToArray();

                var b = false;
                if (k < L && C[k] < J[k])
                {
                    b = true;
                    var D0 = C0; var D1 = C1; var D2 = C2; var D = C;
                    C0 = J0; C1 = J1; C2 = J2; C = J;
                    J0 = D0; J1 = D1; J2 = D2; J = D;
                }

                if (t == 150)
                    t += 0;

                {
                    for (int i = 0; i < k; i++)
                        if (C[i] == '?')
                        {
                            if (J[i] == '?') { C0[i] = '0'; J0[i] = '0'; }
                            else C0[i] = J[i];
                        }
                        else if (J[i] == '?') J0[i] = C[i];
                    for (int i = k + 1; i < L; i++)
                    {
                        if (C[i] == '?') C0[i] = '0';
                        if (J[i] == '?') J0[i] = '9';
                    }

                    for (int i = 0; i < k; i++)
                        if (C[i] == '?')
                        {
                            if (J[i] == '?') { C1[i] = '0'; J1[i] = '0'; }
                            else C1[i] = J[i];
                        }
                        else if (J[i] == '?') J1[i] = C[i];
                    for (int i = k + 1; i < L; i++)
                    {
                        if (C[i] == '?') C1[i] = '9';
                        if (J[i] == '?') J1[i] = '0';
                    }
                    for (int i = k; --i >= 0;)
                    {
                        if (J[i] == '?')
                        {
                            if (C[i] == '?') { J1[i] = '1'; break; }
                            if (C[i] != '9') { J1[i] = (char)(C[i] + 1); break; }
                            J1[i] = '0';
                        }
                    }

                    for (int i = 0; i < k; i++)
                        if (C[i] == '?')
                        {
                            if (J[i] == '?') { C2[i] = '0'; J2[i] = '0'; }
                            else C2[i] = J[i];
                        }
                        else if (J[i] == '?') J2[i] = C[i];
                    for (int i = k + 1; i < L; i++)
                    {
                        if (C[i] == '?') C2[i] = '9';
                        if (J[i] == '?') J2[i] = '0';
                    }
                    for (int i = k; --i >= 0;)
                    {
                        if (C[i] == '?')
                        {
                            if (J[i] == '?') { C2[i] = '9'; continue; }
                            if (J[i] != '0') { C2[i] = (char)(J[i] - 1); break; }
                            C2[i] = '9';
                        }
                    }
                }

                if (b)
                {
                    var D0 = C0; var D1 = C1; var D2 = C2; var D = C;
                    C0 = J0; C1 = J1; C2 = J2; C = J;
                    J0 = D0; J1 = D1; J2 = D2; J = D;
                }

                var c0 = BigInteger.Parse(new string(C0));
                var c1 = BigInteger.Parse(new string(C1));
                var c2 = BigInteger.Parse(new string(C2));
                var j0 = BigInteger.Parse(new string(J0));
                var j1 = BigInteger.Parse(new string(J1));
                var j2 = BigInteger.Parse(new string(J2));
                var d0 = BigInteger.Abs(c0 - j0);
                var d1 = BigInteger.Abs(c1 - j1);
                var d2 = BigInteger.Abs(c2 - j2);
                char[] CC;
                char[] JJ;
                if (d0 < d1 && d0 < d2 || 
                    d0 == d1 && d0 < d2 && (c0 < c1 || c0 == c1 && j0 < j1) || 
                    d0 < d1 && d0 == d2 && (c0 < c2 || c0 == c2 && j0 < j2) ||
                    d0 == d1 && d0 == d2 && (c0 < c1 && c0 <= c2 || c0 <= c1 && c0 < c2 || c0 == c1 && c0 == c2 && j0 <= j1 && j0 <= j2))
                {
                    CC = C0; JJ = J0;
                }
                else if (d1 < d2 || d1 == d2 && (c1 < c2 || c1 == c2 && j1 < j2))
                {
                    CC = C1; JJ = J1;
                }
                else
                {
                    CC = C2; JJ = J2;
                }

                var result = string.Format("Case #{0}: {1} {2}", t + 1, new string(CC), new string(JJ));
                Console.WriteLine(result);
                fileOutput.WriteLine(result);
            }
        }

    }
}
