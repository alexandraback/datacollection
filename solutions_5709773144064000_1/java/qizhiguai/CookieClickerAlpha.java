import java.util.Scanner;

public class CookieClickerAlpha {
	
	public static double c, f, x;
	
	public static double calculate() {
		if (x <= c) {
			return x / 2.0;
		} else {
			double speed = 2.0;
			double passed = 0.0;
			while (x / speed >= (c / speed + x / (speed + f))) {
				passed += c / speed;
				speed += f;
			}
			return passed + x / speed;
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
			System.out.format("Case #%d: %.7f%n", test, calculate());
		}
		scan.close();
	}

}
