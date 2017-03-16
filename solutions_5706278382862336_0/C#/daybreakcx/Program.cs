using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ {
	class Program {
		public static long gcd(long x, long y) {
			long ret;
			while ((ret = x % y) != 0) {
				x = y;
				y = ret;
			}
			return y;
		}

		public static int calc(long s) {
			int ret;
			for (ret = 0; ((long)1 << ret) <= s; ++ret)
				;
			return ret;
		}

		static void Main(string[] args) {
			using (StreamWriter sw = new StreamWriter(args[1])) {
				using (StreamReader sr = new StreamReader(args[0])) {
					int tn = int.Parse(sr.ReadLine());
					string line;
					for (int ti = 1; ti <= tn; ++ti) {
						sw.Write("Case #{0}: ", ti);
						string[] tokens = sr.ReadLine().Trim().Split('/');
						long p = long.Parse(tokens[0]), q = long.Parse(tokens[1]), g = gcd(p, q);
						p /= g;
						q /= g;
						if ((q & (q - 1)) != 0)
							sw.WriteLine("impossible");
						else
							sw.WriteLine((calc(q) - calc(p)).ToString());
					}
					sr.Close();
				}
				sw.Close();
			}
		}
	}
}
