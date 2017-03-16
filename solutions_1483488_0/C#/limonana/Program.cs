using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace template
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = File.OpenText("A-small-practice.in");
            StreamWriter writer = new StreamWriter("small_out.txt");            
            int T = int.Parse(reader.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                IEnumerable<int> data = reader.ReadLine().Split(' ').Select(x => int.Parse(x));
                int A = data.ElementAt(0);
                int B = data.ElementAt(1);

                ulong answer = solve(A, B);
                writer.WriteLine(String.Format("Case #{0}: {1}", t, answer));
            }
            writer.Flush();
            writer.Close();
            reader.Close();
        }

        private static ulong solve(int A, int B)
        {
            ulong count = 0;
            for (int n = A; n <= B; n++)
            {
                List<int> validSwaps = createValidSwaps(n,A,B);
                count += (ulong)validSwaps.Count;
            }
            return count / 2;
        }

        private static List<int> createValidSwaps(int n,int lowerBound, int upperBound)
        {
            HashSet<String> swaps = createSwaps(n.ToString());
            IEnumerable<int> numbers = swaps.Select(x => int.Parse(x));
            IEnumerable<int> validSwaps = numbers.Where(x=> (x>= lowerBound && x<=upperBound));
            return validSwaps.ToList();            
        }

        private static HashSet<string> createSwaps(string str)
        {
            HashSet<string> set = new HashSet<string>();
            set.Add(str);
            StringBuilder b = new StringBuilder(str);
            for (int i = 1; i < str.Length; i++)
            {
                char  firstLetter = b[0];
                b.Remove(0,1);
                b.Append(firstLetter);
                set.Add(b.ToString());
            }
            //can't be pair with itself
            set.Remove(str);
            return set;
        }
        
    }
}
