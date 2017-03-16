package qualification;
import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;


public class A {

	public static void main(String[] args) throws Throwable {
		Scanner in = new Scanner(new File("in/A-small-attempt0.in"));
		System.setOut(new PrintStream(new File("out/A.out")));
		
		int T = in.nextInt();
		in.nextLine();// skip the current line
		for (int test = 1; test <= T; test++) {
			String input = in.nextLine();
			
			String result = parse(input);
			System.out.printf("Case #%d: %s%n", test, result);
		}
		
	}

	private static String parse(String input) {
		char[] output = new char[input.length()];

		for (int i = 0; i < output.length; i++) {
			output[i] = mappings[input.charAt(i)];
		}
		
		return new String(output);
	}
	
	static char[] mappings = new char[128];
	static {
		mappings[' '] = ' ';
		mappings['a'] = 'y';
		mappings['b'] = 'h';
		mappings['c'] = 'e';
		mappings['d'] = 's';
		mappings['e'] = 'o';
		mappings['f'] = 'c';
		mappings['g'] = 'v';
		mappings['h'] = 'x';
		mappings['i'] = 'd';
		mappings['j'] = 'u';
		mappings['k'] = 'i';
		mappings['l'] = 'g';
		mappings['m'] = 'l';
		mappings['n'] = 'b';
		mappings['o'] = 'k';
		mappings['p'] = 'r';
		mappings['q'] = 'z';
		mappings['r'] = 't';
		mappings['s'] = 'n';
		mappings['t'] = 'w';
		mappings['u'] = 'j';
		mappings['v'] = 'p';
		mappings['w'] = 'f';
		mappings['x'] = 'm';
		mappings['y'] = 'a';
		mappings['z'] = 'q';
	}
	
}