import java.util.Scanner;

public class CookieClickerAlpha {
	
	public static double c, f, x;
	
	public static double calculate(double d) {
		if (x <= c) {
			return x / d;
		} else {
			double option1 = x / d;
			double option2 = c / d + x / (d + f);
			if (option1 < option2) {
				return option1;
			} else {
				return c / d + calculate(d + f);
			}
		}
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		for (int test = 1; test <= testNum; test++) {
			scan.nextLine();
			c = scan.nextDouble();
			f = scan.nextDouble();
			x = scan.nextDouble();
			System.out.format("Case #%d: %.7f%n", test, calculate(2.0));
		}
		scan.close();
	}

}
