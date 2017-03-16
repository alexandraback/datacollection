import java.io.*;
import java.util.*;

public class CodeJam2013_R1B_A {
	
	public static void main(String[] args) throws Exception{
//		Scanner sc = new Scanner(new FileReader("testA.in"));
		Scanner sc = new Scanner(new FileReader("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("A-small.out"));

		CodeJam2013_R1B_A obj = new CodeJam2013_R1B_A();
		int ntest = sc.nextInt();
		for(int test=1; test<=ntest; test++) {
			int A = sc.nextInt();
			int N = sc.nextInt();
			int[] v = new int[N];
			for(int i=0; i<N; i++)
				v[i] = sc.nextInt();
			
			int res = obj.calc(A, N, v);
			
			pw.println("Case #" + test + ": " + res);
			System.out.println("Case #" + test + ": " + res);
		}
		System.out.println("Finished.");
		sc.close();
		pw.close();
	}
	
	public int calc(long A, int N, int[] v) {
		if(A==1) return N;
		
		Arrays.sort(v);
		int absorbed = 0;
		while(absorbed<N && v[absorbed]<A) {
			A += v[absorbed];
			absorbed++;
		}
		
		int ans = N-absorbed;
		
		int add=0;
		while(absorbed<N) {
			while(v[absorbed]>=A) {
				A += A-1;
				add++;
			}
			while(absorbed<N && v[absorbed]<A) {
				A += v[absorbed];
				absorbed++;
			}
			ans = Math.min(ans, add+N-absorbed);
		}
		
		return ans;
	}
}
