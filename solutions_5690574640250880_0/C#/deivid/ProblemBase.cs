using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace GoogleCodeJam
{
    public abstract class ProblemBase
    {
        StreamReader _reader;
        StreamWriter _writer;

        public ProblemBase(string fileName)
        {
            _reader = System.IO.File.OpenText(fileName);
            _writer = System.IO.File.CreateText(Path.Combine(Path.GetDirectoryName(fileName), Path.GetFileNameWithoutExtension(fileName) + ".out"));
        }

        protected int ReadInt()
        {
            return int.Parse(_reader.ReadLine());
        }

        protected int[] ReadIntArray()
        {
            return ReadIntIEnumerable().ToArray();
        }

        protected List<int> ReadIntList()
        {
            return ReadIntIEnumerable().ToList();
        }

        protected IEnumerable<int> ReadIntIEnumerable()
        {
            return ReadStringArray().Select(s => int.Parse(s));
        }

        protected long ReadLong()
        {
            return long.Parse(_reader.ReadLine());
        }

        protected long[] ReadLongArray()
        {
            return ReadLongIEnumerable().ToArray();
        }

        protected List<long> ReadLongList()
        {
            return ReadLongIEnumerable().ToList();
        }

        protected IEnumerable<long> ReadLongIEnumerable()
        {
            return ReadStringArray().Select(s => long.Parse(s));
        }

        protected BigInteger ReadBigInteger()
        {
            return BigInteger.Parse(_reader.ReadLine());
        }

        protected BigInteger[] ReadBigIntegerArray()
        {
            return ReadBigIntegerIEnumerable().ToArray();
        }

        protected List<BigInteger> ReadBigIntegerList()
        {
            return ReadBigIntegerIEnumerable().ToList();
        }

        protected IEnumerable<BigInteger> ReadBigIntegerIEnumerable()
        {
            return ReadStringArray().Select(s => BigInteger.Parse(s));
        }

        protected string ReadString()
        {
            return _reader.ReadLine();
        }

        protected string[] ReadStringArray()
        {
            return ReadString().Split();
        }

        protected void WriteCaseResult(int caseNumber, string result)
        {
            _writer.Write("Case #");
            _writer.Write(caseNumber);
            _writer.Write(": ");
            _writer.WriteLine(result);
        }

        protected void ProduceOutput()
        {
            _writer.Flush();
            _writer.Close();
            _writer.Dispose();
            _reader.Close();
            _reader.Dispose();
        }

        protected virtual string SolveCase()
        {
            return null;
        }

        public virtual void Solve()
        {
            int N = ReadInt();
            for (int testCase = 1; testCase <= N; testCase++)
            {
                WriteCaseResult(testCase, SolveCase());
            }
            ProduceOutput();
        }
    }
}
