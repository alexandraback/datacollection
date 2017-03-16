package round1B.java;

import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for(int caseno = 1; caseno <= cases; caseno++)
			System.out.printf("Case #%d: %s%n", caseno, new C().solve(input));
	}

	String solve(Scanner input) {
		int n = input.nextInt();
		long[] d = new long[2], m = new long[2];
		
		int num = 0;
		for(int i = 0; i < n; i++) {
			int di = input.nextInt(), hi = input.nextInt(), mi = input.nextInt();
			for(int j = 0; j < hi; j++)
			{
				d[num] = di;
				m[num++] = mi+j; 
			}
		}
		
		
		if(num == 1)
			return ""+0;
		
		if(d[0] > d[1]) {
			long s = d[0]; d[0] = d[1]; d[1] = s;
			s = m[0]; m[0] = m[1]; m[1] = s;
		}
		
		int res;
		if(m[0] == m[1])
			res = 0;
		else if(m[0] > m[1])
			res = d[0]*(m[0]-m[1]) + m[1]*(360-d[1]+d[0]) > 360*(m[0]-m[1]) ? 0 : 1;
		else
			res = d[1]*(m[1]-m[0]) + m[0]*(360-d[0]+d[1]) > 360*(m[1]-m[0]) ? 0 : 1;
		
		return "" + res;
	}
}
