using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace google_lotto
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter writer = new StreamWriter("result.txt");
            //using (StreamReader reader = new StreamReader("test.txt"))
            using (StreamReader reader = new StreamReader("B-small-attempt0.in"))
            {
                int numGames = Int32.Parse(reader.ReadLine());

                for (int i = 0; i < numGames; i++)
                {
                    // read in pattern
                    int[] lottoData = reader.ReadLine().Split(' ').Select(int.Parse).ToArray();

                    // calculate game
                    string result = "Case #" + (i + 1).ToString() + ": " + calcLotto(lottoData[0], lottoData[1], lottoData[2]).ToString();
                    writer.WriteLine(result);
                }
            }

            writer.Close();
        }

        static int calcLotto(int A, int B, int K)
        {
            int count = 0;

            for (int x = 0; x < A; x++)
            {
                for (int y = 0; y < B; y++)
                {
                    int k2 = x & y;
                    if (k2 < K)
                        count++;
                }
            }

            return count;
        }
    }
}
