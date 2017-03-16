using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;

namespace App1Express
{


    class Case
    {
        private readonly string s;
        private int sLenght;
        private readonly int nNumber;
        private char[] bad = new char[] {'a', 'e', 'i', 'o', 'u'};


        public Case(string s, int nNumber)
        {
            this.s = s;
            this.nNumber = nNumber;
            this.sLenght = s.Length;
        }

        public void solve()
        {
            _PrepareIndicesThatStartString();
            listIndicesThatStart.Sort();
            int[] array = listIndicesThatStart.ToArray();
            for (int i = 0; i < array.Length; i++)
            {
                int myStartIndex = array[i];
                int howManyBeforeSkip = i;
                int myEndIndex = array[i] + nNumber - 1;

                int optionsBefore = myStartIndex - howManyBeforeSkip + 1;
                int optionsAfter = sLenght - myEndIndex;

                if (optionsAfter == 0) optionsAfter = 1;
                if (optionsBefore == 0) optionsBefore = 1;

                result += (optionsAfter * optionsBefore);
            }
        }

        private void _PrepareIndicesThatStartString()
        {
            int index = 0;
            int lenght = s.Length;
            int currentStreak = 0;
            while (index < lenght)
            {
                char c = s[index];
                if (bad.Contains(c))
                {
                    currentStreak = 0;
                }
                else
                {
                    currentStreak++;
                    if (currentStreak >= nNumber)
                    {
                        listIndicesThatStart.Add(index - nNumber + 1);
                    }

                }

                index++;
            }
        }

        List<int> listIndicesThatStart = new List<int>();

        public int result = 0;

    }




    class Program
    {
        static void Main(string[] args)
        {

            string sLine = Console.ReadLine();
            int nCases = int.Parse(sLine);
            List<Case> listCases = new List<Case>();

            for (int i = 0; i < nCases; i++)
            {
                sLine = Console.ReadLine();
                string[] strings = sLine.Split(' ');
                int nNumber = int.Parse(strings[1]);

                Case c = new Case(strings[0], nNumber);
                listCases.Add(c);

            }

            CultureInfo oColture = CultureInfo.CreateSpecificCulture("en-US");
            using (System.IO.StreamWriter file = new System.IO.StreamWriter(@"C:\Michal\result.txt"))
            {
                for (int i = 0; i < nCases; i++)
                {
                    Case c = listCases[i];
                    c.solve();
                    Console.WriteLine("Case #" + (i + 1) + ": " + c.result); 
                    //Console.WriteLine("Case #" + (i + 1) + ": " + c.Result.ToString("N6", oColture)); 
                    //file.WriteLine("Case #" + (i + 1) + ": " + c.Result.ToString("N6", oColture)); 

                }
                Console.ReadLine();
            }

        }
    }
}
