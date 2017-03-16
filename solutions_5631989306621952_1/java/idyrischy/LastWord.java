import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class LastWord {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(new File ("A-large.in"));
		PrintWriter out = new PrintWriter(new File("A-large.out"));
		PrintWriter debug = new PrintWriter(new File("A-d.txt"));
		
		int a = sc.nextInt();
		sc.nextLine();
		
		for (int i = 0; i < a; i++) {
			String str = sc.nextLine().trim();
			
			String build = "" + str.charAt(0);
			
			for (int j = 1; j < str.length(); j++) {
				if (str.charAt(j) >= build.charAt(0)) {
					build = str.charAt(j) + build;
				} else {
					build = build + str.charAt(j);
				}
			}
			
			out.printf("CASE #%d: %s%n", i + 1, build);
		}
		
		
		sc.close();
		out.close();
		debug.close();
	}
}
