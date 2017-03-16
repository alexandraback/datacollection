using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Aufgabe3
{
    class Instance
    {
        //Additional Tools
        public int[] convert_string_to_int_array(int N, string number_string)
        {
            int[] result = new int[N];

            string copy = number_string;
            for (int i = 0; i < N - 1; i++)
            {
                result[i] = Convert.ToInt32(copy.Substring(0, copy.IndexOf(' ')));
                copy = copy.Substring(copy.IndexOf(' ') + 1);
            }
            result[N - 1] = Convert.ToInt32(copy);

            return result;
        }

        public ulong exact_potenz(ulong basis, int exponent)
        {
            ulong result = 1;

            for (int j = 0; j < exponent; j++)
            {
                result *= basis;
            }

            return result;
        }

        public string[] output_strings;

        string code;
        string jam;

        public Instance(string[] input_strings)
        {
            code = input_strings[0].Substring(0, input_strings[0].IndexOf(' '));
            jam = input_strings[0].Substring(input_strings[0].IndexOf(' ') + 1);
        }

        public bool check_consistent(int number, string number_string)
        {
            string conv_number = number.ToString();


            if (conv_number.Length > number_string.Length)
                return false;

            if (conv_number.Length < number_string.Length)
            {
                string zero_string = "";

                for (int i = 0; i < number_string.Length - conv_number.Length;i++)
                {
                    zero_string += '0';
                }

                conv_number = zero_string + conv_number;
            }
             

            bool are_the_same = true;

            for (int i = 0; i < number_string.Length; i++)
            {
                if (number_string[i] != '?')
                {
                    if (number_string[i] != conv_number[i])
                    {
                        are_the_same = false;
                        break;
                    }
                }
            }

            return are_the_same;
        }


        public void solve()
        {
            int min_distance = 99999;

            int opt_i=0;
            int opt_j=0;

            for (int i = 0; i < 999; i++)
            {
                for (int j = 0; j < 999; j++)
                {
                    if(check_consistent(i,code) && check_consistent(j, jam))
                    {
                        if (Math.Abs(i - j) < min_distance)
                        {
                            min_distance = Math.Abs(i - j);

                            opt_i = i;
                            opt_j = j;
                        }
                        else if (Math.Abs(i - j) <= min_distance)
                        {
                            if (i < opt_i)
                            {
                                opt_i = i;
                                opt_j = j;
                            }
                            else if (i <= opt_i)
                            {
                                if (j < opt_j)
                                { 
                                    opt_i = i;
                                    opt_j = j;
                                }
                            }

                        }

                    }
                }

            }


            output_strings = new string[1];

            string opt_i_s = opt_i.ToString();
            string opt_j_s = opt_j.ToString();

            while (opt_i_s.Length < code.Length)
            {
                opt_i_s = '0' + opt_i_s;
            }

            while (opt_j_s.Length < code.Length)
            {
                opt_j_s = '0' + opt_j_s;
            }



            output_strings[0] = opt_i_s.ToString() + " " + opt_j_s.ToString();

        }

    }


    class Program
    {
        static void Main(string[] args)
        {
            //Read Input
            string[] input_lines = File.ReadAllLines("input.txt");

            int T = Convert.ToInt32(input_lines[0]);

            int lines_per_input = (input_lines.Length - 1) / T;

            Instance[] instances = new Instance[T];

            for (int i = 0; i < T; i++)
            {
                string[] data_for_this_instance = new string[lines_per_input];

                for (int j = 0; j < lines_per_input; j++)
                {
                    data_for_this_instance[j] = input_lines[1 + i * lines_per_input + j];
                }

                //Create Instance
                instances[i] = new Instance(data_for_this_instance);
            }

            //Solve Instances
            foreach (Instance ins in instances) ins.solve();


            //Write Output
            StreamWriter output_writer = File.CreateText("output.txt");

            bool single_line_output_mode = true;
            foreach (Instance ins in instances)
            {
                if (ins.output_strings.Length > 1)
                {
                    single_line_output_mode = false;
                    break;
                }
            }

            int case_counter = 1;
            foreach (Instance ins in instances)
            {
                if (single_line_output_mode)
                {
                    output_writer.WriteLine("Case #" + case_counter + ": " + ins.output_strings[0]);
                }
                else
                {
                    output_writer.WriteLine("Case #" + case_counter + ":");
                    foreach (string out_string in ins.output_strings)
                    {
                        output_writer.WriteLine(out_string);
                    }
                }
                case_counter++;
            }
            output_writer.Close();
        }
    }
}