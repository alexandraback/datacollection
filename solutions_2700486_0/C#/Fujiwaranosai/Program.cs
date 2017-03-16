using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Round1B_B
{
    class Program
    {
        static int cx = 10000;
        static int cy = 0;
        static void Main(string[] args)
        {
            StreamReader infile = new StreamReader("input.txt");
            StreamWriter outfile = new StreamWriter("output.txt");
            string line = infile.ReadLine();
            int T = int.Parse(line); // case num
            for (int i = 0; i < T; i++)
            {
                line = infile.ReadLine();
                ulong n;
                int x, y;
                string[] arr = line.Split(' ');
                n = ulong.Parse(arr[0]);
                x = int.Parse(arr[1]);
                y = int.Parse(arr[2]);
                bool[,] map = new bool[10001, 20001];
                int[] hmap = new int[20001];
                hmap[cx] = 1;
                double p = solve(n - 1, x, y, 1, hmap, map);
                outfile.WriteLine(String.Format("Case #{0}: {1}", i + 1, p));
            }
            infile.Close();
            outfile.Close();
        }
        static double solve(ulong n, int x, int y, double p, int[] hmap, bool[,] map)
        {
            if (x == 0 && y == 0)
                return p;
            if (hmap[cx + x] == y + 1)
            {
                return p;
            }
            if (n == 0)
                return 0;
            double pl = 0, pr = 0;
            int l = findLeft(hmap);
            if (l != -1)
            {
                int oleft = hmap[l];
                if (l - 1 >= 0 && hmap[l] == 0 && hmap[l - 1] == 0)
                    hmap[l] = 1;
                else
                    hmap[l] += 2;
                pl = solve(n - 1, x, y, p / 2, hmap, map);
                hmap[l] = oleft;
            }
            int r = findRight(hmap);
            if (r != -1)
            {
                int oright = hmap[r];
                if (r + 1 <= 20000 && hmap[r] == 0 && hmap[r + 1] == 0)
                    hmap[r] = 1;
                else
                    hmap[r] += 2;
                pr = solve(n - 1, x, y, p / 2, hmap, map);
                hmap[r] = oright;
            }
            return pl + pr;
        }
        static int findLeft(int[] hmap)
        {
            int i = cx - 1;
            while(i >= 0 && hmap[i] >= 0 && 
                hmap[i] < hmap[i+1] && hmap[i-1] < hmap[i])
            {
                i--;
            }
            if ((i - 1 >= 0) && hmap[i - 1] > hmap[i])
            {
                return i;
            }
            else if (i - 1 >= 0 && hmap[i - 1] == hmap[i])
            {
                return i - 1;
            }
            return -1;
        }
        static int findRight(int[] hmap)
        {
            int i = cx + 1;
            while (i <= 20000 && hmap[i] >= 0 &&
                hmap[i] < hmap[i - 1] && hmap[i + 1] < hmap[i])
            {
                i++;
            }
            if ((i + 1 <= 20000) && hmap[i + 1] > hmap[i])
            {
                return i;
            }
            else if (i + 1 <= 20000 && hmap[i + 1] == hmap[i])
            {
                return i + 1;
            }
            return -1;
        }
    }
}
