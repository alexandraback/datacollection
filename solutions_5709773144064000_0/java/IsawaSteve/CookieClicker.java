import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * For Google Code Jam Qualification Round.
 * @author Jay
 *
 */
public class CookieClicker {


	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc;
		try {
			sc = new Scanner(new File(args[0]));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return;
		}
		String totalProblems = sc.nextLine();
		int total = Integer.parseInt(totalProblems);
		int pos = 1;
		for (;pos <= total;pos++) {
			String line = sc.nextLine();
			String[] values = line.split(" ");
			String c = values[0];
			String f = values[1];
			String x = values[2];
			
			double choice = bakeCookies(Double.parseDouble(c), Double.parseDouble(f), Double.parseDouble(x));

			
			System.out.println("Case #"+pos+": "+choice);
		}
	}

	private static double bakeCookies(double c, double f, double x) {
		
		return bakeCookies(2, 0, c, f, x, Double.MAX_VALUE);
	}
	
	private static double bakeCookies(double rate, int farms, double c, double f, double x, double winner) {
		double thisRoundTime = calcTime(rate, farms, c, f, x);
		if (thisRoundTime > winner) {
			return winner;
		}
		return bakeCookies(rate+f, farms+1, c, f, x, thisRoundTime);
	}

	private static double calcTime(double rate, int farms, double c, double f,
			double x) {
		double timeSavingForFarms = 0.0;
		for (int i = 0; i < farms; i++) {
			timeSavingForFarms += c / (2 + i * f);
		}
		double timeForGoal = x / rate;
		return timeSavingForFarms + timeForGoal;
	}
	
}
