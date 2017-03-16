import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class A {
	static int n;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int I = 1; I <= T; I++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			n = Integer.parseInt(st.nextToken());
			last = 0;
			long cnt = 0;
			Loop: for (int i = 0; i < s.length(); i++) {
				int curr = 0, start = i;
				for (; i < s.length(); i++) {
					if (isConsonant(s.charAt(i)))
						curr++;
					else {
						cnt += calculate(curr, start, s.length() - i);
						continue Loop;
					}
				}

				cnt += calculate(curr, start, s.length() - i);

			}

			System.out.printf("Case #%d: %d\n", I, cnt);
		}
	}

	static int last;

	private static long calculate(int count, int start, int end) {
		if (count < n)
			return 0;

		long sum = 0;
		if (end != 0) {
			sum += (count - n + 1) * end;
		}
		// from start
		if (start != 0) {
			sum += (count - n + 1) * (start - last);
			sum += (start - last) * end;
		}

		for (int i = n; i <= count; i++)
			sum += count - i + 1;

		last = start + count - n + 1;
		return sum;
	}

	private static boolean isConsonant(char c) {
		return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
	}
}
