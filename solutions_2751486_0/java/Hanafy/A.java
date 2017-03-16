import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int I = 1; I <= T; I++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String s = st.nextToken();
			int n = Integer.parseInt(st.nextToken());

			int cnt = 0;
			for (int i = 0; i < s.length(); i++)
				Loop1: for (int j = i + n; j <= s.length(); j++) {
					String sub = s.substring(i, j);
						Loop2:for (int x = 0; x <= sub.length() - n; x++) {
							int curr = 0;
							for (int y = 0; y < n; y++) {
								if (isConsonant(sub.charAt(x + y)))
									curr++;
								else
									continue Loop2;
							}
							cnt++;
							continue Loop1;
						}
				}

			System.out.printf("Case #%d: %d\n", I, cnt);
		}
	}

	private static boolean isConsonant(char c) {
		return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
	}
}
