// Submitted by Silithus @ Macau
using System;
using System.IO;
using System.Collections.Generic;
using CCF_XOI;

namespace GoogleCodeJam2015
{
	class QR_C
	{
		protected long[,] matrix = new long[5, 5] { { 0, 0, 0, 0, 0 }, { 0, 1, 2, 3, 4 }, { 0, 2, -1, 4, -3 },
		{ 0, 3, -4, -1, 2 }, { 0, 4, 3, -2, -1 } };

		public long calc(long a, long b)
		{
			bool neg = (a < 0) ^ (b < 0);
			long ret = matrix[Math.Abs(a), Math.Abs(b)];
			return neg ? -ret : ret;
		}

		public bool check(long l, long m, long r, long x)
		{
			x -= (l + m + r);
			return ((x >= 0) && (x % 4 == 0));
		}

		public void Solve(XOI xoi)
		{
			long L, X, i, j, k, t, middle, whole;
			long[] num, pre, suff, pre_need, suff_need;
			string s;

			L = xoi.ReadLong();
			X = xoi.ReadLong();
			s = xoi.ReadString();

			num = new long[L];
			pre = new long[L];
			pre_need = new long[L];
			suff = new long[L];
			suff_need = new long[L];

			for (i = 0; i < L; i++)
				num[i] = (s[(int)i] - 'i') + 2;

			for (i = 0, j = L - 1, whole = 1; i < L; i++, j--)
			{
				whole = calc(whole, num[i]);
				pre[i] = (i > 0 ? calc(pre[i - 1], num[i]) : num[i]);
				suff[j] = (j < L - 1 ? calc(num[j], suff[j + 1]) : num[j]);
			}

			for (i = 0, j = L - 1; i < L; i++, j--)
			{
				for (t = pre[i], k = 0; k < 4 && t != 2; k++) t = calc(whole, t);
				pre_need[i] = (k < 4 ? k : -1);
				for (t = suff[j], k = 0; k < 4 && t != 4; k++) t = calc(t, whole);
				suff_need[j] = (k < 4 ? k : -1);
			}

			/*
			xoi.o.WriteLine("whole={0}", whole);
			for (i = 0; i < L; i++)
			{
				xoi.o.WriteLine("pre,pre_need[{0}]={1}, {2}", i, pre[i], pre_need[i]);
				xoi.o.WriteLine("suff,suff_need[{0}]={1}, {2}", i, suff[i], suff_need[i]);
			}	//*/

			for (i = 0; i < L; i++)
			{
				if (pre_need[i] != -1)
				{
					for (j = 0, middle = 1; j < L; j++)
					{
						if (j >= i + 1 && j < L - 1)
						{
							middle = calc(middle, num[j]);
							if (middle == 3 && suff_need[j + 1] != -1)
							{
								if (check(pre_need[i], 0, suff_need[j + 1], X - 1))
								{
									xoi.o.WriteLine("YES");
									return;
								}
							}
						}

						if (suff_need[j] != -1)
						{
							t = (i < L - 1 ? suff[i + 1] : 1);
							long sf = (j > 0 ? pre[j - 1] : 1);
							for (k = 0; k < 4 && (calc(t, sf) != 3); k++)
								t = calc(t, whole);
							if (k < 4)
							{
								if (check(pre_need[i], k, suff_need[j], X - 2))
								{
									xoi.o.WriteLine("YES");
									return;
								}
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
