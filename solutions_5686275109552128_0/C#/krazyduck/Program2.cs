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
                    int n, m, c, f;
                    List<int> p;
                    
                    using (StreamWriter sw = new StreamWriter(oStream))
                    {
                        for (int i = 0; i < t; i++)
                        {
                            n = int.Parse(sr.ReadLine());
                            p = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).OrderBy(x => x).ToList();

                            f = 0;

                            do
                            {
                                m = p[p.Count - 1];
                                c = (int)Math.Ceiling((double)m / 2) + 1;
                                if (c < m)
                                {
                                    f += 1;
                                    p.RemoveAt(p.Count - 1);
                                    p.Add(c);
                                    p.Add(m - c);
                                    p.Sort();
                                }
                            } while (c < m);

                            f += m;

                            sw.WriteLine(string.Format(o, i + 1) + f);
                        }
                    }
                }
            }
        }
    }

   
}