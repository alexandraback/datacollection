using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

namespace R1CProblemA
{
    class Program
    {
        static void Main(string[] args)
        {
            String path = Path.GetDirectoryName(Assembly.GetExecutingAssembly().
                GetModules()[0].FullyQualifiedName);

            String inputPath = path + Path.DirectorySeparatorChar + "A-small-attempt0.in";
            String outputPath = path + Path.DirectorySeparatorChar + "A-small-attempt0.in.txt";

            StreamReader reader = new StreamReader(inputPath);
            StreamWriter writer = new StreamWriter(outputPath);

            int caseNumber = 0;
            string line = reader.ReadLine();
            caseNumber = Convert.ToInt32(line);

            for (int i = 0; i < caseNumber; ++i)
            {
                DoOneCase(i + 1, reader, writer);
            }
            reader.Close();
            writer.Close();
        }

        public static void DoOneCase(int caseNumber, StreamReader reader, StreamWriter writer)
        {
            // read row1
            string line = reader.ReadLine();

            string[] word = line.Split(new char[] { '/' });
            long P = Convert.ToInt64(word[0]);
            long Q = Convert.ToInt64(word[1]);

           
            // cal common factor
            long factor = Q;
            while (factor != 1) {
                if (factor % 2 == 0)
                {
                    factor = factor / 2;
                }
                else {
                    break;
                }
            }

            // judge common factor
            bool isOk = false;
            if (factor == 1)
            {
                isOk = true;
            }
            else 
            {
                if (P % factor == 0)
                {
                    isOk = true;
                } 
            }

            // cal ge
            long curP = P;
            int geCount = 0;
            while (curP < Q) 
            {
                curP *= 2;
                geCount++; 
            }


            string result = "";
            if (!isOk)
            {
                result = "impossible";
            }
            else
            {
                int ge = (int)geCount;
                result = "" + ge;
            }

            writer.WriteLine("Case #" + caseNumber + ": " + result);
        }
    }
}
