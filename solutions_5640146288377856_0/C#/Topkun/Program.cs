using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Example_of_math_variables_and_if_statements
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {

            System.IO.StreamReader inputFile = new System.IO.StreamReader(@"C:\Users\Kosin\Downloads\A-small-attempt0.in");


            int cases = int.Parse(inputFile.ReadLine());

            using(StreamWriter outputFile = new StreamWriter(@"C:\Users\Kosin\Downloads\test3.txt"))
            {
                for (int i = 1; i <= cases; i++)
                {
                    

                    string[] data = inputFile.ReadLine().Split();
                    int row = int.Parse(data[0]);
                    int col = int.Parse(data[1]);
                    int shipLength = int.Parse(data[2]);
                    int minCountEachRow = col / shipLength;
                    
                    int minTotalCount = 0;
                    if (row > 1)
                        minTotalCount += (row - 1) * minCountEachRow;
                    minTotalCount = minTotalCount + Math.Min(minCountEachRow + (shipLength),col);

                    if ((float)col % (float)shipLength == 0 && col!=shipLength && shipLength!=1)
                        minTotalCount -= 1;

                    /* outputFile.WriteLine(itemList.Count() + "\n");*/

                    outputFile.WriteLine("Case #" + i + ": " + minTotalCount);
                }
            }

        }
    }
}
