package problemA;

import java.io.IOException;
import java.util.LinkedList;

public class SolverA {

	public static void main(String[] args) throws IOException {
		LinkedList<String> input = InputReader.read("C:/Users/Danielle/Desktop/A-small-attempt0.in");
		int num = Integer.parseInt(input.removeFirst());
		int i = 1;
		for (String string : input) {
			System.out.println("Case #"+(i++)+": "+translate(string));
		}
	}

	private static String translate(String string) {
		StringBuilder b = new StringBuilder();
		for (int i = 0; i < string.length(); i++){
			b.append(Map.get(string.charAt(i)));
		}
		return b.toString();
	}
}
