using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamReader Input = new StreamReader("Data/Input.txt");
            StreamWriter Output = new StreamWriter("Data/Output.txt");
            int T = int.Parse(Input.ReadLine());
            for (int i = 1; i <= T; i++)
            {
                Console.WriteLine("Case #" + i);
                Output.Write("Case #" + i + ": ");
                Solution(Input, Output);
                Output.WriteLine();
            }
            Input.Close();
            Output.Close();
            //Console.Read();
        }
        static void Solution(StreamReader Input, StreamWriter Output)
        {
            string[] nums = Input.ReadLine().Split(' ');
            int B = int.Parse(nums[0]);
            int M = int.Parse(nums[1]);
            if (M > Math.Pow(2, B - 2))
            {
                Output.Write("IMPOSSIBLE");
                return;
            }
            else
            {
                Output.Write("POSSIBLE");
            }
            List<List<bool>> Matrix = new List<List<bool>>();
            for (int i = 0; i < B; i++)
            {
                Matrix.Add(new List<bool>());
                for (int j = 0; j < B; j++)
                {
                    Matrix[i].Add(false);
                }
            }
            int path = 0;
            Random rnd = new Random();
            while (path != M)
            {
                int from = rnd.Next(0, B - 1);
                int to = rnd.Next(1, B);
                if (to == from)
                {
                    continue;
                }
                Matrix[from][to] = !Matrix[from][to];
                try {
                    path = countDirections(Matrix, 0, new List<int>());
                }
                catch
                {
                    Matrix[from][to] = !Matrix[from][to];
                }
            }
            for(int i = 0; i < B; i++)
            {
                Output.WriteLine();
                for (int j = 0; j < B; j++)
                {
                    Output.Write(Matrix[i][j] ? "1" : "0");
                }
            }
        }
        static int countDirections(List<List<bool>> Matrix, int from, List<int> indexes)
        {
            int path = Matrix[from][Matrix.Count - 1] ? 1 : 0;
            indexes.Add(from);
            if (indexes.Distinct().Count() != indexes.Count())
            {
                //loop
                throw new Exception("loop");
            }
            for(int i = 0; i < Matrix.Count; i++)
            {
                if (Matrix[from][i])
                {
                    List<int> thisWay = new List<int>(indexes);
                    path += countDirections(Matrix, i, thisWay);
                }
            }
            return path;
        }
    }
}
