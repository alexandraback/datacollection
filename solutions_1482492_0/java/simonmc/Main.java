import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = Integer.parseInt(scan.nextLine());
		for(int c = 0; c < cases; c++) {
			String line = scan.nextLine();
			Scanner ls = new Scanner(line);
			double D = ls.nextDouble();
			int N = ls.nextInt();
			int A = ls.nextInt();
			double[] t = new double[N];
			double[] x = new double[N];
			double[] a = new double[A];
			for(int i = 0; i < N; i++) {
				ls = new Scanner(scan.nextLine());
				t[i] = ls.nextDouble();
				x[i] = ls.nextDouble();
			}
			ls = new Scanner(scan.nextLine());
			for(int i = 0; i < A; i++) {
				a[i] = ls.nextDouble();
			}
			
	
			System.out.println("Case #" + (c + 1)+ ":");
			for(int ai = 0; ai < A; ai++) {
				System.out.println(process(D, t, x, a[ai], N));
			}
					
		}
			
		
	
	}
	
	
	public static double process(double D, double[] t, double[] x, double a, int N) {
		
		
		double quickest = time(D, a);
		double cand = t[N - 1];
		double candT = 0;
		
		if(quickest < cand)	{
			quickest = cand;
			candT = t[N - 1] - quickest;
		}
		for(int i = 1; i <= N; i++) {
			if(dist(candT, t[N-i], a) > x[N - i]) {
				candT =  t[N - i] - time(x[N - i], a);
				quickest = time(D, a) +  candT;
			}
		}
		
		return quickest;
	
		
	}
	
	public static double dist(double t0, double t, double a) {
		return 0.5 * a * (t - t0) * (t - t0);
	}
	
	public static double time(double xc, double a) {
		return Math.sqrt(2 * xc / a);
	}
	
}
