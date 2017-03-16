import java.io.*;
import java.util.*;


public class B {
	
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("B-small.out"));
		int T = Integer.parseInt(in.readLine());
		for(int i=0; i<T; i++) {
			int N,X,Y;
			String s = in.readLine();
			StringTokenizer st = new StringTokenizer(s);
			N = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			Y = Integer.parseInt(st.nextToken());
			double ans = 0;
			
			int U = 0;
			int l = 0;
			for(int k=0; k<100000; k++) {
				U+=(4*k+1);
				if(U>=N) {
					U-=(4*k+1);
					l = 2*k;
					break;
				}
			}
			int a = N-U;
			int b = Y+1;
			int g = Math.abs(X)+Y;
			
			System.out.println("U="+U+" l="+l+" a="+a+" b="+b+" g="+g);
			
			if(g<l) ans = 1;
			else if(g>l) ans = 0;
			else if(a==2*l+1 && b>l) ans = 1;
			else if(a==2*l+1) ans = 1;
			else if(b>l) ans = 0;
			else if(a>=b+l) ans = 1;
			else if(a<b) ans = 0;
			else {
				for(int k=0; k<=a-b; k++) {
					ans+=C(a, k);
				}
			}
			
			out.println("Case #"+(i+1)+": "+ ans);
			
		}
		//for(int i=0; i<=100; i++) System.out.println(C(100, i));
		out.close();
	}
	
	public static double C(int a, int b) {
		if(b>a/2) return C(a, a-b);
		double ans = 1;
		for(int i=1; i<=b; i++) {
			ans*=(a-b+i);
			ans/=i*2;
			
		}
		for(int i=0; i<a-b; i++)
			ans/=2;
		return ans;
	}
}
