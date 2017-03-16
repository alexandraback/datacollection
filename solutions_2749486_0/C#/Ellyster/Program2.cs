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

        public static bool verifica(string s, int x, int y)
        {

            if (s.Length > 500)
                return false;

            int step = 1;
            int tX = 0, tY = 0;
            foreach (char c in s)
            {
                if (c == 'N')
                    tX += step;
                if (c == 'S')
                    tX -= step;
                if (c == 'E')
                    tY += step;
                if (c == 'W')
                    tY -= step;

                step++;
            }

            return ((x == tX) && (y == tY));
        }

        public static string Proute(char toX, char fromX, int origin, int end, int stepsize)
        {
            if (origin == end)
                return "";

            int step = stepsize;
            string r = "";
            int s = 0;

            while (Math.Abs(origin) + s < Math.Abs(end))
            {
                r += toX;
                s += step;
                step++;
            }

            while (Math.Abs(origin) + s > Math.Abs(end))
            {
                r += toX;
                r += fromX;
                s--;
            }

            return r;

            
        }

        public static string PongoRute(int x, int y)
        {
            //int absmin = 0;
            char dirX, dirY, dirNoX, dirNoY, min;

            if (Math.Abs(x) < Math.Abs(y))
            {
                min = 'x';
            }
            else
            {
                min = 'y';
            }

            if (x > 0)
            {
                dirX = 'N';
                dirNoX = 'S';
            }
            else
            {
                dirX = 'S';
                dirNoX = 'N';
            }

            if (y > 0)
            {
                dirY = 'E';
                dirNoY = 'W';
            }
            else
            {
                dirY = 'W';
                dirNoY = 'E';
            }
            
            int step = 1;

            string route = "";

            if (min == 'x')
            {
                route += Proute(dirX, dirNoX, 0, x, step);
                route += Proute(dirY, dirNoY, 0, y, step + route.Length);
            }
            else
            {
                route += Proute(dirY, dirNoY, 0, y, step);
                route += Proute(dirX, dirNoX, 0, x, step + route.Length);
            }

            return route;

 
        }

        static void Main(string[] args)
        {
            int nExamples;

            System.IO.StreamReader inFile = new System.IO.StreamReader("B-small-attempt2.in");
            System.IO.StreamWriter outFile = new System.IO.StreamWriter("B-small-attempt2.out");



            nExamples = int.Parse(inFile.ReadLine());


            int[,] Sizes = new int[nExamples,2];
            //List<string> ListM = new List<string>();

            for (int i = 0; i < nExamples; i++)
            {
                string[] numberL = inFile.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                //ListM.Add(numberL[0]);
                Sizes[i, 0] = int.Parse(numberL[0]);
                Sizes[i, 1] = int.Parse(numberL[1]);

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
                string s = PongoRute(Sizes[i, 1], Sizes[i, 0]);
                outFile.WriteLine("Case #" + (i + 1) + ": " + s); // + " - " + verifica(s,Sizes[i, 0], Sizes[i, 1]));

            }
            outFile.Close();
        }
    }
}
