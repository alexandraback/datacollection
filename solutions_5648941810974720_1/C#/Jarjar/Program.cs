using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam1
{
    class Program
    {
        static readonly string small = "small.txt";
        static readonly string large = "large.txt";
        static void Main(string[] args)
        {
            Problem(large);
        }

        static void Problem(string file)
        {
            using (var fsi = new FileStream(file, FileMode.Open))
            {
                using (var sr = new StreamReader(fsi))
                {
                    var fspl = file.Split('.');
                    using (var fso = new FileStream(fspl[0] + "-output." + fspl[1], FileMode.Create))
                    {
                        using (var sw = new StreamWriter(fso))
                        {
                            int T = int.Parse(sr.ReadLine());
                            for (int i = 1; i <= T; i++)
                            {
                                string s = sr.ReadLine();
                                sw.WriteLine(
                                    "Case #{0}: {1}", i,
                                    stringToPhone(s));
                            }
                        }
                    }
                }
            }
        }
        static string stringToPhone(string s)
        {
            List<int> numbers = new List<int>();
            int[] tab = new int[26];
            for (int i = 0; i < s.Length; i++)
            {
                tab[s[i] - 'A']++;
            }
            // Z => 0
            for (int i = 0; i < tab[25]; i++)
            {
                numbers.Add(0);
            }
            tab['E' - 'A'] -= tab[25];
            tab['R' - 'A'] -= tab[25];
            tab['O' - 'A'] -= tab[25];
            tab['Z' - 'A'] -= tab[25];
            // SIX
            for (int i = 0; i < tab['X' - 'A']; i++)
            {
                numbers.Add(6);
            }
            tab['I' - 'A'] -= tab['X' - 'A'];
            tab['S' - 'A'] -= tab['X' - 'A'];
            tab['X' - 'A'] -= tab['X' - 'A'];
            // SEVEN
            for (int i = 0; i < tab['S' - 'A']; i++)
            {
                numbers.Add(7);
            }
            tab['E' - 'A'] -= 2 * tab['S' - 'A'];
            tab['V' - 'A'] -= tab['S' - 'A'];
            tab['N' - 'A'] -= tab['S' - 'A'];
            tab['S' - 'A'] -= tab['S' - 'A'];
            // FIVE
            for (int i = 0; i < tab['V' - 'A']; i++)
            {
                numbers.Add(5);
            }
            tab['I' - 'A'] -= tab['V' - 'A'];
            tab['F' - 'A'] -= tab['V' - 'A'];
            tab['E' - 'A'] -= tab['V' - 'A'];
            tab['V' - 'A'] -= tab['V' - 'A'];

            // TWO
            for (int i = 0; i < tab['W' - 'A']; i++)
            {
                numbers.Add(2);
            }
            tab['O' - 'A'] -= tab['W' - 'A'];
            tab['T' - 'A'] -= tab['W' - 'A'];
            tab['W' - 'A'] -= tab['W' - 'A'];

            // FOUR
            for (int i = 0; i < tab['U' - 'A']; i++)
            {
                numbers.Add(4);
            }
            tab['O' - 'A'] -= tab['U' - 'A'];
            tab['F' - 'A'] -= tab['U' - 'A'];
            tab['R' - 'A'] -= tab['U' - 'A'];
            tab['U' - 'A'] -= tab['U' - 'A'];


            // EIGHT
            for (int i = 0; i < tab['G' - 'A']; i++)
            {
                numbers.Add(8);
            }
            tab['E' - 'A'] -= tab['G' - 'A'];
            tab['I' - 'A'] -= tab['G' - 'A'];
            tab['H' - 'A'] -= tab['G' - 'A'];
            tab['T' - 'A'] -= tab['G' - 'A'];
            tab['G' - 'A'] -= tab['G' - 'A'];

            // THREE
            for (int i = 0; i < tab['H' - 'A']; i++)
            {
                numbers.Add(3);
            }
            tab['E' - 'A'] -= tab['H' - 'A'];
            tab['E' - 'A'] -= tab['H' - 'A'];
            tab['R' - 'A'] -= tab['H' - 'A'];
            tab['T' - 'A'] -= tab['H' - 'A'];
            tab['H' - 'A'] -= tab['H' - 'A'];

            // ONE
            for (int i = 0; i < tab['O' - 'A']; i++)
            {
                numbers.Add(1);
            }
            tab['E' - 'A'] -= tab['O' - 'A'];
            tab['N' - 'A'] -= tab['O' - 'A'];
            tab['O' - 'A'] -= tab['O' - 'A'];

            // NINE
            for (int i = 0; i < tab['N' - 'A']/2; i++)
            {
                numbers.Add(9);
            }
            tab['E' - 'A'] -= tab['N' - 'A']/2;
            tab['I' - 'A'] -= tab['N' - 'A']/2;
            tab['N' - 'A'] -= tab['N' - 'A'];

            numbers.Sort();
            return string.Join("", numbers);
        }
    }

}
