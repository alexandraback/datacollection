import java.io.*;
import java.util.*;

public class A {

	private static long e(int t, long b) { return t==0 ? b : e(t-1, 2*b-1); }
	
	public static void main(String[] args) throws IOException {
		//Scanner cin = new Scanner(System.in);
		Scanner cin = new Scanner(new File("A-small-attempt0.in"));
	    int nCase = cin.nextInt();
	    for(int iCase = 1; iCase<=nCase; iCase++) {
	    	int t = cin.nextInt(), n = cin.nextInt(), ans;
	    	int[] a = new int[n], f = new int[n];
	    	long[] b = new long[n];
	    	for(int i = 0; i<n; i++)
	    		a[i] = cin.nextInt();
	    	if(t==1)
	    		ans = n;
	    	else {
	    		Arrays.sort(a);
	    		b[0] = t;
	    		for(int i = 0; i<n; i++) {
	    			while(e(f[i], b[i])<=a[i])
	    				f[i]++;
	    			if(i!=n-1)
	    				b[i+1] = e(f[i], b[i])+a[i];
	    		}
	    		for(int i = 1; i<n; i++)
	    			f[i] += f[i-1];
	    		ans = Math.min(n,  f[n-1]);
	    		for(int i = 1; i<n; i++)
	    			ans = Math.min(ans, n-i+f[i-1]);
	    		//System.out.println();
	    		//for(int i = 0; i<n; i++)
	    			//System.out.println(b[i]+" "+f[i]+" "+(n-i));
	    	}
	    	System.out.printf("Case #%d: %d\n", iCase, ans);
	    }
	}

}
