using System;
using System.IO;
using System.Collections.Generic;
using System.Text;

namespace QR_A
{
    class Tokenizer
    {
        int pos;
        string[] tokens;
        TextReader reader;
        
        public Tokenizer(TextReader reader)
        {
            pos = 0;
            tokens = new string[] { };
            this.reader = reader;
        }
        
        
        public string NextToken()
        {
            if (pos == tokens.Length)
            {
                tokens = reader.ReadLine().Split(' ');
                pos = 0;
            }
            return tokens [pos++];
        }
        
        public int NextInt()
        {
            return int.Parse(NextToken());
        }
        
        public long NextLong()
        {
            return long.Parse(NextToken());
        }
    }
    
    class MainClass
    {
        static TextReader reader = File.OpenText(@"../../A-small-attempt1.in");
        static TextWriter writer = File.CreateText(@"../../A-small-attempt1.out");
        static Tokenizer t = new Tokenizer(reader);
        static int A;
        static int N;
        static int maxSize = 1000000;
        static int[] sizes;

        static int f(int cur, int size)
        {
            if (size > maxSize || cur >= N)
                return 0;

            if (size > sizes [cur])
                return f(cur + 1, size + sizes [cur]);
            return Math.Min(1 + f(cur, size + size - 1), N - cur);
        }

        static int Solve()
        {
            A = t.NextInt();
            N = t.NextInt();

            sizes = new int[N];
            for (int i = 0; i < N; i++)
            {
                sizes [i] = t.NextInt();
            }
            Array.Sort(sizes);
            if (A == 1)
                return N;
            return f(0, A);
        }

        public static void Main(string[] args)
        {
            int T = t.NextInt();
            for (int i = 1; i <= T; i++)
            {
                writer.WriteLine("Case #{0}: {1}", i, Solve());
            }
            writer.Close();
        }
    }
}
