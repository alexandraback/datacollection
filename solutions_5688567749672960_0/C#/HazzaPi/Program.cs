using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;

namespace CodeJam15
{
    class Program
    {
        static void Main(string[] args)
        {
            File_Manager.Open(@"D:\Users\Harry\Downloads\A-small-attempt2.in"); //practice // A-small-attempt1
            //Problem call goes here
            Counter();
            File_Manager.Close();
            File_Manager.Write(@"D:\Users\Harry\Downloads\A-small-attempt2.out");
            System.Console.WriteLine("Done");
            System.Console.ReadLine(); //Pause
        }

        static void Counter()
        {
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                int N = File_Manager.ReadInts()[0];
                int x = 0;
                while (N!=0)
                {
                    int Nf = int.Parse(Reverse(N.ToString()));
                    int d = (int)Math.Log10(N) + 1;
                    string n2 = N.ToString().Substring((int)Math.Floor(((float)d)/2));
                    if (Nf < N - 1 && (int)Math.Log10(N) == (int)Math.Log10(Nf) && n2 != "" && int.Parse(n2) == 1)
                    {
                        N = Nf;
                    }
                    else
                    {
                        N--;
                    }
                    x++;
                }
                File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + x.ToString());
            }
        }

        public static string Reverse(string s)
        {
            char[] charArray = s.ToCharArray();
            Array.Reverse(charArray);
            return new string(charArray);
        }

        static int NoSteps(int N)
        {
            string Ns = N.ToString();
            int d = Ns.Length;
            //if (Ns.Substring(d-1)
            return d;
        }

        static void name2()
        {
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                int N = File_Manager.ReadInts()[0];
                int x = 0;
                for (int i = 1; i < N; i++)
                {
                }
                File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + x.ToString());
            }
        }

        struct vec
        {
            public int x;
            public int y;
            public vec(int xi, int yi)
            {
                x = xi;
                y = yi;
            }
        }

        static double Angle(vec A, vec B)
        {
            return Math.Atan2((B.y - A.y), (B.x - A.x));
        }

        static void Logging()
        {
            // Seems fine but fails test
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                File_Manager.QueueLine("Case #" + (t + 1).ToString() + ":");
                int N = File_Manager.ReadInts()[0];
                if (N == 1)
                {
                    File_Manager.QueueLine("0");
                    File_Manager.ReadInts();
                    continue;
                }
                vec[] p = new vec[N];
                List<double>[] a = new List<double>[N];
                for (int i = 0; i < N; i++)
                {
                    List<int> xy = File_Manager.ReadInts();
                    p[i] = new vec(xy[0], xy[1]);
                    a[i] = new List<double>();
                }
                for (int i = 0; i < N; i++)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (j != i)
                        {
                            double ai = Angle(p[i], p[j]);
                            a[i].Add(ai);
                        }
                    }
                }
                for (int i = 0; i < N; i++)
                {
                    a[i].Sort();
                    double l = a[i][0];
                    int li = 0;
                    int n = N;
                    a[i].Add(a[i][0] + 2 * Math.PI);
                    for (int j = 1; j < N; j++)
                    {
                        while (a[i][j] >= l + Math.PI)
                        {
                            if (j - li - 1 < n)
                            {
                                n = j - li - 1;
                            }
                            li++;
                            l = a[i][li];
                        }
                    }
                    File_Manager.QueueLine(n.ToString());
                }
            }
        }

        static void Mushroom()
        {
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                int y = 0, z = 0;
                int N = File_Manager.ReadInts()[0];
                List<int> m = File_Manager.ReadInts();
                int s = 0;
                for (int i = 1; i < N; i++)
                {
                    int d = m[i - 1] - m[i];
                    if (d > s)
                    {
                        s = d;
                    }
                    if (d > 0)
                    {
                        y += d;
                    }
                }
                for (int i = 1; i < N; i++)
                {
                    if (m[i - 1] >= s)
                    {
                        z += s;
                    }
                    else
                    {
                        z += m[i - 1];
                    }
                }
                File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + y.ToString() + " " + z.ToString());
            }
        }

        static void Ovation()
        {
            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                string s = File_Manager.ReadLine();
                string[] ss = s.Split(' ');
                int sMax = int.Parse(ss[0]);
                int[] S = Array.ConvertAll(ss[1].ToCharArray(),c => (int)Char.GetNumericValue(c));
                int n = 0;
                int m = 0;
                for (int i = 0; i <= sMax; i++)
                {
                    if (m < i)
                    {
                        n += i - m;
                        m = i;
                    }
                    m += S[i];
                }

                File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + n.ToString());
            }
        }

        static void Omino()
        {
            //X>max(R,C), X>2*min(R,C), R*C not a multiple of X, 

            int T = File_Manager.ReadInts()[0];
            for (int t = 0; t < T; t++)
            {
                List<int> XRC = File_Manager.ReadInts();
                string w = "GABRIEL";
                int X = XRC[0];
                int R = XRC[1];
                int C = XRC[2];
                if (X>Math.Max(R,C) || X>2*Math.Min(R,C) || (R*C)%X != 0 || X>6 || (X>2 && X==2*Math.Min(R,C)))
                {
                    w = "RICHARD";
                }

                File_Manager.QueueLine("Case #" + (t + 1).ToString() + ": " + w);
            }
        }
    }
}
