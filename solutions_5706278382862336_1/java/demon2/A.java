import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner=new Scanner(new File("E:\\A-large.in"));
		PrintWriter printWriter=new PrintWriter(new File("E:\\A.txt"));
		int T=scanner.nextInt();
		for (int test = 1; test <= T; test++) {	
			String string=scanner.next();
			
			long P=Long.parseLong(string.substring(0, string.indexOf('/')));
			long Q=Long.parseLong(string.substring(string.indexOf('/')+1));
			long k=divisor(P, Q);
			P=P/k;
			Q=Q/k;
			long i = 1;
			while (i < Q) {
				i <<= 1;
			}
			if (i != Q) {
				printWriter.println("Case #"+test+": "+"impossible");
			} else {
				int result = 0;
				while (P < Q) {
					P <<= 1;
					result++;
				}
				printWriter.println("Case #"+test+": "+result);
			}
			
		}
		scanner.close();
		printWriter.close();
	}
	
	public static long divisor(long m,long n){    
         long temp;
         while(m%n!=0){
             temp=n;
             n=m%n;
             m=temp;
         }
         return n;
     }
}
