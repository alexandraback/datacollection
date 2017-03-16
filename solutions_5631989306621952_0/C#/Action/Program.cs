using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{
	class Program
	{
		static void Main(string[] args)
		{
			new A().SolveAll();
		}

		class A : Solver
		{
			public override string SolveCase()
			{
				var S = RStr();
				var s = "";
				foreach (var ch in S)
				{
					if (s.Length == 0)
					{
						s += ch;
					}
					else if ((s + ch).CompareTo(ch + s)<0)
					{
						s = ch + s;
					}
					else
					{
						s += ch;
					}
				}
				return s;
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
