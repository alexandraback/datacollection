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


            string wholeLine = Console.ReadLine().Trim();
            string[] parts = wholeLine.Split('?');

            long minDiff = long.MaxValue;

            List<Item> itemList = new List<Item>();

            int questionMarkCount = wholeLine.Count(x => x == '?');

            long maxIt = (long)(Math.Pow(10, questionMarkCount));

            for (long i = 0; i < maxIt; i++)
            {
                string[] arr = new string[questionMarkCount];

                long val = i;

                for (int j = 0; j < questionMarkCount; j++)
                {
                    long divider = (long)(Math.Pow(10, (questionMarkCount - j - 1)));

                    arr[j] = (val / divider).ToString();

                    val -= (val / divider) * divider;
                }

                StringBuilder sb = new StringBuilder();
                for (int k = 0; k < questionMarkCount; k++)
                {
                    sb.Append(parts[k]).Append(arr[k]);
                }
                sb.Append(parts[questionMarkCount]);

                string[] cjStr = sb.ToString().Split(' ');
                /*
                long coders = long.Parse(cjStr[0]);
                long jammers = long.Parse(cjStr[1]);
                */

                Item item = new Item(cjStr[0], cjStr[1]);

                if (item.Diff < minDiff)
                    minDiff = item.Diff;

                itemList.Add(item);
            }

            List<Item> selectedList = itemList.Where(x => x.Diff == minDiff).ToList();

            if (selectedList.Count == 1)
            {
                Item item = selectedList[0];
                Console.WriteLine("Case #{0}: {1} {2}", testNum, item.CodersScoreString, item.JammersScoreString);
                return;
            }

            long minCodersScore = long.MaxValue;

            foreach (Item item in selectedList)
            {
                if (item.CodersScore < minCodersScore)
                    minCodersScore = item.CodersScore;
            }

            selectedList = selectedList.Where(x => x.CodersScore == minCodersScore).ToList();

            if (selectedList.Count == 1)
            {
                Item item = selectedList[0];
                Console.WriteLine("Case #{0}: {1} {2}", testNum, item.CodersScoreString, item.JammersScoreString);
                return;
            }

            Item resultingItem = null;
            long minJammersScore = long.MaxValue;

            foreach (Item item in selectedList)
            {
                if (item.JammersScore < minJammersScore)
                {
                    minJammersScore = item.JammersScore;
                    resultingItem = item;
                }
            }


            Console.WriteLine("Case #{0}: {1} {2}", testNum, resultingItem.CodersScoreString, resultingItem.JammersScoreString);

        }
    }

    class Item
    {
        public long CodersScore { get; private set; }
        public long JammersScore { get; private set; }
        public string CodersScoreString { get; private set; }
        public string JammersScoreString { get; private set; }

        public long Diff { get; private set; }

        public Item(string codersScore, string jammersScore)
        {
            this.CodersScoreString = codersScore;
            this.JammersScoreString = jammersScore;
            this.CodersScore = long.Parse(codersScore);
            this.JammersScore = long.Parse(jammersScore);


            if (CodersScore > JammersScore)
                this.Diff = CodersScore - JammersScore;
            else
                this.Diff = JammersScore - CodersScore;
        }
    }
}
