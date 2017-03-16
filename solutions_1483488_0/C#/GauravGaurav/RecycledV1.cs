using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Reflection;

namespace Recycled
{
	public class ScrollingNumber
	{
		private char[] _Number;
		public ScrollingNumber(long l)
			: this(l.ToString().ToCharArray())
		{

		}
		public ScrollingNumber(char[] number)
		{
			_Number = number;
		}

		public bool TryGetNext(out long nextNumber)
		{
			long originalNumber = long.Parse(new string(_Number));
			nextNumber = GetNextNumber();
			if (originalNumber != nextNumber)
			{
				return true;
			}
			return false;
		}

		public long GetNextNumber()
		{
			if (_Number.Length > 1)
			{
				char ch = _Number[_Number.Length - 1];
				for (int i = _Number.Length - 1; i > 0; i--)
				{
					_Number[i] = _Number[i - 1];
				}
				_Number[0] = ch;
			}

			long number = long.Parse(new string(_Number));
			return number;
		}

		internal long GetNumber()
		{
			long number = long.Parse(new string(_Number));
			return number;
		}
	}

	public class RecycledV1
	{
		public static void Main(string[] args)
		{
			new RecycledV1().Execute();
		}

		public void Execute()
		{
			using (var prob = new CodeJamProblem(@"\recycled.in"))
			{
				int n = prob.ReadLineInt32();

				for (int i = 0; i < n; i++)
				{
					long[] inputs = prob.ReadInt64Array();
					long start = inputs[0];
					long end = inputs[1];

					int numberOfRecycled = _GetRecycledNumbers(start, end);

					prob.OutputCase(numberOfRecycled);
				}
			}
		}


		private bool _IsInBetween(long number, long start, long end)
		{
			return (number >= start && number <= end);
		}

		private int _GetRecycledNumbers(long start, long end)
		{
			Dictionary<string, bool> recycledPairs = new Dictionary<string, bool>();
			for (long l = start; l <= end; l++)
			{

				ScrollingNumber scrollingNumber = new ScrollingNumber(l);

				long nextNumber = 0;
				while (scrollingNumber.TryGetNext(out nextNumber) && nextNumber != l)
				{
					if (_IsInBetween(nextNumber, start, end))
					{
						recycledPairs[l.ToString() + "-" + nextNumber.ToString()] = true;
					}
				}
			}
			return recycledPairs.Count() / 2;
		}
	}
	public class CodeJamProblem : IDisposable
	{
		private int _CaseNumber;

		private StreamReader _TextReader;
		private StreamWriter _TextWriter;

		private bool _IsDisposed = false;

		public CodeJamProblem(string inputFileName)
		{
			string currentDirectory = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
			string inputFileFullPath = string.Concat(currentDirectory, inputFileName);

			if (!File.Exists(inputFileFullPath))
			{
				throw new Exception(string.Format("{0} file doesn't exist", inputFileFullPath));
			}

			this.InputFileName = inputFileFullPath;
			this.OutputFileName = Path.ChangeExtension(this.InputFileName, ".out");

			this._TextReader = new StreamReader(this.InputFileName);
			this._TextWriter = new StreamWriter(this.OutputFileName);

			this._CaseNumber = 1;
			this.StartTime = Environment.TickCount;
		}

		public int StartTime { get; private set; }

		public int ElapsedTime { get; private set; }

		public int CurrentCaseNumber
		{
			get { return this._CaseNumber; }
		}

		public bool InputAvailable
		{
			get { return this._TextReader.Peek() != -1; }
		}

		public string InputFileName { get; private set; }

		public string OutputFileName { get; private set; }

		public void Dispose()
		{
			Dispose(true);
			GC.SuppressFinalize(this);
		}

		protected void Dispose(bool disposing)
		{
			if (!_IsDisposed)
			{
				if (disposing)
				{
					this.ElapsedTime = Environment.TickCount - this.StartTime;

					_TextReader.Dispose();
					_TextWriter.Dispose();

					Console.WriteLine("Elapsed time: {0:#,#0}ms", this.ElapsedTime);
					//Console.Beep();
					Console.ReadKey(true);
				}
			}

			_IsDisposed = true;
		}

