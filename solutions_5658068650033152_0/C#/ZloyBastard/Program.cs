using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    public class Solver
    {
        int answer;
        int n, m, k;

        public void Run()
        {
            using (FileStream input = new FileStream("C-small-attempt1.in", FileMode.Open))
            //using (FileStream input = new FileStream("input.txt", FileMode.Open))
            using (FileStream output = new FileStream("output.txt", FileMode.Create))
            using (StreamReader reader = new StreamReader(input))
            using (StreamWriter writer = new StreamWriter(output))
            {
                int test = Int32.Parse(reader.ReadLine());
                for (int tt = 0; tt < test; tt++)
                {
                    ReadInput(reader);
                    SolveTask(writer);
                    WriteOutput(writer, tt + 1);
                }
            }

        }

        private void SolveTask(StreamWriter writer)
        {
            answer = n * m;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                {
                    int sq = i * j;
                    int curans = Calc(i, j);
                    if (sq >= k && answer > curans)
                    {
                        answer = curans;
                    }
                    if (i > 1)
                    {
                        sq--;
                        curans--;
                        if (sq >= k && answer > curans)
                        {
                            answer = curans;
                        }
                    }
                    if (i > 2)
                    {
                        sq--;
                        curans--;
                        if (sq >= k && answer > curans)
                        {
                            answer = curans;
                        }
                    }
                    if (j > 2)
                    {
                        sq--;
                        curans--;
                        if (sq >= k && answer > curans)
                        {
                            answer = curans;
                        }
                    }
                    if (j > 2)
                    {
                        sq--;
                        curans--;
                        if (sq >= k && answer > curans)
                        {
                            answer = curans;
                        }
                    }


                }

        }

        private int Calc(int i, int j)
        {
            if (i>1)
            {
                if (j>1)
                {
                    return (i - 1 + j - 1) * 2;
                }
                else
                {
                    return i;
                }
            }
            else
            {
                if (j>1)
                {
                    return j;
                }
                else
                {
                    return 1;
                }
            }
            
        }

        private void WriteOutput(StreamWriter writer, int testNum)
        {
            writer.WriteLine(string.Format("Case #{0}: {1}", testNum, answer));
        }

        private void ReadInput(StreamReader reader)
        {
            string[] inp = reader.ReadLine().Split(' ');
            n = Int32.Parse(inp[0]);
            m = Int32.Parse(inp[1]);
            k = Int32.Parse(inp[2]);
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            (new Solver()).Run();
        }

    }
}
