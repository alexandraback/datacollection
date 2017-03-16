using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication3
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"C:\Users\Ozan\Downloads\";
            StreamReader reader = new StreamReader(path + @"A-small-attempt0.in");
            StreamWriter writer = new StreamWriter(path + @"A-small-attempt0.out");

            int t = int.Parse(reader.ReadLine());

            for(int i=0;i<t;i++)
            {
                string text = reader.ReadLine();
                int s_max = int.Parse(text.Split(' ')[0]);
                string s = text.Split(' ')[1];
                int total = 0;
                int additional = 0;
                for (int j = 0; j < s.Length;j++)
                {
                    if(j<=total)
                    {
                        total += s[j] - 48;
                    }
                    else
                    {
                        additional += j - total;
                        total = j + s[j] - 48;
                    }
                }
                writer.WriteLine("Case #" + (i + 1).ToString() + ": " + additional.ToString());
            }
            writer.Close();
            reader.Close();
        }
    }
}
