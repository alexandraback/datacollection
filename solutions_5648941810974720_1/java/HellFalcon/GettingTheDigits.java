import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class GettingTheDigits {
	
	static final String[] NUMS = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	static final char[] ML = {'Z', 'O', 'W', 'T', 'U', 'F', 'X', 'S', 'G', 'E'};
	
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedReader(new FileReader(new File("A-large.in")), 256 << 10));
			BufferedWriter out = new BufferedWriter(new FileWriter(new File("output.txt")), 256 << 10);

			int testsNumber = in.nextInt();
			for (int testId = 1; testId <= testsNumber; testId++) {
				String s = in.next();
				int[] charCounts = new int['Z' - 'A' + 1];
				for (int i = 0; i < s.length(); i++) 
					charCounts[s.charAt(i) - 'A']++;
				int[] digits = new int[10];
				for (int i = 0; i < 10; i+=2) {
					digits[i] = charCounts[ML[i] - 'A'];
					for (int j = 0; j < NUMS[i].length(); j++)
						charCounts[NUMS[i].charAt(j) - 'A'] -= digits[i];
				}
				for (int i = 1; i < 10; i+=2) {
					digits[i] = charCounts[ML[i] - 'A'];
					for (int j = 0; j < NUMS[i].length(); j++)
						charCounts[NUMS[i].charAt(j) - 'A'] -= digits[i];
				}
				out.append("Case #" + testId + ": ");
				for (int i = 0; i < digits.length; i++) {
					for (int j = 0; j < digits[i]; j++)
						out.append((char)('0' + i));
				}
				out.append("\n");
			}
			in.close();
			out.close();
		}
		catch (RuntimeException rte) {
			throw rte;
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
