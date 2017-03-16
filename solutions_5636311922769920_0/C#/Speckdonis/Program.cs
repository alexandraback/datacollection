using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace SmallFractiles
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input_lines = File.ReadAllLines("D-small-attempt0.in");

            int T = Convert.ToInt32(input_lines[0]);

            List<int[]> inputs = new List<int[]>();

            for (int i = 1; i <= T; i++)
            {
                string actual_string = input_lines[i];

                //K
                string K_part = actual_string.Substring(0, actual_string.IndexOf(' '));

                actual_string = actual_string.Substring(actual_string.IndexOf(' ')+1);

                //C
                string C_part = actual_string.Substring(0, actual_string.IndexOf(' '));

                actual_string = actual_string.Substring(actual_string.IndexOf(' ') + 1);

                //S
                string S_part = actual_string;

                inputs.Add(new int[3] { Convert.ToInt32(K_part), Convert.ToInt32(C_part), Convert.ToInt32(S_part) });
            }

            StreamWriter output_writer = File.CreateText("output.txt");

            int case_counter = 1;
            foreach (int[] input in inputs)
            {
                string output_string = "";
                output_string  += "Case #" + case_counter + ":";

                int K = input[0];

                for (int i = 1; i <= K; i++)
                {
                    output_string += " " + i;
                }

                output_writer.WriteLine(output_string);
                case_counter++;


            }

            output_writer.Close();

            Console.WriteLine("Done");
            Console.ReadKey();


        }
    }
}
