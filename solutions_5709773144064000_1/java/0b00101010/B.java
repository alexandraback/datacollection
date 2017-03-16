import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		PrintStream outfile = new PrintStream("B-small.out.txt");
		for (int c = 1; c <= cases; c++) {
			double result = test(scan.nextDouble(), scan.nextDouble(), scan.nextDouble());
			outfile.println("Case #" + c + ": " + result);
			System.out.println("Case #" + c + ": " + result);
		}
		outfile.close();
	}
	
	private static double test(double c, double f, double x) {
		double cps = 2.0;
		double time = 0.0;
		double goal, farm, goalWithFarm;
		while (true) {
			farm = c / cps;
			goal = x / cps;
			goalWithFarm = (x / (cps + f)) + farm;
			if (goalWithFarm >= goal)
				return time + goal;
			cps += f;
			time += farm;
		}
	}
}
