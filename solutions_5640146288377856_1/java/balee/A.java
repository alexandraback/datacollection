import java.io.FileInputStream;
import java.util.Scanner;

public class A {

	private static String process(Scanner in) {
		int R = in.nextInt();
		int C = in.nextInt();
		int W = in.nextInt();
		int result = W + (C - W - 1) / W + 1;
		if ( W == C )
			result = W;
		if ( R > 1 )
			result += (R - 1)*(C / W);
		return Integer.toString(result);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
