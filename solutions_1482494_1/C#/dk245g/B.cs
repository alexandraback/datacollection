using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace B
{
    class Program
    {
        static void Main(string[] args)
        {
            int CN = int.Parse(Console.ReadLine());
            for (int cn = 1; cn <= CN; cn++)
            {
                int N = int.Parse(Console.ReadLine());
                int[,] star_req = new int[1000, 2];
                int[] star_got = new int[1000];
                for (int n = 0; n < N; n++)
                {
                    string[] line = Console.ReadLine().Split(' ');
                    star_req[n, 0] = int.Parse(line[0]);
                    star_req[n, 1] = int.Parse(line[1]);
                    star_got[n] = 0;
                }
                bool done;
                bool found;
                int stars = 0, completes = 0;
                do
                {
                    done = true;
                    found = false;
                    for (int n = 0; n < N; n++)
                    {
                        if (star_got[n] < 2)
                        {
                            done = false;
                            if (star_req[n, 1] <= stars)
                            {
                                stars += 2 - star_got[n];
                                star_got[n] = 2;
                                completes++;
                                found = true;
                                break;
                            }
                        }
                    }
                    if (!found && !done)
                    {
                        int mid = -1, mstar = 0;
                        for (int n = 0; n < N; n++)
                        {
                            if (star_got[n] < 1 && star_req[n, 0] <= stars)
                            {
                                if ((star_req[n, 1] - star_got[n]) > mstar)
                                {
                                    mid = n;
                                    mstar = star_req[n, 1] - star_got[n];
                                }
                            }
                        }
                        if (mid >= 0)
                        {
                            star_got[mid] = 1;
                            stars += 1;
                            completes++;
                            found = true;
                        }
                    }
                    if (!found) break;
                }
                while (!done);

                if (done)
                    Console.WriteLine("Case #" + cn + ": " + completes);
                else
                    Console.WriteLine("Case #" + cn + ": Too Bad");
            }
        }
    }
}
