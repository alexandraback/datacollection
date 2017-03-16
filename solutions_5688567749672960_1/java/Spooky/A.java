package r1b2015;

import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;
import java.util.Scanner;

public class A
{

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in).useLocale(Locale.US);
		//PrintWriter out = new PrintWriter(System.out);
		PrintWriter out = new PrintWriter(new File("A.out"));
		
		for (int t = in.nextInt(), cs = 1; t > 0; t--, cs++) {
			out.print("Case #" + cs + ": ");
			
			long n = in.nextLong();
			
			//long test = solve(n, 0);
			
			if (n < 10) {
				out.println(n);
				continue;
			}
			
			long ten = 1, d = 1;
			long ans = 0;
			int k = numDigits(n);
			while (d < k) {
				ten *= 10;
				d++;
				ans += get(ten-1);
			}
			ans += get(n);
			//out.println(n + " -> " + ans + " " + test);
			out.println(ans);
		}
		
		out.flush();
	}
	
	static long get(long n) {
		if (n < 10) return n;
		String nn = n+"";
		int l = nn.length(), l2 = l/2;
		long k1 = reverse(Long.valueOf(nn.substring(0, l2)));
		long k2 = Long.valueOf(nn.substring(l2, l));
		if (k2 == 0 && k1 > 1) {
			return get(n-1) + 1;
		}
		return k1 + k2 + (k1 > 1 ? 1 : 0);
	}
	
	static int maxSwaps = 10;
	static Map<Long, Long> map = new HashMap<>();
	
	static long solve(long n, int s) {
		long key = (n << 16) + s;
		if (map.containsKey(key)) return map.get(key);
		
		if (n == 1) {
			map.put(key, 1L);
			return 1;
		}
		
		long res = s == maxSwaps ? n : solve(n-1, s) + 1;
		if (s < maxSwaps && n%10 != 0 && reverse(n) != n) res = Math.min(res, solve(reverse(n), s+1) + 1);
		
		map.put(key, res);
		return res;
	}
	
	static int numDigits(long n) {
		return (n+"").length();
	}
	
	static long sumDigits(long n, long ten) {
		int res = 0;
		String nn = n+"";
		res += nn.charAt(0) - '0';
		long x = Long.valueOf(nn.substring(1));
		if (x == 0) {
			return res + ten;
		} else {
			return res + x;
		}
	}
	
	static long reverse(long n) {
		long res = 0;
		while (n > 0) {
			res = res*10 + n%10;
			n /= 10;
		}
		return res;
	}
}
