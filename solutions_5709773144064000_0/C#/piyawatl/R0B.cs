using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2014.RoundQ
{
    class R0B_CookieClickerAlpha
    {
        bool logEnabled = false;
        static string baseFileName = "B-small-attempt0";
        string inputFile = baseFileName + ".in";
        string outputFile = baseFileName + ".out";
        string logFile = baseFileName + ".log";
        StreamReader reader;
        StreamWriter writer;
        StreamWriter logWriter;
        private void Log(string message)
        {
            if (!logEnabled) return;
            logWriter.WriteLine(message);
        }

        private double C { get; set; }
        private double F { get; set; }
        private double X { get; set; }

        private string Result { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };

            string[] s = reader.ReadLine().Split(sep);
            C = Double.Parse(s[0]);
            F = Double.Parse(s[1]);
            X = Double.Parse(s[2]);
        }

        private void Solve()
        {
            double time = 0.0;
            double rate = 2.0;

            long i = 1;

            double buy = (C / rate) + (X / (rate + F));
            double stay = X / rate;

            while (buy < stay)
            {
                time += (C / rate);
                rate += F;
                buy = (C / rate) + (X / (rate + F));
                stay = X / rate;
                i++;
            }

            time += stay;

            Result = time.ToString("0.0000000");
            Log(i.ToString());
        }

        public R0B_CookieClickerAlpha()
        {
            reader = new StreamReader(inputFile);
            writer = new StreamWriter(outputFile);
            if (logEnabled)
                logWriter = new StreamWriter(logFile);
            try
            {
                string s = reader.ReadLine();
                int T = Int32.Parse(s);
                for (int t = 1; t <= T; t++)
                {
                    Log("Start Case #" + t);
                    ReadInput();
                    Solve();
                    writer.WriteLine(String.Format("Case #{0}: {1}", t, Result));
                    Log("End Case #" + t);
                }
            }
            finally
            {
                reader.Close();
                writer.Close();
                if (logEnabled)
                    logWriter.Close();
            }
        }
        static void Main(string[] args)
        {
            new R0B_CookieClickerAlpha();
        }
    }
}
