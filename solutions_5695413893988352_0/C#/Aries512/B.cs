using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Reflection;
using System.Text;

class B
{

	void Run()
	{
		int casesCnt = ReadInt();
		for (int i = 1; i <= casesCnt; ++i)
		{
			Printf("Case #{0}: ", i);
			Solve();
		}
	}



	void Solve()
	{
		string a = ReadWord(), b = ReadWord();
		int min = int.MaxValue;
		string aa = a , bb = b;

		for (int i = 0; i <= 999; ++i)
		{
			for (int j = 0; j <= 999; ++j)
			{
				if (fits(i, a) && fits(j, b))
				{
					int diff = Math.Abs(i - j);
					if (diff < min)
					{
						min = diff;
						aa = getS(i, a);
						bb = getS(j, b);
					}
				}
			}
		}

		Println(aa, bb);
	}

	bool fits(int num, string s)
	{
		string ns = getS(num, s);
		if (ns.Length != s.Length) return false;
		for (int i = 0; i < s.Length; ++i)
		{
			if (s[i] != '?' && s[i] != ns[i]) return false;
		}
		return true;
	}

	string getS(int num, string s)
	{
		string ns = num.ToString();
		int diff = s.Length - ns.Length;
		for (int i = 0; i < diff; ++i)
		{
			ns = '0' + ns;
		}
		
		return ns;
	}




	//////////////////////////////////////////////////////////////////////////////////////////////////////

	static bool submit = !false;
	static string inFile = "D:/AAA/_gcj/" + MethodBase.GetCurrentMethod().DeclaringType.Name + "-small-attempt1.in";
	static string outFile = "D:/AAA/_gcj/" + MethodBase.GetCurrentMethod().DeclaringType.Name + ".out";



	bool HasMoreInput()
	{
		return !streamIn.EndOfStream;
	}

	bool HasMoreNonWhitespaceInput()
	{
		while (streamIn.Peek() <= ' ')
		{
			streamIn.Read();
			if (streamIn.EndOfStream)
			{
				return false;
			}
		}
		return true;
	}

	char ReadChar()
	{
		int r = streamIn.Read();
		return r < 0 ? '\0' : (char)r;
	}

	char ReadNonWhitespaceChar()
	{
		char c = ReadChar();
		while (c <= ' ' && c > '\0')
		{
			c = ReadChar();
		}
		return c;
	}

	string ReadWord()
	{
		StringBuilder sb = new StringBuilder();
		char c = ReadNonWhitespaceChar();
		while (c > ' ')
		{
			sb.Append(c);
			c = ReadChar();
		}
		return sb.ToString();
	}

	string ReadLine()
	{
		while (streamIn.Peek() <= ' ')
		{
			streamIn.Read();
		}
		return streamIn.ReadLine() ?? string.Empty;
	}

	int ReadInt()
	{
		int res = 0;
		char c = ReadNonWhitespaceChar();
		bool neg = false;
		if (c == '-')
		{
			neg = true;
		}
		else {
			res = c - 48;
		}
		c = ReadChar();
		while (c >= '0' && c <= '9')
		{
			res *= 10;
			res += c - 48;
			c = ReadChar();
		}
		return neg ? -res : res;
	}

	long ReadLong()
	{
		long res = 0;
		char c = ReadNonWhitespaceChar();
		bool neg = false;
		if (c == '-')
		{
			neg = true;
		}
		else {
			res = c - 48;
		}
		c = ReadChar();
		while (c >= '0' && c <= '9')
		{
			res *= 10L;
			res += c - 48L;
			c = ReadChar();
		}
		return neg ? -res : res;
	}

	double ReadDouble()
	{
		return double.Parse(ReadWord());
	}

	int[] ReadArrInt(int size)
	{
		int[] arr = new int[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = ReadInt();
		}
		return arr;
	}

	long[] ReadArrLong(int size)
	{
		long[] arr = new long[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = ReadLong();
		}
		return arr;
	}

	double[] ReadArrDouble(int size)
	{
		double[] arr = new double[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = ReadDouble();
		}
		return arr;
	}

	string[] ReadArrStr(int size)
	{
		string[] arr = new string[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = ReadWord();
		}
		return arr;
	}

	char[] ReadArrCh(int size)
	{
		char[] arr = new char[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = ReadNonWhitespaceChar();
		}
		return arr;
	}

