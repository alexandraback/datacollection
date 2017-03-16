using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"C:\Users\ozans_000\Downloads\";
            StreamReader reader = new StreamReader(path + @"B-large.in");
            StreamWriter writer = new StreamWriter(path + @"B-large.out");

            int t = int.Parse(reader.ReadLine());

            for(int i=0;i<t;i++)
            {
                int nd = int.Parse(reader.ReadLine());
                int[] d = new int[nd];

                string text = reader.ReadLine();
                int c = 0;
                foreach(string s in text.Split(' '))
                {
                    d[c] = int.Parse(s);
                    c++;
                }
                int m = d.Max();
                int min = 1000000;
                for(int j=1;j<=m;j++)
                {
                    int total = j;
                    foreach(int diner in d)
                    {
                        if(diner>j)
                        {
                            int moves = (diner - j) / j;
                            if ((moves * j) != (diner - j))
                                moves++;
                            total += moves;
                        }
                    }
                    if (total < min)
                        min = total;
                }
                writer.WriteLine("Case #" + (i + 1).ToString() + ": " + min.ToString());
            }
            writer.Close();
            reader.Close();

        }
    }
}
