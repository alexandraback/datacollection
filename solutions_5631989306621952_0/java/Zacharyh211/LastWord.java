import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class LastWord {
	public static void main(String [] args) throws IOException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		int ct = input.nextInt();
		for(int i = 1; i <= ct; i++) {
			String n = input.next();
			String m = "";
			char best = 'A' - 1;
			for(char c : n.toCharArray())
				if(c >= best) {
					best = c;
					m = c + m;
				}
				else
					m = m + c;
			out.printf("Case #%d: %s%n", i, m);
		}
		out.close();
	}
}
