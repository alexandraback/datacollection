import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	static Scanner scan;
	static PrintWriter writer;
	public static void main(String[] args) {
		
		File file = new File("D://input.txt");
		File out = new File("D://out.txt");
		String[][] A = new String[50][50];
		try {
			scan = new Scanner(file);
			writer = new PrintWriter(out);
			int t = scan.nextInt();
			for (int i = 1; i <= t; i++) {
				writer.print("Case #" + i + ": ");
				int n = scan.nextInt();
				check(n);
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			scan.close();
			writer.close();
		}
	}

	private static void check(int n) {
		if (n == 0) {
			writer.println("INSOMNIA");
		} else {
			boolean[] F = new boolean[10];
			int c = 0, i = 1;

			while ((c = exploinN(n * i, F, c)) != 10) {
				i++;
			}
			writer.println(n * (i));
		}
	}

	private static int exploinN(int n, boolean[] F, int c) {
		do {
			int t = n % 10;
			if (F[t] == false) {
				F[t] = true;
				c++;
			}
		} while ((n /= 10) != 0);

		return c;
	}
}
