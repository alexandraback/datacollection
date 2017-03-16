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
		static StreamReader inp;
		static StreamWriter oup;
		static bool[] a, b, k, ones, zeros;
		static long[] pows;

		static void Main(string[] args)
		{
			inp = new StreamReader(new FileStream("B.in", FileMode.Open, FileAccess.Read));
			oup = new StreamWriter(new FileStream("B.out", FileMode.Create, FileAccess.Write));
			var line = inp.ReadLine();
			var t = int.Parse(line);
			for (int i = 0; i < t; i++)
			{
				line = inp.ReadLine();
				var parts = line.Split(' ');
				var A = int.Parse(parts[0]);
				var B = int.Parse(parts[1]);
				var K = int.Parse(parts[2]);

				a = new bool[32];
				b = new bool[32];
				k = new bool[32];
				pows = new long[32];
				ones = new bool[32];
				zeros = new bool[32];

				var v = 1;
				var max = 0;
				for (var j = 0; j < 32; j++, v *= 2)
				{
					a[j] = (A & v) != 0;
					b[j] = (B & v) != 0;
					k[j] = (K & v) != 0;
					if (a[j] || b[j] || k[j])
					{
						max = j;
					}
					pows[j] = v;
					ones[j] = true;
					zeros[j] = false;
				}

				var sum = Process(max, a, b, k, false, false);

				oup.WriteLine("Case #" + (i + 1).ToString() + ": " + sum.ToString());
			}
			oup.Close();
		}

		static long Get(int p, bool[] bits)
		{
			long sum = 0;
			long v = 1;
			for (int i = 0; i <= p; i++, v *= 2)
			{
				if (bits[i])
				{
					sum += v;
				}
			}
			return sum;
		}

		private static long Process(int p, bool[] a, bool[] b, bool[] k, bool aeq, bool beq)
		{
			var cases = 0;
			//{
			//	var aaa = Get(p, a);
			//	if (aeq)
			//	{
			//		aaa++;
			//	}
			//	var bbb = Get(p, b);
			//	if (beq)
			//	{
			//		bbb++;
			//	}
			//	var kkk = Get(p, k);
			//	for (int i = 0; i < aaa; i++)
			//	{
			//		for (int j = 0; j < bbb; j++)
			//		{
			//			if ((i & j) < kkk)
			//			{
			//				cases++;
			//			}
			//		}
			//	}
			//}


			if (p == 0)
			{
				if (k[p])
				{
					if (a[p] && b[p])
					{
						var res = (aeq ? 2 : 1) * (beq ? 2 : 1) - (aeq && beq ? 1 : 0);
						if (res != cases)
						{

						}
						return res;
					}
					if (a[p])
					{
						var res = (aeq ? 2 : 1) * (beq ? 1 : 0);
						if (res != cases)
						{
							return res;
						}
					}
					if (b[p])
					{
						var res = (aeq ? 1 : 0) * (beq ? 2 : 1);
						if (res != cases)
						{
							return res;
						}
					}
					var ress = (aeq ? 1 : 0) * (beq ? 1 : 0);
					if (ress != cases)
					{

					}
					return ress;
				}
				if (0 != cases)
				{

				}
				return 0;
			}
			var aa = Get(p - 1, a);
			if (aeq)
			{
				aa++;
			}
			var bb = Get(p - 1, b);
			if (beq)
			{
				bb++;
			}
			long all = pows[p];
			if (k[p])
			{
				if (a[p] && b[p])
				{
					var res = Process(p - 1, a, b, k, aeq, beq) + aa * all + bb * all + all * all;
					if (res != cases)
					{

					}
					return res;
				}
				if (a[p])
				{
					var res = all * bb + aa * bb;
					if (res != cases)
					{

					}
					return res;
				}
				if (b[p])
				{
					var res = aa * all + aa * bb;
					if (res != cases)
					{

					}
					return res;
				}
				var res12 = aa * bb;
				if (res12 != cases)
				{

				}
				return res12;
			}
			else
			{
				if (a[p] && b[p])
				{
					var res = Process(p - 1, ones, ones, k, true, true) + Process(p - 1, ones, b, k, true, beq) + Process(p - 1, a, ones, k, aeq, true);
					if (res != cases)
					{

					}
					return res;
				}
				if (a[p])
				{
					var res = Process(p - 1, a, b, k, aeq, beq) + Process(p - 1, ones, b, k, true, beq);
					if (res != cases)
					{

					}
					return res;
				}
				if (b[p])
				{
					var res = Process(p - 1, a, b, k, aeq, beq) + Process(p - 1, a, ones, k, aeq, true);
					if (res != cases)
					{

					}
					return res;
				}
				var res11 = Process(p - 1, a, b, k, aeq, beq);
				if (res11 != cases)
				{

				}
				return res11;
			}
		}
	}
}