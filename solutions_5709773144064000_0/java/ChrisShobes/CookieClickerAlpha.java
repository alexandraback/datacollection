package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CookieClickerAlpha {

	public void solve(String file) {
		try {
			Scanner reader = new Scanner(new File(file));
			reader.nextLine(); // skip first line
			int i = 1;
			String line;
			String[] cfx;
			double c;
			double f;
			double x;
			while(reader.hasNextLine()) {
				line = reader.nextLine();
				cfx = line.split(" ");
				c = Double.parseDouble(cfx[0]); // farm cost
				f = Double.parseDouble(cfx[1]); // cookies from farm
				x = Double.parseDouble(cfx[2]); // total required
				System.out.println("Case #" + i + ": " + solve(c,f,x));
				i++;
			}
		} 
		catch (FileNotFoundException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		}
	}
	private double solve(double c, double f, double x) {
		// double currTotal = 0.0;
		double seconds = 0.0;
		double production = 2.0; // per second
		boolean buyFarm;
		while(true) {
			// is it better to click till x or to buy farm
			buyFarm = isBetterToBuyFarm(c, f, x, production);
			if(buyFarm) {
				seconds += c/production;
				production += f;
			}
			else {
				double range = 10000000.0;
				seconds += x/production;
				return Math.round(seconds * range) / range; 
			}
		}
	}
	
	private boolean isBetterToBuyFarm(double c, double f, double x,
			double production) {
		double speedNoFarm = x/production; 
		double speedWithFarm = c/production + (x/(production + f));
		return (speedWithFarm < speedNoFarm);
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		CookieClickerAlpha test = new CookieClickerAlpha();
		test.solve("B-small-attempt0.in");
		/*
		System.out.println(test.isBetterToBuyFarm(30.0, 1.0, 2.0, 2.0));
		System.out.println(test.isBetterToBuyFarm(30.0, 2.0, 100.0, 2.0));
		//*/
		/*
		System.out.println(test.solve(30.0, 1.0, 2.0));
		double result;
		
		result = test.solve(30.0, 2.0, 100.0); // 39.1666667
		Math.round(result);
		System.out.println(result);
		
		result = test.solve(30.50000, 3.14159, 1999.19990);
		System.out.println(result);
		
		result = test.solve(500.0, 4.0, 2000.0); 
		System.out.println(result);
		
		result = test.solve(10000.0, 100.0, 100000.0); 
		System.out.println(result);
		//*/
	}

}
