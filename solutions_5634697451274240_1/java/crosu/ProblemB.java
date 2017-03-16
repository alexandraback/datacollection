import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

public class ProblemB {	
	public static int findFlipIndex(String pancakeStack) {
		int index = 1;
		int len = pancakeStack.length();
		
		while (index < len && pancakeStack.charAt(index) == pancakeStack.charAt(index - 1)) {
			index++;
		}
		
		return index;
	}
	
	public static String flip(String pancakeStack, int flipIndex) {
		String newStack = "";
		
		for (int i = flipIndex - 1; i >= 0; i--) {
			if (pancakeStack.charAt(i) == '-') {
				newStack += '+';
			} else {
				newStack += '-';
			}
		}
		
		return newStack + pancakeStack.substring(flipIndex, pancakeStack.length());
	}
	
	public static void next_case(long case_num, PrintWriter writer, Scanner scanner) {
		String pancakeStack = scanner.nextLine();
		
		int flips = 0;
		
		for (int i = 1; i < pancakeStack.length(); i++) {
			if (pancakeStack.charAt(i-1) != pancakeStack.charAt(i)) {
				flips++;
			}
		}
		
		if (pancakeStack.endsWith("-")) {
			flips++;
		}
		
		writer.print("Case #" + case_num + ": " + flips);
	}
	
	public static void main(String[] args) throws Exception {
		PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
		Scanner scanner = new Scanner(new File("input.in"));
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
