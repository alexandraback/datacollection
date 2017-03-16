import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("input"));
		PrintWriter outfil = new PrintWriter(new FileWriter("output"));

		int numTests = sc.nextInt();
		for (int test = 1; test <= numTests; test++) {
			
			
			outfil.println("Case #" + test + ": ");
			
		}
		outfil.flush();
		outfil.close();
		sc.close();
	}
}
