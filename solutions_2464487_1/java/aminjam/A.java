import java.io.*;
import java.math.BigDecimal;
import java.util.*;

public class A {
	public static void main(String [] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("practice.in"));		
		PrintWriter pw = new PrintWriter(new FileWriter("practice.out"));		
		int T=sc.nextInt();
		for (int c1=0;c1<T;c1++) {			
			pw.print("Case #" + (c1+1) + ": ");
			System.out.println("Case #" + (c1+1) + ": ");			
			long r=sc.nextLong();
			long t=sc.nextLong();

			long k = 1;
			long sum = 2*r*k+2*k*k-k;
			while (sum <= t) {
				k*=2;
				sum = 2*r*k+2*k*k-k;
			}			
			
			long cc1=k/2,cc2=k;
			long m = (cc1+cc2)/2;
			
			//System.out.println(k+ " " + cc1+ " " + m + " " + cc2 + " " + sum);
			while (cc1<cc2-1) {
				sum = 2*r*m+2*m*m-m;
				//System.out.println(cc1+ " " + m + " " + cc2 + " " + sum);
				if (sum > t) {
					cc2=m;
				}
				else {
					cc1=m;
				}
				m = (cc1+cc2)/2;
			}

			pw.print(m);
/*			
			while (cc1<cc2) {
				long sum = 2*r*m+2*m*m-m;
				m=m-1;
				long sum2 = 2*r*m+2*m*m-m;
				if (sum > t && ) {
					
					break;
				}
			}
			
			
			for (c=1;c<Long.MAX_VALUE;c++) {
				long sum = 2*r*c+2*c*c-c;				
				if (sum > t) {
					pw.print(c-1);
					break;
				}					
			}
*/								
			pw.println("");
		}
		pw.flush();
		pw.close();
		sc.close();
	}	
}
