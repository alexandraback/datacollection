import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		String fileName = "A-small-attempt0";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));
		
		int T = in.nextInt();
		
		for(int i=1; i<=T; i++) {
			out.println("Case #" + i + ": " + solve(in));
		}
		
		in.close();
		out.close();
	}

	private static int solve(Scanner in) {
	
		int R = in.nextInt();
		int C = in.nextInt();
		int W = in.nextInt();
		
		int dodges = (R-1) * (C / W) + (C/W - 1);
		System.out.println("dodges = " + dodges);
		
		return dodges + W + (C%W==0?0:1);
	}
	
}
