using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program1B
{
    class Program1BQ1
    {
        static void Main(string[] args)
        {
            Int64 test_cnt = Int64.Parse(Console.ReadLine());
            String line;
            int test_id;

            for (test_id = 0; test_id < test_cnt; test_id++)
            {
                line = Console.ReadLine();
                String[] nums = line.Split(' ');
                Int64 A = Int64.Parse(nums.ElementAt(0));
                Int64 N = Int64.Parse(nums.ElementAt(1));

                line = Console.ReadLine();
                nums = line.Split(' ');
                List<Int64> motes = new List<Int64>();
                

                for (int i = 0; i < N; i++)
                {
                    Int64 val = Int64.Parse(nums.ElementAt(i));
                    motes.Add(val);
                }

                motes.Sort();

                Int64 correction_count = 0;
                Int64 first_attempts_to_remove = 9999999999999;

                for (int i = 0; i < N; i++)
                {
                    if (A > motes.ElementAt(i))
                    {
                        // it can eat the smaller motes
                        A = A + motes.ElementAt(i);

                        // go for the next motes
                        // no correction needed
                    }
                    else
                    { 
                        // it cant eat the next mote
                        Int64 diff = motes.ElementAt(i) - A;
                        Int64 next_motes_cnt = N - i;

                        // which one is better? removing the motes or add motes?
                        Int64 correction_cnt_if_adding_motes = 0;
                        for (correction_cnt_if_adding_motes = 1; correction_cnt_if_adding_motes <= next_motes_cnt; correction_cnt_if_adding_motes++)
                        {
                            // try to add mote with size A-1
                            A = A + A - 1;
                            // check if it now can eat the next mote
                            if (A > motes.ElementAt(i))
                            {
                                // eat current mote
                                A = A + motes.ElementAt(i);
                                break;
                            }
                            else
                                continue;
                        }

                        if (correction_cnt_if_adding_motes > next_motes_cnt)
                        {
                            // it is better to remove the motes
                            correction_count += next_motes_cnt;
                            goto end;
                        }
                        else
                        {
                            // it is better to add motes
                            correction_count += correction_cnt_if_adding_motes;
                        }
                    }
                }

            end:
                if (correction_count > N) correction_count = N;

                Console.Error.Write("Case #" + (test_id + 1) + ": ");
                Console.Write("Case #" + (test_id+1) + ": ");

                Console.Error.WriteLine(correction_count);
                Console.WriteLine(correction_count);
            }

            return;
        }
    }
}
