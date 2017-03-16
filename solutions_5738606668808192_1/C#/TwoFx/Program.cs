using System;
using System.Linq;
using System.IO;
using System.Collections.Generic;
using System.Numerics;

namespace _16QA
{
	class Program
	{
		private const bool DEBUG = false;
		static void debug()
		{
			inf = new StreamReader("D:\\Users\\marku\\Downloads\\C-test.out");
			read();
			for (int i = 0; i < 500; i++)
			{
				var inp = readMany();
				var inp2 = inp.Skip(1).Select(x => int.Parse(x)).ToArray();
				var dd = inp[0].ToCharArray().Reverse().ToArray();
				for (ulong b = 2; b < 10; b++)
				{
					BigInteger n = 0;
					BigInteger bb = 1;
					for (int w = 0; w < dd.Length; w++)
					{
						if (dd[w] == '1') n += bb;
						bb *= b;
					}
					if (n % inp2[b - 2] != 0)
						throw new Exception();
				}
			}
			Console.WriteLine("All good");
			Console.ReadKey();
		}

		static string solveCase()
		{
			int length = 32;
			int numn = 500;
			int numfound = 0;
			string res = "";

			for (int i = (1 << (length - 1)) + 1; i < 1 << length; i += 2)
			{
				string binary = Convert.ToString(i, 2);
				string r = binary;
				bool error = false;
				for (ulong b = 2; b <= 10; b++)
				{
					BigInteger n = new BigInteger(0);
					//ulong n = 0;
					var dd = binary.ToCharArray().Reverse().ToArray();
					BigInteger bb = new BigInteger(1);
					
					for (int w = 0; w < dd.Length; w++)
					{
						if (dd[w] == '1') n += bb;
						checked
						{
							bb *= b;
						}
					}
					bool found = false;
					for (ulong q = 2; q <= 100; q++)
					{
						if (n % q == 0)
						{
							r += " " + q.ToString();
							found = true;
							break;
						}
					}
					if (!found)
					{
						error = true;
						break;
					}
				}
				if (!error)
				{
					res += Environment.NewLine;
					res += r;
					highlightedPrint(r);
					numfound++;
				}
				if (numfound == numn)
					break;
			}

			return res;
		}

		static void Main(string[] args)
		{
			if (DEBUG)
			{
				debug();
			}
			else
			{
				Initialize();
				SolveAll(solveCase);
			}
			Console.ReadKey();
		}

		private static StreamReader inf;
		private static StreamWriter outf;

		private delegate void o(string format, params object[] args);
		private static o Output;

		private static T read<T>()
		{
			return (T)Convert.ChangeType(inf.ReadLine(), typeof(T));
		}

		private static string read()
		{
			return inf.ReadLine();
		}

		private static T[] readMany<T>()
		{
			return readMany<T>(' ');
		}

		private static _[] readMany<_>(params char[] ___)
		{
			return read().Split(___).Select(__ => (_)Convert.ChangeType(__, typeof(_))).ToArray();
		}

		private static string[] readMany()
		{
			return readMany<string>();
		}

		private static T[][] readField<T>(int height, Func<char, T> map)
		{
			T[][] res = new T[height][];
			for (int _ = 0; _ < height; _++)
			{
				res[_] = read().Select(c => map(c)).ToArray();
			}
			return res;
		}

		private static char[][] readField(int height)
		{
			return readField(height, c => c);
		}

		private static T[][] readField<T>(int height, Dictionary<char, T> dic)
		{
			return readField(height, c => dic[c]);
		}

		public static void Initialize()
		{
			Console.ForegroundColor = ConsoleColor.Yellow;
			Console.Write("File name: ");
			string name = Console.ReadLine();
			inf = new StreamReader("D:\\Users\\marku\\Downloads\\" + name + ".in");
			outf = new StreamWriter("D:\\Users\\marku\\Downloads\\" + name + ".out");
			Console.ForegroundColor = ConsoleColor.White;
			Output = highlightedPrint;
			Output += outf.WriteLine;
		}

		private static void highlightedPrint(string format, params object[] args)
		{
			ConsoleColor prev = Console.ForegroundColor;
			Console.ForegroundColor = ConsoleColor.Green;
			Console.WriteLine(format, args);
			Console.ForegroundColor = prev;
		}

		public static void SolveAll(Func<string> calc)
		{
			int cases = int.Parse(inf.ReadLine());
			for (int _ = 1; _ <= cases; _++)
			{
				Output("Case #{0}:{1}", _, calc());
			}
			inf.Close();
			outf.Close();
			Console.ForegroundColor = ConsoleColor.Cyan;
			Console.WriteLine("Eureka!");
		}
	}
}