using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace codejam2k14
{
    class Program
    {
        static void Main(string[] args)
        {
            FileStream filestream = new FileStream(@"C:\Users\Guillaume\Documents\codeJam2k14\part3\ex1\out.txt", FileMode.Truncate);
            var streamwriter = new StreamWriter(filestream);
            streamwriter.AutoFlush = true;
            Console.SetOut(streamwriter);
            Console.SetError(streamwriter);
            System.IO.StreamReader file = new System.IO.StreamReader(@"C:\Users\Guillaume\Documents\codeJam2k14\part3\ex1\file.txt");
            int nbTestCases = Int32.Parse(file.ReadLine());
            for (int T = 1; T <= nbTestCases; T++)
            {
                Console.Write("Case #"+T+": ");
                int nbStrings = Int32.Parse(file.ReadLine());
                bool ok = false;
                int[] ind = new int[nbStrings];
                int[] counts = new int[nbStrings];
                List<pair>[] strings = new List<pair>[nbStrings];
                bool no = false;
                for(int i = 0 ; i < nbStrings ; i++)
                {
                    string s = file.ReadLine();
                    List<pair> content = new List<pair>();
                    pair last = new pair();
                    last.c = s[0];
                    last.nb = 1;
                    for (int j = 1; j < s.Length; j++ )
                    {
                        if(s[j] != last.c)
                        {
                            content.Add(last);
                            last = new pair();
                            last.nb = 1;
                            last.c = s[j];
                        }
                        else
                        {
                            last.nb++;
                        }
                    }
                    content.Add(last);
                    strings[i] = content;
                    if(content.Count != strings[0].Count)
                    {
                        falseE();
                        no = true;
                    }
                }
                if(no)
                {
                    continue;
                }

                int cost = 0;
                for (var i = 0; i < strings[0].Count; i++)
                {
                    bool inNo = false;
                    for (int j = 0; j < nbStrings; j++)
                    {
                        counts[j] = strings[j][i].nb;
                        if(strings[j][i].c != strings[0][i].c)
                        {
                            inNo = true;
                            break;
                        }
                    }
                    if(inNo)
                    {
                        no = true;
                        falseE();
                        break;
                    }
                    Array.Sort(counts);
                    int med = counts[(counts.Length - 1) / 2];
                    foreach(var ii in counts)
                    {
                        cost += (Math.Abs(ii - med));
                    }
                }
                if(no)
                {
                    continue;
                }
                Console.WriteLine(cost);
                //Console.WriteLine(cost);
            }
        }     
        static void falseE()
        {
            Console.WriteLine("Fegla Won");
        }

        public struct pair
        {
            public char c;
            public int nb;

        }

        static int nbSteps(string a , string b)
        {
            var len = a.Length;
            if(b.Length > len) len = b.Length;
            if (a[0] != b[0])
            {
                //Console.WriteLine(a + " <=> " + b + " :  IMPOSSIBLE");
                return -1;
            }
            int res = 0;
            int ia = 1;
            int ib = 1;
            while(ia < a.Length && ib < b.Length)
            {
                if(a[ia] == b[ib])
                {
                    ia++; ib++;
                }
                else
                {
                    if(a[ia-1] == a[ia])
                    {
                        ia += 1;
                        res++;
                    }
                    else if (b[ib - 1] == b[ib])
                    {
                        ib += 1;
                        res++;
                    }
                    else
                    {
                        //Console.WriteLine(a + " <=> " + b + " :  IMPOSSIBLE");
                        return -1;
                    }
                }
            }
            if (ia == a.Length && ib == b.Length)
            {
                
                //Console.WriteLine(a + " <=> " + b + " : " + res);
                return res;
            }
            else
            {
                if (ia < a.Length)
                {
                    for (int i = ia; i < a.Length; i++)
                    {
                        if (a[i] != a[ia-1])
                        {
                            //Console.WriteLine(a + " <=> " + b + " :  IMPOSSIBLE");
                            return -1;
                        }
                        res++;
                    }
                    //Console.WriteLine(a + " <=> " + b + " : " + res);
                    return res;
                }
                else if (ib < b.Length)
                {
                    for (int i = ib; i < b.Length; i++)
                    {
                        if (b[i] != b[ib-1])
                        {
                            //Console.WriteLine(a + " <=> " + b + " :  IMPOSSIBLE");
                            return -1;
                        }
                        res++;
                    }
                    //Console.WriteLine(a + " <=> " + b + " : " + res);
                    return res;
                }
                else
                {
                    //Console.WriteLine(a + " <=> " + b + " :  IMPOSSIBLE");
                    return -1;
                }
                
            }
        }
    }
}