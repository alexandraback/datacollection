using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace GCJ_2015_QualificationRound
{
    public class A
    {
        private void Run()
        {
            int T = int.Parse(Console.ReadLine().Trim());
            for (int testcase = 1; testcase <= T; ++testcase)
            {
                var input = Console.ReadLine().Trim().Split();
                var p = new PriorityQueue<int>();

                var sMax = int.Parse(input[0]);
                var ks = input[1];
                for (int i = 0; i < ks.Length; ++i)
                {
                    for (int j = 0; j < ks[i] - '0'; ++j)
                    {
                        p.Push(i);
                    }
                }

                int total = 0;
                int res = 0;
                while (p.Count > 0)
                {
                    while (total < p.Peek())
                    {
                        total += 1;
                        res += 1;
                    }
                    p.Pop();
                    total += 1;
                }

                Console.Write("Case #{0}: ", testcase);
                Console.WriteLine(res);
            }
        }

        private static void Main()
        {
            var old = Console.Out;
            using (var writer = new System.IO.StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false })
            {
                Console.SetOut(writer);
                new A().Run();
                Console.Out.Flush();
                Console.SetOut(old);
            }
        }
    }

    public class PriorityQueue<T>
    {
        public PriorityQueue() : this(Comparer<T>.Default) { }
        public PriorityQueue(IComparer<T> compare)
        {
            this.m_buffer = new List<T>();
            this.m_comparer = compare;
        }

        public void Push(T elem)
        {
            int n = this.m_buffer.Count;
            this.m_buffer.Add(elem);
            while (n != 0)
            {
                int i = (n - 1) / 2;
                if (this.m_comparer.Compare(this.m_buffer[i], this.m_buffer[n]) > 0)
                {
                    T temp = this.m_buffer[i];
                    this.m_buffer[i] = this.m_buffer[n];
                    this.m_buffer[n] = temp;
                }
                n = i;
            }
        }
        public T Pop()
        {
            int n = this.m_buffer.Count - 1;
            var res = this.m_buffer[0];
            this.m_buffer[0] = this.m_buffer[n];
            this.m_buffer.RemoveAt(n);
            int i = 0, j;
            while (true)
            {
                j = 2 * i + 1;
                if (j >= n) { break; }
                if (j < n - 1 && this.m_comparer.Compare(this.m_buffer[j], this.m_buffer[j + 1]) > 0) { ++j; }
                if (this.m_comparer.Compare(this.m_buffer[i], this.m_buffer[j]) > 0)
                {
                    T temp = this.m_buffer[i];
                    this.m_buffer[i] = this.m_buffer[j];
                    this.m_buffer[j] = temp;
                }
                i = j;
            }
            return res;
        }
        public T Peek() { return this.m_buffer[0]; }
        public int Count { get { return this.m_buffer.Count; } }
        public void Clear() { this.m_buffer.Clear(); }

        private readonly List<T> m_buffer;
        private readonly IComparer<T> m_comparer;
    }
}
