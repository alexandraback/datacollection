using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1B_PB
{
    class Program
    {
        static Int64 diff(string coders, string jammers)
        {
            Int64 cod = Int64.Parse(coders);
            Int64 jam = Int64.Parse(jammers);

            if (jam > cod)
                return jam - cod;
            else
                return cod - jam;

        }

        static string CreateNumber(string num, int value)
        {
            string output = "";

            foreach(char c in num)
            {
                if (c != '?')
                    output += c;
                else
                {
                    int remainder = value % 10;
                    value = value / 10;
                    output += remainder;
                }
            }
            return output;
        }



        static void Main(string[] args)
        {
            StreamReader file = new StreamReader("B-small-attempt1.in");
            StreamWriter writer = new StreamWriter("Output.txt", false);
            string line;

            line = file.ReadLine();

            Int64 numOfCases = Int64.Parse(line);

            for (Int64 i = 0; i < numOfCases; i++)
            {
                line = file.ReadLine();

                string[] scores = line.Split(' ');

                string coders = scores[0];
                string jamers = scores[1];

                int countC =  (int)Math.Pow(10,coders.Count(f => f == '?'));
                int countJ = (int)Math.Pow(10,jamers.Count(f => f == '?'));

                Int64 minC = Int64.MaxValue;
                Int64 minJ = Int64.MaxValue;
                Int64 minDiff = Int64.MaxValue;

                string outCoders = "";
                string outJamers = "";
                
                for (int c = 0; c < countC; c++)
                {
                    string cod = CreateNumber(coders, c);

                    for (int j = 0; j < countJ; j++)
                    {
                        string jam = CreateNumber(jamers, j);

                        Int64 jam64 = Int64.Parse(jam);

                        Int64 nudiff = diff(cod, jam);

                        if(nudiff < minDiff)
                        {
                            minDiff = nudiff;
                            minC = Int64.Parse(cod);
                            minJ = Int64.Parse(jam);
                            outCoders = cod;
                            outJamers = jam;
                        }

                        if(nudiff == minDiff)
                        {
                            if(Int64.Parse(cod) < minC )
                            {
                                minDiff = nudiff;
                                minC = Int64.Parse(cod);
                                minJ = Int64.Parse(jam);
                                outCoders = cod;
                                outJamers = jam;
                             }

                             if(Int64.Parse(jam) < minJ)
                             {
                                 minDiff = nudiff;
                                 minC = Int64.Parse(cod);
                                 minJ = Int64.Parse(jam);
                                 outCoders = cod;
                                 outJamers = jam;
                             }
                        }
                    }
                }



                string output = string.Format("Case #{0}: {1} {2}", i + 1, outCoders, outJamers);
                writer.WriteLine(output);
            }
            file.Close();
            writer.Close();
        }
    }
}
