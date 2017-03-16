import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Scanner;


public class ProblemC2 {
	public static void main(String[] args) throws IOException {
		Scanner s = null;
		Scanner lineScan = null;
		int size;
		int currentSize;
		String line;
		File output = new File("output.txt");
		PrintWriter printer = new PrintWriter(output);
		s = new Scanner(new BufferedReader(new FileReader("B-small-attempt0.in")));
		size = s.nextInt();
		s.nextLine();
		for (int i = 0; i < size; i++) {
			line = s.nextLine();
			lineScan = new Scanner(line);
			int a = lineScan.nextInt();
			int b = lineScan.nextInt();
			int c = lineScan.nextInt();
			String letters = s.nextLine();
			String goal = s.nextLine();
			int numBan = numBan(c, goal);
			double result = calc(letters, goal, a, b);
			String finalValue;
			if (result != 0) {
				double value = numBan * (1 - result);
				value *= 10000000;
				value = Math.round(value);
				value = value / 10000000;
				finalValue = String.format("%.8g%n", value);
				finalValue = adjust(finalValue);
			} else {
				finalValue = "0.0";
			}
			printer.print("Case #" + (i + 1) + ": ");
			printer.println(finalValue);
		}
		printer.close ();   
	}
	public static int numBan(int total, String goal) {
		int loc = 0;
		int curr = 1;
		while (curr < goal.length()) {
			if (goal.charAt(loc) == goal.charAt(curr)) {
				loc++;
			} else {
				loc = 0;
			}
			curr++;
		}
		int result = 1 + (total - goal.length())/(goal.length() - loc);
		return result;
	}
	public static double calc(String original, String eventual, int countA, int countB) {
		HashMap<Character, Integer> m = new HashMap<Character, Integer>();
		for (int i = 0; i < countA; i++) {
			char value = original.charAt(i);
			if (m.containsKey(value)) {
				m.put(value, m.get(value) + 1);
			} else {
				m.put(value, 1);
			}
		}
		double result = 1.0;
		for (int i = 0; i < countB; i++) {
			char curr = eventual.charAt(i);
			if (m.containsKey(curr)) {
				result *= m.get(curr);
				result /= countA;
			} else {
				result = 0.0;
			}
		}
		return result;
	}
	public static String adjust(String original) {
		int curr = 2;
		int limit = 2;
		while (curr < 9) {
			if (original.charAt(curr) != '0') {
				limit = curr;
			} 
			curr++;
		}
		return original.substring(0, limit + 1);
	}
}
