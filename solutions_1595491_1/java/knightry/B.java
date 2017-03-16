import java.util.Arrays;
import java.util.Scanner;


public class B {

	int N;
	int S;
	int p;
	int[] A = new int[100];
	
	int[][] memo = new int[100][100];
	
	boolean[][] normal = new boolean[11][31];
	boolean[][] surprise = new boolean[11][31];
	
	B() {
		for (int a=0; a<=10; ++a) {
			for (int b=a; b<=10 && b<=a+2; ++b) {
				for (int c=b; c<=10 && c<=a+2; ++c) {
					if (c-a<=1)
						normal[c][a+b+c]=true;
					else
						surprise[c][a+b+c]=true;
				}
			}
		}
		
		Scanner in=new Scanner(System.in);
		for (int T=in.nextInt(),TC=1; T-->0; ++TC) {
			N=in.nextInt();
			S=in.nextInt();
			p=in.nextInt();
			for (int i=0; i<N; ++i)
				A[i]=in.nextInt();
			for (int[] m : memo)
				Arrays.fill(m, -1);
			System.out.printf("Case #%d: %d%n",TC,go(0,0));
		}
	}
	
	int go(int at, int sur) {
		if (at==N)
			return 0;
		if (memo[at][sur]>-1)
			return memo[at][sur];
		
		int res=0;
		for (int max=0; max<=10; ++max) {
			int add=max>=p?1:0;
			if (normal[max][A[at]])
				res=Math.max(res,add+go(at+1,sur));
			if (sur<S && surprise[max][A[at]])
				res=Math.max(res,add+go(at+1,sur+1));
		}
		return memo[at][sur]=res;
	}
	public static void main(String[] args) {
		new B();
	}

}
