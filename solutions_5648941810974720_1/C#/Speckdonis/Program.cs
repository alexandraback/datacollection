using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Aufgabe1
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

        public string S;

        public Instance(string[] input_strings)
        {
            S = input_strings[0];

        }

        public void solve()
        {
            //Count Z

            Dictionary<char, int> counts = new Dictionary<char, int>();

            counts.Add('Z', 0);
            counts.Add('W', 0);
            counts.Add('X', 0);
            counts.Add('G', 0);
            counts.Add('T', 0);
            counts.Add('R', 0);
            counts.Add('F', 0);
            counts.Add('V', 0);
            counts.Add('I', 0);
            counts.Add('O', 0);
            counts.Add('E', 0);
            counts.Add('N', 0);
            counts.Add('H', 0);
            counts.Add('U', 0);
            counts.Add('S', 0);


            for (int i = 0; i < S.Length; i++)
            {
                counts[S[i]]++;
            }

            
            int zero = counts['Z'];

            counts['Z'] -= zero;
            counts['E'] -= zero;
            counts['R'] -= zero;
            counts['O'] -= zero;

            int two = counts['W'];

            counts['T'] -= two;
            counts['W'] -= two;
            counts['O'] -= two;

            int six = counts['X'];

            counts['S'] -= six;
            counts['I'] -= six;
            counts['X'] -= six;

            int eight = counts['G'];

            counts['E'] -= eight;
            counts['I'] -= eight;
            counts['G'] -= eight;
            counts['H'] -= eight;
            counts['T'] -= eight;

            int three = counts['T'];

            counts['T'] -= three;
            counts['H'] -= three;
            counts['R'] -= three;
            counts['E'] -= three;
            counts['E'] -= three;

            int four = counts['R'];

            counts['F'] -= four;
            counts['O'] -= four;
            counts['U'] -= four;
            counts['R'] -= four;

            int five = counts['F'];

            counts['F'] -= five;
            counts['I'] -= five;
            counts['V'] -= five;
            counts['E'] -= five;

            int seven = counts['V'];

            counts['S'] -= seven;
            counts['E'] -= seven;
            counts['V'] -= seven;
            counts['E'] -= seven;
            counts['N'] -= seven;

            int nine = counts['I'];

            counts['N'] -= nine;
            counts['I'] -= nine;
            counts['N'] -= nine;
            counts['E'] -= nine;

            int one = counts['O'];

            counts['O'] -= one;
            counts['N'] -= one;
            counts['E'] -= one;


            output_strings = new string[1];

            string result_string = "";

            for (int i = 0; i < zero; i++) result_string += '0';
            for (int i = 0; i < one; i++) result_string += '1';
            for (int i = 0; i < two; i++) result_string += '2';
            for (int i = 0; i < three; i++) result_string += '3';
            for (int i = 0; i < four; i++) result_string += '4';
            for (int i = 0; i < five; i++) result_string += '5';
            for (int i = 0; i < six; i++) result_string += '6';
            for (int i = 0; i < seven; i++) result_string += '7';
            for (int i = 0; i < eight; i++) result_string += '8';
            for (int i = 0; i < nine; i++) result_string += '9';

            output_strings[0] = result_string;
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