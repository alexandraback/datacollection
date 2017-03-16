using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace D
{
    public class Solver
    {
        List<double> A;
        List<double> B;
        int cnt;
        int first, second;

        public void Run()
        {
            using (FileStream input = new FileStream("D-large.in", FileMode.Open))
            using (FileStream output = new FileStream("Large_output.txt", FileMode.Create))
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
            first = second = 0;
            //First
            int l = 0;
            int r = cnt - 1;
            int ll = 0;
            int rr = cnt - 1;
            while (l<=r)
            {
                if (A[l]>B[ll])
                {
                    first++;
                    ll++;
                    l++;
                }
                else
                {
                    l++;
                    rr--;
                }
            }

            //Second
            l = 0;
            r = cnt - 1;
            for (int i = cnt - 1; i >= 0; i--)
            {
                if (A[i]>B[r])
                {
                    l++;
                    second++;
                }
                else
                {
                    r--;
                }
            }
        }

        private void WriteOutput(StreamWriter writer, int testNum)
        {
            writer.WriteLine(string.Format("Case #{0}: {1} {2}", testNum, first, second));
            
        }

        private void ReadInput(StreamReader reader)
        {
            cnt = Int32.Parse(reader.ReadLine());
            A = new List<double>();
            B = new List<double>();
            string[] input = reader.ReadLine().Split(' ');
            for (int i=0;i<input.Length;i++)
            {
                A.Add(Double.Parse(input[i]));
            }
            input = reader.ReadLine().Split(' ');
            for (int i = 0; i < input.Length; i++)
            {
                B.Add(Double.Parse(input[i]));
            }
            A.Sort();
            B.Sort();
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
