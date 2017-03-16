import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class A {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		StringTokenizer tok = new StringTokenizer(line);
		int T = ti(tok.nextToken());
		for (int ii = 0; ii < T; ii++) {
			tok = new StringTokenizer(br.readLine());
			String name = tok.nextToken();
			int n = ti(tok.nextToken());
			System.out.printf("Case #%d: %d\n", ii+1, solve(name, n));			
		}
	}

	static int solve(String name, int n) {
		int cnt = 0;
		int nl = name.length();
		for (int s = 0; s < nl; s++) {
			for (int t = s; t <= nl; t++) {
				char[] ss = name.substring(s, t).toCharArray();
				int tmp = count(ss);
				if ( tmp >= n ) {
					++cnt;
				}
			}
		}
		return cnt;
	}
	
	static Set<Character> vowels = new HashSet<>();
	static {
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');
	}

	private static int count(char[] ss) {
		int max = 0;
		int tmp = 0;
		for (char c : ss) {
			if ( vowels.contains(c) ) {
				tmp = 0;
			} else {
				++tmp;
				if ( tmp > max) {
					max = tmp;
				}
			}
		}
		return max;
	}

	static int ti(String s) {
		return Integer.parseInt(s);
	}

	static long tl(String s) {
		return Long.parseLong(s);
	}

}
