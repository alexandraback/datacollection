import java.io.File;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class ProblemA {	
	public static void add_digits(long n, Set<Short> digits) {
		while (n > 0) {
			long digit = n % 10;
			n = (n - digit) / 10;
			digits.add((short) digit);
		}
	}
	
	public static void next_case(long case_num, PrintWriter writer, Scanner scanner) {
		long n = scanner.nextLong();
		
		if (n == 0) {
			writer.print("Case #" + case_num + ": INSOMNIA");
		} else {
			Set<Short> digits = new HashSet<Short>();
			
			long count = 0;
			
			while (digits.size() < 10 && count < 100) {
				count++;
				add_digits(count * n, digits);
			}
			
			writer.print("Case #" + case_num + ": " + count * n);
		}
	}
	
	public static void main(String[] args) throws Exception {
		PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
		Scanner scanner = new Scanner(new File("input.in"));
		int t = scanner.nextInt();
		
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
