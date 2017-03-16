using System;
using System.Collections.Generic;
using System.Text;

namespace KingdomRush
{
    class Program
    {
        static void Main(string[] args)
        {
             long T = long.Parse(Console.ReadLine());

             for (long t = 1; t <= T; t++)
             {
                 long N = long.Parse(Console.ReadLine());
                 long[,] required = new long[N,2];
                 bool[,] played = new bool[N, 2];
                 for(int n = 0; n < N; n++)
                 {
                     string[] line = Console.ReadLine().Split();
                     required[n, 0] = long.Parse(line[0]);
                     required[n, 1] = long.Parse(line[1]);
                     played[n , 0] =  played[ n , 1] = false;
                 }

                 long rating = 0;
                 bool impos = false;
                 bool played_all = false;
                 int num = 0;
                 while (!impos && !played_all)
                 {
                     
                     
                     int payoff = 0;
                     int n;
                     for (n = 0; n < N; n++)
                     {
                         
                         if (!played[n, 1] && required[n, 1] <= rating)
                         {
                             if (played[n, 0])
                                 payoff = 1;
                             else
                                 payoff = 2;

                             break;
                         }

                    //     Console.WriteLine("best : " + best);
                     }

                     if (n < N)
                     {
                         // found 2-star game to play
                      //   Console.WriteLine("playing " + best + " , 1");
                         played[n, 1] = true;
                         rating += payoff;
                         num++;
                     }
                     else
                     {
                         n = 0;
                         while (n < N)
                         {
                             if (!played[n, 0] &&  !played[n , 1] && required[n, 0] <= rating)
                                 break;
                             n++;
                         }

                         if (n == N)
                         {
                         //    Console.WriteLine("impos");
                             impos = true;
                         }
                         else
                         {
                          //   Console.WriteLine("playing " + n + " , 0");
                             played[n, 0] = true;
                             rating += 1;
                             num++;
                         }

                     }

                     played_all = true;
                     for (n = 0; n < N; n++)
                         played_all = played_all && played[n, 1];                     
                     
                 }

                 if (impos)
                     Console.WriteLine("Case #" + t + ": Too Bad");
                 else
                     Console.WriteLine("Case #" + t + ": " + num);

             }
        }
    }
}
