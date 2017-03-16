
import java.io.*;
import java.util.*;

public class CodeJam2013_R1B_B {
	
	public static void main(String[] args) throws Exception{
//		Scanner sc = new Scanner(new FileReader("testB.in"));
		Scanner sc = new Scanner(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("B-small.out"));

		CodeJam2013_R1B_B obj = new CodeJam2013_R1B_B();
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			int N = sc.nextInt();
			int X = sc.nextInt();
			int Y = sc.nextInt();
			
			double res = obj.calc(N, X, Y);
			
			pw.println("Case #" + test + ": " + res);
			System.out.println("Case #" + test + ": " + res);
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
	}
	
	public double calc(int N, int X, int Y) {
		int L = Math.abs(X)+Y+1;
		int M = (L-1)*(L-2)/2;
		
		double ans=0;
		if(N <= M + Y) {
			ans=0;
		} else if(N > M + (L-1) + Y) {
			ans=1;
		} else {
			if(X==0) {
				if(N>=L*(L+1)/2) {
					ans=1;
				} else {
					ans=0;
				}
			} else {
				for(int i=Y+1; i<=N-M; i++) {
					ans += comb(N-M, i);
				}
				for(int i=0; i<N-M; i++)
					ans *= 0.5;
			}
		}
		
		return ans;
	}
	
	public double comb(int a, int b) {
		if(b>a-b)
			b = a-b;
		double ans = 1;
		for(int i=0; i<b; i++)
			ans = ans*(a-i)/(b-i);
		return ans;
	}
}
