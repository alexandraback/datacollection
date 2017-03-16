using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
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

        struct Chest
        {
            public int Number;
            public int Type;
            public List<int> KeysInside;
        }

        struct InputData
        {
            public int Case;
            public List<Chest> Chests;
            public int[] KeysIHave;
        }

        private void Go()
        {
            var answers = GetInputData().AsParallel().Select(
                input =>
                {
                    bool[] isOpen = new bool[input.Chests.Count];
                
                    var solution = new List<int>(input.Chests.Count);
                    if (EnoughKeysCheck(input.Chests, input.KeysIHave)
                        && 
                        SolveRecurse(solution, input.Chests, input.KeysIHave, isOpen))
                    {
                        Console.WriteLine("{0} \t {1}", input.Case, String.Join(" ", solution.Select(c => c + 1)));
                        return new { Case = input.Case, Answer = String.Join(" ", solution.Select(c => c + 1)) };
                    }
                    else
                    {
                        Console.WriteLine("{0} \t {1}", input.Case, "IMPOSSIBLE");
                        return new { Case = input.Case, Answer = "IMPOSSIBLE" };
                    }
                }
                ).OrderBy(ans => ans.Case);

            foreach (var answer in answers)
            {
                m_io.WriteCase(answer.Answer);
            }
        }

        private IEnumerable<InputData> GetInputData()
        {
            int T = m_io.ReadInt();
            for (int t = 0; t < T; t++)
            {
                int K = m_io.ReadInt();
                int N = m_io.ReadInt();

                int[] keysIHave = new int[200];
                for (int k = 0; k < K; k++)
                {
                    keysIHave[m_io.ReadInt()]++;
                }
                List<Chest> chests = new List<Chest>(N);
                for (int n = 0; n < N; n++)
                {
                    chests.Add(new Chest { Number = n, Type = m_io.ReadInt(), KeysInside = Enumerable.Range(0, m_io.ReadInt()).Select(x => m_io.ReadInt()).ToList() });
                }
                yield return new InputData { Case = t, Chests = chests, KeysIHave = keysIHave };
            }
        }

        private bool EnoughKeysCheck(List<Chest> chests, int[] initialKeys)
        {
            int[] keyTally = new int[200];
            for (int i = 0; i < initialKeys.Length; i++)
            {
                keyTally[i] = initialKeys[i];
            }

            foreach (var chest in chests)
            {
                --keyTally[chest.Type];
                foreach (var key in chest.KeysInside)
                    ++keyTally[key];
            }
            return !keyTally.Any(i => i < 0);
        }

        private bool SolveRecurse(List<int> solution, List<Chest> chests, int[] keysIHave, bool[] isOpen)
        {
            if (solution.Count == chests.Count)
                return true;

            var dSet = new DisjointSet<int>(chests.Count);
            dSet.Add(0); //current location
            for (int i = 0; i < keysIHave.Length; i++)
                if (keysIHave[i] > 0)
                    dSet.MakeSameSet(0, -i); //keys are neg numbers
            foreach (var chest in chests.Where(c => !isOpen[c.Number]))
            {
                dSet.MakeSameSet(chest.Number, -chest.Type);
                foreach (var key in chest.KeysInside)
                    dSet.MakeSameSet(chest.Number, -key);
            }
            int primeSet = dSet.GetSetRepresentitiveKey(0);
            if (dSet.Any(kvp => kvp.Value != primeSet))
                return false;

            foreach (var chest in chests.Where(c => !isOpen[c.Number] && keysIHave[c.Type] > 0))
            {
                isOpen[chest.Number] = true;
                --keysIHave[chest.Type];
                foreach(var key in chest.KeysInside)
                    ++keysIHave[key];
                solution.Add(chest.Number);

                if (SolveRecurse(solution, chests, keysIHave, isOpen))
                    return true;

                solution.RemoveAt(solution.Count - 1);
                foreach (var key in chest.KeysInside)
                    --keysIHave[key];
                ++keysIHave[chest.Type];
                isOpen[chest.Number] = false;
            }
            return false;
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

    #region Disjoint Set Class
    class DisjointSet<K> : IEnumerable<KeyValuePair<K, K>>
    {
        private class DisjointSetNode<KN>
        {
            public DisjointSetNode<KN> Parent;
            public int Rank;
            public KN Key;
        }

        private Dictionary<K, DisjointSetNode<K>> m_Dictionary;

        public DisjointSet()
            : this(-1)
        {

        }

        public DisjointSet(int estimatedSize)
        {
            if (estimatedSize >= 0)
                m_Dictionary = new Dictionary<K, DisjointSetNode<K>>(estimatedSize);
            else
                m_Dictionary = new Dictionary<K, DisjointSetNode<K>>();
        }

        public void Add(K key)
        {
            AddInternal(key);
        }

        private DisjointSetNode<K> AddInternal(K key)
        {
            DisjointSetNode<K> added;
            if (!m_Dictionary.TryGetValue(key, out added))
            {
                added = new DisjointSetNode<K>() { Rank = 0, Key = key };
                added.Parent = added;
                m_Dictionary.Add(key, added);
            }
            return added;
        }

        public void MakeSameSet(K key1, K key2)
        {
            DisjointSetNode<K> disjointSetNode, disjointSetNode2;
            if (!m_Dictionary.TryGetValue(key1, out disjointSetNode))
                disjointSetNode = AddInternal(key1);
            if (!m_Dictionary.TryGetValue(key2, out disjointSetNode2))
                disjointSetNode2 = AddInternal(key2);

            MakeSameSet(disjointSetNode, disjointSetNode2);
        }


        /// <summary>
        /// Union() from http://en.wikipedia.org/wiki/Disjoint-set_data_structure
        /// </summary>
        /// <param name="disjointSetNode"></param>
        /// <param name="disjointSetNode2"></param>
        private void MakeSameSet(DisjointSetNode<K> disjointSetNode, DisjointSetNode<K> disjointSetNode2)
        {
            var root1 = Find(disjointSetNode);
            var root2 = Find(disjointSetNode2);
            if (root1 != root2)
            {
                if (root1.Rank < root2.Rank)
                    root1.Parent = root2;
                else if (root1.Rank > root2.Rank)
                    root2.Parent = root1;
                else
                {
                    root2.Parent = root1;
                    root1.Rank++;
                }
            }
        }

        public K GetSetRepresentitiveKey(K memberKey)
        {
            return Find(m_Dictionary[memberKey]).Key;
        }

        /// <summary>
        /// Find() from http://en.wikipedia.org/wiki/Disjoint-set_data_structure
        /// </summary>
        /// <param name="disjointSetNode"></param>
        private DisjointSetNode<K> Find(DisjointSetNode<K> disjointSetNode)
        {
            if (disjointSetNode.Parent == disjointSetNode)
                return disjointSetNode;
            else
            {
                disjointSetNode.Parent = Find(disjointSetNode.Parent);
                return disjointSetNode.Parent;
            }
        }

        #region IEnumerable<KeyValuePair<K,K>> Members

        public IEnumerator<KeyValuePair<K, K>> GetEnumerator()
        {
            foreach (var kvp in m_Dictionary)
            {
                yield return new KeyValuePair<K, K>(kvp.Key, Find(kvp.Value).Key);
            }
        }

        #endregion

        #region IEnumerable Members

        System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
        {
            throw new NotImplementedException();
        }

        #endregion
    }
    #endregion Disjoint Set Class
}
