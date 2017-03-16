using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

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

        private List<long> m_smallFairSquares = new List<long>(100);

        private void Go()
        {
            m_smallFairSquares = GetSmallFairSquares(100000000000000).ToList();

            int T = m_io.ReadInt();
            for (int t = 0; t < T; t++)
            {
                long A = m_io.ReadLong();
                long B = m_io.ReadLong();
                
                m_io.WriteCase(Count(A,B));
            }
        }

        private IEnumerable<long> GetSmallFairSquares(long max)
        {
            for (long i = 1; i < max; i++)
            {
                long squared = i * i;
                if (IsPal(i.ToString()) && IsPal(squared.ToString()))
                {
                    Console.WriteLine("{0}\t{1}", i, squared);
                    yield return squared;
                }
                
                if (squared > max)
                    break;
            }
        }

        private static bool IsPal(string number)
        {
            int halfLength = number.Length / 2;
            for (int i = 0; i < halfLength; i++)
            {
                if (number[i] != number[number.Length - 1 - i])
                    return false;
            }
            return true;
        }

        private long Count(long A, long B)
        {
            int count = 0;
            for (int i = 0; i < m_smallFairSquares.Count; i++)
            {
                if (A <= m_smallFairSquares[i] && m_smallFairSquares[i] <= B)
                    count++;

                if (m_smallFairSquares[i] > B)
                    break;
            }
            return count;
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

        public double ReadDouble()
        {
            return double.Parse(ReadWord());
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
