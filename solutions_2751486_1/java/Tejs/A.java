import java.util.*;
public class A {
	static boolean wovel(char c) {
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
	
	static int num[] = new int[1100000];
	static Scanner in;
	
	static void testcase(int t) {
		String s = in.next();
		int n    = in.nextInt();
		int N    = s.length();
		num[N-1] = !wovel(s.charAt(N-1)) ? 1 : 0;
		for(int i = N-2; i >= 0; --i) {
			num[i] = !wovel(s.charAt(i)) ? 1+num[i+1] : 0;
		}
		long sum = 0;//(((long)N)*((long)N+1))/((long)2);
		int i = N-1, j = N-1;
		for(; j >= 0; --j) {
			while(i >= 0 && (num[i] < n || j-i+1 < n)) --i;
			sum += i+1;
		}
		System.out.println("Case #"+t+": "+sum);
	}
	
	public static void main(String[] args) {
		in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t = 1; t <= T; ++t) testcase(t);
	}
}