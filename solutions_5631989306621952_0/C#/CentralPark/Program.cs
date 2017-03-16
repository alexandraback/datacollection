using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    class Program
    {
        static void Main(string[] args)
        {
            var sr = new StreamReader("A-small-attempt0.in");
            var sw = new StreamWriter("output.txt");

            List<long> primeList = new List<long>();

            int T = int.Parse(sr.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                string str = sr.ReadLine();
                string outputStr = str[0].ToString();
                //list.Add(str[0]);
                
                for (int i = 1; i < str.Length; i++) 
                {
                    if (str[i] < outputStr[0])
                        outputStr += str[i];
                    else
                        outputStr = str[i] + outputStr; 
                    
                }

                sw.WriteLine("Case #" + t.ToString() + ": " + outputStr);
            }
            sr.Close();
            sw.Close();
        }
    }
}
