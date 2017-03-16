import java.util.*;

public class A {

	static Scanner sc = new Scanner(System.in);
	static HashSet<Character> set = new HashSet<Character>();
	private static void solve() {
		set.add('a');
		set.add('e');
		set.add('i');
		set.add('o');
		set.add('u');
		int T = sc.nextInt();
		for (int test = 1; test <= T; test++) {
			String in = sc.next();
			int n = sc.nextInt();
			long ans = doIt(in,n);
			System.out.println("Case #" + test + ": "+ans);

		}

	}
	
	private static long doIt(String in, int n) {
		int ct=0;int s = 0, e = n-1;
		for (int j = 0; j < in.length(); j++) {
			if(!set.contains(in.charAt(j))){
				ct++;
			}else {
				ct = 0;
				s = j+1;e = j+n;
			}
			if(ct == n)break;
		}
		long res = 0;
		if(ct==n) {res = (in.length()-e)*(s+1);
		
		return res+doIt(in.substring(s+1),n);
		}
		return 0;
	}

	
	public static void main(String[] ar){
		solve();
	}
}
