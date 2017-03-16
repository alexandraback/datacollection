import java.io.*;
import java.util.*;

public class B {
	
	public static int[] arr;
	public static int E,R,N;
	
	public static void main(String [] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("practice.in"));		
		PrintWriter pw = new PrintWriter(new FileWriter("practice.out"));		
		int T=sc.nextInt();
		for (int c1=0;c1<T;c1++) {			
			pw.print("Case #" + (c1+1) + ": ");
			System.out.println("Case #" + (c1+1) + ": ");			
			E=sc.nextInt();
			R=sc.nextInt();
			N=sc.nextInt();
			
			arr=new int[N];
			for (int c2=0;c2<N;c2++) {
				arr[c2] =sc.nextInt(); 
			}
			
			long maxval = 0;
			for (int c3=0;c3<=E;c3++) {
				for (int c4=c3;c4<=E;c4++) {
					maxval = Math.max(max(N-1,c3, c4), maxval);
				}
			}
			
			pw.print(maxval);			
			pw.println("");
		}
		pw.flush();
		pw.close();
		sc.close();
	}
	
	public static long max (int ind, int en, int ae) {
		
		if (en > ae) {
			return 0;
		}
		
		long val=arr[ind]*en;		
		if (ind == 0) {		
			return val;
		}
				
		long maxval = 0;		
		for (int c1=0;c1<ind;c1++) {						
			for (int c2=0;c2<=E;c2++) {
				for (int c3=c2;c3<=E;c3++) {
					if (ae == Math.min(E, c3-c2+(R*(ind-c1)))) {
						maxval = Math.max(max(c1,c2,c3)+val, maxval);
					}
				}				
			}
		}
		
		//System.out.println(maxval + " " + ind + " " + en + " " + ae);
		return maxval;
	}
}
