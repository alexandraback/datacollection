using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam._2016r1b
{
    class ProblemA : IProblemSolver
    {
        public bool UsedBruteForce
        {
            get
            {
                return false;
            }
        }

        public void Seed()
        {
            
        }

        private int[] letters;
        private int[] digits;

        public void ProcessInput()
        {
            string s = GCJ.io.nextLine().ToLowerInvariant();
            letters = new int['z'-'a'+1];
            digits = new int[10];
            foreach (var letter in s)
            {
                letters[letter - 'a']++;
            }
        }

        public string BruteForce(int caseNo)
        {
            throw new NotImplementedException();
        }

        public string Solve(int caseNo)
        {
            while (letters['z' - 'a'] > 0) //zero
            {
                TakeOutWord("zero");
                digits[0]++;
            }
            while (letters['w' - 'a'] > 0) //two
            {
                TakeOutWord("two");
                digits[2]++;
            }
            while (letters['u' - 'a'] > 0) //four
            {
                TakeOutWord("four");
                digits[4]++;
            }
            while (letters['x' - 'a'] > 0) //six
            {
                TakeOutWord("six");
                digits[6]++;
            }
            while (letters['g'-'a'] > 0) //eight
            {
                TakeOutWord("eight");
                digits[8]++;
            }
            while (letters['o' - 'a'] > 0) //one
            {
                TakeOutWord("one");
                digits[1]++;
            }
            while (letters['h' - 'a'] > 0) //three
            {
                TakeOutWord("three");
                digits[3]++;
            }
            while (letters['f' - 'a'] > 0) //five
            {
                TakeOutWord("five");
                digits[5]++;
            }
            while (letters['s' - 'a'] > 0) //seven
            {
                TakeOutWord("seven");
                digits[7]++;
            }
            while (letters['n' - 'a'] > 0) //nine
            {
                TakeOutWord("nine");
                digits[9]++;
            }
            List<char> number = new List<char>();
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < digits[i]; j++)
                {
                    number.Add((char)('0'+i));
                }
            }
            var result = new string(number.ToArray());
            for (int i = 0; i < letters.Length; i++)
            {
                if(letters[i] != 0)throw new Exception("WTF?!");
            }
            GCJ.io.Write($"Case #{caseNo}: {result}");
            return result;
        }

        private void TakeOutWord(string word)
        {
            foreach (var letter in word)
            {
                letters[letter - 'a']--;
            }
        }
    }
}
