// Submitted by Silithus @ Macau
using System;
using System.Collections.Generic;
using System.IO;
using CCF_XOI;

namespace GoogleCodeJam2014
{
	class R1B_B
	{
		public void Solve(XOI xoi)
		{
			int i, j, A, B, K;
			long ans = 0;

			A = xoi.ReadInt();
			B = xoi.ReadInt();
			K = xoi.ReadInt();

			for (i = 0, ans = 0; i < A; i++)
				for (j = 0; j < B; j++)
					if ((i & j) < K) ans++;

			xoi.o.WriteLine(ans);
		}
	}

	class GCJ2014
	{
		static void Main(string[] args)
		{
			XOI xoi = new XOI();
			int t, T = xoi.ReadInt();

			for (t = 1; t <= T; t++)
			{
				xoi.o.Write("Case #{0}: ", t);
				(new R1B_B()).Solve(xoi);
			}
		}
	}
}

namespace CCF_XOI
{	// version 2014.02.07
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
			else return Double.Parse(s);
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
