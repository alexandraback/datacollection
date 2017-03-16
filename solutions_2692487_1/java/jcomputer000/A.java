import java.util.*;
public class A {
	int[] V;
	final int max = 1000000;
	int[][] memo;
	int foo(int pos, int size) {
		if (size > max)
			return 0;
		if (pos == V.length)
			return 0;
		if (memo[pos][size] != -1)
			return memo[pos][size];
		int ans = (int)1e9;
		if (size > V[pos])
			ans = foo(pos+1,size+V[pos]);
		else if (size > 1) {
			int s2 = size;
			int a2 = 0;
			while(s2 <= V[pos]) {
				a2++;
				s2+=s2-1;
			}
			ans = foo(pos,s2)+a2;
		}
		ans = Math.min(ans,foo(pos+1,size)+1);
		return memo[pos][size] = ans;
	}
	A(Scanner in) {
		int T = in.nextInt();
		for (int t=0; t<T; t++) {
			int A = in.nextInt();
			int N = in.nextInt();
			V = new int[N];
			for (int i=0; i<N; i++)
				V[i] = in.nextInt();
			Arrays.sort(V);
			memo = new int[N][max+1];
			for (int[] x: memo)
				Arrays.fill(x,-1);
			System.out.printf("Case #%d: %d\n",t+1,foo(0,A));
		}
	}
	public static void main(String[] args) {
		new A(new Scanner(System.in));
	}
}
