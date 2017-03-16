using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _14_2B
{
    class _1C_C
    {
        static void Main(string[] args)
        {

            int T;

            string str;
            string[] strs;
            str = Console.ReadLine();
            T = int.Parse(str);

            for (int caseNumber = 1; caseNumber <= T; caseNumber++)
            {
                int N, M, K;
                str = Console.ReadLine();
                strs = str.Split(' ');
                N = int.Parse(strs[0]);
                M = int.Parse(strs[1]);
                K = int.Parse(strs[2]);


                if ((N == 1) || (N == 2) || (M == 1) || (M == 2))
                {
                    Console.WriteLine("Case #" + caseNumber + ": " + K);
                    goto next;
                }

                if (K < 5)
                {
                    Console.WriteLine("Case #" + caseNumber + ": " + K);
                    goto next;

                }

                if (K == 5)
                {
                    Console.WriteLine("Case #" + caseNumber + ": " + 4);
                    goto next;

                }

                if (K == 6)
                {
                    Console.WriteLine("Case #" + caseNumber + ": " + 5);
                    goto next;

                }

                int answer = K;
                for (int tate = 2; tate <= N; tate++)
                {

                    for (int yoko = 2; yoko <= M; yoko++)
                    {
                        int tateYoyu1 = (N - tate + 1) / 2;
                        int tateYoyu2 = (N - tate) / 2;
                        tateYoyu1 = (tateYoyu1 < (yoko - 1) / 2) ? tateYoyu1 : (yoko - 1) / 2;
                        tateYoyu2 = (tateYoyu2 < (yoko - 1) / 2) ? tateYoyu2 : (yoko - 1) / 2;

                        int yokoYoyu1 = (M - yoko + 1) / 2;
                        int yokoYoyu2 = (M - yoko) / 2;
                        yokoYoyu1 = (yokoYoyu1 < (tate - 1) / 2) ? yokoYoyu1 : (tate - 1) / 2;
                        yokoYoyu2 = (yokoYoyu2 < (tate - 1) / 2) ? yokoYoyu2 : (tate - 1) / 2;

                        int space = tate * yoko +
                            (yoko - 1 - tateYoyu1) * tateYoyu1  +
                            (yoko - 1 - tateYoyu2) * tateYoyu2  +
                            (tate - 1 - yokoYoyu1) * yokoYoyu1  +
                            (tate - 1 - yokoYoyu2) * yokoYoyu2 ;

                        if (space >= K)
                        {
                            int kazu = 2 * tate + 2 * yoko - 4;
                            if (answer > kazu)
                            {
                                answer = kazu;
                            }
                        }
                        else if (space == K - 1)
                        {
                            if ((tateYoyu1 != 0) || (yokoYoyu1 != 0))
                            {
                                int kazu = 2 * tate + 2 * yoko - 4 + 1;
                                if (answer > kazu)
                                {
                                    answer = kazu;
                                }

                            }
                        }
                        else if (space == K - 2)
                        {
                            if ((tate % 2 == 0) || (yoko % 2 == 0))
                            {
                                if ((tateYoyu1 != 0) || (yokoYoyu1 != 0))
                                {
                                    int kazu = 2 * tate + 2 * yoko - 4 + 1;
                                    if (answer > kazu)
                                    {
                                        answer = kazu;
                                    }

                                }
                            }
                        }
                    }
                }


                Console.WriteLine("Case #" + caseNumber + ": " + (answer));
            next:
                continue;

            }

            Console.Error.WriteLine("fin");

            Console.ReadLine();
        }
    }
}
