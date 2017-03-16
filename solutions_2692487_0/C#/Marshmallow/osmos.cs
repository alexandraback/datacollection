using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Osmos
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Users\John\Desktop\osmos.txt");
            int cursor = 0;

            int problem_sets = Convert.ToInt32(lines[cursor++]);
            //Console.WriteLine("{0} problem sets detected", problem_sets);

            System.IO.StreamWriter file_out = new StreamWriter(@"C:\Users\John\Desktop\osmos_out.txt");

            for (int i = 0; i < problem_sets; i++)
            {
                string size_number = lines[cursor++];
                string[] words = size_number.Split(' ');

                // Load size and number
                ulong size = Convert.ToUInt64(words[0]);
                int number = Convert.ToInt32(words[1]);

                string others = lines[cursor++];
                string[] words2 = others.Split(' ');

                // A special case when the mote starts off with size 1 and we have
                // to remove all the motes.
                if (size == 1)
                {
                    //Console.WriteLine("Special case: answer is {0}", number);
                    string special_output = string.Format("Case #{0}: {1}", (i + 1), number);
                    file_out.WriteLine(special_output);
                    continue;
                }

                // Load the other motes
                ulong[] motes = new ulong[number];
                for (int j = 0; j < number; j++)
                {
                    motes[j] = Convert.ToUInt64(words2[j]);
                }

                // Sort the array:
                Array.Sort(motes);

                // Now we begin the solve. Just go through eating the smallest mote. If you can't,
                // make a mote that is size-1.
                ulong current_size = size;
                int moves_made = 0;
                int shortcut_score = 1000001;
                int next_mote = 0;

                for (; ; )
                {
                    // 0. Maybe no motes remain:
                    if (next_mote == number) break;

                    // 1. Eat the next mote if possible
                    if (current_size > motes[next_mote])
                    {
                        //Console.WriteLine("Eating a mote of size {0}", motes[next_mote]);
                        current_size += motes[next_mote];
                        next_mote += 1;
                        continue;
                    }
                    // 2. If not, we'll make a mote, but we'll also write down a possible
                    // best score.
                    else
                    {
                        shortcut_score = Math.Min(shortcut_score, moves_made + number - next_mote);
                        //Console.WriteLine("Making a mote of size {0}", (current_size - 1));
                        //Console.WriteLine("New shortcut score: {0}", shortcut_score);
                        current_size += current_size - 1;
                        moves_made += 1;
                        continue;
                    }
                }

                // Now see what's best out of the shortcut score and the real score
                int score = Math.Min(shortcut_score, moves_made);
                string output = string.Format("Case #{0}: {1}", (i + 1), score);
                file_out.WriteLine(output);
            }


            file_out.Close();
            Console.WriteLine("\nDone!\n");
            Console.ReadLine();
        }
    }
}
