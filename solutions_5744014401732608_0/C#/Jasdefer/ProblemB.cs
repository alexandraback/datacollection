using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam2016.Round1C
{
    public class ProblemB
    {
        private static readonly string PATH = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.Desktop), "GoogleCodeJam2016", "Round1C", "ProblemB");
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
                byte b = Convert.ToByte(lines[i].Split(' ')[0]);
                ulong m = Convert.ToUInt64(lines[i].Split(' ')[1]);
                string result = Solve(b,m);
                SB.AppendLine($"Case #{i}: {result}");
            }

            File.WriteAllText(Path.Combine(PATH, OUTPUT_FILE), SB.ToString());
        }

        private string Solve(byte b, ulong m)
        {
            string result = string.Empty;
            ulong max = Convert.ToUInt64(Math.Pow(2, b - 2));
            if (max < m)
                return "IMPOSSIBLE";

            byte[,] matrix = new byte[b,b];
            for (byte i = 0; i < b; i++)
                for (byte j = Convert.ToByte(i+1); j < b; j++)
                    matrix[i, j] = 1;

            ulong diff = max - m;
            for (byte i = 0; i < b-1; i++)
            {
                ulong connections = Convert.ToUInt64(Math.Max(1,Math.Pow(2, b - i-3)));
                if (diff >= connections)
                {
                    matrix[0,i+1] = 0;
                    diff -= connections;
                    if (diff == 0)
                        i = b;
                }
            }
            if (diff != 0)
                throw new Exception();
            return PrintMatrix(matrix).Trim();
        }


        private string PrintMatrix(byte[,] matrix)
        {
            StringBuilder sb = new StringBuilder();
            sb.AppendLine("POSSIBLE");
            for (int i = 0; i < matrix.GetLength(0); i++)
            {
                string line = string.Empty;
                for (int j = 0; j < matrix.GetLength(1); j++)
                    line += matrix[i, j].ToString();
                sb.AppendLine(line);
            }

            return sb.ToString();
        }



    }
}
