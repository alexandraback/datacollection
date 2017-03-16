import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class A {
	
	public long solve(BufferedReader in) throws IOException {
		String[] line = in.readLine().split(" ");
		char[] s = line[0].toCharArray(); int n = Integer.parseInt(line[1]);
		int[] run = new int[s.length];
		run[s.length - 1] = vow[s[s.length-1]] ? 0 : 1;
		for (int i = s.length - 2; i >= 0; i--) {
			if (vow[s[i]]) {
				run[i] = 0;
			} else {
				run[i] = run[i+1]+1;
			}
		}
		
		long total = 0;
		int lastStart = 0;
		for (int i = 0; i < s.length; i++) {
			if (run[i] >= n) {
				total += s.length - (i+n-1);
				if (lastStart < i) {
					total += (s.length - (i+n-1)) * (i - lastStart);
				}
				lastStart = i + 1;
			}
		}
		return total;
	}
	
	public static boolean vow[];
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		vow = new boolean[300];
		for (char c : new char[]{'a', 'e', 'i', 'o', 'u'}) { 
			vow[(int)c] = true;
		}
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for (int iT = 1; iT <= T; iT++) {
			long res = new A().solve(in);
			System.out.println("Case #" + iT + ": " + res);
		} 
	}
}
