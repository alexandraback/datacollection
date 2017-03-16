package qualy;

import java.util.Scanner;

public class B {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int cases = sc.nextInt();
		for (int caze = 1; caze <= cases; caze++) {
			double C = sc.nextDouble();
			double F = sc.nextDouble();
			double X = sc.nextDouble();
			int R = Math.max((int)Math.ceil(X / C - 2 / F - 1), 0);
			double ans = 0.0;
			for (int i=0; i<R;i++) ans += C / (2+i*F);
			ans += X / (2 + R*F);
			
			System.out.println("Case #" + caze + ": " + String.format("%.10f", ans));
		}
	}

}
