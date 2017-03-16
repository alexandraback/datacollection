import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int kases=1;kases<=T;kases++) {
			double C = in.nextDouble();
			double F = in.nextDouble();
			double X = in.nextDouble();
			double r = 2.0;
			double min = X/r;
			double t=0;
			while(true) {
				t+=C/r;
				r+=F;
				double attempt = t+(X/r);
				if(attempt>min)
					break;
				min=attempt;
			}
			System.out.print("Case #"+kases+": ");
			System.out.printf("%.7f\n",min);
		}
	}
}
