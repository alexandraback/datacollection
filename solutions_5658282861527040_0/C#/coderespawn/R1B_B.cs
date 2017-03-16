using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014
{
    class Node
    {
        public Node(int id) { this.id = id; }
        public int id;
        public List<int> edges = new List<int>();
    }

    /////////////////////////// Solution ////////////////////////////////
    class R1B_B : GSolution
    {
        
        public ulong Process(ulong a, ulong b, ulong k)
        {
            if (a >= A || b >= B || k >= K) return 0;
            if (ContainsMemo(a, b, k)) return GetMemo(a, b, k);

            ulong result = ((a & b) == k) ? 1UL : 0UL;
            int[,] offsets = new int[,] {
                {1, 1, 1},
                {1, 0, 0},
                {0, 1, 0},
                {0, 0, 0},
            };
            for (int i = 0; i < 4; i++)
            {
                ulong oa = (ulong)offsets[i, 0];
                ulong ob = (ulong)offsets[i, 1];
                ulong ok = (ulong)offsets[i, 2];
                if (i == 3 && (a == 0 && b == 0)) continue;
                result += Process((a << 1) + oa, (b << 1) + ob, (k << 1) + ok);
            }
            SetMemo(a, b, k, result);
            return result;
        }
        ulong A, B, K;
        Dictionary<ulong, Dictionary<ulong, Dictionary<ulong, ulong>>> memo = new Dictionary<ulong, Dictionary<ulong, Dictionary<ulong, ulong>>>();
        bool ContainsMemo(ulong a, ulong b, ulong k)
        {
            return memo.ContainsKey(a) && memo[a].ContainsKey(b) && memo[a][b].ContainsKey(k);
        }

        ulong GetMemo(ulong a, ulong b, ulong k)
        {
            return memo[a][b][k];
        }

        void SetMemo(ulong a, ulong b, ulong k, ulong value)
        {
            if (!memo.ContainsKey(a)) memo[a] = new Dictionary<ulong, Dictionary<ulong, ulong>>();
            if (!memo[a].ContainsKey(b)) memo[a][b] = new Dictionary<ulong, ulong>();
            memo[a][b][k] = value;
        }


        public override void ProcessCase(GStream stream, int caseId)
        {
            memo.Clear();
            string[] tokens = stream.ReadStringArray();
            A = ulong.Parse(tokens[0]);
            B = ulong.Parse(tokens[1]);
            K = ulong.Parse(tokens[2]);

            ulong result = Process(0, 0, 0);
            stream.PrintCase(caseId, result.ToString());
        }
    }

    /////////////////////////// Bootstrap ////////////////////////////////

    public class Program
    {
        static void Main(string[] args)
        {
            string directory = "R1B_B";
            string filename =
               //"Example.in"
                "B-small-attempt0.in"
               // "A-large.in"
                    ;
            var stream = new GStream(directory + "/" + filename);
            new R1B_B().Run(stream);
            stream.Close();
        }

    }


    /////////////////////////// GCJ Utils ////////////////////////////////
    abstract class GSolution
    {
        abstract public void ProcessCase(GStream stream, int caseId);

        public void Run(GStream stream)
        {
            int numCases = int.Parse(stream.Input.ReadLine());
            for (int i = 0; i < numCases; i++)
            {
                ProcessCase(stream, i + 1);
            }
        }
    }

    class GStream
    {
        StreamReader input;
        public System.IO.StreamReader Input
        {
            get { return input; }
        }

        StreamWriter output;
        public System.IO.StreamWriter Output
        {
            get { return output; }
        }

        public GStream(string inputFilename)
        {
            inputFilename = "../../Data/" + inputFilename;
            var inputFileInfo = new FileInfo(inputFilename);
            string outputFilename = inputFilename.Replace(inputFileInfo.Extension, ".out");

            input = new StreamReader(new FileStream(inputFilename, FileMode.Open));
            output = new StreamWriter(new FileStream(outputFilename, FileMode.Create));
        }

        public void Close()
        {
            input.Close();
            output.Close();
        }

        public void PrintCase(int caseId, string result)
        {
            Output.WriteLine("Case #{0}: {1}", caseId, result);
        }

        public int ReadInt()
        {
            return int.Parse(Input.ReadLine());
        }

        public string[] ReadStringArray()
        {
            return Input.ReadLine().Split(" ".ToCharArray(), StringSplitOptions.RemoveEmptyEntries);
        }

        public string ReadString()
        {
            return Input.ReadLine();
        }

        public int[] ReadIntArray()
        {
            string[] tokens = ReadStringArray();
            var result = new List<int>();
            foreach (string token in tokens)
            {
                result.Add(int.Parse(token));
            }
            return result.ToArray();
        }

        public double[] ReadRealArray()
        {
            string[] tokens = ReadStringArray();
            var result = new List<double>();
            foreach (string token in tokens)
            {
                result.Add(double.Parse(token));
            }
            return result.ToArray();
        }

        public void ReadIntArray(out int a, out int b)
        {
            int[] tokens = ReadIntArray();
            a = tokens[0];
            b = tokens[1];
        }

        public void ReadIntArray(out int a, out int b, out int c)
        {
            int[] tokens = ReadIntArray();
            a = tokens[0];
            b = tokens[1];
            c = tokens[2];
        }

        public void ReadRealArray(out double a, out double b, out double c)
        {
            double[] tokens = ReadRealArray();
            a = tokens[0];
            b = tokens[1];
            c = tokens[2];
        }

        public void DiscardLine()
        {
            input.ReadLine();
        }
    }

}
