using System;
using System.Text;
using System.IO;
using System.Collections;
using System.Collections.Generic;

namespace tribes
{

    class Program
    {

        public static HashSet<char> _vowels = new HashSet<char>();
        public static string name = "tribes";
        static void Main(string[] args)
        {
            _vowels.Add('a');
            _vowels.Add('e');
            _vowels.Add('i');
            _vowels.Add('o');
            _vowels.Add('u');

            StreamReader reader = new StreamReader(@"C:\codejam\" + name + @"\input.txt");
            int cases = int.Parse(reader.ReadLine());

            StringBuilder result = new StringBuilder();

            for (int i = 0; i < cases; i++)
            {
                solveCase(result, i, reader);
            }

            reader.Close();

            StreamWriter sw = new StreamWriter(@"C:\codejam\" + name + @"\result.txt", false);
            sw.Write(result.ToString());
            sw.Flush();
            sw.Close();
        }

        public static void solveCase(StringBuilder result, int caseno, StreamReader reader)
        {
            int consecutive_val;
            string name;

            SortedList<int, SortedSet<int>> done = new SortedList<int, SortedSet<int>>();

            string[] row = reader.ReadLine().Split(' ');

            name = row[0];
            consecutive_val = int.Parse(row[1]);

            int sol = solve(name, consecutive_val, done,0, name.Length-1);
            sol += increase_n_count(name, consecutive_val);

            addResult(result, sol.ToString(), caseno);
        }

        public static int solve(string word, int n_value, SortedList<int, SortedSet<int>> done_list, int left_val, int right_val)
        {

            //base case
            if (word.Length == n_value)
                return 0;

            bool do_left = true;

            bool do_right = true;

            //work out if startign left overlap
            if (done_list.ContainsKey(left_val))
            {
                if (done_list[left_val].Contains(right_val - 1))
                    do_left = false;
            }

            if (done_list.ContainsKey(left_val + 1))
            {
                if (done_list[left_val + 1].Contains(right_val))
                    do_right = false;
            }

            int n_count = 0;
            if (do_left)
            {
                if (!done_list.ContainsKey(left_val))
                {
                    SortedSet<int> temp = new SortedSet<int>();
                    temp.Add(right_val - 1);
                    done_list.Add(left_val, temp);
                }
                else
                {
                    done_list[left_val].Add(right_val - 1);
                }
            
                string left_word = word.Substring(0, word.Length - 1);
                int l_count = increase_n_count(left_word, n_value);
                if (l_count != 0)
                {
                    n_count += solve(left_word, n_value, done_list, left_val, right_val - 1) + l_count;
                }
            }

            if (do_right)
            {

                if (!done_list.ContainsKey(left_val + 1))
                {
                    SortedSet<int> temp = new SortedSet<int>();
                    temp.Add(right_val);
                    done_list.Add(left_val + 1, temp);
                }
                else
                {
                    done_list[left_val + 1].Add(right_val);
                }
            

                string right_word = word.Substring(1);
                int r_count = increase_n_count(right_word, n_value);
                if (r_count != 0)
                {
                    n_count += solve(right_word, n_value, done_list, left_val + 1, right_val) + r_count;
                }
            }
          
            return n_count;
        }

        public static int increase_n_count(string word, int n_value)
        {
            int cons = 0;
            for (int i = 0; i < word.Length; i++)
            {
                if (_vowels.Contains(char.Parse(word.Substring(i, 1))))
                {
                    cons = 0;
                }
                else
                {
                    cons++;
                    if (cons == n_value)
                        return 1;
                }
            }
            return 0;
        }



        public static void addResult(StringBuilder result, string result_to_add, int caseno)
        {
            result.AppendLine("Case #" + (caseno + 1) + ": " + result_to_add);
        }
    }
}
