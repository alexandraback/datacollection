import java.util.Scanner;


public class OutOfGas {
	private static double process(double D, double[] t, double[] x, double a) {
		double[] speeds = new double[t.length];
		for (int i=1; i < t.length; i++) {
			speeds[i-1] = (x[i] - x[i-1])/(t[i]-t[i-1]);	
		}
		if (x.length == 1 || x[0] >= D) {
			double timeToHouse = Math.sqrt(2*D/a);
			return timeToHouse;
		}
		//speeds[t.length - 1] = speeds[t.length - 2];
		double myX = 0;
		double myVel = 0;
		for (int i=1; i < t.length; i++) {
			//System.out.println(myX+" "+myVel);
			if (x[i] >= D) {
				t[i] = t[i-1] + (D-x[i-1])/speeds[i-1];
				x[i] = D;
			}
			double time = t[i]-t[i-1];
			double possibleX = myX + myVel*time + 0.5*a*time*time;
			if (possibleX > x[i]) {
				if (x[i]==D) return t[i];
				myX = x[i];
				myVel = speeds[i-1];
			}
			else {
				if (x[i]==D) {
					//System.out.println("my x"+myX);
					double timeToHouse = (-myVel + Math.sqrt(myVel*myVel - 2*a*(myX - D)))/a;
					return t[t.length-1] + timeToHouse;
				}
				myX = possibleX;
				myVel = myVel + a*time;
			}
			
		}
		return -1;
		/*
		System.out.println("end: "+myX+" "+myVel);
		//intersects before reaching house?
		double time = (D - x[x.length - 1])/speeds[x.length - 1];
		double possibleX = myX + myVel*time + 0.5*a*time*time;
		if (possibleX > D) {
			System.out.println("lj");
			return t[t.length - 1] + time;
		}
		double timeToHouse = (-myVel + Math.sqrt(myVel*myVel - 2*a*(myX - D)))/a;
		return timeToHouse;
		*/
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i=0; i < T; i++) {
			double D = in.nextDouble();
			int N = in.nextInt();
			int A = in.nextInt();
			double[] x = new double[N];
			double[] t = new double[N];
			for (int j=0; j < N; j++) {
				t[j] = in.nextDouble();
				x[j] = in.nextDouble();
			}
			System.out.println("Case #"+(i+1)+": ");
			for (int j=0; j < A; j++) {
				double a = in.nextDouble();
				System.out.println(process(D,t,x, a));
			}
		}
	}
}
