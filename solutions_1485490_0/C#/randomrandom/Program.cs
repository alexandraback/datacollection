using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Toys
{
    class Product
    {
        public ulong Amount { get; set; }
        public int Type { get; set; }

        public Product(ulong amount, int type)
        {
            this.Amount = amount;
            this.Type = type;
        }
    }
    class Program
    {
        private static StreamReader reader = null;
        private static StreamWriter writer = null;

        static void Main(string[] args)
        {
            reader = new StreamReader("C-small-attempt1.in");
            writer = new StreamWriter("C-small.out");
            //reader = new StreamReader("C-large.in");
            //writer = new StreamWriter("C-large.out");
            using (reader)
            {
                using (writer)
                {
                    int tests = int.Parse(reader.ReadLine());
                    string line = null;
                    string[] parameters = null;
                    int boxes = 0;
                    int toys = 0;
                    
                    for (int test = 0; test < tests; test++)
                    {
                        line = reader.ReadLine();
                        parameters = line.Split(' ');

                        boxes = int.Parse(parameters[0]);
                        toys = int.Parse(parameters[1]);

                        Product[] allBoxez = new Product[boxes];
                        Product[] allToyz = new Product[toys];

                        line = reader.ReadLine();
                        parameters = line.Split(' ');
                        int ty = 0;
                        ulong am = 0;
                        int index = 0;
                       
                        for (int amount = 0; amount < parameters.Length; amount+=2)
                        {
                            am = ulong.Parse(parameters[amount]);
                            ty = int.Parse(parameters[amount + 1]);

                            if (index > 0 && ty == allBoxez[index-1].Type)
                            {
                                allBoxez[index - 1].Amount += am;
                            }
                            else
                            {
                                allBoxez[index] = new Product(am, ty);
                                index++;
                            }
                        }

                        Product[] allBoxes = new Product[index];
                        for (int amount = 0; amount < index; amount++)
                        {
                            allBoxes[amount] =
                                new Product(allBoxez[amount].Amount,
                                    allBoxez[amount].Type);
                        }

                        line = reader.ReadLine();
                        parameters = line.Split(' ');
                        ty = 0;
                        am = 0;
                        index = 0;

                        for (int amount = 0; amount < parameters.Length; amount += 2)
                        {
                            am = ulong.Parse(parameters[amount]);
                            ty = int.Parse(parameters[amount + 1]);

                            if (index > 0 && ty == allToyz[index - 1].Type)
                            {
                                allToyz[index - 1].Amount += am;
                            }
                            else
                            {
                                allToyz[index] = new Product(am, ty);
                                index++;
                            }
                        }

                        Product[] allToys = new Product[index];
                        for (int amount = 0; amount < index; amount++)
                        {
                            allToys[amount] =
                                new Product(allToyz[amount].Amount,
                                    allToyz[amount].Type);
                        }

                        ulong maxCountOfBoxedToys = FindCount(allBoxes.Length, allToys.Length,
                            allBoxes, allToys);
                        writer.WriteLine("Case #{0}: {1}", test + 1, maxCountOfBoxedToys);
                    }
                    
                }
            }
        }

        private static ulong FindCount(int boxCount, int toysCount, Product[] allBoxes,
            Product[] allToys)
        {
            int curToy = 0;
            int curBox = 0;
            ulong count = 0;

            while (curBox < boxCount && curToy < toysCount)
            {
                if (allBoxes[curBox].Type == allToys[curToy].Type)
                {
                    if (allBoxes[curBox].Amount > allToys[curToy].Amount)
                    {
                        count += allToys[curToy].Amount;
                        allBoxes[curBox].Amount -= allToys[curToy].Amount;
                        curToy++;
                    }
                    else
                    {
                        count += allBoxes[curBox].Amount;
                        allToys[curToy].Amount -= allBoxes[curBox].Amount;
                        curBox++;
                    }
                }
                else
                {
                    ulong maxBox = 0;
                    ulong maxToy = 0;
                    if (curToy + 1 < toysCount &&
                        allBoxes[curBox].Type == allToys[curToy + 1].Type)
                    {
                        maxBox = Math.Min(allBoxes[curBox].Amount, allToys[curToy + 1].Amount);
                    }

                    if (curBox + 1 < boxCount &&
                        allBoxes[curBox + 1].Type == allToys[curToy].Type)
                    {
                        maxToy = Math.Min(allToys[curToy].Amount, allBoxes[curBox + 1].Amount);
                    }

                    if (maxBox > maxToy)
                    {
                        curToy++;
                    }
                    else
                    {
                        curBox++;
                    }
                }
            }
            
            return count;
        }
    }
}
