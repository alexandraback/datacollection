using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace GCJ2014.RoundQ
{
    class R1BB_NewLotteryGame
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

        private string Result { get; set; }

        private long A { get; set; }
        private long B { get; set; }
        private long K { get; set; }

        private void Init()
        {
        }

        private void ReadInput()
        {
            char[] sep = { ' ' };

            string[] s = reader.ReadLine().Split(sep);
            A = Int64.Parse(s[0]);
            B = Int64.Parse(s[1]);
            K = Int64.Parse(s[2]);
        }

        private void Solve()
        {
            if (Math.Min(A, B) <= K)
            {
                Result = (A * B).ToString();
                return;
            }
            long count = 0;
            for (long i = 0; i < A; i++)
            {
                for (long j = 0; j < B; j++)
                {
                    if ((i & j) < K) count++;
                }
            }
            Result = count.ToString();
        }

        public R1BB_NewLotteryGame()
        {
            reader = new StreamReader(inputFile);
            writer = new StreamWriter(outputFile);
            Init();
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
            new R1BB_NewLotteryGame();
        }
    }
}
