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
                int count = m_io.ReadInt();
                var cars = Enumerable.Range(0, count).Select(i => m_io.ReadWord()).ToList();
                if (HasImpossibleCars(cars))
                    m_io.WriteCase(0);
                else
                {
                    var simpleCars = Enumerable.Range(0, count).Select(i => new Tuple<int,int>(cars[i][0] - 'a', cars[i].Last() - 'a')).ToList();
                    int[] letterCounts = new int[26];
                    foreach (var car in simpleCars)
                    {
                        letterCounts[car.Item1]++;
                        letterCounts[car.Item2]++;
                    }
                    m_io.WriteCase(BruteForce(simpleCars, new bool[count], 0, -1, letterCounts, new int[26]));
                    //m_io.WriteCase(1);
                }
            }
        }
        
        private bool HasImpossibleCars(List<string> cars)
        {
            var surrounded = new HashSet<char>();
            var usedInAnyPreviousCar = new HashSet<char>();
            var begins = new HashSet<char>();
            var ends = new HashSet<char>();
            foreach(var car in cars)
            {
                var closed = new HashSet<char>();
                char current = '$';
                foreach(var letter in car)
                {
                    if (surrounded.Contains(letter))
                    {
                        Console.WriteLine("{0} used surr in {1}", car, String.Join(",", cars));
                        return true;
                    }

                    if (letter != current)
                    {
                        if (current != '$')
                        {
                            if (closed.Contains(letter))
                            {
                                Console.WriteLine("{0} is no good because of {1}", car, letter);
                                return true;
                            }
                            if(closed.Count == 0)
                            {
                                if (begins.Contains(current))
                                {
                                    Console.WriteLine("{0} begins with problem in {1}", car, String.Join(",", cars));
                                    return true;
                                }
                                else
                                    begins.Add(current);
                            }
                            else
                            {
                                surrounded.Add(current);
                                if (usedInAnyPreviousCar.Contains(current))
                                {
                                    Console.WriteLine("{0} had surr already used in {1}", car, String.Join(",", cars));
                                    return true;
                                }
                            }
                            closed.Add(current);
                        }
                        current = letter;
                    }
                }
                if(car.Length > 1 && car[0] != car[car.Length-1])
                {
                    if (ends.Contains(car[car.Length - 1]))
                    {
                        Console.WriteLine("{0} ends badly {1}", car, String.Join(",", cars));
                        return true;
                    }
                    else
                        ends.Add(car[car.Length - 1]);
                }


                usedInAnyPreviousCar.UnionWith(car);
            }
            return false;
        }

        private long BruteForce(List<Tuple<int, int>> cars, bool[] usedCars, int usedCount, int lastLetter, int[] letterCounts, int[] lettersUsed)
        {
            if(usedCount == cars.Count)
                return 1;

            long count = 0;
            for(int i=0; i<cars.Count; i++)
            {
                var car = cars[i];
                var remaining = (lastLetter == -1 ? 0 : letterCounts[lastLetter] - lettersUsed[lastLetter]);
                if(!usedCars[i])
                {
                    if ((lastLetter == -1 && (car.Item1 == car.Item2 || letterCounts[car.Item1] == 1))
                        || lastLetter != -1 
                        && (
                            (lastLetter == car.Item1 && lastLetter == car.Item2)
                            || remaining == 0
                            || (remaining == 1 && car.Item1 == lastLetter))
                        )
                    {
                        lettersUsed[car.Item1]++;
                        lettersUsed[car.Item2]++;
                        usedCars[i] = true;
                        count += BruteForce(cars, usedCars, usedCount + 1, car.Item2, letterCounts, lettersUsed);
                        lettersUsed[car.Item1]--;
                        lettersUsed[car.Item2]--;
                        usedCars[i] = false;
                    }
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