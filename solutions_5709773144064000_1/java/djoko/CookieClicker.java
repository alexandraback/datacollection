import java.util.Scanner;


public class CookieClicker {
	
	public double solve(double c, double f, double x) {
		double rate = 2.0, time = 0.0;
		double requiredToC, additionalTimeIfContinue, additionalTimeIfBuyingFarm;
		
		if (x <= c)
			return x / rate;
		
		while (true) {
			requiredToC = c / rate;
			time += requiredToC;
			additionalTimeIfContinue = (x - c) / rate;
			additionalTimeIfBuyingFarm = x / (rate + f);
			if (additionalTimeIfBuyingFarm >= additionalTimeIfContinue)
				break;
			
			rate += f;
		};

		return time + additionalTimeIfContinue;
	}
	
	public void process() {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++) {
			System.out.println("Case #" + (i + 1) + ": " + solve(sc.nextDouble(), sc.nextDouble(), sc.nextDouble()));
		}
	}
	
	public static void main(String args[]) {
		CookieClicker cc = new CookieClicker();
		cc.process();
	}
}
