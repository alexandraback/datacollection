using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace ConsoleApplication2
{
	class С
	{
		public void Solve()
		{
			var n = 16;
			var j = 50;
			var primes = new List<int> {2,3,5,7,11,13,17,19};

			using (var sw = new StreamWriter("C-small.out"))
			{
				sw.WriteLine("Case #1:");
				var proveList = Enumerable.Repeat(0, 9).ToList();
				for (var q = 0; q < 1 << (n - 2); ++q)
				{
					for (var @base = 2; @base < 11; ++@base)
					{
						var found = false;
						foreach (var prime in primes)
						{
							if (@base % prime == 0)
								continue;
							var res = BinPowMod(@base, n - 1, prime) + 1;
							var qCopy = q;
							var i = 0;
							while (qCopy != 0)
							{
								if (qCopy%2 == 1)
									res += BinPowMod(@base, i + 1, prime);
								qCopy /= 2;
								++i;
							}
							if (res%prime == 0)
							{
								found = true;
								proveList[@base - 2] = prime;
								break;
							}
						}
						if (!found)
							break;
						if (@base == 10)
						{
							var qString = string.Join("", Enumerable.Range(0, n - 2).Select(p => (q >> p) & 1).Reverse());
							sw.WriteLine("1{0}1 {1}", qString, string.Join(" ", proveList));
							--j;
							if (j == 0)
								return;
						}
					}
				}
				sw.WriteLine("Need {0} more", j);
			}
		}

		private Dictionary<string, int> binPowModCache = new Dictionary<string, int>(); 
		private int BinPowMod(int value, int pow, int mod)
		{
			if (pow == 0)
				return 1;
			var key = $"{value}^{pow}%{mod}";
			if (binPowModCache.ContainsKey(key))
				return binPowModCache[key];
			var temp = BinPowMod(value, pow/2, mod);
			var res = temp*temp%mod;
			if (pow%2 == 1)
				res = res*value%mod;
			binPowModCache[key] = res;
			return res;
		}
	}
}
