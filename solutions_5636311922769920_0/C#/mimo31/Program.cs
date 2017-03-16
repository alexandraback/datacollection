using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.IO;

namespace JamArchaeologist
{
    class Program
    {
        const string INPUT_PATH = "D:\\CodeJam\\input.in";
        const string OUTPUT_PATH = "D:\\CodeJam\\output.txt";

        static void Main(string[] args)
        {
            FileStream inputStream = new FileStream(INPUT_PATH, FileMode.Open);
            TextReader reader = new StreamReader(inputStream);
            FileStream outputStream = new FileStream(OUTPUT_PATH, FileMode.Create);
            TextWriter writer = new StreamWriter(outputStream);
            int count = int.Parse(reader.ReadLine());
            for (int i = 0; i < count; i++)
            {
                string readLine = reader.ReadLine();
                string[] chunks = readLine.Split(' ');
                int originalSize = int.Parse(chunks[0]);
                int complexity = int.Parse(chunks[1]);
                int numberOfStudents = int.Parse(chunks[2]);
                BigInteger[] result = GetTiles(originalSize, complexity, numberOfStudents);
                StringBuilder outputBuilder = new StringBuilder();
                outputBuilder.Append("Case #");
                outputBuilder.Append((i + 1).ToString());
                outputBuilder.Append(":");
                if (result == null)
                {
                    outputBuilder.Append(" IMPOSSIBLE");
                }
                else
                {
                    for (int j = 0; j < result.Length; j++)
                    {
                        outputBuilder.Append(" ");
                        outputBuilder.Append(result[j].ToString());
                    }
                }
                writer.WriteLine(outputBuilder.ToString());
            }
            reader.Close();
            inputStream.Close();
            writer.Close();
            outputStream.Close();
        }

        static BigInteger[] GetTiles(int originalSize, int complexity, int numberOfStudents)
        {
            if (complexity * numberOfStudents < originalSize)
            {
                return null;
            }
            else
            {
                List<BigInteger> tilesToClean = new List<BigInteger>();
                int positionToCheck = 0;
                while (positionToCheck < originalSize)
                {
                    BigInteger nextTileToClean = 0;
                    for (int i = 0; i < complexity && positionToCheck < originalSize; i++)
                    {
                        nextTileToClean += positionToCheck * BigInteger.Pow(originalSize, i);
                        positionToCheck++;
                    }
                    tilesToClean.Add(nextTileToClean + 1);
                }
                return tilesToClean.ToArray();
            }
        }
    }
}
