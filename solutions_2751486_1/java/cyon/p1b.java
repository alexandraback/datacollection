
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class p1b {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	private static final Set<Character> vow = new HashSet<Character>();
	private static String solve(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		String s = st.nextToken(); 
		int n = Integer.parseInt(st.nextToken());
		long cnt=0;
		int cnti=0;
		int li=0;
		for(int i=0;i<s.length();i++) {
			if(!vow.contains(s.charAt(i))) {
				cnti++;
				if(cnti >= n) {
					long bf=i-li-n+1;
					long af=s.length()-i-1;
					li=Math.min(i-n+2,s.length());
					//debug(i,s.substring(0,i+1),cnt,bf,af,li);
					cnt+=bf;
					cnt+=af;
					cnt+=bf*af+1;
				}
			}
			else {
				cnti=0;
			}
		}
		return cnt+"";
	}

	public static void main(String[] rags) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		vow.add('a');
		vow.add('e');
		vow.add('i');
		vow.add('o');
		vow.add('u');
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
}
