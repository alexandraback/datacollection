import java.util.*;

public class Problem2 {

	static double solve2(int buttons, Map<Character,Double> keys, String target) {
		int overlap = overlap(target);
		int max = Math.max(0,1 + (buttons - target.length()) / (target.length() - overlap));
		for(char c : target.toCharArray())
			if(! keys.keySet().contains(c))
				max = 0;
		//System.out.println(max);
		double[][] cache = new double[buttons+1][target.length()];
		for(int k=1; k <= buttons; k++)
			for(int i=0; i < target.length(); i++)
				for(char c : keys.keySet()) {
					if(c == target.charAt(i)) {
						double ev = (i+1==target.length() ? (1 + cache[k-1][overlap]) : cache[k-1][i+1]);
						cache[k][i] += keys.get(c)*ev;
					}
					else if(c == target.charAt(0))
						cache[k][i] += keys.get(c)*cache[k-1][1];
					else
						cache[k][i] += keys.get(c)*cache[k-1][0];
				}
		return max - cache[buttons][0];
	}
	
	static int overlap(String str) {
		char[] chars = str.toCharArray();
		int n = chars.length;
		for(int i=n-2,j; i >= 0; i--) {
			for(j=0; j < i && chars[n-1-j] == chars[i-j]; j++);
			if(j == i && chars[n-1-i] == chars[0]) return i+1;
		}
		return 0;		
	}

	static double solve(int k, int l, int s, String keys, String target) {
	
		Map<Character,Double> keys2 = new HashMap<>();
		char[] chars = keys.toCharArray();
		int len = chars.length;
		Arrays.sort(chars);
		for(int i=0, j; i < len; i+=j) {
			j=0;
			while(i+j < len && chars[i] == chars[i+j])
				j++;
			keys2.put(chars[i],(double) j / len);
		}
		//System.out.println(keys2);
		return solve2(s, keys2, target);
	}
	
	static void printSoln(int test, double soln) {
		System.out.println("Case #" + test + ": " + soln);
	}

	public static void main(String... args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int i=1; i <= T; i++) {
			int k = in.nextInt(), l = in.nextInt(), s = in.nextInt();
			double ans = solve(k,l,s, in.next(),in.next());
			printSoln(i,ans);
		}
		
		in.close();
	}
	
	static double bruteForce(int k, int l, int s, String keys, String target) {
		Map<Character,Double> keys2 = new HashMap<>();
		char[] chars = keys.toCharArray();
		int len = chars.length;
		Arrays.sort(chars);
		for(int i=0, j; i < len; i+=j) {
			j=0;
			while(i+j < len && chars[i] == chars[i+j])
				j++;
			keys2.put(chars[i],(double) j / len);
		}
		return helper2(s, "", keys2, target) - helper(s, "", keys2, target);
	}
	
	static double helper(int buttons, String str, Map<Character,Double> chars, String target) {
		double ev = 0;
		if(target.equals(str.substring(Math.max(0,str.length()-target.length()))))
			ev += 1;
		if(buttons == 0)
			return ev;
		for(char c : chars.keySet()) {
			ev += chars.get(c)*helper(buttons-1,str + c, chars, target);
		}
		return ev;
	}
	
	static double helper2(int buttons, String str, Map<Character,Double> chars, String target) {
		double ans = 0;
		if(target.equals(str.substring(Math.max(0,str.length()-target.length()))))
			ans += 1;
		if(buttons == 0)
			return ans;
		double ans2 = 0;
		for(char c : chars.keySet()) {
			ans2 = Math.max(ans2, helper2(buttons-1,str + c, chars, target));
		}
		return ans+ans2;
	}


}