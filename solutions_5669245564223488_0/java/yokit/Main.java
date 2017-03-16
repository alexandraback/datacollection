import static java.lang.System.*;
import java.util.*;

public class Main {
	final public static int MOD = 1000000007;
	static int n;
	static String[] str;
	static boolean[] used;
	static int[] anscount;
	
	static void solve(int count, int[] num) {
		if(count >= n) {
			int c = 0;
			for(int i=0; i<n-1; i++) {
				if(str[num[i]].charAt(str[num[i]].length()-1) == str[num[i+1]].charAt(0)) 
					c++;
			}
			anscount[c]++;
		}
		
		for(int i=0; i<n; i++) {
			if(used[i]) continue;
			used[i] = true;
			
			num[count] = i;
			solve(count+1, num);
			
			used[i] = false;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(in);

		int setnum = sc.nextInt();
		for(int seti=1; seti<=setnum; seti++) {
			n = sc.nextInt();
			
			str = new String[n];
			for(int i=0; i<n; i++) str[i] = sc.next();
			
			anscount = new int[n];
			used = new boolean[n];
			solve(0, new int[n]);
			
			int ans = 0;
			for(int i=n-1; i>=1; i--) {
				if(anscount[i] != 0) {
					ans = anscount[i];
					break;
				}
			}
			out.println("Case #" + seti + ": " + (ans%MOD));
		}
	}

}
