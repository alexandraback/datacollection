
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class p1 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	private static final Set<Character> vow = new HashSet<Character>();
	private static String solve(BufferedReader br) throws Exception {
		StringTokenizer st = new StringTokenizer(br.readLine());
		String s = st.nextToken(); 
		int n = Integer.parseInt(st.nextToken());
		int cnt=0;
		for(int i=0;i<s.length();i++) {
			int v=0;
			for(int j=0;j+i<s.length();j++) {
				String r=s.substring(i,i+j+1);
				int maxi=0;
				int cnti=0;
				for(int k=0;k<r.length();k++) {
					if(vow.contains(r.charAt(k))) {
						maxi = Math.max(maxi, cnti);
						cnti=0;
					}
					else {
						cnti++;
					}
				}
				maxi = Math.max(maxi, cnti);
				//debug(r, maxi);
				if(maxi >= n) {
					cnt++;
				}
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
