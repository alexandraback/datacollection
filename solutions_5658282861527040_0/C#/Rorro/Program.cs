using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace CodeJam2014
{
    
  
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("C:/cjam/B.in");
            StreamWriter writer = new StreamWriter("C:/cjam/B.out");
            int N = int.Parse(reader.ReadLine());
            for (int i = 1; i <= N; i++)
            {

                string[] inp = reader.ReadLine().Split(' ');
                int A = int.Parse(inp[0]);
                int B = int.Parse(inp[1]);
                int K = int.Parse(inp[2]);
                int cont = 0;
                for (int j = 0; j < A; j++)
                {
                    for (int k = 0; k < B; k++)
                    {
                        int c = j & k;
                        cont += (c < K) ? 1 : 0;
                    }
                }
                writer.WriteLine("Case #" + i.ToString() + ": " + cont.ToString());

                
            }
            reader.Close();
            writer.Close();
        }
    }
}
