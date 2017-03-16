using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication2
{
    class Program
    {
        static int[,] table = new int[,] { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
        
        static int Operation(int a, int b)
        {
            int result;
            result = table[Math.Abs(a)-1,Math.Abs(b)-1];
            result *= Math.Sign(a*b);
            return result;
        }
        static void Main(string[] args)
        {
            string path = @"C:\Users\Ozan\Downloads\";
            StreamReader reader = new StreamReader(path + @"C-large.in");
            StreamWriter writer = new StreamWriter(path + @"C-large.out");
            int t = Int32.Parse(reader.ReadLine());
            for(int i = 0; i< t;i++)
            {
                string s = reader.ReadLine();
                int l = Int32.Parse(s.Split(' ')[0]);
                long x = Int64.Parse(s.Split(' ')[1]);

                string text = reader.ReadLine();
                int[] series = new int[text.Length];
                series[0] = text[0]-103;

                for(int j=1;j<text.Length;j++)
                {
                    int b = text[j] - 103;
                    series[j] = Operation(series[j - 1], b);
                }

                int[] rep = new int[4];
                rep[0] = 1;
                rep[1] = series[series.Length-1];
                rep[2] = Operation(rep[1], rep[1]);
                rep[3] = Operation(rep[2], rep[1]);

                bool fnd1=false;
                bool fnd2=false;
                if(rep[x % 4] == -1)
                {
                    long nt = 8 < x ? 8 : x;
                    for (int d = 0; d < nt; d++)
                    {
                        for (int e = 0; e < series.Length; e++)
                        {
                            if (!fnd1)
                                fnd1 = Operation(rep[d % 4], series[e]) == 2;
                            else
                                fnd2 = Operation(rep[d % 4], series[e]) == 4;
                            if (fnd2)
                                break;
                        }
                        if (fnd2)
                            break;
                    }
                }
                if (fnd2)
                    writer.WriteLine("Case #" + (i + 1).ToString() + ": YES");
                else
                    writer.WriteLine("Case #" + (i + 1).ToString() + ": NO");
            }
            reader.Close();
            writer.Close();
        }
    }        
}