	char[,] ReadArrCh(int rows, int columns)
	{
		char[,] arr = new char[rows, columns];
		for (int i = 0; i < rows; ++i) for (int j = 0; j < columns; ++j)
			{
				arr[i, j] = ReadNonWhitespaceChar();
			}
		return arr;
	}

	char[,] ReadArrChBorders(int rows, int columns, char border)
	{
		char[,] arr = new char[rows + 2, columns + 2];
		for (int i = 1; i <= rows; ++i) for (int j = 1; j <= columns; ++j)
			{
				arr[i, j] = ReadNonWhitespaceChar();
			}
		for (int i = 0; i < columns + 2; ++i)
		{
			arr[0, i] = border;
			arr[rows + 1, i] = border;
		}
		for (int i = 0; i < rows + 2; ++i)
		{
			arr[i, 0] = border;
			arr[i, columns + 1] = border;
		}
		return arr;
	}



	void Print(object obj, bool trailingSpace = true)
	{
		if (submit)
		{
			foreach (char c in obj.ToString())
			{
				streamOut.Write(c);
			}
			if (trailingSpace)
			{
				streamOut.Write(' ');
			}
		}
		else {
			Debug.Write(obj ?? "<null>");
			if (trailingSpace)
			{
				Debug.Write(' ');
			}
		}
	}

	void Println()
	{
		if (submit)
		{
			streamOut.WriteLine();
		}
		else {
			Debug.WriteLine(string.Empty);
		}
	}

	void Println(object obj)
	{
		Print(obj, false);
		Println();
	}

	void Printf(string format, params object[] args)
	{
		Print(string.Format(format, args), false);
	}

	void Print(params object[] items)
	{
		if (items == null)
		{
			Print(null, true);
		}
		else {
			for (int i = 0; i < items.Length; ++i)
			{
				Print(items[i], true);
			}
		}
	}

	void Println(params object[] items)
	{
		if (items == null)
		{
			Print(null, false);
		}
		else {
			for (int i = 0; i < items.Length; ++i)
			{
				Print(items[i], i != items.Length - 1);
			}
		}
		Println();
	}

	void Print<T>(ICollection<T> items)
	{
		foreach (T item in items)
		{
			Print(item, true);
		}
	}

	void Println<T>(ICollection<T> items)
	{
		int i = 0, cnt = items.Count;
		foreach (T item in items)
		{
			Print(item, i != cnt - 1);
			i++;
		}
		Println();
	}

	void Dbg(params object[] items)
	{
		if (!submit)
		{
			Print("###");
			Print(items);
			Println("###");
		}
	}

	void Dbg<T>(ICollection<T> items)
	{
		if (!submit)
		{
			Print("###");
			Print(items);
			Println("###");
		}
	}



	Stopwatch stopWatch = new Stopwatch();

	void StartTimer()
	{
		stopWatch.Restart();
	}

	void StopTimer()
	{
		stopWatch.Stop();
		Dbg("ELAPSED TIME:", stopWatch.ElapsedMilliseconds);
	}

	void Assert(bool condition)
	{
		if (!condition)
		{
			throw new Exception();
		}
	}



	static StreamReader streamIn;
	static StreamWriter streamOut;

	public static void Main(string[] args)
	{
		System.Threading.Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("en-US");

		if (submit)
		{
			streamIn = new StreamReader(inFile);
			streamOut = new StreamWriter(outFile);
			streamOut.AutoFlush = false;
		}
		else {
			streamIn = File.OpenText("../../in" + MethodBase.GetCurrentMethod().DeclaringType.Name + ".txt");
		}

		new B().Run();

		if (streamOut != null)
		{
			streamOut.Flush();
		}
	}
}



static class Extensions
{

	public static void For<T>(this IEnumerable<T> source, Action<int> action)
	{
		int idx = 0;
		foreach (T element in source)
		{
			action(idx++);
		}
	}

	public static void ForEach<T>(this IEnumerable<T> source, Action<T> action)
	{
		foreach (T item in source)
		{
			action(item);
		}
	}

	public static void ForEach<T>(this IEnumerable<T> source, Action<int, T> action)
	{
		int idx = 0;
		foreach (T element in source)
		{
			action(idx++, element);
		}
	}
}
