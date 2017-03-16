using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class Program
{
    public static void Main()
    {
        using (FileStream iStream = File.OpenRead(@"C:\Users\James\Downloads\input.in"))
        {
            using (FileStream oStream = File.OpenWrite(@"C:\Users\James\Documents\Visual Studio 2012\Projects\TopCoder\TopCoder\output.out"))
            {
                using (StreamReader sr = new StreamReader(iStream))
                {
                    int t = int.Parse(sr.ReadLine());
                    string o = "Case #{0}: ";

                    string w;
                    int[] g;
                    int m;

                    using (StreamWriter sw = new StreamWriter(oStream))
                    {
                        for (int i = 0; i < t; i++)
                        {
                            g = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                            m = g[1] * g[2];

                            switch (g[0])
                            {
                                case 1:
                                    w = "GABRIEL";
                                    break;
                                case 2:
                                    w = m % 2 == 0 ? "GABRIEL" : "RICHARD";
                                    break;
                                case 3:
                                    w = m % 3 == 0 && m > 3 ? "GABRIEL" : "RICHARD";
                                    break;
                                case 4:
                                    w = m == 12 || m == 16 ? "GABRIEL" : "RICHARD";
                                    break;
                                default:
                                    w = "RICHARD";
                                    break;
                            }

                            sw.WriteLine(string.Format(o, i + 1) + w);
                        }
                    }
                }
            }
        }
    }
}