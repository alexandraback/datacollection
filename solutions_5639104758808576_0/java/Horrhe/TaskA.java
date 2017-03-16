package pl.gg.codejam2015.roundQ.taskA;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class TaskA {
	
	private static int solve(String s) {
		int result = 0, standing = 0;
		
		for (int i = 0; i < s.length(); i++) {
			int si = s.charAt(i) - '0';
			
			if (si > 0 && i > standing) {
				result += i - standing;
				standing += i - standing;
			}
			
			standing += si;
		}
		
		return result;
	}
	
	
	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(new FileInputStream("C:\\Users\\Grzegorz\\workspace_juno\\CodeJam2015\\src\\pl\\gg\\codejam2015\\roundQ\\taskA\\A-small-attempt0.in"));
		//System.setOut(new PrintStream(new FileOutputStream("C:\\Users\\Grzegorz\\workspace_juno\\CodeJam2015\\src\\pl\\gg\\codejam2015\\roundQ\\taskA\\A-small-attempt0.out")));
		
		try (Scanner in = new Scanner(System.in)) {
			
			int cases = in.nextInt();
			for (int i = 0; i < cases; i++) {
				int smax = in.nextInt();
				String s = in.next();
				
				int res = solve(s);
				
				System.out.println("Case #" + (i + 1) + ": " + res);
			}
		}
	}
}
