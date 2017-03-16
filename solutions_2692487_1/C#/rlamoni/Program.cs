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

        private void Go()
        {
            int T = m_io.ReadInt();
            for (int t = 0; t < T; t++)
            {
                int currentSize = m_io.ReadInt();
                int n = m_io.ReadInt();
                int[] motes = Enumerable.Range(0, n).Select(i => m_io.ReadInt()).ToArray();
                m_io.WriteCase(SolveEasy(currentSize, motes));
            }
        }

        private int SolveEasy(int currentSize, int[] motes)
        {
            if (currentSize == 1) //cannot eat anything
                return motes.Length;
            motes = motes.OrderBy(x => x).ToArray();
            return SolveRest(currentSize, 0, motes.Length, motes);
        }

        private int SolveRest(int currentSize, int location, int moteCount, int[] motes)
        {
            if (location >= moteCount)
                return 0;
            if (currentSize > motes[location])
            {
                return SolveRest(currentSize + motes[location], location + 1, moteCount, motes);
            }
            else
            {
                int deleteRest = moteCount - location;
                int solveNotDeleting = SolveRest(currentSize + (currentSize - 1), location, moteCount, motes) + 1;
                return Math.Min(deleteRest, solveNotDeleting);
            }
        }

        private int SolveHard(int currentSize, int[] motes)
        {
            motes = motes.OrderBy(x => x).ToArray();
            int operationCount = 0;
            int lastMote = motes[motes.Length - 1];

            for (int i = 0; i < motes.Length; i++)
            {
                int motesLeft = motes.Length - i;
                int currentMote = motes[i];
                if (currentMote < currentSize)
                {
                    currentSize += currentMote;
                }
                else if (NeededToGetTo(currentSize, 0000) >= motesLeft)
                {
                    operationCount += motesLeft;
                    break;
                }
                else
                {
                    motes[i] = currentSize - 1;
                    i--; //step back
                    operationCount++;
                }
            }

            return operationCount;
        }

        private int NeededToGetTo(int currentSize, int moteToReach)
        {
            if (currentSize == 1)
                return int.MaxValue;
            int count = 0;
            while (currentSize <= moteToReach)
            {
                count++;
                currentSize += currentSize - 1;
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
