import java.util.*;
import java.io.*;
public class Round1A {
public static void main(String[] args) throws Exception{
	Scanner input = new Scanner(System.in);
	PrintWriter out = new PrintWriter("A.txt");
	int numCases = input.nextInt();
	for (int i = 0 ; i < numCases; i++) {
		String s = input.next();
		String res = helper(s);
	int index = i+1;
	out.print("Case #" + index + ": "+res+"\n");
	}
	input.close();
	out.close();
}
	private static String helper(String s) {
		char[] c = s.toCharArray();
		int len = s.length();
		String[] dp = new String[len];
		dp[0] = c[0]+"";
		for (int i=1; i < len; i++) {
			String pre = dp[i-1];
			if (c[i] >= dp[i-1].charAt(0)) {
				dp[i] = c[i] +  dp[i-1];
			}else {
				dp[i] = dp[i-1] + c[i];
			}
		}
		return dp[len-1];
	}

}