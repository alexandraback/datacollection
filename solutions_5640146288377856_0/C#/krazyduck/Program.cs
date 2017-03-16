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

                    using (StreamWriter sw = new StreamWriter(oStream))
                    {
                        int[] b;
                        int r, s;
                        for (int i = 0; i < t; i++)
                        {
                            r = 0;
                            b = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                            s = b[1] / b[2];

                            if (b[0] > 1)
                                r = (b[0] - 1) * s;

                            r += s;
                            r += s * b[2] == b[1] ? b[2] - 1 : b[2];

                            sw.WriteLine(string.Format(o, i + 1) + r);
                        }
                    }
                }
            }
        }
    }
}