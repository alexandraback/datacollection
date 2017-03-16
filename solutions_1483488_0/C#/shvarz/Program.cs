using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq; 
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            checked
            {
                const string outputfile = @"F:\GoogleCodeJam\output.txt";

                StreamReader r = new StreamReader(@"F:\GoogleCodeJam\input.in");

                if (File.Exists(outputfile))
                    File.Delete(outputfile);

                if (File.Exists(@"F:\GoogleCodeJam\Program.cs"))
                    File.Delete(@"F:\GoogleCodeJam\Program.cs");

                File.Copy(@"f:\Projects\ConsoleApplication1\ConsoleApplication1\Program.cs",
                    @"F:\GoogleCodeJam\Program.cs");

                StreamWriter w = new StreamWriter(outputfile);

                int T = int.Parse(r.ReadLine());

                for (int t = 0; t < T; t++)
                {
                    string[] ss = r.ReadLine().Split(" ".ToCharArray());

                    int a = int.Parse(ss[0]);
                    int b = int.Parse(ss[1]);


                    w.WriteLine("Case #" + (t + 1) + ": " + getCnt(a, b));

                    
                }

                r.Close();
                w.Close();
            }
            //Console.ReadLine();
        }

        private static long getCnt(int a, int b)
        {
            long cnt = 0;
            for (int curr = a; curr < b; curr++)
            {
                string s = curr.ToString();

                

                List<string> ss = new List<string>();
               // List<int> ii = new List<int>();

                string curs = s;

                bool already = false;
                
                while (true)
                {
                    string newcurs = curs.Substring(1) + curs[0];
                    if (newcurs == s)
                        break;

                    Debug.Assert(!ss.Contains(newcurs));

                    int newcur = int.Parse(newcurs);

                    if (newcur < a)
                    {
                        curs = newcurs;
                        continue;
                    }

                    if (newcur > b)
                    {
                        curs = newcurs;
                        continue;
                    }

                    // если нашли в цепочке меньшее число, значит всю цепочку уже подсчитали
                    if (newcur < curr)
                    {
                        already = true;
                        break;
                    }
                    
                    ss.Add(newcurs);

                    //Console.Write(" ");
                    //Console.Write(newcurs);
                    //ii.Add()
                    curs = newcurs;
                }

                if (already)
                {
                    //Console.WriteLine();
                    continue;
                }

                
                //Console.WriteLine(s + " " + fac(ss.Count) + " " + cnt);
                //Console.Write(" ");
                //Console.WriteLine(cnt);
                cnt += fac(ss.Count);
            }

            return cnt;
        }

       public static int fac(int cnt)
       {
           return (cnt + 1)*cnt/2;
       }
    }
}
