using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
namespace codejam1C
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader(@"C:\Users\mohit\Documents\Visual Studio 2010\Projects\codejam1C\A-small-attempt0.in");
            StreamWriter writer = new StreamWriter(@"C:\Users\mohit\Documents\Visual Studio 2010\Projects\codejam1C\Asmall.out");
            int T = Int32.Parse(reader.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                string[] s = reader.ReadLine().Split('/');
                Console.WriteLine(s[0]+" "+s[1]);
                if (Int32.Parse(s[1]) % 2 == 1)
                {
                    writer.WriteLine("Case #"+i+": impossible");
                    continue;
                }
                int count = 1;
                double d = Double.Parse(s[0]) / Double.Parse(s[1]);
                Console.WriteLine(d);
                while (true)
                {
                    if (d * 2 >= 1)
                    {
                        writer.WriteLine("Case #"+i+": "+count);
                        break;
                    }
                    else
                    {
                        d = d * 2;
                        count++;
                        /*if (count > 40)
                        {
                            writer.WriteLine("Case #" + i + ": impossible");
                            break;
                        }*/
                    }
                }
            }
            writer.Close();
            reader.Close();
        }
    }
}
