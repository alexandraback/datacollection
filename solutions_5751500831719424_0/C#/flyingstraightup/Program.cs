using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace google_repeater
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter writer = new StreamWriter("result.txt");
            using (StreamReader reader = new StreamReader("A-small-attempt2.in"))
            {
                int numGames = Int32.Parse(reader.ReadLine());

                for (int i = 0; i < numGames; i++)
                {
                    // read in pattern
                    int numLines = Int32.Parse(reader.ReadLine());
                    List<string> lines = new List<string>();
                    for (int j = 0; j < numLines; j++)
                    {
                        lines.Add(reader.ReadLine());
                        
                        // for debug
                        //writer.WriteLine(lines[j].Length.ToString() + " " + lines[j]);
                    }

                    // calculate game
                    string result = "Case #" + (i + 1).ToString() + ": " + calc(lines, writer);
                    writer.WriteLine(result);
                }
            }

            writer.Close();
        }

        static string calc(List<string> input, StreamWriter writer)
        {
            List<int> counter = new List<int>();
            List<int> marker = new List<int>();
            for (int c = 0; c < input.Count(); c++)
            {
                counter.Add(0);
                marker.Add(0);
            }

            int i = 0;
            int totalMoves = 0;
            while (i < input[0].Length)
            {
                // count each letter in each string
                char targetLetter = input[0][i];

                for (int j = 0; j < input.Count(); j++)
                {
                    counter[j] = 0;
                    if (marker[j] >= input[j].Length || input[j][marker[j]] != targetLetter)
                        return "Fegla won";
                    while (marker[j] < input[j].Length && input[j][marker[j]] == targetLetter)
                    {
                        counter[j]++;
                        marker[j]++;
                    }
                }

                // compare letter counts
                if (counter.Contains(0))
                    return "Fegla Won";
                counter.Sort();
                int targetValue = counter[counter.Count() / 2];
                foreach (int count in counter)
                {
                    totalMoves += Math.Abs(count - targetValue);

                    // for debug
                    //if (Math.Abs(count - targetValue) > 0)
                    //    writer.WriteLine(targetLetter + " " + Math.Abs(count - targetValue).ToString());
                }

                i = marker[0];
            }
            
            // check for leftover letters
            for (int j = 1; j < input.Count(); j++)
            {
                if (marker[j] < input[j].Length)
                    return "Fegla Won";
            }

            return totalMoves.ToString();
        }
    }
}
