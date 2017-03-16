// Submitted by Silithus @ Macau
using System;
using System.IO;
using System.Collections.Generic;
using CCF_XOI;

namespace GoogleCodeJam2015
{
	class QR_C
	{
		protected int[,] matrix = new int[5, 5] { {0,0,0,0,0}, { 0, 1, 2, 3, 4 }, { 0,  2, -1,4, -3 }, 
		{0,3,-4,-1,2},{0,4,3,-2,-1}};

		public int calc(int a, int b)
		{
			bool neg = (a < 0) ^ (b < 0);
			int ret = matrix[Math.Abs(a), Math.Abs(b)];
			return neg ? -ret : ret;
		}

		public void Solve(XOI xoi)
		{
			int L, X, LX, i, j, k, leftmost, middle;
			int[] num, rightmost;
			string s;

			L = xoi.ReadInt();
			X = xoi.ReadInt();
			s = xoi.ReadString();
			LX = L * X;
			num = new int[LX];
			rightmost = new int[LX];

			for (i = 0; i < LX; i++)
				num[i] = s[i % L] - 'i' + 2;

			rightmost[LX - 1] = num[LX - 1];
			for (i = LX - 2; i >= 0; i--)
				rightmost[i] = calc(num[i], rightmost[i + 1]);

			for (i = 0, leftmost = 1; i < LX - 2; i++)
			{
				leftmost = calc(leftmost, num[i]);

				if (leftmost == 2)
				{
					for (j = i + 1, middle = 1; j < LX - 1; j++)
					{
						middle = calc(middle, num[j]);

						if (middle == 3)
						{
							if (rightmost[j + 1] == 4)
							{
								xoi.o.WriteLine("YES");
								return;
							}
						}
					}
				}
			}

			xoi.o.WriteLine("NO");
		}
	}

	class GCJ2015
	{
		static void Main(string[] args)
		{
			XOI xoi = new XOI();
			int t, T = xoi.ReadInt();

			for (t = 1; t <= T; t++)
			{
				xoi.o.Write("Case #{0}: ", t);
				(new QR_C()).Solve(xoi);
			}
		}
	}
}

namespace CCF_XOI
{	// version 2014.06.20
	class XOI
	{
		protected StreamReader sr;
		public StreamWriter o;
		protected Queue<string> buf = new Queue<string>();
		public bool EOF = false;

		public XOI()
		{
			this.sr = new StreamReader(Console.OpenStandardInput());
			this.o = new StreamWriter(Console.OpenStandardOutput());
			this.o.AutoFlush = true;
		}

		public XOI(string in_path, string out_path)
		{
			this.sr = new StreamReader(in_path);
			this.o = new StreamWriter(out_path);
			this.o.AutoFlush = true;
		}

		public int ReadInt()
		{
			string s = this.GetNext();
			if (s == null) return -1;
			else return Int32.Parse(s);
		}

		public long ReadLong()
		{
			string s = this.GetNext();
			if (s == null) return -1;
			else return Int64.Parse(s);
		}

		public double ReadDouble()
		{
			string s = this.GetNext();
			if (s == null) return -1;
			else return Double.Parse(s, System.Globalization.CultureInfo.InvariantCulture);
		}

		public string ReadString()
		{
			string s = this.GetNext();
			return (s == null ? null : s);
		}

		public string ReadLine()
		{	// I will ignore current buffer and read a new line
			string s = "";
			while (s == "" && !this.EOF)
			{
				s = sr.ReadLine();
				this.EOF = (s == null);
			}
			return (this.EOF ? null : s);
		}

		protected string GetNext()
		{
			if (buf.Count == 0)
			{
				while (buf.Count == 0 && !this.EOF)
				{
					string s = sr.ReadLine();
					if (s == null)
						this.EOF = true;
					else
						foreach (string ss in s.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries))
							buf.Enqueue(ss);
				}
			}

			return (this.EOF ? null : buf.Dequeue());
		}
	}
}
