import java.io.*;
import java.math.*;
import java.util.*;

public class Main {

	private static void gao(char[] buff) {
		BigInteger x = new BigInteger(new String(buff));
		BigInteger y = x.multiply(x);
		String s = y.toString();
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				return;
			}
		}
		cache.add(y);
	}

	private static void dfs(int pos, char[] buff, int length) {
		if (pos == length / 2) {
			if (length % 2 == 0) {
				gao(buff);
			}
			else {
				for (int d = 0; d <= (buff[0] == '1' ? 2 : 1); ++d) {
					buff[pos] = (char)('0' + d);
					gao(buff);
				}
			}
			return;
		}
		if (pos == 0) {
			for (int d = 1; d <= 2; ++d) {
				buff[pos] = buff[length - 1 - pos] = (char)('0' + d);
				dfs(pos + 1, buff, length);
			}
		}
		else {
			for (int d = 0; d <= (buff[0] == '1' ? 1 : 0); ++d) {
				buff[pos] = buff[length - 1 - pos] = (char)('0' + d);
				dfs(pos + 1, buff, length);
			}
		}
	}

	private static void build() {
		cache = new ArrayList<BigInteger>();
		cache.add(BigInteger.valueOf(1L));
		cache.add(BigInteger.valueOf(4L));
		cache.add(BigInteger.valueOf(9L));
		for (int length = 2; length <= LENGTH / 2; ++length) {
			char[] buff = new char [length];
			dfs(0, buff, length);
		}
		StringBuffer sb = new StringBuffer();
		sb.append('9');
		for (int l = 0; l < LENGTH; ++l) {
			sb.append('0');
		}
		cache.add(new BigInteger(sb.toString()));
	}

	private static int bisearch(BigInteger value) {
		int down = 0, up = cache.size() - 1;
		int mid;
		while (down < up) {
			mid = (down + up) >> 1;
			if (cache.get(mid).compareTo(value) < 0) {
				down = mid + 1;
			}
			else {
				up = mid;
			}
		}
		return down;
	}

	private static List<BigInteger> cache;
	private static final int LENGTH = 14;

	public static void main(String[] args) throws IOException {
		build();
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(in.readLine());
		for (int cc = 1; cc <= tc; ++cc) {
			String[] parts = in.readLine().split(" ", -1);
			System.out.printf("Case #%d: %d\n",
					cc, bisearch((new BigInteger(parts[1])).add(BigInteger.ONE)) - bisearch(new BigInteger(parts[0])));
		}
	}

}
