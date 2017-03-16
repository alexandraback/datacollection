using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Diamonds
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Users\John\Desktop\diamonds.txt");
            int cursor = 0;

            int problem_sets = Convert.ToInt32(lines[cursor++]);
            Console.WriteLine("{0} problem sets detected", problem_sets);

            System.IO.StreamWriter file_out = new StreamWriter(@"C:\Users\John\Desktop\diamonds_out.txt");

            for (int i = 0; i < problem_sets; i++)
            {
                
                Console.WriteLine();

                string info = lines[cursor++];
                string[] words = info.Split(' ');

                //if (i != 5) continue;

                int diamond_count = Convert.ToInt32(words[0]);
                int target_x = Convert.ToInt32(words[1]);
                int target_y = Convert.ToInt32(words[2]);
                Console.WriteLine("Found a problem with {0} diamonds, target square {1}, {2}", diamond_count, target_x, target_y);

                // TODO: Special cases for low diamond count

                // Quick exit if a diamond can never fall there
                if ((target_x + target_y) % 2 != 0)
                {
                    Console.WriteLine("Shortcut false");
                    string special_output = string.Format("Case #{0}: {1}", (i + 1), 0.0);
                    file_out.WriteLine(special_output);
                    continue;
                }

                // We know it will fill up in triangular numbers, so get the triangular number just
                // below diamond_count
                int triangular_n = 0;
                for (int n = 1; n < 100000; n += 2)
                {
                    if ((n + 1) * n / 2 > diamond_count)
                    {
                        triangular_n = n - 2;
                        break;
                    }
                }
                Console.WriteLine("It's the {0}th triangular number", triangular_n);

                // Write down the diamonds in the triangle and the ones left over
                int diamonds_in_triangle = (triangular_n + 1) * triangular_n / 2;
                int leftover_diamonds = diamond_count - diamonds_in_triangle;
                Console.WriteLine("{0} diamonds in the triangle, {1} left over", diamonds_in_triangle, leftover_diamonds);

                // Step 1: If it's in the triangle, we win.
                int xplusy = Math.Abs(target_x) + target_y;
                if (xplusy < triangular_n + 1)
                {
                    Console.WriteLine("Inside triangle. Guaranteed win.");
                    string special_output = string.Format("Case #{0}: {1}", (i + 1), 1.0);
                    file_out.WriteLine(special_output);
                    continue;
                }
                else if (xplusy > triangular_n + 1)
                {
                    Console.WriteLine("Outside triangle. Guaranteed loss.");
                    string special_output = string.Format("Case #{0}: {1}", (i + 1), 0.0);
                    file_out.WriteLine(special_output);
                    continue;
                }
                else
                {
                    // This is the tricky bit. We need to figure out how many diamonds need to fall
                    // to a particular side, and then compare with the amount of diamonds left
                    // to fall.
                    int diamonds_needed = target_y + 1;

                    // If we don't have enough, it's a guaranteed loss
                    if (diamonds_needed > leftover_diamonds)
                    {
                        Console.WriteLine("Not enough diamonds. Guaranteed loss.");
                        string special_output = string.Format("Case #{0}: {1}", (i + 1), 0.0);
                        file_out.WriteLine(special_output);
                        continue;
                    }

                    // Special case: can't do it if we're looking for x = 0
                    else if (target_x == 0)
                    {
                        Console.WriteLine("Can't reach the apex. Guaranteed loss.");
                        string special_output = string.Format("Case #{0}: {1}", (i + 1), 0.0);
                        file_out.WriteLine(special_output);
                        continue;
                    }

                    // The serious ones go here:
                    else
                    {
                        double answer = GetProbability(leftover_diamonds, diamonds_needed);
                        Console.WriteLine("Calculating the probability as {0}", answer);
                        string output = string.Format("Case #{0}: {1}", (i + 1), answer);
                        file_out.WriteLine(output);
                        continue;
                    }


                }


            }


            file_out.Close();
            Console.WriteLine("\nDone!\n");
            Console.ReadLine();
        }

        static double GetProbability(int n, int m)
        {
            // Returns the probability of at least m heads from n throws
            int sum = 0;
            for (int i = m; i <= n; i++)
            {
                sum += nCr(n, i);
            }

            int divisor = xtoy(2, n);

            return ((double) sum)/((double) divisor);
        }

        static int nCr(int n, int r)
        {
            int score = 1;
            for (int i = 0; i < r; i++)
            {
                score *= (n - i);
                //score /= (r - i);
            }

            for (int i = 0; i < r; i++)
            {
                score /= (r - i);
            }

            return score;
        }

        static int xtoy(int x, int y)
        {
            int answer = 1;
            for (int i = 0; i < y; i++)
            {
                answer *= x;
            }

            return answer;
        }


    }
}
