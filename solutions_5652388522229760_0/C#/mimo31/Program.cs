using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace JamSleep
{
    class Program
    {
        const string INPUT_PATH = "D:\\CodeJam\\input.in";
        const string OUTPUT_PATH = "D:\\CodeJam\\output.txt";

        static void Main(string[] args)
        {
            FileStream inputStream = new FileStream(INPUT_PATH, FileMode.Open);
            TextReader reader = new StreamReader(inputStream);
            int[] results = new int[int.Parse(reader.ReadLine())];
            for (int i = 0; i < results.Length; i++)
            {
                int startNumber = int.Parse(reader.ReadLine());
                if (startNumber == 0)
                {
                    results[i] = -1;
                    continue;
                }
                bool[] seenDigits = new bool[10];
                int multiple = 0;
                while (!areAllSeen(seenDigits))
                {
                    multiple++;
                    addDigits(startNumber * multiple, seenDigits);
                }
                results[i] = multiple * startNumber;
            }
            reader.Close();
            inputStream.Close();
            FileStream outputStream = new FileStream(OUTPUT_PATH, FileMode.Create);
            TextWriter writer = new StreamWriter(outputStream);
            for (int i = 0; i < results.Length; i++)
            {
                string resultText;
                if (results[i] == -1)
                {
                    resultText = "INSOMNIA";
                }
                else
                {
                    resultText = results[i].ToString();
                }
                writer.WriteLine("Case #" + (i + 1).ToString() + ": " + resultText);
            }
            writer.Close();
            outputStream.Close();
        }

        static void addDigits(int number, bool[] seenDigits)
        {
            string numberString = number.ToString();
            for (int i = 0; i < numberString.Length; i++)
            {
                seenDigits[int.Parse(numberString[i].ToString())] = true;
            }
        }

        static bool areAllSeen(bool[] seenDigits)
        {
            for (int i = 0; i < 10; i++)
            {
                if (seenDigits[i] == false)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
