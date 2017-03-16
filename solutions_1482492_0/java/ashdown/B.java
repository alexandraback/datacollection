import java.io.File;
import java.io.FileNotFoundException;
import java.util.Formatter;
import java.util.Scanner;


public class B {

	static double solve(double D, double A, double t0,double x0,double t1,double x1) {
		double myTimeNoBrake = Math.sqrt(D/(0.5*A));
		
		if (x0>=D) return myTimeNoBrake;
		
		double hisTime = (D-x0)/((x1-x0)/t1);
		if (myTimeNoBrake>=hisTime)
			return myTimeNoBrake;
		else
			return hisTime;
	}

	public static void main(String[] args) throws FileNotFoundException {
		//String filename = "B-test.in";
		String filename = "B-small-attempt0.in";
		//String filename = "B-large.in";
		assert filename.endsWith(".in");
		Scanner in = new Scanner(new File(filename));
		Formatter out = new Formatter(new File(filename.replace(".in", ".out")));

		assert in.hasNext();
		int T = in.nextInt();
		in.nextLine();
		for (int t = 0; t < T; t++) {

			String result;
			result = String.format("Case #%d:%n", t + 1);
			out.format(result);
			System.out.format(result);

			double D = in.nextDouble();
			int N = in.nextInt();
			int A = in.nextInt();
			if (N!=2 && N!=1) {
				System.out.println("N!=2, skipping.");
				out.format("SKIPPED ***%n");			
			} else {
				if (N==2) {
					double t0 = in.nextDouble();
					double x0 = in.nextDouble();
					double t1 = in.nextDouble();
					double x1 = in.nextDouble();
					assert (t0==0.0);
					
					for (int a=0;a<A;a++) {
						double accel = in.nextDouble();
						double secs = solve(D, accel, t0,x0,t1,x1);
						result = String.format("%s%n", ""+secs);
						
						out.format(result);					
						System.out.format(result);					
					}
				} else {
					double t0 = in.nextDouble();
					double x0 = in.nextDouble();
					assert (t0==0.0);
					
					for (int a=0;a<A;a++) {
						double accel = in.nextDouble();
						double secs = solve(D, accel, t0,x0,t0,x0);
						result = String.format("%s%n", ""+secs);
						
						out.format(result);					
						System.out.format(result);					
					}
				}
			}
		}

		out.flush();
		out.close();
	}


}
