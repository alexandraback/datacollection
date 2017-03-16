using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Infinite_House_of_Pancakes
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"./in.txt";
            Boolean first = false;
            int textCase = 1;
            using (StreamWriter sw = new StreamWriter("out2.out"))
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    while (sr.Peek() > 0)
                    {
                        if (!first)
                        {
                            string data = sr.ReadLine();
                            first = true;
                            continue;
                        }
                        else
                        {
                            int numberDinnerNoEmptyPlate = int.Parse(sr.ReadLine());
                            List<int> dinnerNumberPancake = sr.ReadLine().Split(' ').Select(s => int.Parse(s)).ToList();
                            Console.WriteLine("Case #" + (textCase + 1));
                            int max = dinnerNumberPancake.Max();
                            int result = getOtherSolution(dinnerNumberPancake, max, 1);
                            sw.WriteLine("Case #" + textCase++ + ": " + result);
                            Console.WriteLine("Case #" + (textCase - 1) + ": " + result);
                        }
                    }
                }
                sw.Close();
            }
            Console.WriteLine("END");
            Console.Read();
        }

        static public int getOtherSolution(List<int> dinnerNumberPancake, int max, int current)
        {
            if (current == max)
            {
                return current;
            }
            List<int> numberPancackeList = dinnerNumberPancake.OrderByDescending(s => s).ToList();
            if (numberPancackeList[0] == 1)
            {
                return current;
            }

            List<int> numberPancackeListEaten = numberPancackeList.ToList();
            for (int i = 0; i < numberPancackeListEaten.Count; i++)
            {
                numberPancackeListEaten[i] = numberPancackeListEaten[i] - 1;
            }
            numberPancackeListEaten.RemoveAll(s => s == 0);
            numberPancackeListEaten = numberPancackeListEaten.OrderByDescending(s => s).ToList();

            List<int> numberPancackeListNotEaten = numberPancackeList.ToList();
            numberPancackeListNotEaten.Add(numberPancackeListNotEaten[0] - numberPancackeListNotEaten[0] / 2);
            numberPancackeListNotEaten[0] = numberPancackeListNotEaten[0] / 2;
            return Math.Min(getOtherSolution(numberPancackeListNotEaten,max,current + 1 ), getOtherSolution(numberPancackeListEaten,max,current + 1));
        }
    }
}
