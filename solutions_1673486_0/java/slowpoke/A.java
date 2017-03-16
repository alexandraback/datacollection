import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	static int count = 0;
	public static void main(String[] args) throws Exception {
//		Scanner sc = new Scanner(new File("A-large.in"));
//		PrintWriter pw = new PrintWriter("A-large.out");
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter("A-small-attempt0.out");
//		Scanner sc = new Scanner(new File("A-small.in"));
//		PrintWriter pw = new PrintWriter("A-small.out");
		
		int tc = sc.nextInt();
		for(int t=1; t<=tc; t++){
			int A = sc.nextInt();
			int B = sc.nextInt();
			double[] p = new double[A];
			for(int i=0; i<A; i++){
				p[i] = sc.nextDouble();
			}
			
			double[] cp = new double[1<<A];
			count = 0;
			fill(p, cp, 0, 1);
			
			double expected = B+2;
			int bad = B+2+B-A;
			int good = B-A+1;
			
			int[] ind = {0,1,4};
			for(int i=0; i<A; i++){
				double test = 0;
				for(int j=0; j<=ind[i]; j++){
					test += cp[j]*good;
				}
				for(int k=ind[i]+1; k<(1<<A); k++){
					test += cp[k]*bad;
				}
				if(test<expected) expected = test;
				good += 2;
				bad += 2;

			}
			
			pw.println("Case #" + t + ": " + expected);
		}
		
		pw.close();
		sc.close();
	}
	
	public static void fill(double[] p, double[] cp, int cur, double mul){
		if(cur == p.length){
			cp[count++] = mul;
			return;
		}
		fill(p,cp,cur+1,mul*p[cur]);
		fill(p,cp,cur+1,mul*(1-p[cur]));
	}

}
