using System;
using System.IO;

namespace diamond_inheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter myW = new StreamWriter("C:\\Users\\susanne\\Documents\\cojate_oben\\output.txt");
            StreamReader myR = new StreamReader("C:\\Users\\susanne\\Documents\\cojate_oben\\input.txt");
            int T = Int32.Parse(myR.ReadLine());
            for (int t = 1; t <= T; t++)
            {
                Console.WriteLine(t);
                myW.Write("Case #" + t + ": ");
                int N = Int32.Parse(myR.ReadLine());
                int[,] inherits = new int[N + 1, N + 1];
                int[] M = new int[N + 1];
                for (int n = 1; n <= N; n++)
                {
                    String[] line = myR.ReadLine().Split(' ');
                    M[n] = Int32.Parse(line[0]);
                    for (int m = 1; m <= M[n]; m++)
                        inherits[n, m] = Int32.Parse(line[m]);
                }
                bool f = false;
                for (int n = 1; n <= N && f == false; n++)
                {
                    bool[] heritage = new bool[1001];
                    int[] path = new int[3000000];
                    int i_path = 0;
                    for (int m1 = 1; m1 <= M[n]; m1++)
                    {
                        int v = inherits[n, m1];
                        heritage[v] = true;
                        path[++i_path] = v;
                    }
                    while (i_path != 0 && f == false)
                    {
                        int v = path[i_path--];
                        for (int m = 1; m <= M[v]; m++)
                        {
                            int v1 = inherits[v, m];
                            if (heritage[v1] == true)
                            {
                                f = true;
                                myW.WriteLine("Yes");
                                break;
                            }
                            else
                            {
                                heritage[v1] = true;
                                path[++i_path] = v1;
                            }
                        }
                    }
                }
                if (f == false)
                    myW.WriteLine("No");
            }
            myW.Close();
            myR.Close();
        }
    }
}
