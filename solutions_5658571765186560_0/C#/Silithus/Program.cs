// Submitted by Silithus @ Macau
using System;
using System.IO;
using System.Collections.Generic;
using CCF_XOI;

namespace GoogleCodeJam2015
{
	class QR_D
	{
		public struct one_block
		{
			public int bit, L, H, grp, offset;
		}
		List<one_block>[] blocks;

		protected int shrink(char[,] c)
		{
			int up, down, left, right;
			int i, j, v, ret;

			up = left = Int32.MaxValue;
			down = right = Int32.MinValue;

			for (i = 0; i < 7; i++)
				for (j = 0; j < 7; j++)
				{
					if (c[i, j] == '#')
					{
						up = Math.Min(up, i);
						down = Math.Max(down, i);
						left = Math.Min(left, j);
						right = Math.Max(right, j);
					}
				}

			for (i = ret = 0; i < 7; i++)
				for (j = 0; j < 7; j++)
				{
					if (c[i, j] == '#')
					{
						v = (i - up) * 4 + (j - left);
						ret |= (0x8000 >> v);
					}
				}

			return ret;
		}

		protected void bit_to_map(int bit, char[,] c)
		{
			int i, j, k;

			for (i = 0; i < 7; i++)
				for (j = 0; j < 7; j++)
					c[i, j] = ' ';

			for (i = 0, k = 0x8000; i < 4; i++, k >>= 4)
				for (j = 0; j < 4; j++)
					if ((bit & (k >> j)) != 0)
						c[3 + i, 3 + j] = '#';
		}

		protected one_block bit_to_block(int bit)
		{
			int i, j, k;
			one_block ob = new one_block();

			ob.bit = bit;
			ob.L = ob.H = 0;
			ob.offset = -1;

			for (i = 0, k = 0x8000; i < 4; i++, k >>= 4)
				for (j = 0; j < 4; j++)
					if ((bit & (k >> j)) != 0)
					{
						ob.H = Math.Max(ob.H, i + 1);
						ob.L = Math.Max(ob.L, j + 1);
						if (ob.offset == -1)
							ob.offset = j;
					}

			return ob;
		}

		protected void dump_bit(int bit)
		{
			int i, j, k;

			for (i = 0, k = 0x8000; i < 4; i++, k >>= 4)
			{
				for (j = 0; j < 4; j++)
					Console.Write(((bit & (k >> j)) == 0) ? ' ' : '#');
				Console.WriteLine();
			}
			Console.WriteLine("============");
		}

		protected HashSet<int> rotate_and_reflect(char[,] map)
		{
			HashSet<int> ret = new HashSet<int>();
			char[,] qmap = new char[7, 7];
			char[,] tmap = new char[7, 7];
			int i, j, t;

			for (t = 0; t < 4; t++)
			{
				for (i = 0; i < 7; i++)
					for (j = 0; j < 7; j++)
					{
						qmap[i, j] = map[j, 7 - i - 1];
						tmap[i, 7 - j - 1] = qmap[i, j];
					}

				ret.Add(shrink(tmap));
				ret.Add(shrink(qmap));

				for (i = 0; i < 7; i++)
					for (j = 0; j < 7; j++)
						map[i, j] = qmap[i, j];
			}

			return ret;
		}

		protected void gen_omino()
		{
			int r, c, nr, nc, d, i, grp_top;
			int[] mr = { 0, 1, 0, -1 }, mc = { 1, 0, -1, 0 };
			char[,] map = new char[7, 7], tmap = new char[7, 7];
			HashSet<int> set = new HashSet<int>();
			Dictionary<int, int> dict = new Dictionary<int, int>();

			grp_top = 0;
			map[3, 3] = '#';
			i = shrink(map);
			dict[i] = grp_top;
			one_block iob = bit_to_block(i);
			iob.grp = dict[i];
			blocks[1].Add(iob);

			for (i = 2; i <= 4; i++)
			{
				set.Clear();

				foreach (one_block oob in blocks[i - 1])
				{
					bit_to_map(oob.bit, tmap);

					for (r = 0; r < 7; r++)
						for (c = 0; c < 7; c++)
						{
							if (tmap[r, c] == '#')
							{
								for (d = 0; d < 4; d++)
								{
									nr = r + mr[d];
									nc = c + mc[d];
									if (tmap[nr, nc] != '#')
									{
										++grp_top;
										tmap[nr, nc] = '#';
										HashSet<int> hs = rotate_and_reflect(tmap);
										foreach (int w in hs)
										{
											dict[w] = grp_top;
											set.Add(w);
										}
										tmap[nr, nc] = ' ';
									}
								}
							}
						}
				}

				foreach (int vv in set)
				{
					one_block ob = bit_to_block(vv);
					ob.grp = dict[vv];
					blocks[i].Add(ob);
				}
			}

			/*for (i = 1; i <= 4; i++)
			{
				foreach (one_block ob in blocks[i])
				{
					Console.WriteLine("L={0}, H={1}, bit={2}, grp={3}", ob.L, ob.H, ob.bit, ob.grp);
					dump_bit(ob.bit);
				}
			}//*/
		}

		public int[] cnt;
		public int X, R, C, N, full;
		public bool poss;
		Dictionary<int, bool> grp_used;

		public void try_to_put(int bmap)
		{
			int i, j, k, v, nc;

			if (bmap == full)
			{
				for (i = 0; i < N; i++)
					if (cnt[i] > 0)
						grp_used[blocks[X][i].grp] = true;
				poss = true;
				return;
			}

			for (i = 0; i < R; i++)
				for (j = 0; j < C; j++)
				{
					if ((bmap & (0x8000 >> (i * 4 + j))) == 0)
					{
						for (k = 0; k < N; k++)
						{
							nc = j - blocks[X][k].offset;
							if ((i + blocks[X][k].H - 1 < R) && (nc >= 0) && (nc + blocks[X][k].L - 1 < C))
							{
								v = blocks[X][k].bit >> (i * 4 + nc);
								if ((bmap & v) == 0)
								{
									++cnt[k];
									try_to_put(bmap | v);
									--cnt[k];
								}
							}
						}
						return;
					}
				}
		}

		public void Solve(XOI xoi)
		{
			int i, j, k;

			X = xoi.ReadInt();
			R = xoi.ReadInt();
			C = xoi.ReadInt();

			blocks = new List<one_block>[5];
			for (i = 1; i <= 4; i++)
				blocks[i] = new List<one_block>();

			gen_omino();

			N = blocks[X].Count;
			cnt = new int[N];
			
			grp_used = new Dictionary<int, bool>();
			foreach (one_block ob in blocks[X])
				grp_used[ob.grp] = false;

			for (i = full = 0, k = 0x8000; i < R; i++, k >>= 4)
				for (j = 0; j < C; j++)
					full |= (k >> j);

			poss = false;
			try_to_put(0);

			if (!poss)
				xoi.o.WriteLine("RICHARD");
			else
			{
				bool ans = true;
				foreach (KeyValuePair<int, bool> kvp in grp_used)
					ans &= kvp.Value;

				xoi.o.WriteLine(ans ? "GABRIEL" : "RICHARD");
			}
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
				(new QR_D()).Solve(xoi);
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
