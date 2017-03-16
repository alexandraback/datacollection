using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class Case
    {
        private int mysize;
        private readonly int _othersCount;
        private readonly int[] _others;

        public Case(int mysize, int othersCount, int[] others)
        {
            this.mysize = mysize;
            _othersCount = othersCount;

            Array.Sort(others);
            _others = others;
        }

        public int resultInt;

        public void Solve()
        {
            if (mysize == 1)
            {
                resultInt = _othersCount;
                return;
            }

            int operationsRequired = 0;
            int overallCostIfWeRemoveAll = int.MaxValue;

            for (int i = 0; i < _othersCount; i++)
            {
                if (mysize > _others[i])
                {
                    mysize += _others[i]; // growing, hell yeag carry on
                }
                else
                {
                    if (overallCostIfWeRemoveAll <= operationsRequired)
                    {
                        resultInt = overallCostIfWeRemoveAll;
                        return;
                    }

                    int overallCostIfWeRemoveAllTemp = operationsRequired + _othersCount - i;
                    if (overallCostIfWeRemoveAllTemp < overallCostIfWeRemoveAll)
                    {
                        overallCostIfWeRemoveAll = overallCostIfWeRemoveAllTemp;
                    }
                    //will see which cost is lower

                    while (mysize > _others[i] == false)
                    {
                        mysize += (mysize - 1);
                        operationsRequired++;
                    }
                    // we are big enough growing
                    mysize += _others[i];
                }
            }

            resultInt = operationsRequired > overallCostIfWeRemoveAll ? overallCostIfWeRemoveAll : operationsRequired;
        }

        public string result()
        {
            return resultInt + "";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Case> Cases = new List<Case>();

            //Case my = new Case(10, 5, new int[] {9, 18, 60, 1000, 10000});
            //my.Solve();

            //;

            string line = Console.ReadLine();
            int cases = int.Parse(line);

            for (int i = 0; i < cases; i++)
            {
                line = Console.ReadLine();
                string[] strings = line.Split(' ');
                int mysize = int.Parse(strings[0]);
                int othersSize = int.Parse(strings[1]);
                
                line = Console.ReadLine();
                string[] cs = line.Split(' ');
                int[] c = new int[othersSize];
                for (int j = 0; j < othersSize; j++)
                {
                    c[j] = int.Parse(cs[j]);
                }

                Cases.Add(new Case(mysize, othersSize, c));
            }
            using (System.IO.StreamWriter file = new System.IO.StreamWriter("output.txt"))
            {
                int counter = 1;
                foreach (Case c in Cases)
                {
                    c.Solve();
                    Console.WriteLine("Case #" + counter++ + ": " + c.result());
                    //file.WriteLine("Case #" + counter++ + ": " + c.result());
                }
            }

            // XXX: wait // not hie
            //Console.ReadLine();
        }
    }
}
