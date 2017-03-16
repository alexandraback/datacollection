using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace DeceitfulWar
{
    class TestCase
    {
        int number;
        double[] nitems;
        double[] kitems;

        int? deceitfulResult;
        int? normalResult;

        int length;


        public string GetResult()
        {
            if (deceitfulResult == null)
                Calc();

            return string.Format("Case #{0}: {1} {2}", number, deceitfulResult, normalResult);
        }

        public TestCase(int _number, int _length, double[] _nitems, double[] _kitems)
        {
            number = _number;
            nitems = _nitems;
            kitems = _kitems;
            length = _length;
        }

        private void Calc()
        {
            deceitfulResult = CalcDeceit();
            normalResult = CalcNormal();
        }

        private double?[] copy(double[] input)
        {
            int l = input.Length;
            var output = new double?[l];
            for (int i = 0; i < l; i++)
                output[i] = input[i];
            return output;
        }

        private int CalcDeceit()
        {
            //naomi sacrifies smallest to remove kens largest until she can win
            var dnitems = copy(nitems).OrderBy(x=>x).ToArray();
            var dkitems = copy(kitems).OrderBy(x => x).ToArray();

            for (int i = 0; i < length; i++)
            {
                if (nwin(length-i,dnitems,dkitems))
                {
                    return length - i;
                }
                else
                {
                    //remove naomi smallest, ken biggest
                    dnitems = dnitems.Skip(1).ToArray();
                    dkitems = dkitems.Take(length - 1 - i).ToArray();
                }
            }
            return 0;
        }

        private bool nwin(int l, double?[] n, double?[] k)
        {
            for (int i = 0; i < l; i++)
            {
                if (n[i].Value < k[i].Value)
                    return false;
            }
            return true;
        }

        private int CalcNormal()
        {
            int naomiScore = 0;
            var nnitems = copy(nitems);
            var nkitems = copy(kitems);

            for (int i = 0; i < length; i++)
            {
                double nPick = NaomiNormalPick(nnitems);
                double kPick = KenPick(nPick, nkitems);
                if (nPick > kPick)
                    naomiScore++;
            }
         
            //var nnitems = copy(nitems).OrderBy(x => x).ToArray();
            //var nkitems = copy(kitems).OrderBy(x => x).ToArray();

            //for (int i = 0; i < length; i++)
            //{
            //    if (nnitems[i].Value > nkitems[i].Value)
            //        naomiScore++;

            //}
            return naomiScore;
        }

        private double KenPick(double naomiPick, double?[] kens)
        {
            int chosenIdx=-1;
            int smallesstIdx=-1;
            double chosen;           
            //pick smallest larger than naomi
            for (int i = 0; i < length; i++)
            {
                if (kens[i] != null)
                {
                    if (smallesstIdx == -1 || kens[i].Value < kens[smallesstIdx].Value)
                        smallesstIdx = i;
                    if (kens[i].Value > naomiPick &&(chosenIdx == -1 || kens[i].Value < kens[chosenIdx].Value))
                        chosenIdx = i;
                }
                
            }

            if (chosenIdx == -1)
                chosenIdx = smallesstIdx;
            
            chosen = kens[chosenIdx].Value;
            kens[chosenIdx] = null;                
  
            return chosen;
        }

        private double NaomiNormalPick(double?[] naomi)
        {

          
            int chosenIdx = -1;          
           
            double chosen;
            //pick largest
            for (int i = 0; i < length; i++)
            {
                if (naomi[i] != null)
                {
                    
                    if (chosenIdx == -1 || naomi[i].Value > naomi[chosenIdx].Value)
                        chosenIdx = i;
                }

            }
         

            chosen = naomi[chosenIdx].Value;
            naomi[chosenIdx] = null;

            return chosen;
        }

        
    }
    class DeceitfulWar
    {
        static void Main(string[] args)
        {
            try
            {
                using (StreamReader sr = new StreamReader(string.Format("c:\\codejam\\{0}", args[0])))
                {
                    System.IO.StreamWriter file = new System.IO.StreamWriter(string.Format("c:\\codejam\\out_{0}", args[0]));
                    int numberOfTest = Int32.Parse(sr.ReadLine());
                    double[] nitems;
                    double[] kitems;
                    TestCase test;
                    int length;
                    Console.WriteLine(string.Format("{0} Test cases", numberOfTest));
                    for (int i = 0; i < numberOfTest; i++)
                    {
                        length = int.Parse(sr.ReadLine());
                        nitems = sr.ReadLine().Split(' ').Select(x => double.Parse(x)).ToArray();
                        kitems = sr.ReadLine().Split(' ').Select(x => double.Parse(x)).ToArray();
     
                        test = new TestCase(i + 1, length, nitems, kitems);
                        file.WriteLine(test.GetResult());
                        Console.WriteLine(test.GetResult());
                        Console.WriteLine("N Sorted" + string.Join(",",nitems.OrderBy(x=>x)));
                        Console.WriteLine("K Sorted" + string.Join(",",kitems.OrderBy(x=>x)));
                        Console.WriteLine("--------------------------");
                        //if (i % 10 == 0)
                        //    Console.WriteLine(string.Format("wrote test {0}", i + 1));
                    }
                    file.Close();
                    Console.WriteLine(string.Format("Done {0} Tests", numberOfTest));

                }
            }
            catch (Exception e)
            {
                Console.WriteLine("Something bad:");
                Console.WriteLine(e.Message);
                return;
            }
        }

        private static int[] ReadLayout(StreamReader sr)
        {
            int row = int.Parse(sr.ReadLine());
            int[] xitems = new int[row];
            for (int j = 0; j < 4; j++)
            {
                if (j == (row - 1))
                    xitems = sr.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
                else
                    sr.ReadLine();

            }
            return xitems;
        }
    }
}
