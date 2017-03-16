import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int no = 1; no <= T; no++) {
			long N = in.nextLong();
			long t = 1;
			long ans = 1;
			
			if (N % 10 == 0) {
				N--;
				ans += 1;
			}
			
			while (log10(N) > log10(t)) {
				String s = String.valueOf(t);
				s = s.substring(0, s.length() - 1) + '9';
				long e9 = Long.parseLong(s);
				ans += e9 - t;
				t = e9;

				if (s.length() > 1) {
					String rs = reverse(s);
					ans++;
					t = Long.parseLong(rs);
				}

				String next = "1";
				for (int i = 0; i < s.length(); i++) {
					next += '0';
				}
				long nextt = Long.parseLong(next);
				ans += nextt - t;
				t = nextt;
			}

			long min = N - t;
			char[] ccs = String.valueOf(t).toCharArray();
			char[] ncs = String.valueOf(N).toCharArray();
			for (long i = 0; i < ccs.length; i++) {
				ccs[ccs.length - 1 - (int) i] = ncs[(int) i];
				long mid1 = Long.parseLong(new String(ccs));
				long mid2 = Long.parseLong(reverse(new String(ccs)));
				long val = (mid1 - t) + 1 + (N - mid2);
				min = Math.min(val, min);
			}

			System.out.printf("Case #%d: %d%n", no, ans + min);
		}
	}

	private static long log10(long x) {
		long a = 0;
		while (x > 0) {
			x /= 10;
			a++;
		}
		return a;
	}

	private static String reverse(String s) {
		char[] cs = s.toCharArray();
		for (int i = 0; i < cs.length / 2; i++) {
			char tmp = cs[i];
			cs[i] = cs[cs.length - 1 - i];
			cs[cs.length - 1 - i] = tmp;
		}
		return new String(cs);
	}

}
