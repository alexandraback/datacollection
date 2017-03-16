using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace googlecode
{
    class Program
    {
        static void Main(string[] args)
        {
            
            int t;
            string line;
            System.IO.StreamReader file =
   new System.IO.StreamReader("d:\\temp.txt");
            System.IO.StreamWriter outfile =
   new System.IO.StreamWriter("d:\\out.txt");
            while ((line = file.ReadLine()) != null)
            {
                t = int.Parse(line);

                for (int i = 0; i < t; ++i) 
                {
                    line = file.ReadLine();
                    long p,q;
                    var lines = line.Split(new char[] { '/' }, StringSplitOptions.RemoveEmptyEntries);
                    p = long.Parse(lines[0]);
                    q = long.Parse(lines[1]);
                    string res;
                    if (p > q)
                    {
                        res = "impossible";
                        outfile.WriteLine("Case #" + (i + 1) + ": " + res);
                        continue;
                    }
                    int j = 0;
                    long z = 1;
                    while (q % 2 == 0)
                    {
                        q /= 2;
                        ++j;
                        z *= 2;
                    }
                    while (p % 2 == 0)
                    {
                        p /= 2;
                        --j;
                        z /= 2;
                    }
                    if (q != 1)
                    {
                        if (p % q != 0)
                        {
                            res = "impossible";
                            outfile.WriteLine("Case #" + (i + 1) + ": " + res);
                            continue;
                        }
                        
                    }
                    p/=q;
                    while (p > 1)
                    {
                        p /= 2;
                        --j;
                    }
                    res = j.ToString();
                    outfile.WriteLine("Case #" + (i + 1) + ": " + res);

                    
                }
                outfile.Close();
                return;
            }

        }
    }
}
