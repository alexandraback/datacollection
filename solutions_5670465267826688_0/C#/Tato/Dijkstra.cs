using System;

namespace Dijkstra
{
    class Dijkstra
    {
        static void Main(string[] args)
        {
            var inputFile = new System.IO.StreamReader(args[0]);
            var outputFile = new System.IO.StreamWriter("C-small-attempt0.out");

            var D = new int[5, 5] { { 0, 0,  0,  0,  0 }, 
                                    { 0, 1,  2,  3,  4 }, 
                                    { 0, 2, -1,  4, -3 }, 
                                    { 0, 3, -4, -1,  2 },
                                    { 0, 4,  3, -2, -1 } }; 

            var T = Convert.ToInt32(inputFile.ReadLine());

            for (var n = 0; n < T; n++)
            {
                var line = inputFile.ReadLine();
                var data = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                var L = Convert.ToInt64(data[0]);
                var X = Convert.ToInt64(data[1]);

                var s = inputFile.ReadLine();
                var a = new int[L];
                var p = 0;
                foreach (var c in s)
                {
                    switch (c)
                    {
                        case 'i':
                            a[p] = 2;
                            break;
                        case 'j':
                            a[p] = 3;
                            break;
                        case 'k':
                            a[p] = 4;
                            break;
                    }

                    p++;
                }

                var foundI = false;
                var foundIJ = false;

                var product = 1;

                for (p = 0; p < L*X; p++)
                {
                    var index = p%L;
                    product = Math.Sign(product)*D[Math.Abs(product), a[index]];

                    foundI = foundI || (product == 2);
                    foundIJ = foundIJ || (foundI && (product == 4));
                }

                var foundIJK = foundI && foundIJ && (product == -1);

                if (foundIJK)
                {
                    outputFile.Write("Case #" + (n + 1) + ": YES" + "\n");
                }
                else
                {
                    outputFile.Write("Case #" + (n + 1) + ": NO" + "\n");
                }
            }

            inputFile.Close();

            outputFile.Flush();
            outputFile.Close();
        }
    }
}
