using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1BQ1
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine().Trim());

            for (int i = 0; i < t; i++)
                SolveProblem(i + 1);
        }

        private static void SolveProblem(int testNum)
        {
            int maxFakeCount = 0;

            int n = int.Parse(Console.ReadLine().Trim());

            Dictionary<string, int> firstWords = new Dictionary<string, int>();
            Dictionary<string, int> secondWords = new Dictionary<string, int>();


           
            List<Item> items = new List<Item>();

            for (int i = 0; i < n; i++)
            {
                string[] parts = Console.ReadLine().Trim().Split(' ');
                Item item = new Item(parts[0], parts[1]);

                if (firstWords.ContainsKey(item.FirstWord))
                    firstWords[item.FirstWord] += 1;
                else
                    firstWords[item.FirstWord] = 1;

                if (secondWords.ContainsKey(item.SecondWord))
                    secondWords[item.SecondWord] += 1;
                else
                    secondWords[item.SecondWord] = 1;


                foreach (Item el in items)
                {
                    if (el.FirstWord == item.FirstWord || el.SecondWord == item.SecondWord)
                    {
                        el.possibleDup = true;
                        item.possibleDup = true;
                        break;
                    }
                }
                items.Add(item);
            }

            List<Item> poss = items.Where(x => x.possibleDup).ToList();

            for (int i = 0; i < poss.Count; i++)
            {
                Item item = poss[i];

                if (poss.Count(x => x.FirstWord == item.FirstWord) < 2 ||
                    poss.Count(x => x.SecondWord == item.SecondWord) < 2)
                    item.secondPass = true; // safe
            }

            int minOriginalCount = secondWords.Keys.Count;

            if (firstWords.Keys.Count > minOriginalCount)
                minOriginalCount = firstWords.Keys.Count;



            maxFakeCount = n - minOriginalCount;

            int count = poss.Where(x => !x.secondPass).Count();

            if (count < maxFakeCount)
                maxFakeCount = count;


            Console.WriteLine("Case #{0}: {1}", testNum, maxFakeCount);




        }
    }

    class Item
    {
        public string FirstWord { get; private set; }
        public string SecondWord { get; private set; }

        public bool possibleDup { get; set; }
        public bool secondPass { get; set; }

        public Item(string firstWord, string secondWord)
        {
            this.FirstWord = firstWord;
            this.SecondWord = secondWord;
            this.possibleDup = false;
            this.secondPass = false;
        }
    }
}