		public void OutputCase(params object[] values)
		{
			var parts = new string[values.Length];
			for (int i = 0; i < parts.Length; i++)
				parts[i] = values[i].ToString();
			OutputCase(string.Join(" ", parts));
		}

		public void OutputCase()
		{
			OutputCase((string)null);
		}

		public void OutputCase(string value)
		{
			WriteLine("Case #{0:#0}: {1}", this._CaseNumber, value);
			this._CaseNumber++;
		}

		public void WriteArrays<T>(T[][] entries)
		{
			for (int i = 0; i < entries.Length; i++)
				WriteArray(entries[i]);
		}

		public void WriteArray<T>(T[] values)
		{
			var parts = new string[values.Length];
			for (int i = 0; i < parts.Length; i++)
				parts[i] = values[i].ToString();
			WriteLine(string.Join(" ", parts));
		}

		public void WriteLines(string[] lines)
		{
			for (int i = 0; i < lines.Length; i++)
				WriteLine(lines[i]);
		}

		public void WriteLine(string format, params object[] arg)
		{
			Console.WriteLine(format, arg);
			this._TextWriter.WriteLine(format, arg);
		}

		public void WriteLine(string line)
		{
			Console.WriteLine(line);
			this._TextWriter.WriteLine(line);
		}

		public T[][] ReadArrays<T>(int count, Func<string, T> converter)
		{
			var entries = new T[count][];
			for (int i = 0; i < entries.Length; i++)
				entries[i] = ReadArray(converter);
			return entries;
		}

		public T[] ReadArray<T>(Func<string, T> converter)
		{
			var parts = ReadParts();
			var values = new T[parts.Length];
			for (int i = 0; i < values.Length; i++)
				values[i] = converter(parts[i]);
			return values;
		}

		public short[][] ReadInt16Arrays(int count)
		{
			var entries = new short[count][];
			for (int i = 0; i < entries.Length; i++)
				entries[i] = ReadInt16Array();
			return entries;
		}

		public short[] ReadInt16Array()
		{
			var parts = ReadParts();
			var values = new short[parts.Length];
			for (int i = 0; i < values.Length; i++)
				values[i] = short.Parse(parts[i]);
			return values;
		}

		public int[][] ReadInt32Arrays(int count)
		{
			var entries = new int[count][];
			for (int i = 0; i < entries.Length; i++)
				entries[i] = ReadInt32Array();
			return entries;
		}

		public int[] ReadInt32Array()
		{
			var parts = ReadParts();
			var values = new int[parts.Length];
			for (int i = 0; i < values.Length; i++)
				values[i] = int.Parse(parts[i]);
			return values;
		}

		public long[][] ReadInt64Arrays(int count)
		{
			var entries = new long[count][];
			for (int i = 0; i < entries.Length; i++)
				entries[i] = ReadInt64Array();
			return entries;
		}

		public long[] ReadInt64Array()
		{
			var parts = ReadParts();
			var values = new long[parts.Length];
			for (int i = 0; i < values.Length; i++)
				values[i] = long.Parse(parts[i]);
			return values;
		}

		public double[][] ReadDoubleArrays(int count)
		{
			var entries = new double[count][];
			for (int i = 0; i < entries.Length; i++)
				entries[i] = ReadDoubleArray();
			return entries;
		}

		public double[] ReadDoubleArray()
		{
			var parts = ReadParts();
			var values = new double[parts.Length];
			for (int i = 0; i < values.Length; i++)
				values[i] = double.Parse(parts[i]);
			return values;
		}

		public string[] ReadParts()
		{
			return ReadLine().Split(' ');
		}

		public string[] ReadLines(int count)
		{
			var lines = new string[count];
			for (int i = 0; i < lines.Length; i++)
				lines[i] = ReadLine();
			return lines;
		}

		public short ReadLineInt16()
		{
			return short.Parse(ReadLine());
		}

		public int ReadLineInt32()
		{
			return int.Parse(ReadLine());
		}

		public long ReadLineInt64()
		{
			return long.Parse(ReadLine());
		}

		public double ReadLineDouble()
		{
			return double.Parse(ReadLine());
		}

		public string ReadLine()
		{
			return this._TextReader.ReadLine();
		}
	}
}
