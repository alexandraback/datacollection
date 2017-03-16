
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Solution1 {

	static boolean DEBUG = false;

	static String process(String str) {
		if (null == str || str.length() < 2) {
			return str;
		}
		char[] array = str.toCharArray();
		StringBuilder sb = new StringBuilder();
		sb.append(array[0]);
		for (int i = 1; i < array.length; i++) {
			char ch = array[i];
			if (ch >= sb.charAt(0)) {
				sb.insert(0, ch);
			} else {
				sb.append(ch);
			}
		}
		return sb.toString();
	}

	static void processTerminal() {
		System.out.println(process("ZXCASDQWE"));
	}

	static void processFile(String inputFile, String outputFile) {
		try (Scanner scanner = new Scanner(new FileInputStream(inputFile));
				PrintWriter pw = new PrintWriter(outputFile)) {
			int testCaseCount = scanner.nextInt();
			scanner.nextLine();
			for (int i = 1; i <= testCaseCount; i++) {
				String result = process(scanner.nextLine());
				pw.print("Case #" + i + ": " + result);
				pw.println();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		if (DEBUG) {
			processTerminal();
		} else {
			processFile(args[0], args[1]);
		}
	}

}
