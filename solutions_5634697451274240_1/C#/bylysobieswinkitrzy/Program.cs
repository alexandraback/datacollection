using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RevengeOfThePancakes
{
    class Program
    {
        public static List<int> pancakes = new List<int>();

        static void Flip()
        {
            int startValue = pancakes[0];
            int diffValue = startValue == 0 ? 1 : 0;
            int stopValue = pancakes.IndexOf(diffValue);
            for (int i = 0; i < stopValue; i++)
            {
                pancakes[i] = diffValue;
            }
        }

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines("B-large.in");
            int noOfCases = int.Parse(lines[0]);
            List<string> output = new List<string>();

            for (int i = 1; i <= noOfCases; i++)
            {
                pancakes = lines[i].ToCharArray().Select(x => x == '-' ? 0 : 1).ToList();
                int flips = 0;
                while (pancakes.Count() != pancakes.Sum())
                {
                    flips += 1;
                    if (pancakes.Sum() == 0) { break; }
                    Flip();
                }
                output.Add(String.Format("Case #{0}: {1}", i, flips));
            }
            File.WriteAllLines("output.out", output);
        }
    }
}
