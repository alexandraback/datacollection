using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = System.IO.File.ReadAllLines(@"D:\Input\A-small-attempt2.in");
            string[] outputlines = new string[lines.Length];
            System.Console.WriteLine("Out put");
            int i = 0;
            int result = 0;
            int aud = 0;
            foreach (string line in lines)
            {
                result = 0;
                aud = 0;
                if(i > 0)
                { 
                string strshy = line.Substring(2);
                for (int j = 0; j < strshy.Length; j++)
                    {
                        if(strshy[j].ToString() == "0" && aud <= j)
                        {
                            result += 1;
                            aud += 1;
                        }
                        else
                        {
                            aud += Convert.ToInt16(strshy[j].ToString());
                        }
                    }
                
                Console.WriteLine("Case #" + i.ToString() + ": " + result.ToString() );
                outputlines[i - 1] = "Case #" + i.ToString() + ": " + result.ToString();
                }
                i += 1;
            }

            // Keep the console window open in debug mode.
            System.IO.File.WriteAllLines(@"D:\Input\A-small-attempt2.out", outputlines);
            Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }
    }
}
