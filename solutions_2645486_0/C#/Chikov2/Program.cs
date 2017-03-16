using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace TopCoderJamProb2
{
    class Program
    {
        public static StreamWriter writer = new StreamWriter("c:\\test\\output.txt", false);
        public static StreamReader reader = new StreamReader("c:\\test\\input.txt");
        public static List<int> howMuchIsWorth = new List<int>();
        public static int recover = 0;
        public static int startingEnergy = 0;

        public static int calculate(int energy, int position)
        {
            if (position == howMuchIsWorth.Count)
            {
                return 0;
            }

            int maxRes = 0;

            for (int i = 0; i <= energy; i++)
            {
                int newEnergy = energy - i + recover;
                if (newEnergy > startingEnergy) newEnergy = startingEnergy;
                int result = calculate(newEnergy, position + 1) + i * howMuchIsWorth[position];
                if (result > maxRes)
                    maxRes = result;
            }

            return maxRes;
        }

        static void Main(string[] args)
        {
            writer.AutoFlush = true;
            int num = Int32.Parse(reader.ReadLine());
            for (int i = 1; i <= num; i++)
            {
                string line = reader.ReadLine();
                string[] inputData = line.Split(' ');
                startingEnergy = Int32.Parse(inputData[0]);
                recover = Int32.Parse(inputData[1]);
                int numOfActivities = Int32.Parse(inputData[2]);
                line = reader.ReadLine();
                inputData = line.Split(' ');
                howMuchIsWorth = new List<int>();
                for (int j = 0; j < inputData.Length; j++)
                {
                    howMuchIsWorth.Add(Int32.Parse(inputData[j]));
                }

                int res = 0;
                if (howMuchIsWorth.Count == 1) 
                   res = howMuchIsWorth[0] * startingEnergy;    
                else
                   res = calculate(startingEnergy, 0);

                writer.WriteLine("Case #" + i + ": " + res);
            }
        }
    }
}
