import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
	static int n;
	static String words[] = new String[105];
	static boolean letters[][];
	static long perm[] = new long[101];
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder out = new StringBuilder();
		StringTokenizer st;
		boolean valid = true;
		init();
		int numcases = Integer.parseInt(br.readLine().trim());
		for (int casenum = 1; casenum <= numcases; casenum++) {
			valid = true;
			n = Integer.parseInt(br.readLine().trim());
			st = new StringTokenizer(br.readLine());
			out.append(String.format("Case #%d: ", casenum));
			for (int i = 0; i < n; i++) {
				char temp[] = st.nextToken().toLowerCase().toCharArray();
				StringBuilder sb = new StringBuilder();
				int len = temp.length;
				char curr;
				for (int j = 0; j < len; ) {
					curr = temp[j];
					sb.append(curr);
					int k = j + 1;
					while (k < len) {
						if (temp[k] == curr)
							k++;
						else
							break;
					}
					j = k;
				}
				words[i] = sb.toString();
				boolean occur[] = new boolean[26];
				len = words[i].length();
				for (int j = 1; j < len - 1; j++) {
					curr = words[i].charAt(j);
					if (occur[curr - 'a'])
						valid = false;
					occur[curr - 'a'] = true;
				}
			}
			int start[] = new int[26];
			int end[] = new int[26];
			int middle[] = new int[26];
			int next[] = new int[26];
			Arrays.fill(next, -1);
			int wordlen[] = new int[26];
		if (valid) {
			//System.out.println(casenum);
			letters = new boolean[n][26];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < words[i].length(); j++)
					for (int k = 0; k < n; k++)
						if (i != k)
							letters[k][words[i].charAt(j) - 'a'] = true;
			}
			int c, d;
			for (int i = 0; i < n && valid; i++) {
				//System.out.println(words[i]);
				if (words[i].length() > 1) {
					c = (words[i].charAt(0) - 'a');
					if (start[c] > 0)
						valid = false;
					start[c]++;
					d = (words[i].charAt(words[i].length() - 1) - 'a');
					if (end[d] > 0)
						valid = false;
					end[d]++;
					next[c] = d;
				}
				else
					middle[words[i].charAt(0) - 'a']++;
				for (int j = 1; j < words[i].length() - 1; j++)
					if (letters[i][words[i].charAt(j) - 'a'])
						valid = false;
			}
		}
		long arrangements = 1;
		int count = 0;
		if (valid) {
			boolean used[] = new boolean[26];
			for (int i = 0; i < 26; i++) {
				if (end[i] == 0 && start[i] == 1) {
					count++;
					used[i] = true;
					arrangements = (arrangements * perm[middle[i]]) % 1000000007;
					int j = next[i];
					wordlen[i] = 2;
					while (!(end[j] == 1 && start[j] == 0)) {
						wordlen[i]++;
						used[j] = true;
						arrangements = (arrangements * perm[middle[j]]) % 1000000007;
						j = next[j];
					}
					used[j] = true;
					arrangements = (arrangements * perm[middle[j]]) % 1000000007;
				}
			}
			for (int i = 0; i < 26; i++)
				if (middle[i] > 0 && !used[i]) {
					arrangements = (arrangements * perm[middle[i]]) % 1000000007;
					count++;
					used[i] = true;
				}
			for (int i = 0; i < 26; i++)
				if (!used[i] && start[i] == 1 && end[i] == 1) {
					valid = false;
					break;
				}
		}
			if (valid)
				arrangements = (arrangements * perm[count]) % 1000000007;
			else
				arrangements = 0;
			out.append(arrangements);
			out.append('\n');
		}
		System.out.print(out);
	}
	static void init() {
		perm[0] = 1;
		perm[1] = 1;
		for (int i = 2; i <= 100; i++)
			perm[i] = (perm[i - 1] * i) % 1000000007;
	}
}
