using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
    public class Program
    {
        int N, M;
        int[] zips;
        int start = 0;
        int[] ii, jj;

        public void ReadData()
        {
            var ar = ReadArray<int>();
            N = ar[0]; M = ar[1];
            zips = new int[N];
            for (int i = 0; i < N; i++)
            {
                zips[i] = ReadInt();
                if (zips[i] < zips[start])
                    start = i;
            }
            ii = new int[M];
            jj = new int[M];
            for (int i = 0; i < M; i++)
            {
                ar = ReadArray<int>();
                ii[i] = ar[0] - 1; jj[i] = ar[1] - 1;
            }
        }

        bool[] visited;
        //public string Solve()
        //{
        //    visited = new bool[N];

        //    var q = new List<int>();
        //    q.Add(start);

        //    var result = new StringBuilder();

        //    while (q.Count > 0)
        //    {
        //        var next = MinZip(q);
        //        visited[next] = true;
        //        result.Append(zips[next].ToString());
        //        q.Remove(next);
        //        q.AddRange(Neighbors(next).Where(n => !visited[n]));
        //    }

        //    return result.ToString();
        //}

        //public string Solve()
        //{
        //    visited = new bool[N];
            
        //    var order = new int[N];
        //    order[0] = start;

        //    int current = start;

        //    for (int o = 1; o < N; o++)
        //    {
        //        var unvisitedNeighbors = Neighbors(current).Where(n => !visited[n]);
        //        int next = MinZip(unvisitedNeighbors.ToList());

        //        // Swap
        //        var nns = Neighbors(next).Where(n => visited[n]);

                
        //        order[o] = next;
        //        visited[next] = true;

        //        //var next = MinZip(q);
        //        //visited[next] = true;
        //        //result.Append(zips[next].ToString());
        //        //q.Remove(next);
        //        //q.AddRange(Neighbors(next).Where(n => !visited[n]));
        //    }

        //    return string.Join("", order.Select(o => zips[o]));
        //}

        public string Solve()
        {
            return Solve(new List<int> { start });
        }

        public string Solve(List<int> orderSoFar)
        {
            if (orderSoFar.Count == N)
            {
                if (IsValid(orderSoFar))
                    return string.Join("", orderSoFar.Select(o => zips[o]));
                return null;
            }

            string min = null;
            for (int i = 0; i < N; i++)
            {
                if (!orderSoFar.Contains(i))
                {
                    var l = new List<int>(orderSoFar);
                    l.Add(i);
                    var soln = Solve(l);
                     if (soln != null && (min == null || string.Compare(soln, min) < 0))
                        min = soln;
                }
            }
            return min;
        }

        private bool IsValid(List<int> order)
        {
            for (int i = 1; i < N; i++)
            {
                int previous = order[i - 1];
                while (previous >= 0 && !IsConnected(order[i], previous))
                {
                    previous = Parent(order, previous);
                }
                if (previous == -1)
                    return false;
            }
            return true;
        }

        private int Parent(List<int> order, int n) {
            int parent = -1;
            int max = order.IndexOf(n);
            for (int i = 0; i < max; i++)
            {
                if (IsConnected(order[i], n))
                    parent = order[i];
            }
            return parent;
        }

        //public string Solve(List<int> orderSoFar, int current)
        //{
        //    if (orderSoFar.Count == N)
        //    {
        //        return string.Join("", orderSoFar.Select(o => zips[o]));
        //    }

        //    var unvisited = new HashSet<int>(Neighbors(current));
        //    unvisited.ExceptWith(orderSoFar);            

        //    // Take the min flight, or none
        //    string min = null;

        //    foreach(int next in unvisited)            
        //    {                
        //        var l = new List<int>(orderSoFar);
        //        l.Add(next);
        //        var soln = Solve(l, next);
        //        if (soln != null && (min == null || string.Compare(soln, min) < 0))
        //            min = soln;
        //    }

        //    // Find previous city (connected to current)            
        //    int previous = orderSoFar.IndexOf(current) - 1;
        //    while (previous >= 0 && !IsConnected(orderSoFar[previous], current))
        //    {
        //        previous--;
        //    }

        //    if (previous >= 0) {                
        //        string soln = Solve(orderSoFar, orderSoFar[previous]);
        //        if (soln != null && (min == null || string.Compare(soln, min) < 0))
        //            min = soln;
        //    }

        //    return min;
        //}

        private bool IsConnected(int a, int b)
        {
            if (a > b)
            {
                int t = a;
                a = b;
                b = t;
            }
            for (int i = 0; i < M; i++)
            {
                if (ii[i] == a && jj[i] == b)
                {
                    return true;
                }
            }
            return false;
        }

        //private string Solve(List<int> orderSoFar)
        //{
        //    if (orderSoFar.Count == N)
        //    {
        //        return string.Join("", orderSoFar.Select(o => zips[o]));
        //    }

        //    string min = null;
        //    //var neighbors = new HashSet<int>();
        //    //foreach (int o in orderSoFar)
        //    //{
        //    //    neighbors.UnionWith(Neighbors(o));
        //    //}
                
        //    var neighbors = Neighbors(orderSoFar[orderSoFar.Count - 1]);
        //    foreach(int next in neighbors)
        //    {
        //        if (!orderSoFar.Contains(next))
        //        {
        //            var l = new List<int>(orderSoFar);
        //            l.Add(next);
        //            string soln = Solve(l);
        //            if (soln != null && (min == null || string.Compare(soln, min) < 0))
        //                min = soln;
        //        }
        //    }
        //    return min;
        //}     

        private IEnumerable<int> Neighbors(int next)
        {
            for (int i = 0; i < M; i++)
            {
                if (ii[i] == next || jj[i] == next)
                {
                    yield return ii[i] == next ? jj[i] : ii[i];
                }
            }
        }

        private int MinZip(List<int> q)
        {
            int min = 100000;
            int min_q = -1;
            for (int i = 0; i < q.Count; i++)
            {
                if (zips[q[i]] < min)
                {
                    min = zips[q[i]];
                    min_q = q[i];
                }
            }
            return min_q;
        }

        static StreamReader reader;

        static void Main(string[] args)
        {
            string filename = args.Length > 0 ? args[0] : "test.in";
            string outFileName = filename.Replace(".in", ".out");
            string expectedFileName = filename.Replace(".in", ".expected");

            using (reader = File.OpenText(filename))
            using (var outFile = File.CreateText(outFileName))
            {
                int T = ReadInt();
                Console.WriteLine("{0} test cases", T);

                for (int tc = 1; tc <= T; tc++)
                {
                    Console.WriteLine("Starting test case {0}", tc);
                    var problem = new Program();
                    problem.ReadData();
                    string solution = problem.Solve();

                    outFile.WriteLine("Case #{0}: {1}", tc, solution);
                    Console.WriteLine("Case #{0}: {1}", tc, solution);
                }
            }

            if (File.Exists(expectedFileName))
            {
                CompareOutputToExpected(outFileName, expectedFileName);
            }
        }

        private static void CompareOutputToExpected(string outFileName, string expectedFileName)
        {
            string[] expected = File.ReadAllLines(expectedFileName);
            string[] actual = File.ReadAllLines(outFileName);
            for (int i = 0; i < Math.Max(expected.Length, actual.Length); i++)
            {
                string lineActual = i < actual.Length ? actual[i] : "** missing **";
                string lineExpected = i < expected.Length ? expected[i] : "** missing **";
                if (lineActual != lineExpected)
                {
                    Console.WriteLine("{0}: Expected: {1} Actual: {2}", (i + 1), lineExpected, lineActual);
                }
            }
        }

        #region Readers

        private static string ReadWord()
        {
            StringBuilder word = new StringBuilder();
            while (reader.Peek() >= 0)
            {
                char c = (char)reader.Read();
                if (Char.IsControl(c) || Char.IsWhiteSpace(c))
                    break;
                word.Append(c);
            }
            return word.ToString();
        }

        private static string ReadLine()
        {
            return reader.ReadLine();
        }

        private static int ReadInt()
        {
            return int.Parse(ReadLine());
        }

        private static T Read<T>()
        {
            return (T)Convert.ChangeType(ReadLine(), typeof(T));
        }

        private static T[] ReadArray<T>()
        {
            return ReadLine().Split(' ').Select(v => (T)Convert.ChangeType(v, typeof(T))).ToArray();
        }

        #endregion
    }
}
