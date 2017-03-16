import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class A2 {
	public static void main(String[] args) throws InterruptedException {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		int casenum = 1;

		Thread.sleep(1000);
		while (T-- > 0) {
			System.out.println("Case #" + casenum++ + ": " );
			String num = solve(sc);
			
			
		}
	}

	private static String solve(Scanner sc) {
		double D =Double.parseDouble(sc.next());
		int N = sc.nextInt();
		int A = sc.nextInt();
		
		
		double[] X = new double[N];
		double[] T = new double[N];
		double[] XdT = new double[N];
		double xsum = 0;
		
		double Tgoal = 0;
		for (int i = 0; i < N; i++) {
			double t = Double.parseDouble(sc.next());
			double x = Double.parseDouble(sc.next());
			T[i] = t;
			X[i] = x;
			
			if(i> 0){
				XdT[i-1] = (X[i] - X[i-1]) / (T[i]-T[i-1]); 
			}
			if(i > 0 && X[i] >= D && Tgoal == 0){
				Tgoal = T[i-1] + (D-X[i-1])/ XdT[i-1];
				//System.out.println("Other car is in goal at " + Tgoal);
			}
			
		}
		
		double[] MPS = new double[A];
		for (int i = 0; i < A; i++) {
			double mps = Double.parseDouble(sc.next());
			MPS[i] = mps;
		}
		
		double mypos = 0;
		double myspeed = 0;
		
		for (int i = 0; i < N-1; i++) {
			double dt = T[1] - T[0];
			double dx = X[1] - X[0];
		}
		
		
		
		for (int i = 0; i < A; i++) {
			double fastest =Math.pow(D/MPS[i]*2,0.5);
			if(fastest > Tgoal) System.out.println(fastest);
			else System.out.println(Tgoal);
		}
		

		return "";
		
	}
}