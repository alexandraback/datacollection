import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class ProblemD {	
	/* find position in expanded tile sequence that contains info about 
	 * positions [start] to [end] of initial tile sequence
	 */
	public static BigInteger findPosition(int k, int c, int start, int end) {
		BigInteger pos = BigInteger.valueOf(1);
		BigInteger factor = BigInteger.valueOf(k).pow(c - 1);
		
		for (int i = start - 1; i < end; i++) {
			pos = pos.add(factor.multiply(BigInteger.valueOf(i)));
			factor = factor.divide(BigInteger.valueOf(k));
		}
		
		return pos;
	}
	
	public static void next_case(long case_num, PrintWriter writer, Scanner scanner) {
		int k = scanner.nextInt();
		int c = scanner.nextInt();
		int s = scanner.nextInt();
		
		if (s * c < k) {
			writer.print("Case #" + case_num + ": IMPOSSIBLE");
		} else {
			writer.print("Case #" + case_num + ":");
			
			int start = 1;
			int end = Integer.min(k, c);
			
			for (int i = 0; i < s; i++) {
				if (start <= k) {
					BigInteger pos = findPosition(k, c, start, end);
					writer.print(" " + pos);
					start += c;
					end = Integer.min(k, end + c);
				} else {
					break;
				}
			}
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
