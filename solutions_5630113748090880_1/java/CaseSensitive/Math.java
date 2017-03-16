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
		
		int t = console.nextInt();
		for (int ti = 0; ti < t; ti++) {
			int n = console.nextInt();
			
			String x = "";
			int[] a = new int[2505];
			for (int i = 0; i < (2 * n - 1) * n; i++) {
				int c = console.nextInt();
				//System.out.println(c);
				a[c] = 1 - a[c];
			}
			for (int i = 0; i < 2505; i++) {
				if (a[i] == 1) {
					x += " " + i;
				}
			}
			x = x.trim();

			//System.out.println(x);
			writer.printf("Case #%d: %s\n", ti + 1, x);
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