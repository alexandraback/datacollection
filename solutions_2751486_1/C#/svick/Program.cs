using System.IO;
using GCJ_base;
using System.Linq;

namespace GCJ_1CA
{
    class Program
    {
        static void Main()
        {
            new Gcj1CA().Run();
        }
    }

    class Gcj1CA : Gcj
    {
        public Gcj1CA()
        {
            Problem = 'A';
            Small = false;
        }

        protected override string ComputeCase(TextReader reader)
        {
            string[] line = reader.ReadLine().Split(' ');
            string name = line[0];
            int n = int.Parse(line[1]);

            int position = -1;
            int total = 0;

            for (int i = 0; i < name.Length - n + 1; i++)
            {
                if (position < i)
                {
                    position = FindNext(name, i, n);
                    if (position == -1)
                        break;
                }

                total += name.Length - position - n + 1;
            }

            return total.ToString();
        }

        private static readonly char[] Vowels = "aeiou".ToCharArray();

        private static int FindNext(string name, int start, int n)
        {
            int consonants = 0;
            if (start != 0)
            {
                start += n - 1;
                consonants = n - 1;
            }
            for (int i = start; i < name.Length; i++)
            {
                if (Vowels.Contains(name[i]))
                    consonants = 0;
                else
                    consonants++;

                if (consonants == n)
                    return i - n + 1;
            }

            return -1;
        }
    }
}