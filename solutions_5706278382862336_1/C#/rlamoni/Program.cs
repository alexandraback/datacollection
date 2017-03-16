using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    class Program
    {
        static void Main(string[] args)
        {
            using (CodeJamIO io = new CodeJamIO("in.txt", "out.txt"))
            {
                Program p = new Program(io); ;
                p.Go();
            }
        }

        private CodeJamIO m_io = null;
        public Program(CodeJamIO io)
        {
            m_io = io;
        }

        private void Go()
        {
            int T = m_io.ReadInt();
            for (int t = 0; t < T; t++)
            {
                var strg = m_io.ReadWord().Split('/');

                long P = long.Parse(strg[0]);
                long Q = long.Parse(strg[1]);
                long gcd= GCD(P,Q);

                P = (P / gcd);
                Q = (Q / gcd);

                var num = HighestBitLocationWithCount(P);
                var denom = HighestBitLocationWithCount(Q);

                if (denom.Item2 != 1)
                    m_io.WriteCase("impossible");
                else
                    m_io.WriteCase(denom.Item1 - num.Item1);
            }
        }

        private long GCD(long u, long v)
        {

            // simple cases (termination)
            if (u == v)
                return u;

            if (u == 0)
                return v;

            if (v == 0)
                return u;

            // look for factors of 2
            if ((~u & 1L) == 1) // u is even
            {
                if ((v & 1L) == 1) // v is odd
                    return GCD(u >> 1, v);
                else // both u and v are even
                    return GCD(u >> 1, v >> 1) << 1;
            }

            if ((~v & 1L) == 1) // u is odd, v is even
                return GCD(u, v >> 1);

            // reduce larger argument
            if (u > v)
                return GCD((u - v) >> 1, v);

            return GCD((v - u) >> 1, u);

        }

 

        private Tuple<int, int> HighestBitLocationWithCount(long Q)
        {
            long count = 0;
            int highest = 1;
            int curBit = 1;
            while(Q != 0)
            {
                long bit = (Q & 0x1L);
                if(bit == 1)
                    highest = curBit;
                curBit++;
                count += bit;
                Q >>= 1;
            }
            return new Tuple<int, int>(highest, (int)count);
        }


    }

    #region IO Class

    class CodeJamIO : IDisposable
    {
        private int m_case = 0;
        private string m_currentLine;
        private StreamReader m_reader;
        private StreamWriter m_writer;

        public CodeJamIO(string infile, string outfile)
        {
            m_reader = new StreamReader(infile);
            m_writer = new StreamWriter(outfile);
        }

        public void WriteCase(string result)
        {
            ++m_case;
            m_writer.WriteLine("Case #{0}: {1}", m_case, result);
            Console.WriteLine("Case #{0}: {1}", m_case, result);
        }
        public void WriteCase(long result)
        {
            WriteCase(result.ToString());
        }
        public void WriteCase(int result)
        {
            WriteCase(result.ToString());
        }

        public long ReadLong()
        {
            return long.Parse(ReadWord());
        }

        public int ReadInt()
        {
            return int.Parse(ReadWord());
        }

        public string ReadLine()
        {
            if (String.IsNullOrWhiteSpace(m_currentLine))
            {
                m_currentLine = m_reader.ReadLine();
                if (m_currentLine == null)
                    throw new Exception("end of file");
            }
            string ret = m_currentLine;
            m_currentLine = null;
            return ret;
        }

        private static char[] whitespace = new char[] { ' ', '\t', '\n', '\r' };

        public string ReadWord()
        {

            string ret;
            int i;
            for (i = 0; string.IsNullOrWhiteSpace(m_currentLine) && i < 1000; i++)
            {
                m_currentLine = m_reader.ReadLine();
            }
            if (i >= 1000)
                throw new Exception("Too many bad reads");
            m_currentLine = m_currentLine.TrimStart(whitespace);
            int positionOfNextSpace = m_currentLine.IndexOfAny(whitespace);
            if (positionOfNextSpace < 0)
            {
                ret = m_currentLine;
                m_currentLine = null;

            }
            else
            {
                ret = m_currentLine.Substring(0, positionOfNextSpace);
                m_currentLine = m_currentLine.Substring(positionOfNextSpace);
            }

            return ret;
        }

        private bool m_disposed = false;
        public void Dispose()
        {
            Dispose(true);
            GC.SuppressFinalize(this);
        }

        protected virtual void Dispose(bool disposing)
        {
            // Check to see if Dispose has already been called.
            if (!m_disposed)
            {
                // If disposing equals true, dispose all managed
                // and unmanaged resources.
                if (disposing)
                {
                    // Dispose managed resources.
                    m_writer.Flush();
                    m_writer.Close();
                    m_writer.Dispose();
                }

                m_disposed = true;
            }
        }
    }
    #endregion IO Class
}