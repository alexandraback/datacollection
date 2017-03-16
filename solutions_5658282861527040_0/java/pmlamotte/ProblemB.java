import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


/**
 * @author Paul LaMotte
 *
 */
public class ProblemB {

	public static void main(String[] args) {
		try {
			System.setOut(new PrintStream(new FileOutputStream("ProblemB.out")));
			Scanner scan = new Scanner(new FileInputStream("ProblemB.in"));
			int cases = new Scanner(scan.nextLine()).nextInt();
			for (int l = 0; l < cases; l++) {
				int a = scan.nextInt();
				int b = scan.nextInt();
				int k = scan.nextInt();
				
				int count = 0;
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < b; j++) {
						int res = i & j;
						if (res < k) {
							count++;
						}
					}
				}
				System.out.printf("Case #%d: %d%n", l+1, count);
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
