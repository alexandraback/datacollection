import java.util.*;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int radius = in.nextInt();
			int paint = in.nextInt();
			if (a!=cases-1) {
				in.nextLine();
			}
			int rings = 0;
			while (paint >= 2*radius+1) {
				paint = paint - 2*radius - 1;
				radius += 2;
				rings++;
			}
			System.out.println("Case #" + (a+1) + ": " + rings);
		}
	}

}
