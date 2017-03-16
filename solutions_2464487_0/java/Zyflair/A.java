import java.io.File;
import java.util.Scanner;


public class A {
	public static void main(String[] args) {
		new A();
	}
	A() {
		Scanner sc = null;
		try {
			sc = new Scanner(new File("A.in"));
		}
		catch (Exception e) {
		
		}
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			long r = sc.nextLong(),
					n = sc.nextLong(),
					a = 0;
			while (n >= (2 * r + 1L)) {
				n -= 2 * r + 1L;
				r += 2;
				a++;
			}
			System.out.println("Case #" + t + ": " + a);
		}
	}
}
