using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace B
{
	class Program
	{
		static void Main(string[] args)
		{
			new B().SolveAll();
		}

		class B : Solver
		{
			public override string SolveCase()
			{
				var N = RInt();
				var l = new Dictionary<int, int>();
				var tot = (2 * N - 1) * N;
				for (var i = 0; i < tot; i++)
				{
					var k = RInt();
					if (l.ContainsKey(k))
					{
						l[k]++;
					}
					else
					{
						l[k] = 1;
					}
				}
				var list = l.Where(x => (x.Value % 2) == 1).Select(x => x.Key).OrderBy(x => x).ToArray();
				return string.Join(" ", list);
			}
		}

		abstract class Solver
		{
			public FileStream _inFile, _outFile;
			public StreamReader _reader;
			public StreamWriter _writer;
			public Queue<string> _readQ = new Queue<string>();

			public void SolveAll()
			{
				_inFile = new FileStream(GetType().Name + ".in", FileMode.Open, FileAccess.Read);
				_reader = new StreamReader(_inFile);
				_outFile = new FileStream(GetType().Name + ".out", FileMode.Create, FileAccess.Write);
				_writer = new StreamWriter(_outFile);
				var T = RInt();
				for (var t = 1; t <= T; t++)
				{
					_writer.WriteLine($"Case #{t}: {SolveCase()}");
				}
				_writer.Flush();
				_writer.Close();
			}

			public abstract string SolveCase();

			public virtual char[] GetSeparators()
			{
				return new char[] { ' ' };
			}

			public int RInt()
			{
				EnsureQ();
				return int.Parse(_readQ.Dequeue());
			}

			public string RStr()
			{
				EnsureQ();
				return _readQ.Dequeue();
			}

			private void EnsureQ()
			{
				if (_readQ.Count == 0)
				{
					var s = _reader.ReadLine();
					foreach (var part in s.Split(GetSeparators()))
					{
						_readQ.Enqueue(part);
					}
				}
			}
		}
	}
}
