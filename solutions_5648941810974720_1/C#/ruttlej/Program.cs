using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace R1B_PA
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader file = new StreamReader("A-large.in");
            StreamWriter writer = new StreamWriter("Output.txt", false);
            string line;

            line = file.ReadLine();

            Int64 numOfCases = Int64.Parse(line);
            
            string[] numbers = {"ZERO", "TWO", "FOUR", "SIX", "SEVEN", "EIGHT", "FIVE", "THREE", "ONE", "NINE"};
            string[] values = { "0", "2", "4", "6", "7", "8", "5", "3", "1", "9" };
            int[] intValues = {0, 2, 4, 6, 7, 8, 5, 3, 1, 9};
            string[] values2 = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

            for (Int64 i = 0; i < numOfCases; i++)
            {
                line = file.ReadLine();

                List<int> nums = new List<int>();

                string output = string.Format("Case #{0}: ", i + 1);

                string answer = "";
                for(int n = 0; n < 10; n++)
                {
                    bool found = true;

                    string tempLine = line;
                    foreach(char c in numbers[n])
                    {
                        int index = tempLine.IndexOf(c);
                        if(index >= 0)
                        {
                            tempLine = tempLine.Remove(index, 1);
                        }
                        else
                        {
                            found = false;
                            break;
                        }
                    }
                    if(found)
                    {
                        //answer += values[n];

                        nums.Add(intValues[n]);

                        foreach (char c in numbers[n])
                        {
                            int index = line.IndexOf(c);
                            line = line.Remove(index, 1);
                        }
                        n--;
                    }
                }
                if(line.Length != 0)
                {
                    int x = 0;
                }

                nums.Sort();

                for (int n = 0; n < nums.Count; n++)
                {
                    output += values2[nums[n]];

                }

                writer.WriteLine(output);
            }
            file.Close();
            writer.Close();
        }
    }
}
