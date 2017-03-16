import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;


public class CookieClicker {

	public static void main(String[] args) {
	    try {
	    	Scanner in = new Scanner(new FileReader("D:/input.txt"));
	    	PrintWriter writer = new PrintWriter("D:/output.txt", "UTF-8");
	    	int testCases = in.nextInt();
	    	for (int i = 1; i <= testCases; i++) {
	    		double C = in.nextDouble(); // no of cookies needed for a farm
	    		double F = in.nextDouble(); // no of cookies produced per farm
	    		double X = in.nextDouble(); // no of cookies needed to win
	    		
	    		// setup initial data
	    		double noCookiesPerSecond = 2;
	    		double time = 0;
	    		while(true) {
	    			double timeForFarm = C / noCookiesPerSecond + X / (noCookiesPerSecond + F);
	    			double timeTillWin = X / noCookiesPerSecond;
	    			if (timeForFarm < timeTillWin) {
	    				time += C / noCookiesPerSecond;
	    				noCookiesPerSecond += F;
	    			} else {
	    				time += timeTillWin;
	    				break;
	    			}
	    		}
	    		writer.println("Case #" + i + ": " + time);
	    	}
	    	writer.close();
	    	in.close();
	    } catch (Exception e) {
			e.printStackTrace();
			System.out.println(e.getLocalizedMessage());
		}
	}

}
