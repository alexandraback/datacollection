import java.io.*;
import java.util.*;

public class C {
	public static void main(String [] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("practice.in"));		
		PrintWriter pw = new PrintWriter(new FileWriter("practice.out"));		
		int T=sc.nextInt();
		for (int c1=0;c1<T;c1++) {			
			pw.print("Case #" + (c1+1) + ": ");
			System.out.println("Case #" + (c1+1) + ": ");
			pw.println("");
			int R=sc.nextInt();
			int N=sc.nextInt();
			int M=sc.nextInt();
			int K=sc.nextInt();
									
			for (int c2=0;c2<R;c2++) {				
				int ma2=0, ma3=0, ma5=0;
				
				for (int c3=0;c3<K;c3++) {
					int a2=0, a3=0, a5=0;
					int rr=sc.nextInt();
					while (rr%2==0 && rr>0) {
						rr/=2;
						a2++;
					}
					while (rr%3==0 && rr>0) {
						rr/=3;
						a3++;
					}
					while (rr%5==0 && rr>0) {
						rr/=5;
						a5++;
					}	
					ma2=Math.max(ma2, a2);
					ma3=Math.max(ma3, a3);
					ma5=Math.max(ma5, a5);
				}			
				
				int kha=N-ma5-ma3;
				for (int c5=0;c5<ma5;c5++) {
					pw.print("5");					
				}
				for (int c5=0;c5<ma3;c5++) {
					pw.print("3");					
				}
												
				if (kha!=0) {
					if (kha==1) {
						if (ma2==1) {
							pw.print("2");
						}
						else if (ma2==2) {
							pw.print("4");
						}
						else {
							pw.print("4");
						}
					}
					else if (kha==2) {
						if (ma2==2) {
							pw.print("22");
						}
						else if (ma2==3) {
							pw.print("42");
						}
						else if (ma2==4) {
							pw.print("44");
						}	
						else {
							pw.print("44");
						}
					}
					else if (kha==3) {
						if (ma2==3) {
							pw.print("222");
						}
						else if (ma2==4) {
							pw.print("422");
						}
						else if (ma2==5) {
							pw.print("442");
						}	
						else if (ma2==6) {
							pw.print("444");
						}	
						else {
							pw.print("444");
						}
					}					
				}
				pw.println("");
			}
					
			pw.println("");
		}
		pw.flush();
		pw.close();
		sc.close();
	}	
}
