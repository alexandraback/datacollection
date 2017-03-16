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
                    int n = int.Parse(r.ReadLine());

                    A[] arr = new A[n];

                    int[] test = new int[2 * n];

                    for (int i = 0; i < n; i++)
                    {
                        A a = new A();

                        string[] ss = r.ReadLine().Split(" ".ToCharArray());

                        a.a = int.Parse(ss[0]);
                        a.b = int.Parse(ss[1]);

                        arr[i] = a;

                        test[2*i] = a.a;
                        test[2*i + 1] = a.b;
                    }

                    Array.Sort(arr, delegate (A a, A b)
                                        {
                                            if (a.b == b.b)
                                                return 0;
                                            return a.b < b.b ? -1 : 1;
                                        });

                    Array.Sort(test);

                    bool bad = false;
                    for (int i = 0; i < 2*n; i++)
                    {
                        if (test[i] > i)
                        {
                            w.WriteLine("Case #" + (t + 1) + ": Too Bad");
                            bad = true;
                            break;
                        }
                    }
                    if (bad)
                        continue;

                    // test for 0
                    bool has1 = false;
                    bool has2 = false;
                    for (int i = 0; i < n; i++)
                    {
                        if (arr[i].a == 0)
                            has1 = true;

                        if (arr[i].b == 0)
                            has2 = true;
                    }

                    if (!has1 && ! has2)
                    {
                        w.WriteLine("Case #" + (t + 1) + ": Too Bad");
                        continue;
                    }

                    int stars = 0;
                    int cnt = 0;
                    int curlevel = 0;

                    while (curlevel < n)
                    {
                        
                        if (arr[curlevel].b > stars)
                        {
                            int delta = arr[curlevel].b - stars;

                            while (delta > 0)
                            {
                                bool has = false;
                                for (int i = n - 1; i >= curlevel; i--)
                                {
                                    if (delta == 0)
                                        break;

                                    if (!arr[i].tried && arr[i].a <= stars)
                                    {
                                        stars++;
                                        delta--;
                                        arr[i].tried = true;
                                        cnt++;
                                        has = true;
                                        break;
                                    }
                                }
                                
                                if (!has)
                                    Debug.Assert(false);

                            }


                        }
                        
                        if (arr[curlevel].tried)
                            stars++;
                        else
                        {
                            stars += 2;
                        }
                        

                        cnt++;
                        curlevel++;
                        continue;
                    }

                        w.WriteLine("Case #" + (t + 1) + ": " + cnt);

                    
                }

                r.Close();
                w.Close();
            }
            //Console.ReadLine();
        }

        
    }

    public class A
    {
        public int a, b;
        public bool tried;
    }
}
