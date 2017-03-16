using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace bullseye
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("A-small.in");
            StreamWriter writer = new StreamWriter("output.txt");
            Int64 TTestCases = Int32.Parse(reader.ReadLine());

            for (int tIndex = 0; tIndex < TTestCases; tIndex++)
            {
                int y=0;        
                String[] rt = (reader.ReadLine()).Split(' '); ;
                Int64 r = Int64.Parse(rt[0]);
                Int64 t = Int64.Parse(rt[1]);

                while(t>0)
                {
                
                    Int64 paintNeeded = (1+(2*r));
                    if(paintNeeded <= t)
                    {
                        y++;
                        t-=paintNeeded;
                    }
                    else
                    {
                        break;
                    }
                    r+=2;
                }
                writer.WriteLine("Case #"+(tIndex+1)+": "+y);
            }
            reader.Close();
            writer.Close();
        }
        
    }
}
