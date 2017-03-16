import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p2 {

	public static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}

	public static void main(String... args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		solve(br, pw);
		pw.flush();
	}

	private static void solve(BufferedReader br, PrintWriter pw) throws Exception {
		int cases = Integer.parseInt(br.readLine());
		for (int c = 1; c <= cases; c++) {
			pw.printf("Case #%d: %s\n", c, solveCase(br, pw));
		}
	}

	private static Object solveCase(BufferedReader br, PrintWriter pw) throws Exception {
		int N = Integer.parseInt(br.readLine());
		String[]ch = new String[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i=0;i<N;i++) {
			ch[i]=st.nextToken();
		}
		
		for(String chu : ch) {
			if (!cons(chu)) {
				return 0;
			}
		}
		if (!allCons(ch)) {
			return 0;
		}
		
		Arrays.sort(ch);
		boolean used[]=new boolean[ch.length];
		long cnt = dfs(ch, used, -1, 0, new StringBuilder());
		
		return cnt;
	}

	private static long dfs(String[] ch, boolean[]used, int pos, int uc, StringBuilder sb) {
		if(uc == used.length) {
			String can = sb.toString();
			if (cons(can)) return 1;
			return 0;
		}
		
		long res = 0;
		for (int i=0;i<ch.length;i++) {
			if (used[i])continue;
			used[i]=true;
			
			sb.append(ch[i].charAt(0)).append(ch[i].charAt(ch[i].length()-1));
			res += dfs(ch, used, i, uc+1,sb);
			sb.deleteCharAt(sb.length()-1);
			sb.deleteCharAt(sb.length()-1);
			used[i]=false;
		}
		
		return res;
	}

	private static boolean allCons(String[] ch) {
		boolean[]s=new boolean[26];
		for (String chu : ch) {
			int st = chu.charAt(0)-'a';
			int en = chu.charAt(chu.length()-1)-'a';
			if (s[st] || s[en]) {
				return false;
			}
			boolean[]s2 = new boolean[26];
			for (int i=1;i<chu.length()-1;i++) {
				int r = chu.charAt(i)-'a';
				if (r == st || r == en) continue;
				if (s[r]) {
					return false;
				}
				s2[r]=true;
			}
			for (int i=0;i<s2.length;i++) {
				if (s2[i]) s[i]=true;
			}
		}
		return true;
	}

	private static boolean cons(String chu) {
		boolean[]s=new boolean[26];
		s[chu.charAt(0)-'a']=true;
		for(int i=1;i<chu.length();i++) {
			int r = chu.charAt(i)-'a';
			int p = chu.charAt(i-1)-'a';
			if (s[r] && r != p) {
				return false;
			}
			s[r]=true;
		}
		return true;
	}
}