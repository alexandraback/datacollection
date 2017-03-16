import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Math {
	
	static PrintWriter  writer = null;
	
	public static void main(String[] args) {
		
		Scanner console = null;
		try {
			console = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		try {
			writer = new PrintWriter("output.txt", "UTF-8");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int t = console.nextInt(); console.nextLine();
		for (int ti = 0; ti < t; ti++) {
			String s = console.nextLine();
			writer.printf("Case #%d: %s\n", ti + 1, solve(s));
		}
		writer.close();
	}
	
	public static String solve(String s) {
		String x = "";
		while (!s.isEmpty()) {
			char c = s.charAt(0);
			if (x.isEmpty() || c >= x.charAt(0)) {
				x = c + x;
			} else {
				x = x + c;
			}
			s = s.substring(1);
		}
		return x;
	}
	
	
}