using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace Round_1C
{
    class Program
    {
        public static bool isConsonat(char l)
        {
            if (l == 'a')
                return false;

            if (l == 'e')
                return false;

            if (l == 'i')
                return false;

            if (l == 'o')
                return false;

            if (l == 'u')
                return false;

            return true;
        }

        public static int possibleSub(int leftlimit, int left, int right, int rightlimit)
        {
            return ((rightlimit-right)+1)*((left-leftlimit)+1);
        }

        public static int nValues(string name, int n)
        {
            List<int[]> nSub = new List<int[]>();

            for (int i = 0; i <= name.Length - n; i++)
            {
                bool conso = true;
                for (int j = 0; j < n; j++)
                {
                    if (!isConsonat(name[i + j]))
                        conso = false;
                }

                if (conso)
                {
                    int[] indexes = new int[2];
                    indexes[0] = i;
                    indexes[1] = i + n;

                    nSub.Add(indexes);
                }
            }

            if (nSub.Count == 0)
                return 0;

            if (nSub.Count == 1)
                return possibleSub(0, nSub[0][0], nSub[0][1], name.Length);

            int nVal = possibleSub(0, nSub[0][0], nSub[0][1], name.Length);

            for (int i = 1; i < nSub.Count; i++)
            {
                nVal += possibleSub(nSub[i - 1][0] + 1, nSub[i][0], nSub[i][1], name.Length);
            }

            return nVal;
        }

        static void Main(string[] args)
        {
            int nExamples;

            System.IO.StreamReader inFile = new System.IO.StreamReader("A-small-attempt0.in");
            System.IO.StreamWriter outFile = new System.IO.StreamWriter("A-small-attempt0.out");



            nExamples = int.Parse(inFile.ReadLine());


            int[] Sizes = new int[nExamples];
            List<string> ListM = new List<string>();

            for (int i = 0; i < nExamples; i++)
            {
                string[] numberL = inFile.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                ListM.Add(numberL[0]);
                Sizes[i] = int.Parse(numberL[1]);

                //string[] numberL2 = inFile.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                //ListM[i] = new List<int>();
 
                //for (int j = 0; j < Sizes[i,1]; j++)
                //{
                //    ListM[i].Add(int.Parse(numberL2[j]));
                //}

            }


            for(int i = 0; i < nExamples; i++)
            {
                //ListM[i].Sort();
                outFile.WriteLine("Case #" + (i + 1) + ": " + nValues(ListM[i],Sizes[i]));

            }
            outFile.Close();
        }
    }
}
