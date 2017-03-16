import java.util.Scanner;

public class A {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int cases = scan.nextInt();
		long r, t, count;
		for (int c = 1; c <= cases; c++) {
			r = scan.nextLong();
			t = scan.nextLong();
			count = 0;
			while (t > 0) {
				count++;
				t -= 2*r+1;
				r += 2;
			}
			if (t < 0)
				count--;
			System.out.println("Case #" + c + ": " + count);
		}
	}
}
