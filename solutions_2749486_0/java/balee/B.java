import java.io.FileInputStream;
import java.util.Scanner;

public class B {

	private static String process(Scanner in) {
		int X = in.nextInt();
		int Y = in.nextInt();
		String res = "";
		for(int i = 0; i < Math.abs(X); i++) 
			if ( X > 0 )
				res += "WE";
			else
				res += "EW";
		for(int i = 0; i < Math.abs(Y); i++) 
			if ( Y > 0 )
				res += "SN";
			else
				res += "NS";
		return res;
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
