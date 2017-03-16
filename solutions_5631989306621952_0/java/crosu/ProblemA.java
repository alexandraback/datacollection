import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemA {	
	public static void next_case(long case_num, PrintWriter writer, Scanner scanner) {
		String letters = scanner.nextLine();
		String word = "" + letters.charAt(0);
		
		for (int i = 1; i < letters.length(); i++) {
			char first = word.charAt(0);
			char next = letters.charAt(i);
			
			String candidate1 = next + word;
			String candidate2 = word + next;
			
			if (candidate1.compareTo(candidate2) > 0) {
				word = candidate1;
			} else {
				word = candidate2;
			}
		}
		
		writer.print("Case #" + case_num + ": " + word);
	}
	
	public static void main(String[] args) throws Exception {
		String fileName = "fileA";
		PrintWriter writer = new PrintWriter(fileName + ".out", "UTF-8");
		Scanner scanner = new Scanner(new File(fileName + ".in"));
		int t = scanner.nextInt();
		scanner.nextLine();
		
		for (int i = 0; i < t; i++) {
			next_case(i+1, writer, scanner);
			
			if (i < t - 1) {
				writer.println("");
			}
		}
		
		writer.close();
		scanner.close();
	}
}
