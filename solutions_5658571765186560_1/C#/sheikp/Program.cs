using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam3
{
    class Program
    {
        static void Main(string[] args)
        {

            string[] lines = System.IO.File.ReadAllLines(@"D:\Input\D-large.in");
            string[] outputlines = new string[lines.Length];
            System.Console.WriteLine("Out put");
            int i = 0;
            string result = "";
            int X = 0;
            int R = 0;
            int C = 0;
            foreach (string line in lines)
            {
                result = "";               
                int minRC = 0;
                int maxRC = 0;
                
                if (i > 0)
                {
                    string[] inputstr = line.Split(" ".ToCharArray());
                    X = Convert.ToInt16(inputstr[0]);
                    R = Convert.ToInt16(inputstr[1]);
                    C = Convert.ToInt16(inputstr[2]);
                    if (R > C)
                    {
                        minRC = C;
                        maxRC = R;
                    }
                    else
                    {
                        minRC = R;
                        maxRC = C;
                    }
                    bool ans = true;
                    if (X >= 7)
                        ans = false;
                    else if (X > R && X > C)
                        ans = false;
                    else if ((R * C) % X != 0)
                        ans = false;
                    else if ((X + 1) / 2 > minRC)
                        ans = false;
                    else if (X == 1 || X == 2 || X == 3)
                        ans = true;
                    else if (X == 4)
                        ans = minRC > 2;
                    else if (X == 5)
                        ans = !(minRC == 3 && maxRC == 5);
                    else if (X == 6)
                        ans = minRC > 3;

                    //int GridCells = (R * C);
                    if (ans)
                        result = "GABRIEL";
                    else
                        result = "RICHARD";

                    Console.WriteLine("Case #" + i.ToString() + ": " + result.ToString());
                    outputlines[i - 1] = "Case #" + i.ToString() + ": " + result.ToString();
                }
                i += 1;
            }

            // Keep the console window open in debug mode.
            System.IO.File.WriteAllLines(@"D:\Input\D-large.out", outputlines);
            Console.WriteLine("Press any key to exit.");
            System.Console.ReadKey();
        }
    }
}
