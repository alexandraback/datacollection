using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace gcj_kindomrush
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream fs = new FileStream(@"C:\Users\Patrick\Desktop\B-small-attempt1.in", System.IO.FileMode.Open);

            StreamReader sr = new StreamReader(fs);

            int cases = int.Parse(sr.ReadLine());

            FileStream fw = new FileStream(@"C:\Users\Patrick\Desktop\out.txt", FileMode.Create);
            StreamWriter sw = new StreamWriter(fw);

            for (int i = 0; i < cases; i++)
            {
                string line = sr.ReadLine();

                //string[] parts = line.Split(' ');
                int N = int.Parse(line);

                int[] ai = new int[N];
                int[] bi = new int[N];

                bool[] bicomp = new bool[N];
                bool[] aicomp = new bool[N];


                for (int j = 0; j < N; j++)
                {
                    line = sr.ReadLine();
                    string[] parts = line.Split(' ');
                    ai[j] = int.Parse(parts[0]);
                    bi[j] = int.Parse(parts[1]);
                }


                Console.WriteLine(i);

                int totalStars = 2 * N;
                int collected = 0;
                int gamesplayed = 0;

                int thresh2 = 0;
                int thresh1 = 0;

                int tick = 0;
                bool fail = false;

                bool swap = true;
                while (swap == true)
                {
                    swap = false;
                    for (int k = 0; k < N - 1; k++)
                    {
                        if (bi[k] < bi[k + 1])
                        {
                            int atemp = ai[k];
                            int btemp = bi[k];

                            ai[k] = ai[k + 1];
                            bi[k] = bi[k + 1];

                            ai[k + 1] = atemp;
                            bi[k + 1] = btemp;
                            swap = true;
                        }
                    }
                }

                Console.Write("");
                while (collected < totalStars)
                {
                    if (tick > 10)
                    {
                        fail = true;
                        break;
                    }

                    tick++;

                    bool level2completedthispass = true;

                    //search for double coins
                    while (level2completedthispass == true)
                    {
                        level2completedthispass = false;
                        for (int j = 0; j < N; j++)
                        {
                            if (!bicomp[j] && !aicomp[j])
                            {
                                int entrance = bi[j];
                                if (entrance <= collected)
                                {
                                    bicomp[j] = true;
                                    collected += aicomp[j] ? 1 : 2;
                                    aicomp[j] = true;
                                    level2completedthispass = true;
                                    tick = 0;
                                    gamesplayed++;
                                }
                            }
                        }
                    }

                    level2completedthispass = true;
                    bool secondcoinfound = false;
                    //search for second coin
                    //while (level2completedthispass == true)
                    {
                        level2completedthispass = false;
                        for (int j = 0; j < N; j++)
                        {
                            if (!bicomp[j])
                            {
                                int entrance = bi[j];
                                if (entrance <= collected)
                                {
                                    bicomp[j] = true;
                                    collected += aicomp[j] ? 1 : 2;
                                    aicomp[j] = true;
                                    level2completedthispass = true;
                                    secondcoinfound = true;
                                    tick = 0;
                                    gamesplayed++;
                                }
                            }
                        }
                    }

                    if (!secondcoinfound)
                    {
                        int[] ai2 = (int[])ai.Clone();
                        Array x = ai2.ToArray();
                        var asx = ai2.OrderByDescending(q => q);



                        bool level1completedthispass = true;
                        //while (level1completedthispass ==false)
                        {
                            level1completedthispass = false;

                            for (int j = 0; j < N; j++)
                            {
                                if (!aicomp[j])
                                {
                                    int entrance = ai[j];
                                    if (entrance <= collected)
                                    {
                                        aicomp[j] = true;
                                        collected += 1;
                                        level1completedthispass = true;
                                        tick = 0;
                                        gamesplayed++;
                                        break;
                                    }
                                }
                            }
                        }

                    }

                }


                var output = 0;




                if (!fail)
                {
                    sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, gamesplayed));

                }
                else
                    sw.WriteLine(string.Format("Case #{0}: {1}", i + 1, "Too Bad"));

            }


            sw.Flush();
            sw.Close();
            fw.Close();
            fs.Close();





        }
    }
}
