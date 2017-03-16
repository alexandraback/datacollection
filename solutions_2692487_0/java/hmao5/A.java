import java.io.*;
import java.util.*;


public class A {
	
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt0.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-small.out"));
		int T = Integer.parseInt(in.readLine());
		for(int i=0; i<T; i++) {
			int[] motes;
			int N,A;
			String s = in.readLine();
			StringTokenizer st = new StringTokenizer(s);
			A = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			s = in.readLine();
			st = new StringTokenizer(s);
			motes = new int[N];
			for(int n=0; n<N; n++) {
				motes[n] = Integer.parseInt(st.nextToken());
			}
			int ans = 0;
			Arrays.sort(motes);
			
			int a=0, b=55555;
			if(A==1) a=N;
			else for(int n=0; n<N; n++) {
				//System.out.println(A+" "+n+" "+a+" "+b);
				b = Math.min(b, a+N-n);
				if(A<=motes[n]) {
					n--;
					a++;
					A = A*2-1;
				} else {
					A = A+motes[n];
				}
			}
			
			
			out.println("Case #"+(i+1)+": "+ Math.min(a, b));
			
		}
		out.close();
	}
}
