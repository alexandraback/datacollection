import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tn = sc.nextInt();
		for (int ti = 0; ti < tn; ti++) {
			int a = sc.nextInt(), b = sc.nextInt();
			double[] ps = new double[a];
			for (int i = 0; i < ps.length; i++)
				ps[i] = sc.nextDouble();
			double minValue = b + 2;

			double[] products = new double[ps.length];
			products[0] = ps[0];
			for (int i = 1; i < products.length; i++)
				products[i] = products[i - 1] * ps[i];

			for (int i = 0; i < a; i++) {
				double tmp = products[a - 1 - i] * (i + b - a + i + 1) + (1 - products[a - 1 - i])
						* (i + b - a + i + 1 + b + 1);
				minValue = Math.min(minValue, tmp);
			}

			System.out.printf("Case #%d: %.6f%n", ti + 1, minValue);
		}
	}
}
