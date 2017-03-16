using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication5
{
    class Program
    {
        static void Main(string[] args)
        {
            string fileName = "D-small-attempt0";

            StreamReader reader = new StreamReader(@"c:\users\alon\gcj\" + fileName + ".in");
            StreamWriter writer = new StreamWriter(@"c:\users\alon\gcj\" + fileName + ".out");


            int T = int.Parse(reader.ReadLine());

            for (int i = 1; i <= T; i++)
            {

                int N = int.Parse(reader.ReadLine());

                double[] naomiBlocks = getBlocks(reader);
                double[] kenBlocks = getBlocks(reader);

                MergeSort(naomiBlocks, 0, N - 1);
                MergeSort(kenBlocks, 0, N - 1);

                writer.WriteLine("Case #{0}: {1} {2}", i, pointsOfNaomiDeceitfulWar(naomiBlocks, kenBlocks), pointsOfNaomiWar(naomiBlocks, kenBlocks));




            }

            writer.Close();
        }

        static double[] getBlocks(StreamReader reader)
        {
            string[] strs = reader.ReadLine().Split(' ');
            
            double[] ret = new double[strs.Length];

            for (int i = 0; i < ret.Length; i++)
                ret[i] = double.Parse(strs[i]);

            return ret;
        }

        static int pointsOfNaomiWar(double[] naomi, double[] ken) {

            int naomiPoints = 0;

            for(int i=0;i<naomi.Length;i++) {

                int minKenIndex = 0;

                while (minKenIndex<ken.Length && (ken[minKenIndex] == -1 || ken[minKenIndex] < naomi[i]) )
                    minKenIndex++;


                if (minKenIndex == ken.Length)
                {
                    for (int j = 0; j < ken.Length && minKenIndex == ken.Length; j++)
                        if (ken[j] != -1)
                            minKenIndex = j;

                    naomiPoints++;
                }

                ken[minKenIndex] = -1;
            }

            return naomiPoints;
        }

        static int pointsOfNaomiDeceitfulWar(double[] naomi, double[] ken)
        {
            int N = ken.Length;

            bool cheat = true;

            int naomiPoints = 0;

            int naomiStart = 0;
            int naomiEnd = N - 1;

            int kenStart = 0;
            int kenEnd = N - 1;

            while (naomiStart <= naomiEnd)
            {

                if (naomi[naomiStart] < ken[kenStart])
                {
                    kenEnd--;
                    naomiStart++;
                }
                else
                {
                    kenStart++;
                    naomiStart++;
                    naomiPoints++;
                }

            }

            return naomiPoints;
        }

        public static void MergeSort(double[] input, int left, int right)
        {
            if (left < right)
            {
                int middle = (left + right) / 2;

                MergeSort(input, left, middle);
                MergeSort(input, middle + 1, right);

                //Merge
                double[] leftArray = new double[middle - left + 1];
                double[] rightArray = new double[right - middle];

                Array.Copy(input, left, leftArray, 0, middle - left + 1);
                Array.Copy(input, middle + 1, rightArray, 0, right - middle);

                int i = 0;
                int j = 0;
                for (int k = left; k < right + 1; k++)
                {
                    if (i == leftArray.Length)
                    {
                        input[k] = rightArray[j];
                        j++;
                    }
                    else if (j == rightArray.Length)
                    {
                        input[k] = leftArray[i];
                        i++;
                    }
                    else if (leftArray[i] <= rightArray[j])
                    {
                        input[k] = leftArray[i];
                        i++;
                    }
                    else
                    {
                        input[k] = rightArray[j];
                        j++;
                    }
                }
            }
        }
    }
}
