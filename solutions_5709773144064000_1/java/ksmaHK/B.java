import java.util.*;

public class B {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	double e = 0.0000005;
	for (int nc = 1; nc <= nCase; nc++) {
		double C = scanner.nextDouble();
		double F = scanner.nextDouble();
		double X = scanner.nextDouble();
		
		double rate = 2;
		double timeToFinish = X/rate;
		double nextTimeToBuyFarm = C/rate;
		
		while(nextTimeToBuyFarm < timeToFinish) {
			double newRate = rate + F;
			double newTimeToFinish = X/newRate + nextTimeToBuyFarm;
			double newNextTimeToBuyFarm = C/newRate + nextTimeToBuyFarm;
			if (newTimeToFinish + e < timeToFinish) {
				timeToFinish = newTimeToFinish;
				nextTimeToBuyFarm = newNextTimeToBuyFarm;
				rate = newRate;
			} else break;
		}
		
		System.out.println("Case #" + nc + ": " + timeToFinish);
	}
}
}