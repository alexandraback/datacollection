using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace LargeFractiles
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] input_lines = File.ReadAllLines("D-large.in");

            int T = Convert.ToInt32(input_lines[0]);

            List<int[]> inputs = new List<int[]>();

            for (int i = 1; i <= T; i++)
            {
                string actual_string = input_lines[i];

                //K
                string K_part = actual_string.Substring(0, actual_string.IndexOf(' '));

                actual_string = actual_string.Substring(actual_string.IndexOf(' ') + 1);

                //C
                string C_part = actual_string.Substring(0, actual_string.IndexOf(' '));

                actual_string = actual_string.Substring(actual_string.IndexOf(' ') + 1);

                //S
                string S_part = actual_string;

                inputs.Add(new int[3] { Convert.ToInt32(K_part), Convert.ToInt32(C_part), Convert.ToInt32(S_part) });
            }


            List<string> outputs = new List<string>();

            foreach (int[] input in inputs)
            {
                int K = input[0];
                int C = input[1];
                int S = input[2];


                if (C * S < K)
                {
                    outputs.Add(" IMPOSSIBLE");
                    //Console.WriteLine(" IMPOSSIBLE");
                    continue;
                }

                ulong[] positions = new ulong[S];


                List<int[]> list_inner_positions = new List<int[]>();

                int actual_index = 1;

                for (int i = 0; i < Math.Ceiling((double)K/(double)C); i++)
                {
                    int[] inner_positions = new int[C];

                    for (int j = 0; j < C; j++)
                    {
                        if (actual_index <= K)
                        {
                            inner_positions[j] = actual_index;
                            actual_index++;
                        }
                        else
                        {
                            inner_positions[j] = 1;
                        }
                    }
                    list_inner_positions.Add(inner_positions);

                }


                for (int i = 0; i < Math.Ceiling((double)K / (double)C); i++)
                {
                    ulong new_position = 1;

                    for (int j = 1; j <= C; j++)
                    {
                        ulong potenz = 1;

                        for (int pot = 0; pot < C - j; pot++)
                        {
                            potenz *= Convert.ToUInt64(K);
                        }

                        new_position += Convert.ToUInt64(list_inner_positions[i][j-1] - 1) * potenz;
                    }

                    positions[i] = new_position;

                }


                ulong offset = 2;
                for (int i = (int)Math.Ceiling((double)K / (double)C) + 1; i <= S ; i++)
                {
                    ulong potenz = Convert.ToUInt64(K-1);

                    for (int pot = 0; pot < C - 1; pot++)
                    {
                        potenz *= Convert.ToUInt64(K);
                    }

                    positions[i-1] = potenz + offset;
                    offset++;
                }

                string result_string = "";

                for (int i = 0; i < S; i++)
                {
                    result_string += " " + positions[i].ToString();
                }

                outputs.Add(result_string);

            }

            StreamWriter output_writer = File.CreateText("output.txt");

            int case_counter = 1;
            foreach(string output in outputs)
            {
                output_writer.WriteLine("Case #" + case_counter + ":" + output);
                    case_counter++;
            }

            output_writer.Close();
            Console.WriteLine("DONE");
            Console.ReadKey();

        }
    }
}
