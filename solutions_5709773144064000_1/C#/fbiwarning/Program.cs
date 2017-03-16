using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

namespace QRProblemB
{
    class Program
    {
        static void Main(string[] args)
        {
            String path = Path.GetDirectoryName(Assembly.GetExecutingAssembly().
                GetModules()[0].FullyQualifiedName);

            String inputPath = path + Path.DirectorySeparatorChar + "B-large.in";
            String outputPath = path + Path.DirectorySeparatorChar + "B-large.in.txt";

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
            // read conditions 
            string line = reader.ReadLine();
            string[] word = line.Split(new char[] { ' ' });
            double FarmPrice = Convert.ToDouble(word[0]);
            double FramRate = Convert.ToDouble(word[1]);
            double WinCookies = Convert.ToDouble(word[2]);
            double CurrentRate = 2;
            double totalSecond = 0;

            // judge
            while (true)
            {
                double needTime = WinCookies / CurrentRate;
                double costTime = FarmPrice / CurrentRate + WinCookies / (CurrentRate + FramRate);
                if (costTime < needTime)
                {
                    totalSecond += FarmPrice / CurrentRate;
                    CurrentRate += FramRate;
                }
                else
                {
                    totalSecond += needTime;
                    break;
                }
            }

            string result = "" + totalSecond;
            writer.WriteLine("Case #" + caseNumber + ": " + result);
        }
    }
}
