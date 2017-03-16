import java.text.*;
import java.io.*;
import java.util.*;
import java.lang.Math;

public class B
{

	public static long solve(int i1, int i2, long[] a, int[] A, long[] b, int[] B) {
		int aa = 0, bb = 0;
		if(i1 == a.length && i2 == b.length) return 0;
		if(i1 == a.length) aa = i1-1; else aa = i1;
		if(i2 == b.length) bb = i2-1; else bb = i2;
		//System.out.println(aa + " " + a.length + " "+ bb + " " +b.length);
		long count = 0;
		long[] a2 = Arrays.copyOf(a, a.length);
		long[] b2 = Arrays.copyOf(b, b.length);
		if(A[aa] == B[bb]) {
			
			count = Math.min(a2[aa], b2[bb]);
			a2[aa] -= count;
			b2[bb] -= count;
			//System.out.println(aa + " " + bb + " " + count);
		}
		long s1 = 0;
		long s2 = 0;
		if(i1 < a.length) s1 = solve(i1+1, i2, a2, A, b2, B);
		if(i2 < b.length) s2 = solve(i1, i2+1, a2, A, b2, B);
		return count + Math.max(s1, s2);
	}
	public static void main(String[] args) throws Exception
	{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String str;
		
		int T = Integer.parseInt(br.readLine());
		String[] ss;
		for(int t = 1; t <= T; t++) {
			System.out.print("Case #" + t + ": ");
			
			ss = br.readLine().split(" ");
			int N = Integer.parseInt(ss[0]);
			int M = Integer.parseInt(ss[1]);
			long[] a = new long[N];
			int[] A = new int[N];
			long[] b = new long[M];
			int[] B = new int[M];
			ss = br.readLine().split(" ");
			for(int i = 0; i < N; i++) {
				a[i] = Long.parseLong(ss[2*i]);
				A[i] = Integer.parseInt(ss[2*i+1]);
			}
			ss = br.readLine().split(" ");
			for(int i = 0; i < M; i++) {
				b[i] = Long.parseLong(ss[2*i]);
				B[i] = Integer.parseInt(ss[2*i+1]);
			}
			
	
			
			
			System.out.println(solve(0,0,a,A,b,B));
		}
		
	}
}