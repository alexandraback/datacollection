import java.io.*;
import java.util.*;

public class BC {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("C-small-attempt0.in"));
		PrintStream output = new PrintStream(new File("c1.txt"));
		int caseNum = console.nextInt();
		for (int i = 1; i <= caseNum; i++) {
			int length = console.nextInt();
			int times = console.nextInt();
			String circle = console.next();
				output.println("Case #" + i + ": " + result(length, times, circle));
			}
	}

	public static String result(int length, int times, String circle) {
		return "";
	}

}
