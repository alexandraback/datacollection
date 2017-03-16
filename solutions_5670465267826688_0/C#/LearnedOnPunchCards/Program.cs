using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam2015_B
{
    class Program
    {
        public static String fileIn = @"C:\Users\johnk_000\Documents\CodeJam2015\C\smallin.txt";
        public static String fileOut = @"C:\Users\johnk_000\Documents\CodeJam2015\C\smallout.txt";

        public static int i = 2;
        public static int j = 3;
        public static int k = 4;

        public static int[,] mult = {
                            {0, 0, 0, 0, 0},
                            {0, 1, 2, 3, 4},
                            {0, 2,-1, 4,-3},
                            {0, 3,-4,-1, 2},
                            {0, 4, 3,-2,-1}};

        static void Main(string[] args)
        {
            long count;
            long maxCount;

            String inLine;
            String[] parts;





            long L;
            long X;
            String inString;
            int inValue;
            Char[] inChar;
            int currValue;
            int finalValue;

            int lookingFor;
            String answer;

            


            System.IO.StreamWriter outFile = new System.IO.StreamWriter(fileOut);
            System.IO.StreamReader file = new System.IO.StreamReader(fileIn);
            String firstline = file.ReadLine();

            long.TryParse(firstline, out maxCount);

            for (count = 0; count < maxCount; count++)
            {
                inLine = file.ReadLine();
                parts = inLine.Split(' ');

                long.TryParse(parts[0], out L);
                long.TryParse(parts[1], out X);
                Console.WriteLine("L: " + L + "  X: " + X);


                inString = file.ReadLine();

                inChar = inString.ToCharArray();

                currValue = 1;
                lookingFor = i;

                long XY = ((X - 12) % 4) + 12;
                long XX = Math.Min(X, XY);
                
                for (int b = 0; b < XX; b++)
                {
                    for (int a = 0; a < L; a++)
                    {
                        if (inChar[a] == 'i')
                            inValue = i;
                        else if (inChar[a] == 'j')
                            inValue = j;
                        else
                            inValue = k;

                        currValue = array_mult(currValue, inValue);

                        if (currValue == lookingFor)
                        {
                            if (lookingFor == i)
                            {
                                Console.WriteLine("  Found i at: " + b + ", " + a);
                                lookingFor = j;
                                currValue = 1;
                            }
                            else if (lookingFor == j)
                            {
                                Console.WriteLine("  Found j at: " + b + ", " + a);
                                lookingFor = k;
                                currValue = 1;
                            }
                            //else if (lookingFor == k)
                            //{
                            //    Console.WriteLine("  Found k at: " + b + ", " + a);
                            //    lookingFor = 1;
                            //    currValue = 1;
                            //}

                        }
                    }

                }

                finalValue = currValue;
                Console.WriteLine("  Final Value: " + finalValue);
                
                if ((lookingFor == k) && (finalValue == k))
                    answer = "YES";
                else
                    answer = "NO";
                
                //long XX = X % 4;
                //for (int b = 1; b < XX; b++)
                //   finalValue = array_mult(finalValue, currValue);

                //Console.WriteLine("Instring #" + (count + 1) + ":Value = " + finalValue);

                Console.WriteLine("Case #" + (count + 1) + ": " + answer);
                outFile.WriteLine("Case #" + (count + 1) + ": " + answer);

                //System.Console.ReadLine();

            }

            outFile.Close();
            System.Console.ReadLine();


        }

        public static int array_mult(int row, int col)
        {
            int rsign = 1;
            int csign = 1;
            int irow = row;
            int icol = col;
            if (row < 0)
            {
                row = -row;
                rsign = -1;
            }


            if (col < 0)
            {
                col = -col;
                csign = -1;
            }


            return (mult[row, col] * rsign * csign);
        }
    }
}
