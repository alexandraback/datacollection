import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class BPancakes {
	
	public static int solve(char[] s, int end) {
		if (end < 0) {
			return 0;
		}
		if (s[end] == '+'){
			return solve(s, end - 1);
		}
		int ans = 1;
		int curr = 0;
		while (curr <= end && s[curr] == '+') {
			ans = 2;
			curr++;
		}
		flip(s, curr);
		flip(s, end +1);
		return ans + solve(s, end);
	}
	
	public static void flip (char[] s, int n) {
		boolean[] t = new boolean[n];
		for (int i = 0; i < n; i++) {
			t[i] = (s[i] == '+');
		}
		for (int i = 0; i < n; i++) {
			s[i] = t[n-i-1] ? '-' : '+';
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			System.out.printf("Case #%d: ", i);
			String s = sc.next();
			System.out.println(solve(s.toCharArray(), s.length() - 1));
		}
		sc.close();
	}
}
