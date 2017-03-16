using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJam
{
    class Program
    {
        public static IEnumerable<Tuple<int,int,int,bool>> ValidAnswersForTotal(int total)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = i; j <= Math.Min(10, i + 2); j++)
                {
                    int k = total - i - j;
                    if(k >= i && k<=10 && k>=j)
                    {
                        if (k - i < 2 && j - i < 2)
                            yield return new Tuple<int, int, int, bool>(i, j, k, false);
                        else if(k-i < 3)
                            yield return new Tuple<int, int, int, bool>(i, j, k, true);
                    }
                }
            }
        }

        private Tuple<int[], int[]> GetHighestTables()
        {
            int[] highestNormalTable = new int[31];
            int[] highestSurprisingTable = new int[31];

            for (int i = 0; i < 31; i++)
            {
                int highestNormal = -1;
                int highestSurprising = -1;

                foreach (var validAnswer in Program.ValidAnswersForTotal(i))
                {
                    if (validAnswer.Item4 && validAnswer.Item3 > highestSurprising)
                    {
                        highestSurprising = validAnswer.Item3;
                    }
                    else if (!validAnswer.Item4 && validAnswer.Item3 > highestNormal)
                    {
                        highestNormal = validAnswer.Item3;
                    }
                }
                highestNormalTable[i] = highestNormal;
                highestSurprisingTable[i] = highestSurprising;

                //Console.WriteLine("{0}:\t[{1},{2}]\t{3}",
                //    i,
                //    validAnswers.Where(t => !t.Item4).Count(),
                //    validAnswers.Where(t => t.Item4).Count(),
                //    String.Join(" ", validAnswers.Select(v => String.Format("({0},{1},{2})", v.Item1, v.Item2, v.Item3)))
                //    );
            }

            return new Tuple<int[], int[]>(highestNormalTable, highestSurprisingTable);
        }

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

            Tuple<int[], int[]> highestTables = GetHighestTables();
            m_highestNormalTable = highestTables.Item1;
            m_highestSurprisingTable = highestTables.Item2;
        }

        private int[] m_highestNormalTable;
        private int[] m_highestSurprisingTable;

        private void Go()
        {
            int T = m_io.ReadInt();
            for (int t = 0; t < T; t++)
            {
                int N = m_io.ReadInt();
                int S = m_io.ReadInt();
                int p = m_io.ReadInt();
                int[] googlersSums = Enumerable.Range(0, N).Select(i => m_io.ReadInt()).ToArray();

                m_io.WriteCase(Solve(N,S,p,googlersSums));
            }
        }



        private int Solve(int N, int S, int p, int[] googlersSums)
        {
            int count = 0;
            for (int i = 0; i < googlersSums.Length; i++)
            {
                if (m_highestNormalTable[googlersSums[i]] >= p)
                    count++;
                else if (m_highestSurprisingTable[googlersSums[i]] >= p && S > 0)
                {
                    count++;
                    S--;
                }
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
