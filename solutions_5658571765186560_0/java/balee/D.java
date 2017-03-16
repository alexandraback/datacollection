import java.io.FileInputStream;
import java.util.Scanner;

public class D {

	private static String process(Scanner in) {
		int X = in.nextInt();
		int R = in.nextInt();
		int C = in.nextInt();
		String result = "GABRIEL";
		// Areas are not dividable
		if ( (R * C) % X != 0 )
			result = "RICHARD";
		// The straight shape does not fit in
		else if ( X > R && X > C )
			result = "RICHARD";
		// Some of the L-shaped does not fit in (the smaller
		// side is larger than the smaller side of the box)
		else if ( (X+1) / 2 > Math.min(R, C) )
			result = "RICHARD";
		// The shape closes a smaller area.
		// Works only for small input (X <= 4)
		else if ( X == 4 && Math.min(R, C) < 3 )
			result = "RICHARD";
		//if ( result.equals("GABRIEL") && X != 1 && X != 2 ) result += " " + X + " " + R + " " + C;
		return result;
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
