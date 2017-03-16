using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    class Program
    {
        class Solver
        {
            public string solve(System.IO.StreamReader p_Reader)
            {
                string[] input = p_Reader.ReadLine().Split(' ');

                int a = Convert.ToInt32(input[0]);
                int b = Convert.ToInt32(input[1]);
                int k = Convert.ToInt32(input[2]);

                int combinacoes = 0;

                for (int i = 0; i < a; i ++)
                {
                    for (int j = 0; j < b; j++)
                    {
                        int gerado = i & j;
                        if (gerado < k)
                        { 
                            combinacoes++;
                        }
                    }
                }

                return combinacoes + "";
            }
        }

        static String Path
        {
            get
            {
                return @"C:\Users\Nilson\Desktop\vivian-codejam\round-1B\b\arquivo\";
            }
        }

        static void Main(string[] args)
        {
            Solver v_Solver = new Solver();
            StreamReader v_InputStream = new StreamReader(Path + "B-small-attempt0.in");
            int v_NumberOfCases = Convert.ToInt32(v_InputStream.ReadLine());

            StreamWriter v_Writer = new StreamWriter(Path + "Output.txt");
            for (int i = 1; i <= v_NumberOfCases; i++)
            {
                v_Writer.WriteLine(String.Format("Case #{0}: {1}", i, v_Solver.solve(v_InputStream)));
            }
            v_InputStream.Close();
            v_Writer.Flush();
            v_Writer.Close();
        }
    }
}
