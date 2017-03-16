import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class TypewriterMonkey {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			System.out.println("Couldn't open input file.\n" + e.getMessage());
			e.printStackTrace();
		}
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e) {
			System.out.println("Couldn't open/make output file."
					+ e.getMessage());
			e.printStackTrace();
		}

		int numTrials = scanner.nextInt();
		for (int trial = 1; trial <= numTrials; trial++) {
			try {
				writer.write("Case #" + trial + ": ");
				System.out.println("Trial #" + trial);
				solveTrial(scanner, writer);
				writer.write("\n");
			} catch (IOException e) {
				System.out.println("Error on trial #" + trial + "\n"
						+ e.getMessage());
				e.printStackTrace();
			}
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
		System.out.println("Completed Trials!");
	}

	static long maxCount = 0;
	
	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		int K = scanner.nextInt();
		int L = scanner.nextInt();
		int S = scanner.nextInt();
		scanner.nextLine();
		String keyboard = scanner.nextLine();
		String target = scanner.nextLine();
		if (target.length() > keyboard.length()) {
			writer.write("0.0");
			return;
		}

		// create a frequency table
		int[] frequency = new int[26];
		for (int i = 0; i < keyboard.length(); i++) {
			frequency[keyboard.charAt(i) - 'A']++;
		}

		// check if all the characters are present
		for (int i = 0; i < L; i++) {
			if (frequency[target.charAt(i) - 'A'] == 0) {
				writer.write("0.0");
				return;
			}
		}

		double expectedBan = 0;
		maxCount = 0;
		char[] chars = new char[S];
		expectedBan = (Math.pow(K, S) - count(chars, 0, keyboard, target)) / Math.pow(K, S);
		writer.write((maxCount - expectedBan) + "");
	}
	
	static long count(char[] chars, int startIndex, String keyboard, String target){
		long c = 0;
		for (int i = 0; i < keyboard.length(); i++){
			chars[startIndex] = keyboard.charAt(i);
			if (startIndex + 1 < chars.length){
				c += count(chars, startIndex + 1, keyboard, target);
			}else{
				long a = countNum(chars,target);
				c += a;
				maxCount = Math.max(maxCount, a);
			}
		}
		return c;
	}

	static long countNum(char[] chars, String target) {
		long count = 0;
		for (int i = 0; i <= chars.length - target.length(); i++) {
			count++;
			for (int j = 0; j < target.length(); j++) {
				if (target.charAt(j) != chars[i + j]) {
					count--;
					break;
				}
			}
		}
		if (count < 0){
			System.out.println("WHAT THE FUCK");
			System.exit(-1);
		}
		return count;
	}
}
