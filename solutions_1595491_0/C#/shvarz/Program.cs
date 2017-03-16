using System;
using System.Collections.Generic;
using System.Linq; 
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            checked
            {
                const string outputfile = @"F:\GoogleCodeJam\output.txt";

                StreamReader r = new StreamReader(@"F:\GoogleCodeJam\input.in");

                if (File.Exists(outputfile))
                    File.Delete(outputfile);

                if (File.Exists(@"F:\GoogleCodeJam\Program.cs"))
                    File.Delete(@"F:\GoogleCodeJam\Program.cs");

                File.Copy(@"f:\Projects\ConsoleApplication1\ConsoleApplication1\Program.cs",
                    @"F:\GoogleCodeJam\Program.cs");

                StreamWriter w = new StreamWriter(outputfile);

                int T = int.Parse(r.ReadLine());

                for (int t = 0; t < T; t++)
                {
                    string[] ss = r.ReadLine().Split(" ".ToCharArray());

                    int n = int.Parse(ss[0]);
                    int s = int.Parse(ss[1]);
                    int p = int.Parse(ss[2]);

                    int cnt = 0;
                    for (int i = 0; i <n; i++ )
                    {
                        int scores = int.Parse(ss[i + 3]);

                        if (getMax(scores, false) >= p)
                        {
                            cnt++;
                            continue;
                        }

                        
                        if (s > 0 && getMax(scores, true) >= p)
                        {
                            cnt++;
                            s--;
                        }

                    }
                    
                    
                    w.WriteLine("Case #" + (t + 1) + ": " + cnt);

                    
                }

                r.Close();
                w.Close();
            }
        }

        private static int getMax(int sum, bool surprise)
        {
            if (sum == 0)
                return 0;

            if (sum%3 == 0)
            {
                if (surprise)
                    return sum/3 + 1;
                else
                    return sum/3;
            }

            if (sum % 3 == 1)
            {
                    return sum / 3 + 1;
            }

            if (sum % 3 == 2)
            {
                if (surprise)
                    return sum / 3 + 2;
                else
                    return sum / 3 + 1;
            }

            throw new ArgumentException();
        }

       
    }
}
