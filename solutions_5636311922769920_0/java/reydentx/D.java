import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {
	static Scanner scan;
	static PrintWriter writer;
	static Boolean[] A = new Boolean[100];
	public static void main(String[] args) {
		
		File file = new File("D://input.txt");
		File out = new File("D://out.txt");
		try {
			scan = new Scanner(file);
			writer = new PrintWriter(out);
			int t = scan.nextInt();
			for (int i = 1; i <= t; i++) {
				writer.print("Case #" + i + ": ");
				int a = scan.nextInt();
				int b = scan.nextInt();
				int c = scan.nextInt();
				
				for(int j=1; j<=a; j++) {
					writer.print(j + " ");
				}
				writer.println();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			scan.close();
			writer.close();
		}
	}
}
