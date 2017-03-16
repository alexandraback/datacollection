using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Qualif3
{
    class Program
    {
        static void Main(string[] args)
        {
            var file = new StreamReader(@"C:\Users\Administrator\Documents\CodeJam\third5.txt");
            var outFile = new StreamWriter(@"C:\Users\Administrator\Documents\CodeJam\thirdOut5.txt");
            var total = long.Parse(file.ReadLine());
            for (int t = 1; t <= total; t++)
            {
                var values = file.ReadLine().Split(' ');
                int r = int.Parse(values[0]);
                int c = int.Parse(values[1]);
                int m = int.Parse(values[2]);

                var field = new char[r, c];

                for (int i = 0; i < r; i++)
                    for (int j = 0; j < c; j++)
                        field[i, j] = '.';

                field[0, 0] = 'c';

                int currentR = r - 1;
                int currentC = c - 1;
                int nextCellR = currentR;
                int nextCellC = currentC;
                int currentM = m;
                bool possible = true;
                while (currentM > 0)
                {
                    field[nextCellR, nextCellC] = '*';

                    if (currentC > currentR)
                    {
                        nextCellR--;
                        if (nextCellR == 0 && currentM == 1)
                        {
                            field[nextCellR+1, nextCellC] = '.';
                            currentC--;
                            if (currentC <= 1 || currentR <= 1)
                                possible = false;
                            nextCellR = currentR;
                            nextCellC = currentC;
                            field[nextCellR, nextCellC] = '*';
                        }
                        else if (nextCellR < 0)
                        {
                            nextCellR = currentR;
                            currentC--;
                            if (currentC == 0 && currentR+1!=currentM)
                                possible = false;
                            nextCellC = currentC;
                        }
                    }
                    else
                    {
                        nextCellC--;
                        if (nextCellC == 0 && currentM == 1)
                        {
                            field[nextCellR, nextCellC+1] = '.';
                            currentR--;
                            if (currentR <= 1 || currentC<=1)
                                possible = false;
                            nextCellR = currentR;
                            nextCellC = currentC;
                            field[nextCellR, nextCellC] = '*';
                        }
                        else if (nextCellC < 0)
                        {
                            currentR--;
                            nextCellC = currentC;
                            nextCellR = currentR;
                            if (currentR == 0 && currentC+1 != currentM)
                                possible = false;
                        }
                    }
                    currentM--;
                }

                
                outFile.WriteLine(string.Format("Case #{0}:", t));
                if(possible)
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        outFile.Write(field[i, j]);
                    }
                    outFile.WriteLine();
                }
                else
                    outFile.WriteLine("Impossible");

                int mineCount = 0;
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        if(field[i, j]=='*')
                            mineCount++;
                    }
                }
                if (mineCount != m)
                    throw new Exception("Wring mine count for case " + t);
            }


            file.Close();
            outFile.Close();
        }
    }
}
