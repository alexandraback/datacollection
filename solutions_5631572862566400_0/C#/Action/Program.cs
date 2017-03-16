using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C
{
	class Program
	{
		static void Main(string[] args)
		{
			new C().SolveAll();
		}

		class C : Solver
		{
			public override string SolveCase()
			{
				var N = RInt();
				var bff = new int[N + 1];
				var notInCircle = new bool[N + 1];
				for (var i = 1; i <= N; i++)
				{
					bff[i] = RInt();
					notInCircle[i] = true;
				}
				var bestFound = 0;
				var limit = 1;
				for (var i = 0; i < N; i++)
				{
					limit *= 2;
				}
				for (var subsetIndicator = 0; subsetIndicator < limit; subsetIndicator++)
				{
					var subset = new List<int>();
					var ss = subsetIndicator;
					for (var i = 1; ss > 0; i++)
					{
						if (ss % 2 == 1)
						{
							subset.Add(i);
						}
						ss /= 2;
					}
					if (subset.Count <= bestFound || subset.Count == 1)
					{
						continue;
					}
					var min = subset.Min();
					var ll = subset.Skip(1).ToList();
					GeneratePerm(ll, l =>
					{
						int bf = bff[min];
						if (bf != l[0] && bf != l[l.Count - 1])
						{
							return false;
						}
						for (var i = 0; i < l.Count; i++)
						{
							bf = bff[l[i]];
							if (bf == min && (i == 0 || i == l.Count - 1))
							{
								continue;
							}
							if (i < l.Count - 1 && bf == l[i + 1])
							{
								continue;
							}
							if (i > 0 && bf == l[i - 1])
							{
								continue;
							}
							return false;
						}
						bestFound = l.Count + 1;
						return true;
					});
				}
				Console.WriteLine("done");
				return bestFound.ToString();
			}
		}

		private static void GeneratePerm(List<int> list, Func<List<int>, bool> action)
		{
			var n = list.Count;
			int[] factorials = new int[n + 1];
			factorials[0] = 1;
			for (int i = 1; i <= n; i++)
			{
				factorials[i] = factorials[i - 1] * i;
			}
			var last = factorials[n];
			for (int i = 0; i < last; i++)
			{
				var onePermutation = new List<int>();
				var temp = new List<int>(list);
				int positionCode = i;
				for (int position = n; position > 0; position--)
				{
					int selected = positionCode / factorials[position - 1];
					onePermutation.Add(temp[selected]);
					positionCode = positionCode % factorials[position - 1];
					temp.RemoveAt(selected);
				}
				if (action(onePermutation))
				{
					return;
				}
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
