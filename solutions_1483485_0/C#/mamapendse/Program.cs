using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Codejam_1
{
    class Program
    {
        static Dictionary<char,char> directory = new Dictionary<char,char>();

        static void Translate(String orig,TextWriter w)
        {
            int i = 0;
            int len = orig.Length;

            for (i = 0; i < len; i++)
            {
                char c = orig[i];

                if (directory.ContainsKey(c))
                {
                    char c1 = directory[c];
                    w.Write("{0}", c1);
                }
                else
                {
                    Console.WriteLine("No substitute for {0}", c);
                }
            }

            
        }

        static void FinalizeLearning()
        {
            int i = 'a';
            char missingkey = ' ' , missingval = ' ' ;
            for (i = 'a'; i <= 'z'; i++)
            {
                char c = (char)i;
                if (!directory.ContainsKey(c))
                {
                    Console.WriteLine("No key {0}", c);
                    missingkey = c;
                }
            }

            for (i = 'a'; i <= 'z'; i++)
            {
                char c = (char)i;
                if (!directory.ContainsValue(c))
                {
                    missingval = c;
                    Console.WriteLine("No key {0}", c);
                }
            }

            directory[missingkey] = missingval;

        }

        static void Learn(String a, String b)
        {
            int i = 0;
            int len = a.Length;
            if (b.Length != len)
            {
                Console.WriteLine("Lengths do not match returning ");
                return;
            }

            for (i = 0; i < len; i++)
            {
                char ca = a[i];
                char cb = b[i];

                if (directory.ContainsKey(ca))
                {
                    char c = directory[ca];
                    if (c != cb)
                    {
                        Console.WriteLine("Different value for {0} , original {1} , new {2}", ca, c, cb);
                    }
                }

                directory[ca] = cb;

            }
        }

        static void Main(string[] args)
        {
            Learn("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand");
            Learn("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
            Learn("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");
            Learn("y qee","a zoo");

            FinalizeLearning();

            TextReader tr = new StreamReader(@"c:\bhargav\A-small-attempt3.in");
            TextWriter of = new StreamWriter(@"c:\bhargav\out.txt");
            string line = tr.ReadLine();

            int numCases = 0;
            try
            {
                numCases = Int32.Parse(line);
            }
            catch (Exception e)
            {
                Console.Out.WriteLine("Parse exception while getting count");
            }

            int i = 0;
            for (i = 0; i < numCases; i++)
            {
                Console.Out.WriteLine("Reading case {0}", i + 1);
                line = tr.ReadLine();
                of.Write("Case #{0}: ",i+1);
                Translate(line, of);
                of.WriteLine();
                of.Flush();
            }

            of.Close();
        }
    }
}
