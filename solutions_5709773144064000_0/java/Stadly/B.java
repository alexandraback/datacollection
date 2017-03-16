import java.util.Scanner;

public class B {
	static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for(int q = 1; q <= t; ++q) {
			double c = sc.nextDouble();
			double f = sc.nextDouble();
			double x = sc.nextDouble();
			
			double rate = 2;
			double best = x/rate;
			double p = 0;
			for(int i = 1; true; ++i) {
				double time = c/rate;
				rate += f;
				p += time;
				if(p+x/rate < best)
					best = p+x/rate; 
				else
					break;
			}
			System.out.println("Case #"+q+": "+best);
		}
	}
}
