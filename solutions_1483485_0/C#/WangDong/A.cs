using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
        class A
        {
                string filein = "C:/Users/yaoyao/Downloads/in.txt";
                string filea = "C:/Users/yaoyao/Downloads/A-small-attempt0.in";
                string fileout = "C:/Users/yaoyao/Downloads/out.txt";

                Dictionary<char, char> d = new Dictionary<char, char>();
                Dictionary<char, char> d2 = new Dictionary<char, char>();

                public void run()
                {
                        StreamReader sr = new StreamReader(filein);
                        string line, s1 = "", s2 = "";
                        int index = 0;
                        while ((line = sr.ReadLine()) != null)
                        {
                                if (index % 2 == 0)
                                        s1 = line.ToLower().Trim();
                                else
                                {
                                        s2 = line.ToLower().Trim();
                                        for (int i = 0; i < s1.Length; i++)
                                        {
                                                d[s1[i]] = s2[i];
                                                d2[s2[i]] = s1[i];
                                        }
                                }
                                index++;
                        }
                        sr.Close();
                        d2['z'] = 'q';
                        d['q'] = 'z';
                        for (char i = 'a'; i<='z'; i++)
                                if (!d2.ContainsKey(i))
                                {
                                        for (char j = 'a'; j <= 'z'; j++)
                                                if (!d.ContainsKey(j))
                                                {
                                                        d[j] = i;
                                                        d2[i] = j;
                                                }
                                }
                        for (char j = 'a'; j <= 'z'; j++)
                                if (d.ContainsKey(j))
                                        System.Console.WriteLine("{0}\t{1}", j, d[j]);
                        System.Console.WriteLine(d2.Count);
                }

                public void translate()
                {
                        StreamReader sr = new StreamReader(filea);
                        StreamWriter sw = new StreamWriter(fileout);
                        string line;
                        int index = 0;
                        while ((line = sr.ReadLine()) != null)
                        {
                                if (index == 0)
                                {
                                        index++;
                                        continue;
                                }
                                sw.Write("Case #{0}: ", index);
                                for (int i = 0; i < line.Length; i++)
                                        sw.Write(d[line.ToLower()[i]]);
                                sw.WriteLine();
                                index++;
                        }
                        sr.Close();
                        sw.Close();
                }

                static void Main(string[] args)
                {
                        A p = new A();
                        p.run();
                        p.translate();
                }
        }
}
