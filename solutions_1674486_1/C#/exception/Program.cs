using System;
using System.Collections.Generic;
using System.Collections;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            TextReader tr = new StreamReader("C:\\Users\\Avinash\\Desktop\\input.txt");
            TextWriter tw = new StreamWriter("C:\\Users\\Avinash\\Desktop\\output.txt");

            int T;
            string input = tr.ReadLine();
            T = int.Parse(input);
            for (int caseno = 1; caseno <= T; caseno++)
            {
                input = tr.ReadLine();
                int N = int.Parse(input);
                List<List<int>> Outer = new List<List<int>>();
                for(int i =0 ; i< N; i++)
                {
                    input = tr.ReadLine();
                    string[] arr = input.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                    List<int> inner = new List<int>();
                    for (int j = 1; j < arr.Length; j++)
                    {
                        inner.Add(int.Parse(arr[j]));
                    }
                    Outer.Add(inner);
                }
                bool diamond = false;
                for (int i = 1; i <= N; i++)
                {
                    Stack S = new Stack();
                    S.Push(i);
                    bool[] visited = new bool[N+1];
                    
                    while (S.Count > 0)
                    {
                        int pope = (int)S.Pop();
                        if (visited[pope] == false)
                        {
                            visited[pope] = true;
                            for (int k = 0; k < Outer[pope-1].Count; k++)
                            {
                                S.Push(Outer[pope-1][k]);
                            }
                        }
                        else
                        {
                            diamond = true;
                            i = N;
                            break;
                        }
                    }
                }
                if(diamond)
                    tw.WriteLine("Case #{0}: Yes", caseno);
                else
                    tw.WriteLine("Case #{0}: No", caseno);


            }



            tr.Close();
            tw.Close();
        }
    }
}