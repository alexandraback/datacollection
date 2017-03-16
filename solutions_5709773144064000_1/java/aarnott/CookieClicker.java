import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;


public class CookieClicker {
	
	
	/**
	 * For this problem, there wasn't a nice polynomial to find the root
	 * of, so I had to solve it in a somewhat lame way. I start at 0 farms
	 * and figure out if the next farm saves time. Once it doesn't save
	 * time, I return the previous result.
	 * 
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		
		Scanner scanner = new Scanner(new FileReader("cookie_clicker.txt"));
		
		int tests = scanner.nextInt();
		for(int i = 1; i <= tests; i++) {
			//Get the constants
			double C = scanner.nextDouble();
			double F = scanner.nextDouble();
			double X = scanner.nextDouble();
			
			double bestTime = getBestTime(C, F, X);
			
			System.out.printf("Case #%d: %.7f\n", i, bestTime);			
		}
		
		scanner.close();
		
		System.exit(0);
		
	}
	
	
	private static double getBestTime(double C, double F, double X) {
		double cps = 2;	//Base cookies per second
		double bestTime = X / cps;	//0 farms is the one to beat
		
		//Track the amount of time spent on building farms separately
		double farmTime = 0;
		
		//Keep going until a better time is not found or the loop cutoff is met
		while(true) {
			double nextCps = cps + F;
			
			//Amount of time spent on farms is additive 
			farmTime += C / cps;
			
			double totalTime = farmTime + X / nextCps;
			if(totalTime < bestTime) {
				bestTime = totalTime;
				cps = nextCps;
			} else {
				break;
			}
			
		}
		
		return bestTime;
	}
	


}
