package codejam.e2014;

import java.util.Locale;
import java.util.Scanner;

public class B {

	private static void handleCase(int i, Scanner scanner) {
		double C = scanner.nextDouble();
		double F = scanner.nextDouble();
		double X = scanner.nextDouble();
		
		double time = 0.0;
		double rate = 2.0;
		while(true) {
			double secondsLeft = X / rate;
			double currentEnd = time + secondsLeft;
			
			double secondsToFarm = C / rate;
			double farmEnd = time + secondsToFarm + (X / (rate + F));
			
			if (currentEnd < farmEnd) {
				System.out.println("Case #"+i+": "+currentEnd);
				return;
			}
			
			time += secondsToFarm;
			rate += F;
		}
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
		int cases = scanner.nextInt();
		
		for(int i=0;i<cases; i++)
			handleCase(i+1,scanner);
	}
}
