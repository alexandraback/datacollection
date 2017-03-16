using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Soln
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hi");
            StreamReader rd = new StreamReader("E:/Practice/GoogleCode Jam/Round1A_consol/Files/A-large.in");
            //  Stream outstrm =  File.Create("E:/Practice/GoogleCode Jam/Practice/Input/output_1A.in");
            TextWriter wr = new StreamWriter("E:/Practice/GoogleCode Jam/Round1A_consol/Files/output.in");
            int testCaseCount = Int32.Parse(rd.ReadLine());
            int current = 1;
            while (testCaseCount >= current)
            {
                int nodes = Int32.Parse(rd.ReadLine());
                int[,] arr = new int[nodes, nodes];
                int temp1 = 0;
                while (temp1 < nodes)
                {
                    string[] inp = rd.ReadLine().Split(' ');
                    for (int temp2 = 1; temp2 < inp.Count(); temp2++)
                    {
                        arr[temp1, Int32.Parse(inp[temp2]) - 1] = 1;
                    }
                    temp1++;


                }
                //matrix ready
                bool ans=false;

                for (int temp3 = 0; temp3 < nodes; temp3++)
                {
                    if (ans)
                        break;
                    for (int temp4 = 0; temp4 < nodes; temp4++)
                    {
                        if (ans)
                            break;
                        for (int temp5 = 0; temp5 < nodes; temp5++)
                        {
                            if (ans)
                                break;
                            if (arr[temp4, temp3] == 1 && arr[temp3, temp5] == 1)
                                if (arr[temp4, temp5] == 1)
                                    ans = true;
                                else arr[temp4, temp5] = 1;
                        }

                    }



                }

                if(ans)
                    wr.WriteLine("Case #" + current.ToString() + ": Yes");
                else
                    wr.WriteLine("Case #" + current.ToString() + ": No");


                current++;
            }
            wr.Dispose();

            Console.WriteLine("Done");


        }
    }
}

