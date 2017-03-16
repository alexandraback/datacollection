using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
    public class Solver
    {
        double answer;
        double C, F, X;

        public void Run()
        {
            using (FileStream input = new FileStream("B-large.in", FileMode.Open))
            using (FileStream output = new FileStream("Large_Output.txt", FileMode.Create))
            using (StreamReader reader = new StreamReader(input))
            using (StreamWriter writer = new StreamWriter(output))
            {
                int test = Int32.Parse(reader.ReadLine());
                for (int tt = 0; tt < test; tt++)
                {
                    ReadInput(reader);
                    SolveTask();
                    WriteOutput(writer, tt + 1);
                }
            }

        }

        private void SolveTask()
        {
            answer = X / 2;
            double curTime = 0;
            double curProduce = 2;
            for (int i = 1; ; i++)
            {
                curTime += C / curProduce;
                curProduce += F;
                double curAns = curTime + X / curProduce;
                if (curAns+1e-7<answer)
                {
                    answer = curAns;
                }
                else
                {
                    break;
                }
            }
        }

        private void WriteOutput(StreamWriter writer, int testNum)
        {
            writer.WriteLine(string.Format("Case #{0}: {1}", testNum, answer.ToString("0.0000000")));
        }

        private void ReadInput(StreamReader reader)
        {
            string[] input = reader.ReadLine().Split(' ');
            C = Double.Parse(input[0]);
            F = Double.Parse(input[1]);
            X = Double.Parse(input[2]);
    
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
