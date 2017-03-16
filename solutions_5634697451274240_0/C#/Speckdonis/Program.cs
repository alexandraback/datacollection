using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Pancakes
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input_lines = File.ReadAllLines("B-small-attempt0.in");

            int T = Convert.ToInt32(input_lines[0]);

            List<bool[]> inputs = new List<bool[]>();

            for (int i = 1; i <= T; i++)
            {
                bool[] new_array = new bool[input_lines[i].Length+1];

                for (int j = 0; j < input_lines[i].Length; j++)
                {
                    new_array[j] = (input_lines[i][j] == '+');
                }

                new_array[input_lines[i].Length] = true;

                inputs.Add(new_array);
            }

            List<int> outputs = new List<int>();

            foreach (bool[] input in inputs)
            {
                bool actual_value = input[0];

                int number_changes = 0;

                for(int i=1;i< input.Length;i++)
                {
                    if (input[i] != actual_value)
                    {
                        actual_value = input[i];
                        number_changes++;
                    }
                }
                outputs.Add(number_changes);
            }

            StreamWriter output_writer = File.CreateText("output.txt");

            for (int counter = 1; counter <= T; counter++)
            {
                output_writer.WriteLine("Case #" + counter + ": " + outputs[counter-1]);
            }

            output_writer.Close();

            Console.WriteLine("DONE");
            Console.ReadKey();
        }
    }
}
