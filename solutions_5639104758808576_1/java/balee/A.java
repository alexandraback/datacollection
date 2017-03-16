import java.io.FileInputStream;
import java.util.Scanner;

public class A {

	private static String process(Scanner in) {
		int sMax = in.nextInt();
		String counts = in.next();
		int standing = 0;
		int neededTotal = 0;
		for(int shynessLevel = 0; shynessLevel <= sMax; shynessLevel++) {
			int count = counts.charAt(shynessLevel) - '0';
			if ( count > 0 && standing < shynessLevel ) {
				int needed = shynessLevel - standing;
				neededTotal += needed;
				standing += needed;
			}
			standing += count;
		}
		return Integer.toString(neededTotal);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
