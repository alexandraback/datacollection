import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class Cookies {
	public static void main(String[] args) throws Exception {
		
		Scanner s = new Scanner(new File("B-large.in"));
		String firstLine = s.nextLine();
		int numCases = Integer.parseInt(firstLine);
		FileWriter output = new FileWriter("cookies_out_large.txt");
		for(int c = 1;c<=numCases;c++) {
			String problem = s.nextLine();
			String[] probArr = problem.split(" ");
			double result = solve(Double.parseDouble(probArr[0]),Double.parseDouble(probArr[1]),Double.parseDouble(probArr[2]));
			System.out.println("Case #" + c + ": " + result);
			output.write("Case #" + c + ": " + result + "\n");
		}
		output.flush();
		output.close();
		
		
	}
	public static double solve(double c, double f, double x) {
		double result = 0;
		double cookiesPerSecond = 2;
		
		
		while(timeWaiting(x,cookiesPerSecond) > timeBuying(x,cookiesPerSecond,c,f)) {
			result+=timeWaiting(c,cookiesPerSecond);
			cookiesPerSecond+=f;
		}
		result+=timeWaiting(x,cookiesPerSecond);
		
		
		return result;
	}
	public static double timeWaiting(double goal, double cookiesPerSecond) {
		return goal/cookiesPerSecond;
	}
	
	public static double timeBuying(double goal, double cookiesPerSecond, double cost, double bonusCookies) {
		double timeForBuy = cost/cookiesPerSecond;
		return timeForBuy + goal/(cookiesPerSecond + bonusCookies);
	}
}
