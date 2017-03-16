using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2014.RoundQ
{
    class R0D_DeceitfulWar
    {
        bool logEnabled = false;
        static string baseFileName = "D-small-attempt1";
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

        private int N { get; set; }
        private List<double> Naomi { get; set; }
        private List<double> Ken { get; set; }
        
        private int Y { get; set; }
        private int Z { get; set; }
        private string Result { get; set; }

        private void ReadInput()
        {
            char[] sep = { ' ' };

            N = Int32.Parse(reader.ReadLine());
            Naomi = reader.ReadLine().Split(sep).Select(num => Double.Parse(num)).ToList();
            Ken = reader.ReadLine().Split(sep).Select(num => Double.Parse(num)).ToList();
        }

        private void Solve()
        {
            Naomi.Sort();
            Ken.Sort();

            Z = 0;
            int foil = 0;
            int ni = Naomi.Count - 1;
            int ki = Ken.Count - 1;
            while (ni >= 0 && ki >= 0)
            {
                if (Naomi[ni] > Ken[ki])
                {
                    if (foil == 0)
                    {
                        Z++;
                    }
                    else
                    {
                        foil--;
                    }
                    ni--;
                }
                else
                {
                    foil++;
                    ki--;
                }
            }

            Y = 0;
            while (Naomi.Count > 0)
            {
                while (Naomi.Count > 0 && Naomi[0] < Ken[0])
                {
                    Naomi.RemoveAt(0);
                    Ken.RemoveAt(Ken.Count - 1);
                }
                while (Naomi.Count > 0 && Naomi[0] > Ken[0])
                {
                    Y++;
                    Naomi.RemoveAt(0);
                    Ken.RemoveAt(0);
                }
            }

            Result = String.Format("{0} {1}", Y, Z);
        }

        public R0D_DeceitfulWar()
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
            new R0D_DeceitfulWar();
        }
    }
}
