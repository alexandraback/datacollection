import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Scanner;


public class CookieClickerAlpha {
	
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedReader(new FileReader(new File("B-large.in")), 256 << 10));
			PrintStream out = new PrintStream(new File("output.txt"));

			int testsNumber = in.nextInt();
			for (int testId = 1; testId <= testsNumber; testId++) {
				out.print("Case #" + testId + ": ");
				double factoryCost = Double.parseDouble(in.next());
				double factoryProduction = Double.parseDouble(in.next());
				double target = Double.parseDouble(in.next());
				double production = 2.0;
				double time = 0.0;
				double result = time + target / production;
				int uselessFactories = 0;
				while (uselessFactories < 100000) {
					time += factoryCost / production;
					production += factoryProduction;
					double totalTime = time + target / production;
					if (result > totalTime) {
						result = totalTime;
						uselessFactories = 0;
					}
					else {
						uselessFactories++;
					}
				}
				out.println(result);
			}
			in.close();
			out.close();
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
