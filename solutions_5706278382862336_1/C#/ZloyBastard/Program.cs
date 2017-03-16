using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
    public class Solver
    {
        int answer;
        bool hasAnswer;
        UInt64 A,B;
        
        public void Run()
        {
            using (FileStream input = new FileStream("A-large.in", FileMode.Open))
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

        public UInt64 NOD(UInt64 a,UInt64 b)
        {
            if (b==0)
            {
                return a;
            }
            else
            {
                return NOD(b, a % b);
            }
        }

        private void SolveTask(StreamWriter writer)
        {
            //writer.WriteLine("{0} / {1}", A, B);
            UInt64 d = NOD(A, B);
            A /= d;
            B /= d;
            answer = 0;
            hasAnswer = true;
            while (A < B)
            {
                if (B % 2 == 1)
                {
                    hasAnswer = false;
                    break;
                }
                answer++;
                B /= 2;
            }
            A -= B;
            while (A > 0 && hasAnswer)
            {
                UInt64 dd = NOD(A, B);
                A /= dd;
                B /= dd;
                while (A < B)
                {
                    if (B % 2 == 1)
                    {
                        hasAnswer = false;
                        break;
                    }
                    B /= 2;
                }
                A -= B;
            }
        }

        private void WriteOutput(StreamWriter writer, int testNum)
        {
            writer.WriteLine(string.Format("Case #{0}: {1}", testNum, (hasAnswer) ? answer.ToString() : "impossible"));
        }

        private void ReadInput(StreamReader reader)
        {
            string[] parts = reader.ReadLine().Split('/');
            A = UInt64.Parse(parts[0]);
            B = UInt64.Parse(parts[1]);
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
