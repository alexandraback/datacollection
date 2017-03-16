import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;


public class ProblemA {
	
	private static final Map<Character, Character> map = new HashMap<>(26);
	
	static {
		map.put('a', 'y');
		map.put('b', 'h');
		map.put('c', 'e');
		map.put('d', 's');
		map.put('e', 'o');
		map.put('f', 'c');
		map.put('g', 'v');
		map.put('h', 'x');
		map.put('i', 'd');
		map.put('j', 'u');
		map.put('k', 'i');
		map.put('l', 'g');
		map.put('m', 'l');
		map.put('n', 'b');
		map.put('o', 'k');
		map.put('p', 'r');
		map.put('q', 'z');
		map.put('r', 't');
		map.put('s', 'n');
		map.put('t', 'w');
		map.put('u', 'j');
		map.put('v', 'p');
		map.put('w', 'f');
		map.put('x', 'm');
		map.put('y', 'a');
		map.put('z', 'q');
	}

	public static void main(String[] args) {
		final Scanner in = new Scanner(System.in);
		final PrintWriter out = new PrintWriter(System.out);
		
		final int t = in.nextInt();
		in.nextLine();
		
		for (int tt = 0; tt < t; tt++) {
			final String message = in.nextLine();
			final String translatedMessage = translate(message);
			out.println("Case #" + (tt + 1) + ": " + translatedMessage);
		}
		
		out.flush();
	}
	
	private static String translate(String message) {
		final StringBuilder sb = new StringBuilder(message.length());
		for (int i = 0; i < message.length(); i++) {
			final char c = message.charAt(i);
			if (' ' == c) {
				sb.append(' ');
			} else {
				sb.append(map.get(c));
			}
		}
		return sb.toString();
	}

}
