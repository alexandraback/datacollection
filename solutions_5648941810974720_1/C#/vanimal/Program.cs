using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Jam
{
    class Program
    {
        static void Main(string[] args)
        {
            int cases = ReadInt();

            for (int i = 0; i < cases; i++)
            {
                Console.WriteLine("Case #{0}: {1}", i + 1, Solve());
            }
        }

        static string[] letters = new string[] { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
        static Dictionary<char, int> identifier = new Dictionary<char, int>
        {
            { 'Z', 0 },
            { 'W', 2 },
            { 'U', 4 },
            { 'X', 6 },
            { 'G', 8 },
            { 'O', 1 },
            { 'H', 3 },
            { 'F', 5 },
            { 'V', 7 },
            { 'E', 9 }
        };
        
        static string Solve()
        {
            var numberCode = ReadString();
            var frequencies = numberCode.GroupBy(c => c).ToDictionary(g => g.Key, g => g.Count());
            var number = new List<int>();

            foreach (var kvp in identifier)
            {
                if (frequencies.ContainsKey(kvp.Key))
                {
                    int count = frequencies[kvp.Key];

                    for (int i = 0; i < count; i++)
                    {
                        number.Add(kvp.Value);
                        
                        foreach (var letter in letters[kvp.Value])
                        {
                            frequencies[letter]--;
                        }
                    }
                }
            }

            return string.Join(string.Empty, number.OrderBy(n => n).Select(n => n.ToString()));
        }

        static int ReadInt()
        {
            return int.Parse(Console.ReadLine());
        }

        static string ReadString()
        {
            return Console.ReadLine();
        }

        static List<T> ReadList<T>()
        {
            return Console.ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToList();
        }
    }
}
