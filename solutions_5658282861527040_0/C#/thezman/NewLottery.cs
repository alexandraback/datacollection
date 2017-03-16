using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CodeJam
{
    class NewLottery
    {
        public void Go()
        {
            var file = File.ReadAllLines("input.txt");
            var outFile = File.CreateText("output.txt");
            int numCases = int.Parse(file[0]);
            for (int i = 1; i <= numCases; i++)
            {
                var inputs = file[i].Split(' ');
                int a = int.Parse(inputs[0]);
                int b = int.Parse(inputs[1]);
                int k = int.Parse(inputs[2]);

                //int n1 = k < a ? k : a;
                //int n2 = k < b ? k : b;

                //int numWins = n1 * n2;
                //numWins += k < a ? (a - k) * n2: 0;
                //numWins += k < b ? (b - k) * n1: 0;

                //numWins = a * k;
                //numWins += (b-k) * k;
                int numWins = 0;
                for (int h = 0; h < a; h++)
                {
                    for (int j = 0; j < b; j++)
                    {
                        if ((h & j) < k) numWins++;
                    }
                }


                    outFile.WriteLine("Case #" + i + ": " + numWins);

            }
            outFile.Close();
        }

        static void Main(string[] args)
        {
            new NewLottery().Go();

        }

    }
}
