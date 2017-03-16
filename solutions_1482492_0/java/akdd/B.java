import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		

		Scanner sc = null;
		if (args != null && args.length > 0) {
			
			try {
				sc = new Scanner(new File(args[0]));
					
				if (args.length > 1) {
					System.setOut(new PrintStream(new BufferedOutputStream(new FileOutputStream(new File(args[1])), 128)));
				}
			} catch (FileNotFoundException e) {
				
				// e.printStackTrace();
				sc = new Scanner(System.in);
			}
			
		} else {
			
			sc = new Scanner(System.in);
		}

		int T = Integer.valueOf(sc.nextLine());
		
		for (int i = 0; i < T; i++) {
			double D = sc.nextDouble();
			int N = sc.nextInt();
			int A = sc.nextInt();
			
			double[] t = new double[N];
			double[] x = new double[N];
			for (int j = 0; j < N; j++) {
				t[j] = sc.nextDouble();
				x[j] = sc.nextDouble();
			}
			
			double[] a = new double[A];
			for (int j = 0; j < A; j++) {
				a[j] = sc.nextDouble();
			}
			
			double[] answer = solve(D, N, A, t, x, a);
			
			System.out.printf("Case #%d:\n", i + 1);
			
			for (int j = 0; j < A; j++) {
				System.out.println(answer[j]);
			}
			
		}
		System.out.close();

	}
	
	public static double[] solve(double D, int N, int A, double[] t, double[] x, double[] a) {
		double[] answer = new double[A];
		
		for (int i = 0; i < A; i++) {
			double v = 0;
			double aa = a[i];
			double p = 0;
			for (int j = 0; j < N; j++) {
				if (x[j] >= D) {
					
					if (t[j] == 0 || j == 0) {
						break;
					}
					double dt = t[j] - t[j-1];
					double ds = x[j] - x[j-1];
					
					double vo = ds / dt;
					double to = (D - x[j-1]) / vo;
					
					double tt =	(Math.sqrt( v * v + 2 * aa * (D - p)) - v) / aa;
					
					if (tt > to) {
						answer[i] += tt;
						
					} else {
						answer[i] += to;
					}
					p = D;
					break;
				} else {
					
					if (t[j] == 0) {
						
						continue;
					}
					double tt = (Math.sqrt( v * v + 2 * aa * (x[j] - p)) - v) / aa;
					double dt = t[j];
					double ds = x[j];
					if (j > 0) {
						dt -= t[j-1];
						ds -= x[j-1];
					}
					if (tt > t[j]) {
						p += v * dt + aa * dt * dt * 0.5d;
						v += aa * dt;
					} else {
						p = x[j];
						v = ds / dt;
					}
					answer[i] += dt;
					
				}
			}
			
			if (p < D) {
				
				double tt = (Math.sqrt( v * v + 2 * aa * (D - p)) - v) / aa;
				answer[i] += tt;
			}
		}
		
		return answer;
	}
	
	
}
