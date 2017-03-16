using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {

            //Read input
            string[] input_lines = File.ReadAllLines("A-small-attempt0.in");

            int T = Convert.ToInt32(input_lines[0]);

            List<int> inputs = new List<int>();

            for (int i = 1; i <= T; i++)
            {
                inputs.Add(Convert.ToInt32(input_lines[i]));
            }
                      
            List<string> outputs = new List<string>();

            foreach (int input in inputs)
            {

                int N = input;

                if (N == 0)
                {
                    outputs.Add("INSOMNIA");
                    continue;
                }

                bool seen_all_digits = false;

                int fac = 1;

                bool[] seen_digit = new bool[10];

                while (!seen_all_digits)
                {
                    int new_number = fac * N;

                    string number_string = new_number.ToString();

                    for (int j = 0; j < number_string.Length; j++)
                    {
                        switch (number_string[j])
                        {
                            case '0':
                                seen_digit[0] = true;
                                break;
                            case '1':
                                seen_digit[1] = true;
                                break;
                            case '2':
                                seen_digit[2] = true;
                                break;
                            case '3':
                                seen_digit[3] = true;
                                break;
                            case '4':
                                seen_digit[4] = true;
                                break;
                            case '5':
                                seen_digit[5] = true;
                                break;
                            case '6':
                                seen_digit[6] = true;
                                break;
                            case '7':
                                seen_digit[7] = true;
                                break;
                            case '8':
                                seen_digit[8] = true;
                                break;
                            case '9':
                                seen_digit[9] = true;
                                break;
                        }
                    }

                    seen_all_digits = true;

                    for (int i = 0; i < 10; i++)
                    {
                        if (!seen_digit[i])
                        {
                            seen_all_digits = false;
                            break;
                        }
                    }
                    
                    fac++;
                    if (seen_all_digits) outputs.Add(number_string);
                }

            }


            StreamWriter output_writer = File.CreateText("output.txt");
            int output_counter = 1;
            foreach (string output in outputs)
            {
                output_writer.WriteLine("Case #" + output_counter + ": " + output);
                output_counter++;
            }

            output_writer.Close();

            //Console.ReadKey();
        }
    }
}
