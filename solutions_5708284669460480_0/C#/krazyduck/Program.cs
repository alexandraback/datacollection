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
                        int[] s;
                        double r, e;
                        int l;
                        string a;
                        for (int i = 0; i < t; i++)
                        {
                            s = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                            a = sr.ReadLine();
                            target = sr.ReadLine();
                            
                            prob = a.GroupBy(x => x).Select(x => new { c = x.Key, p = (double)x.Count() / a.Length }).ToDictionary(x => x.c, x => x.p);

                            subIndex = 0;
                            for (int j = 1; j < target.Length; j++)
                            {
                                if (target.StartsWith(target.Substring(j)))
                                {
                                    subIndex = j;
                                    break;
                                }
                            }

                            expect = new double[target.Length][];

                            for (int k = 0; k < expect.Length; k++)
                            {
                                expect[k] = Enumerable.Repeat(-1, s[2] + 1).Select(x => (double)x).ToArray();
                            }

                            r = 0d;
                            e = Math.Round(Expected(0, s[2]), 6);

                            if (e > 0)
                            {
                                l = 0;
                                while (s[2] - l >= target.Length)
                                {
                                    r++;
                                    l += subIndex == 0 ? target.Length : subIndex;
                                }
                            }

                            r -= e;
                            sw.WriteLine(string.Format(o, i + 1) + r);
                        }
                    }
                }
            }
        }
    }

    private static int subIndex;
   
    private static string target;
    private static Dictionary<char, double> prob;

    private static double[][] expect;

    public static double Expected(int index, int length)
    {
        if (index == target.Length)
            return 0;

        if (expect[index][length] == -1)
        {

            if (target.Length - index > length)
                expect[index][length] = 0;
            else
            {
                double p;
                prob.TryGetValue(target[index], out p);
                int ind = 0;
                if (subIndex > 0)
                    ind = target.Length - subIndex;
                if (index + 1 == target.Length)
                    expect[index][length] = p + Expected(ind, length - 1);
                else
                    expect[index][length] = p * Expected(index + 1, length - 1) + (1 - p) * Expected(0, length - 1);
            }
        }

        return expect[index][length];
    }
}