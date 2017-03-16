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
            using (FileStream oStream = File.OpenWrite(@"C:\Users\James\Documents\output.out"))
            {
                using (StreamReader sr = new StreamReader(iStream))
                {
                    int t = int.Parse(sr.ReadLine());
                    string o = "Case #{0}: ";
                    string[] s;
                    int[] a;
                    int r, f, n;

                    using (StreamWriter sw = new StreamWriter(oStream))
                    {
                        for (int i = 0; i < t; i++)
                        {
                            r = 0;
                            f = 0;

                            s = sr.ReadLine().Split(' ');
                            a = s[1].Select(x => x - '0').ToArray();

                            for (int j = 0; j < a.Length; j++)
			                {
                                if (r < j)
                                {
                                    n = j - r;
                                    f += n;
                                    r += n;
                                }

                                r += a[j];
			                }

                            sw.WriteLine(string.Format(o, i + 1) + f);
                        }
                    }
                }
            }
        }
    }
}