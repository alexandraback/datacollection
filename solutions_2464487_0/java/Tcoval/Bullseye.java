package GoogleCodeJam2013;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class Bullseye {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintStream output = new PrintStream("output.txt");
		int numCases = input.nextInt();
		for (int num = 1; num <= numCases; num++) {
			int radius = input.nextInt();
			double paint = input.nextInt();
			int count = doSomething(radius, paint);
			output.println("Case #" + num + ": " + count);
		}
		
	}

	private static int doSomething(int radius, double paint) {
		int r = radius;
		double area = getArea(r);
		int count = 0;
		while (paint >= area) {
			System.out.println(area);
			paint -= area;
			r += 2;
			count++;
			area = getArea(r);
		}
		return count;
	}
	
	private static double getArea(int radius) {
		return ((radius + 1) * (radius + 1)) - (radius * radius);
	}
}
