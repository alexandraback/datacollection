import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;
import java.util.Set;

public class Main {

	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileInputStream("input.txt"));
			scanner.useLocale(Locale.ENGLISH);
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
			int tests = scanner.nextInt();
			for (int i = 0; i < tests; i++) {
				int x = scanner.nextInt();
				int r = scanner.nextInt();
				int c = scanner.nextInt();
				
				out.write("Case #" + (i + 1) + ": " + solve(x, r, c) + "\n");
				out.flush();
			}
			out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}

	private static String solve(int x, int r, int c) {
		if (r*c % x != 0) {
			return "RICHARD";
		}
		if (x >= 7) {
			return "RICHARD";
		}
		else if (x == 1) {
			return "GABRIEL";
		}
		else if (x == 2) {
			return "GABRIEL";
		}
		else if (x == 3) {
			if ((x + 1)/2 > Math.min(r,c)) {
				return "RICHARD";
			}
			return "GABRIEL";
		}
		if ((x + 1)/2 >= Math.min(r,c)) {
			return "RICHARD";
		}
		return "GABRIEL";
	}
}