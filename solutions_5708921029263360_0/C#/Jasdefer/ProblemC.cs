using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam2016.Round1C
{
    public class ProblemC
    {
        private static readonly string PATH = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "GoogleCodeJam2016", "Round1C", "ProblemC");
        private const string INPUT_FILE = "input-small.in";
        private const string OUTPUT_FILE = "output-small.out";
        private byte T;
        private StringBuilder SB;

        public void Solve()
        {
            string[] lines = File.ReadAllLines(Path.Combine(PATH, INPUT_FILE));
            T = Convert.ToByte(lines[0]);
            SB = new StringBuilder();
            for (byte i = 1; i <= T; i++)
            {
                string[] values = lines[i].Split(' ');
                if (values.Length != 4)
                    throw new Exception();
                byte j = Convert.ToByte(values[0]);
                byte p = Convert.ToByte(values[1]);
                byte s = Convert.ToByte(values[2]);
                byte k = Convert.ToByte(values[3]);
                string result = Solve(j,p,s,k);
                SB.AppendLine($"Case #{i}: {result}");
            }

            File.WriteAllText(Path.Combine(PATH, OUTPUT_FILE), SB.ToString());
        }

        private string Solve(byte jMax, byte pMax, byte sMax, byte k)
        {
            StringBuilder sb = new StringBuilder();
            List<int[]> list = new List<int[]>();
            int counter = 0;

            for (byte j = 1; j <= jMax; j++)
            {
                for (byte p = 1; p <= pMax; p++)
                {
                    for (byte s = 1; s <= sMax; s++)
                    {
                        if(list.Where(x => x[0]==j && x[1] ==p).Count()<k &&
                            list.Where(x => x[0] == j && x[2] == s).Count() < k &&
                            list.Where(x => x[1] == p && x[2] == s).Count() < k)
                        {
                            counter++;
                            list.Add(new int[3] { j, p, s });
                            sb.AppendLine($"{j} {p} {s}");
                        }
                        
                    }
                }

            }

            return counter+"\r\n"+sb.ToString().Trim();
        }

    }
}
