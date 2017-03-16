/* C# Program
 * Google Code Jam 2012
 * Qualification Round
 * Problem A. Speaking in Tongues
 * 
 * Copyright Craig A Maher - 2012
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.IO;

namespace CodeJamQR12PA {
    class Program {
        static Dictionary<char, char> decode = new Dictionary<char,char>();
        static void Main(string[] args) {
            BuildDecoder("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
            BuildDecoder("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            BuildDecoder("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
            BuildDecoder("y qee", "a zoo");
            BuildDecoder("z", "q");

            //files
            StreamReader input;
            StreamWriter output;
            input = new StreamReader("A-small-attempt0.in");
            output = new StreamWriter("A-small-attempt0.out");

            //if it fails porgram needs to exit anyway
            int TestCases = int.Parse(input.ReadLine());
            string decoded;
            for (int i = 1; i <= TestCases; ++i) {
                decoded = Translate(input.ReadLine());
                output.WriteLine("Case #{0}: {1}", i, decoded);
                Console.WriteLine("Case #{0}: {1}", i, decoded);
            }

            input.Close();
            output.Close();


            Console.ReadLine();
        }

        static void BuildDecoder(string encoded, string decoded) {
            Debug.Assert(encoded.Length == decoded.Length);

            for (int i = 0; i < encoded.Length; ++i) {
                decode[encoded[i]] = decoded[i];
            }
        }

        static string Translate(string encoded) {
            string decoded = String.Empty;
            for (int i = 0; i < encoded.Length; ++i) {
                decoded += decode[encoded[i]];
            }
            return decoded;
        }
    }
}
