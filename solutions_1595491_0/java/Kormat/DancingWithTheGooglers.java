import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class DancingWithTheGooglers {
	public static void main(String[] args) {
		try {
			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
			Scanner scanner = new Scanner(new File(args[0]));
			int testsNum = scanner.nextInt();
			
			String solution;
			for (int i=1; i<=testsNum; i++) {
				solution = solve(scanner);
				System.out.println("Case #"+i+": "+solution);
				System.err.println("Case #"+i+": "+solution);
			}
		} catch (Exception e) {e.printStackTrace();}
	}
	
	private static String solve(Scanner scanner) {
		int n = scanner.nextInt();
		int s = scanner.nextInt();
		int p = scanner.nextInt();
		
		int score;
		int ret = 0;
		for (int i=0; i<n; i++) {
			score = scanner.nextInt();
			if (score >= 3*p-2) ret++;
			else if (score >= 3*p-4 && score >= 2) {
				if (s-->0) ret++;
			}
		}
		
		return ""+ret;
	}
}
