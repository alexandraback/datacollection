using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GoogleCodeJam2012
{
    struct pos{
        public int a;
        public int b;
    }

    class Program
    {

        static void Main(string[] args)
        {
            int size = int.Parse(Console.ReadLine());

            for (int i = 0; i < size; i++)
            {
                int ret = 0;
                //SortedList<int, int> sl = new SortedList<int, int>();
                Console.Write("Case #");
                Console.Write(i+1);
                Console.Write(": ");                
                
                string inputs = Console.ReadLine();
                string[] ips = inputs.Split(' ');
                int H = int.Parse(ips[0]);
                int W = int.Parse(ips[1]);
                int D = int.Parse(ips[2]);

                List<int> H1L, H2L, W1L, W2L;
                int H1 = 0, H2 = 0, W1 = 0, W2 = 0;
                
                for (int h = 0; h < H; h++)
                {
                    string line = Console.ReadLine();
                    char[] charArray = line.ToCharArray();
                    for (int w = 0; w < W; w++)
                    {
                        if(charArray[w] == 'X')
                        {
                            H1 = h * 2 - 1;
                            H2 =  - (H - h - 1) * 2 + 1;
                            W1 = w * 2 - 1;
                            W2 = - (W - w - 1) * 2 + 1;
                        }
                    }
                }
                H1L = makelist(H1, H2, D);
                H2L = makelist(H2, H1, D);
                W1L = makelist(W1, W2, D);
                W2L = makelist(W2, W1, D);

                if (H1 * H1 <= D * D) ret++;
                if (H2 * H2 <= D * D) ret++;
                if (W1 * W1 <= D * D) ret++;
                if (W2 * W2 <= D * D) ret++;

                ret += calc(H1L, W1L, D);
                ret += calc(H1L, W2L, D);
                ret += calc(H2L, W1L, D);
                ret += calc(H2L, W2L, D);
                
                Console.WriteLine(ret);
            }
        }

        static List<int> makelist(int H1,int H2, int D )
        {
            List<int> ret = new List<int>();
            int t =0;
            while (Math.Abs(t) <= D)
            {
                t += H1;
                ret.Add(t);
                t += (-H2);
                ret.Add(t);
            }
            return ret;
        }

        static int calc(List<int> A, List<int> B ,int D)
        {
            int D2 = D * D;            
            int ret = 0;
            
            List<pos> list = new List<pos>();
            foreach (int a in A)
            {
                int a2 = a * a;
                foreach (int b in B)
                {
                    int b2 = b * b;

                    if (b2 + a2 <= D2)
                    {
                        //Console.Write(a + " " + b + " " + (a2 + b2));
                        int hcf = HCF(a, b);
                        int aa = a;
                        int bb = b;
                        if (hcf != 1)
                        {
                            aa = a / hcf;
                            bb = b / hcf;
                        }
                        pos p = new pos();
                        p.a = aa;
                        p.b = bb;
                        if (!list.Contains(p))
                        {
                            list.Add(p);
                            //Console.Write(" Add");
                            ret++;
                        }
                        //Console.WriteLine();
                    }
                    else
                    {
                        break;
                    }
                }
            }

            return ret;
        }

        static int HCF(int a, int b)
        {
            a = Math.Abs(a);
            b = Math.Abs(b);
            if (a == 0 || b == 0)
                return 0;
            int hcf = 1, counter = 1;
            while (counter <= Math.Min(a, b))
            {
                if ((a % counter == 0) && (b % counter == 0)) hcf = counter;
                counter++;
            }
            return hcf;
        }
    }
}
