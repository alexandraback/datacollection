import java.util.*;

public class A {

	public static void main(String[] args) {
		A a = new A();
		a.run();
	}

	public void run() {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int r = in.nextInt();
			int c = in.nextInt();
			int w = in.nextInt();
			if (a!=cases-1) {
				in.nextLine();
			}
			int base = c/w;
			base *= r;
			if (c%w==0) {
				base += (w-1);
			}
			else {
				base += w;
			}
			System.out.println("Case #" + (a+1) + ": " + base);
		}
	}

}