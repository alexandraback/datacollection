import java.io.*;
import java.util.*;

class A {
	private final static double EPSILON = 0.00001;

	public static int gcd(int a, int b) {
	   	if (b==0) return a;
		return gcd(b,a%b);
	}



	public static int solve(int P, int Q) {
		if(P == 0) return 0;
		int res1 = 0;
		int g = gcd(P, Q);
		P /= g;
		Q /= g;
		int QTEMP = Q;
		while(QTEMP > 1) {
			if(QTEMP % 2 != 0) return -1;
			QTEMP /= 2;
		}

		while(P < Q) {
			P *= 2;
			res1 ++;
		}
		
		P = P - Q;
		int res2 = solve(P, Q);
		if(res1 > 40 || res2 > 40) return -1;
		if(res1 == -1 || res2 == -1) return -1;
		return res1;	
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = Integer.parseInt(sc.next());
		int test = 0;
		while(++test <= T) {
			String s = sc.next();
			String[] pArr = s.split("/");
			int P = Integer.parseInt(pArr[0]);
			int Q = Integer.parseInt(pArr[1]);
			
			int result = solve(P, Q);
			System.out.print("Case #" + test + ": ");
			if(result == -1) 
				System.out.println("impossible");
			else 
				System.out.println(result);
		}
	}
}
